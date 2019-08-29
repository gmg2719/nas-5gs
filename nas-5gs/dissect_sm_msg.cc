#include "dissect_nas_5gs.hh"
#include "dissect_sm_msg.hh"
#include "ts24007.hh"

using namespace nas;

/* 8.3 5GS session management messages */

/*
 * 8.3.6 PDU session authentication result
 */
int sm::pdu_ses_auth_res(dissector d, context* ctx) {
    auto start = d.offset;
    /* Direction: network to UE */
    d.pinfo->dir = pi_dir::dl;

    /*EAP message    EAP message 9.11.2.2    M    LV-E    6-1502 */
    // ELEM_MAND_LV_E(NAS_5GS_PDU_TYPE_COMMON,
    //                DE_NAS_5GS_CMN_EAP_MESSAGE,
    //                NULL,
    //                ei_nas_5gs_missing_mandatory_elemen);
    auto consumed = dissect_elem_lv_e(nullptr, &eap_msg, d, ctx);
    d.step(consumed);

    /*7B    Extended protocol configuration options    Extended protocol configuration
     * options    9.11.4.2    O    TLV - E    4 - 65538*/
    // ELEM_OPT_TLV_E(0x7B, NAS_PDU_TYPE_ESM, DE_ESM_EXT_PCO, NULL);
    consumed = dissect_opt_elem_tlv_e(nullptr, &ext_pco, d, ctx);
    d.step(consumed);

    d.extraneous_data_check(0);
    return d.offset - start;
}

/*
 * 9.9.4.26 Extended protocol configuration options
 */
int sm::dissect_sm_cause(dissector d, context* ctx) { return 0; }

int sm::dissect_ext_pco(dissector d, context* ctx) {
    bug("no dissect\n");
    return d.length;
}

int sm::dissect_eap_msg(dissector d, context* ctx) {
    return nas::dissect_eap_msg(d, ctx);
}
// *     9.11.4.13    QoS rules

static true_false_string tfs_nas_5gs_sm_dqr = {
    "The QoS rule is the default QoS rule",
    "The QoS rule is not the default QoS rule",
};

static const value_string nas_5gs_rule_operation_code_values[] = {
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

static const value_string nas_5gs_sm_pf_type_values[] = {
    {0x01, "Match-all type"},
    {0x10, "IPv4 remote address type"},
    {0x11, "IPv4 local address type"},
    {0x21, "IPv6 remote address/prefix length type"},
    {0x23, "IPv6 local address/prefix length type"},
    {0x30, "Protocol identifier/Next header type"},
    {0x40, "Single local port type"},
    {0x41, "Local port range type"},
    {0x50, "Single remote port type"},
    {0x51, "Remote port range type"},
    {0x60, "Security parameter index type"},
    {0x70, "Type of service/Traffic class type"},
    {0x80, "Flow label type"},
    {0x81, "Destination MAC address type"},
    {0x82, "Source MAC address type"},
    {0x83, "802.1Q C-TAG VID type"},
    {0x84, "802.1Q S-TAG VID type"},
    {0x85, "802.1Q C-TAG PCP/DEI type"},
    {0x86, "802.1Q S-TAG PCP/DEI type"},
    {0x87, "Ethertype type"},
    {0, nullptr},
};

static const value_string nas_5gs_sm_pkt_flt_dir_values[] = {
    {0x00, "Reserved"},
    {0x01, "Downlink only"},
    {0x02, "Uplink only"},
    {0x03, "Bidirectional"},
    {0, nullptr},
};

static const value_string nas_5gs_rule_param_cont[] = {
    {0x0, "Reserved"},
    {0x01, "5QI 1"},
    {0x02, "5QI 2"},
    {0x03, "5QI 3"},
    {0x04, "5QI 4"},
    {0x05, "5QI 5"},
    {0x06, "5QI 6"},
    {0x07, "5QI 7"},
    {0x08, "5QI 8"},
    {0x09, "5QI 9"},
    {0, nullptr},
};

const field_meta hf_sm_dqr = {
    "DQR",
    "nas_5gs.sm.dqr",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,
    (&tfs_nas_5gs_sm_dqr),
    nullptr,
    0x10,
};
const field_meta hf_sm_rop = {
    "Rule operation code",
    "nas_5gs.sm.rop",
    ft::ft_uint8,
    fd::base_dec,
    (nas_5gs_rule_operation_code_values),
    nullptr,
    nullptr,
    0xe0,
};
const field_meta hf_sm_nof_pkt_filters = {
    "Number of packet filters",
    "nas_5gs.sm.nof_pkt_filters",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x0f,
};

const field_meta hf_sm_qfi = {
    "Qos flow identifier",
    "nas_5gs.sm.qfi",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,nullptr,nullptr,
    0x3f,
};

const field_meta hf_sm_qos_rule_id = {
    "QoS rule identifier",
    "nas_5gs.sm.qos_rule_id",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,nullptr,nullptr,
    0x0,
};
const field_meta hf_sm_length = {
    "Length",
    "nas_5gs.sm.length",
    ft::ft_uint16,
    fd::base_dec,
    nullptr,nullptr,nullptr,
    0x0,
};
const field_meta hf_sm_pkt_flt_id = {
    "Packet filter identifier",
    "nas_5gs.sm.pkt_flt_id",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,nullptr,nullptr,
    0x0f,
};
const field_meta hf_sm_pkt_flt_dir = {
    "Packet filter direction",
    "nas_5gs.sm.pkt_flt_dir",
    ft::ft_uint8,
    fd::base_dec,
    (nas_5gs_sm_pkt_flt_dir_values),
    nullptr,
    nullptr,
    0x30,
};
const field_meta hf_sm_pf_len = {
    "Length",
    "nas_5gs.sm.pf_len",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,nullptr,nullptr,
    0x0,
};
const field_meta hf_sm_pf_type = {
    "Packet filter component type",
    "nas_5gs.sm.pf_type",
    ft::ft_uint8,
    fd::base_dec,
    (nas_5gs_sm_pf_type_values),
    nullptr,
    nullptr,
    0x0,
};

const field_meta hf_pdu_addr_ipv4 = {
    "PDU address information",
    "nas_5gs.sm.pdu_addr_inf_ipv4",
    ft::ft_uint32, // FT_IPv4,
    fd::ipv4,
    nullptr,
    nullptr,
    nullptr,
    0x0,
};
const field_meta hf_pdu_ipv4_mask = {
    "IPv4 address mask",
    "nas_5gs.ipv4_address_mask",
    ft::ft_uint32,
    fd::ipv4,
    nullptr,
    nullptr,
    nullptr,
    0x0,
};
const field_meta hf_pid_next_hd = {
    "Protocol identifier/Next header type",
    "nas_5gs.protocol_identifier_or_next_hd",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,nullptr,nullptr,
    0x0,
};
const field_meta hf_single_port_type = {
    "Port number",
    "nas_5gs.port_type",
    ft::ft_uint16,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x0,
};
const field_meta hf_sm_qos_rule_precedence = {
    "QoS rule precedence",
    "nas_5gs.sm.qos_rule_precedence",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x0,
};

int dissect_packet_filter(dissector d, int pf_type, context* ctx) {
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
        d.add_item(4, &hf_pdu_addr_ipv4, enc::be);
        d.step(4);
        d.add_item(4, &hf_pdu_ipv4_mask, enc::be);
        d.step(4);
        len = 8;
    } break;
    case 48: {
        d.add_item(1, &hf_pid_next_hd, enc::be);
        d.step(1);
        len = 1;
    } break;
    case 64: { /* Single local port type */
        d.add_item(2, &hf_single_port_type, enc::be);
        d.step(2);
        len = 2;
    } break;
    case 80: { /* Single remote port type */
        d.add_item(2, &hf_single_port_type, enc::be);
        d.step(2);
        len = 2;
    } break;
    default:
        d.step(d.length);
    }
    return len;
}
int dissect_packet_filters(dissector d, int rop, context* ctx) {
    auto start = d.offset;
    /* "create new QoS rule", or "modify existing QoS rule and add packet
     * filters" or "modify existing QoS rule and replace packet filters"
     */
    /* 0    0    Packet filter direction 1    Packet filter identifier 1*/
    d.add_item(1, &hf_sm_pkt_flt_dir, enc::be);
    d.add_item(1, &hf_sm_pkt_flt_id, enc::be);
    d.step(1);

    /* Length of packet filter contents */
    auto pfclen = (int) d.tvb->get_uint8(d.offset);
    d.add_item(1, &hf_sm_pf_len, enc::be);
    d.step(1);

    auto k       = 1;

    /* Packet filter contents */
    while (pfclen > 0) {
        auto start = d.offset;
        auto subtree = d.tree->add_subtree(
            d.pinfo, d.tvb, d.offset, -1, "Packet filter component %u", k);
        use_tree ut(d, subtree);
        /* Each packet filter component shall be encoded as a sequence of a
         * one octet packet filter component type identifier and a fixed
         * length packet filter component value field. The packet filter
         * component type identifier shall be transmitted first.
         */
        auto pf_type = d.tvb->get_uint8(d.offset);
        d.add_item(1, &hf_sm_pf_type, enc::be);
        d.step(1);
        /* Packet filter length contains the length of component type and
         * content */

        auto consumed = dissect_packet_filter(d.slice(pfclen - 1), pf_type, ctx);
        d.step(consumed);
        subtree->set_length(d.offset - start);

        ++k;
    } // while(fclen)

    return d.offset - start;
}
int sm::dissect_authorized_qos_rules(dissector d, context* ctx) {
    auto len = d.length;
    static const field_meta* pkt_flt_flags[] = {
        &hf_sm_rop,
        &hf_sm_dqr,
        &hf_sm_nof_pkt_filters,
        nullptr,
    };
    auto i = 1;
    while(d.offset>0){
        /* QoS Rule */
        auto subtree = d.tree->add_subtree(d.pinfo, d.tvb, d.offset, -1, "QoS rule %u", i);
        use_tree ut(d, subtree);

        /* QoS rule identifier Octet 4*/
        auto rule_id = d.tvb->get_uint8(d.offset);
        d.add_item(1, &hf_sm_qos_rule_id, enc::be);
        d.step(1);

        /* Length of QoS rule Octet 5 - 6*/
        auto length = (int) d.tvb->get_ntohs(d.offset);
        d.add_item(2, &hf_sm_length, enc::be);
        d.step(2);

        subtree->set_length(length + 3);

        /* Rule operation code    DQR bit    Number of packet filters */
        auto n_filters = d.tvb->get_uint8(d.offset);
        auto rop       = n_filters >> 5;
        n_filters      = n_filters & 0x0f;
        d.add_bits(pkt_flt_flags);
        d.step(1);

        /* For the "delete existing QoS rule" operation and for the "modify existing QoS
         * rule without modifying packet filters" operation, the number of packet filters
         * shall be coded as 0.
         */
        if (rop ==0 || rop == 7){
            // reserved
            ++i;
            d.step(length - 1);
            continue;
        }
        if (rop == 2 || rop == 6){
            if (n_filters !=0){
                d.step(length - 1);
                ++i;
                continue;
            }
        }
        /* Packet filter list */
        auto j = 1;
        while (n_filters > 0) {
            auto subtree =
                d.tree->add_subtree(d.pinfo, d.tvb, d.offset, -1, "Packet filter %u", j);
            use_tree ut(d, subtree);
            if (rop == 5) {
                /* modify existing QoS rule and delete packet filters */
                /* 0    0    0    0    Packet filter identifier x*/
                d.add_item(1, &hf_sm_pkt_flt_id, enc::be);
                d.step(1);
            }else{
                auto consumed = dissect_packet_filters(d, rop, ctx);
                d.step(consumed);
            }
        }
        /* QoS rule precedence (octet z+1)
         * For the "delete existing QoS rule" operation, the QoS rule precedence value
         * field shall not be included. For the "create new QoS rule" operation, the
         * QoS rule precedence value field shall be included.
         */
        if (rop != 2) { /* Delete existing QoS rule */
            d.add_item(1, &hf_sm_qos_rule_precedence, enc::be);
            d.step(1);
        }
        /* QoS flow identifier (QFI) (bits 6 to 1 of octet z+2)
         * For the "delete existing QoS rule" operation, the QoS flow identifier value
         * field shall not be included. For the "create new QoS rule" operation, the
         * QoS flow identifier value field shall be included.
         */
        /* Segregation bit (bit 7 of octet z+2) */
        d.add_item(1, &hf_sm_qfi, enc::be);
        d.step(1);

        ++i;
    } // while(d.offset)
    return len;
}

int sm::dissect_mapped_eps_b_cont(dissector d, context* ctx) { return 0; }

int sm::dissect_backoff_gprs_timer3(dissector d, context* ctx) { return 0; }

int sm::dissect_sm_cap(dissector d, context* ctx) { return 0; }

int sm::dissect_max_num_sup_kpt_flt(dissector d, context* ctx) { return 0; }

int sm::dissect_ses_ambr(dissector d, context* ctx) { return 0; }

int sm::dissect_rq_gprs_timer(dissector d, context* ctx) { return 0; }

int sm::dissect_always_on_pdu_ses_ind(dissector d, context* ctx) { return 0; }
