#include "../dissect_sm_msg.hh"

using namespace sm;


/*The description and valid combinations of packet filter component type identifiers in a
 * packet filter are defined in 3GPP TS 23.501 [8].*/
int dissect_packet_filter(dissector d, int pf_type, context* ctx) {
    const use_context uc(ctx, "packet-filter", d, -1);

    auto len = d.length;
    switch (pf_type) {
    case 1: {
        /* Match-all type
         * . If the "match-all type" packet filter component is
         * present in the packet filter, no other packet filter
         * component shall be present in the packet filter and the
         * length of the packet filter contents field shall be set
         * to one.
         */
        len = 0;
    } break;
    case 16:
        /* For "IPv4 remote address type", the packet filter
         * component value field shall be encoded as a sequence of
         * a four octet IPv4 address field and a four octet IPv4
         * address mask field. The IPv4 address field shall be
         * transmitted first.
         */

    case 17: {
        /* For "IPv4 local address type", the packet filter
         * component value field shall be encoded as defined for
         * "IPv4 remote address type"
         */
        (void) d.add_item(4, &hf_pdu_addr_ipv4, enc::be);
        d.step(4);
        (void) d.add_item(4, &nas::hf_pdu_ipv4_mask, enc::be);
        d.step(4);
        len = 8;
    } break;
    case 33: { // IPv6 remote address/prefix length type
    };
    case 35: { // IPv6 local address/prefix length type
        // d.add_item(16, &hf_pdu_addr_ipv6, enc::be);
        d.step(16);
        // d.add_item(1, &hf_pdu_addr_ipv6_prefix, enc::be);
        d.step(1);
    } break;
    case 48: { // Protocol identifier/Next header type
        (void) d.add_item(1, &nas::hf_pid_next_hd, enc::be);
        d.step(1);
        len = 1;
    } break;
    case 64: { /* Single local port type */
        (void) d.add_item(2, &nas::hf_single_port_type, enc::be);
        d.step(2);
        len = 2;
    } break;
    case 0x51: { // Remote port range type
        // the packet filter component value field shall be encoded as a sequence of a two
        // octet port range low limit field and a two octet port range high limit field.
        // The port range low limit field shall be transmitted first
        d.step(4);
    } break;
    case 80: { /* Single remote port type */
    };
    case 0x41: { // Local port range type
        (void) d.add_item(2, &nas::hf_single_port_type, enc::be);
        d.step(2);
        len = 2;
    }; break;
    case 0x60: { // Security parameter index type
        // For "security parameter index", the packet filter component value field shall
        // be encoded as four octets which specify the IPSec security parameter index
        d.step(4);
    } break;
    case 0x70: { // Type of service/Traffic class type
        // For "type of service/traffic class type", the packet filter component value
        // field shall be encoded as a sequence of a one octet type-of-service/traffic
        // class field and a one octet type-of-service/traffic class mask field. The
        // type-of-service/traffic class field shall be transmitted first.
        d.step(2);
    } break;
    default:
        d.step(d.length);
    }
    return len;
}

// Figure 9.11.4.13.4 Packet filter list when the rule operation is "create new QoS rule",
// or "modify existing QoS rule and add packet filters" or "modify existing QoS rule and
// replace all packet filters"
int dissect_packet_filters(dissector d, int rop, context* ctx) {
    (void) rop;

    const use_context uc(ctx, "packet-filters", d, -1);

    /* "create new QoS rule", or "modify existing QoS rule and add packet
     * filters" or "modify existing QoS rule and replace packet filters"
     */
    /* 0    0    Packet filter direction 1    Packet filter identifier 1*/
    (void) d.add_item(1, &hf_sm_pkt_flt_dir, enc::be);
    (void) d.add_item(1, &hf_sm_pkt_flt_id, enc::be);
    d.step(1);

    /* Length of packet filter contents */
    auto pfclen = static_cast< int >(d.uint8());
    // (void) d.add_item(1, &hf_sm_pf_len, enc::be);
    d.step(1);

    d.step(pfclen);
    pfclen = 0; // skip dissect packet filter contents
    // TODO: detail
    auto k = 1;
    /* Packet filter contents */
    while (pfclen > 0) {
        const auto start   = d.offset;
        auto       subtree = d.add_item(-1, "Packet filter component %u", k);
        use_tree   ut(d, subtree);
        /* Each packet filter component shall be encoded as a sequence of a
         * one octet packet filter component type identifier and a fixed
         * length packet filter component value field. The packet filter
         * component type identifier shall be transmitted first.
         */
        const auto pf_type = d.uint8();
        (void) d.add_item(1, &hf_sm_pf_type, enc::be);
        d.step(1);
        /* Packet filter length contains the length of component type and
         * content */
        const auto consumed = dissect_packet_filter(d.slice(pfclen - 1), pf_type, ctx);
        d.step(consumed);
        subtree->set_length(d.offset - start);

        ++k;
    } // while(fclen)

    return d.offset - uc.offset;
}
const true_false_string tfs_segregation = {
    "Segregation requested",
    "Segregation not requested",
};
const field_meta hf_segregation = {
    "Segregation",
    "nas.nr.sm.qos_rule.segregation",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,
    &tfs_segregation,
    nullptr,
    0x40u,
};
// Authorized QoS rules QoS rules 9.11.4.13
int sm::dissect_qos_rules(dissector d, context* ctx) {
    const use_context uc(ctx, "authorized-qos-rules", d);

    static const field_meta* pkt_flt_flags[] = {
        &hf_sm_rop,
        &hf_sm_dqr,
        &hf_sm_nof_pkt_filters,
        nullptr,
    };

    auto i = 1;
    while (d.length > 0) {
        /* QoS Rule */
        auto     subtree = d.add_item(-1, "QoS rule %u", i++);
        use_tree ut(d, subtree);

        /* QoS rule identifier Octet 4*/
        (void) d.add_item(1, &hf_sm_qos_rule_id, enc::be);
        d.step(1);

        /* Length of QoS rule Octet 5 - 6*/
        const auto length = static_cast< int >(d.ntohs());
        // (void) d.add_item(2, &hf_sm_length, enc::be);
        d.step(2);

        subtree->set_length(length + 3);

        /* Rule operation code    DQR bit    Number of packet filters */
        auto n_filters = d.uint8();
        const auto rop       = n_filters >> 5u;
        n_filters            = n_filters & 0x0fu;
        d.add_bits(pkt_flt_flags);
        d.step(1);

        /* For the "delete existing QoS rule" operation and for the "modify existing QoS
         * rule without modifying packet filters" operation, the number of packet filters
         * shall be coded as 0.
         */
        if (rop == 0 || rop == 7) {
            // reserved
            ++i;
            d.step(length - 1);
            continue;
        }
        // 6 Modify existing QoS rule without modifying packet filters
        if (rop == 2 || rop == 6) { // 2 Delete existing QoS rule
            if (n_filters != 0) {
                diag("the number of packet filters shall be coded as 0\n");
                d.step(length - 1);
                ++i;
                continue;
            }
        }
        /* Packet filter list */
        for (auto j = 1; j <= n_filters; j++) {
            const auto     st2 = d.add_item(-1, "Packet filter %u", j);
            use_tree ut2(d, st2);
            auto           start = d.offset;
            if (rop == 5) {
                /* modify existing QoS rule and delete packet filters */
                /* 0    0    0    0    Packet filter identifier x*/
                (void) d.add_item(1, &hf_sm_pkt_flt_id, enc::be);
                d.step(1);
            } else {
                const auto consumed = dissect_packet_filters(d, rop, ctx);
                d.step(consumed);
            }
            st2->set_length(d.offset - start);
        }
        /* QoS rule precedence (octet z+1)
         * For the "delete existing QoS rule" operation, the QoS rule precedence value
         * field shall not be included. For the "create new QoS rule" operation, the
         * QoS rule precedence value field shall be included.
         */
        if (rop != 2) { /* Delete existing QoS rule */
            (void) d.add_item(1, &hf_sm_qos_rule_precedence, enc::be);
            d.step(1);
        }
        /* QoS flow identifier (QFI) (bits 6 to 1 of octet z+2)
         * For the "delete existing QoS rule" operation, the QoS flow identifier value
         * field shall not be included. For the "create new QoS rule" operation, the
         * QoS flow identifier value field shall be included.
         */
        /* Segregation bit (bit 7 of octet z+2) */
        (void) d.add_item(1, &hf_sm_qfi, enc::be);
        (void) d.add_item(1, &hf_segregation, enc::be);
        d.step(1);

    } // while(d.offset)

    return uc.length;
}

// Authorized QoS rules QoS rules 9.11.4.13
int sm::dissect_authorized_qos_rules(dissector d, context* ctx) {
    return dissect_qos_rules(d, ctx);
}

extern const element_meta sm::requested_qos_rules = {
    0x7A,
    "QoS rules - Requested QoS rules",
    dissect_requested_qos_rules,
    nullptr,

};
/*  9.11.4.13    QoS rules */
const true_false_string sm::tfs_sm_default_qos_rules = {
    "The QoS rule is the default QoS rule",
    "The QoS rule is not the default QoS rule",
};

const field_meta sm::hf_sm_dqr = {
    "DQR",
    "nas.nr.sm.dqr",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,
    &tfs_sm_default_qos_rules,
    nullptr,
    0x10,
};

extern const value_string nas_5gs_rule_operation_code_values[] = {
    {0x0, "Reserved"},
    {0x1, "Create new QoS rule"},
    {0x2, "Delete existing QoS rule"},
    {0x3, "Modify existing QoS rule and add packet filters"},
    {0x4, "Modify existing QoS rule and replace packet filters"},
    {0x5, "Modify existing QoS rule and delete packet filters"},
    {0x6, "Modify existing QoS rule without modifying packet filters"},
    {0x7, "Reserved"},
    {0, nullptr},
};

// Authorized QoS rules QoS rules 9.11.4.13
const element_meta sm::authorized_qos_rules = {
    0x7A,
    "QoS rules - Authorized QoS rules",
    dissect_authorized_qos_rules,
    nullptr,
};


extern const value_string sm::rule_operation_code_values[] = {
    {0x0, "Reserved"},
    {0x1, "Create new QoS rule"},
    {0x2, "Delete existing QoS rule"},
    {0x3, "Modify existing QoS rule and add packet filters"},
    {0x4, "Modify existing QoS rule and replace packet filters"},
    {0x5, "Modify existing QoS rule and delete packet filters"},
    {0x6, "Modify existing QoS rule without modifying packet filters"},
    {0x7, "Reserved"},
    {0, nullptr},
};

const field_meta sm::hf_sm_rop = {
    "Rule operation code",
    "nas.nr.sm.rop",
    ft::ft_uint8,
    fd::base_dec,
    rule_operation_code_values,
    nullptr,
    nullptr,
    0xe0,
};
const field_meta sm::hf_sm_nof_pkt_filters = {
    "Number of packet filters",
    "nas.nr.sm.nof_pkt_filters",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x0f,
};

const field_meta sm::hf_sm_qos_rule_id = {
    "QoS rule identifier",
    "nas.nr.sm.qos_rule_id",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x0,
};


const field_meta sm::hf_sm_qos_rule_precedence = {
    "QoS rule precedence",
    "nas.nr.sm.qos_rule_precedence",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x0,
};