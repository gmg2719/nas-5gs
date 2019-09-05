#include "../dissect_nas5g.hh"
#include "../dissect_sm_msg.hh"
#include "../ts24007.hh"

using namespace nas;
using namespace sm;

/* 8.3.9 PDU session modification command */
int sm::dissect_pdu_ses_mod_cmd(dissector d, context* ctx) {    
    const use_context uc(ctx, "pdu-session-modification-command", d, 8);

    /* Direction: network to UE */
    d.pinfo->dir = pi_dir::dl;

    /*59 5GSM cause 9.11.4.2    O    TV    2*/
    // ELEM_OPT_TV(0x59, , DE_NAS_5GS_SM_5GSM_CAUSE, NULL);
    auto consumed = dissect_opt_elem_tv(nullptr, &sm_cause, d, ctx);
    d.step(consumed);

    /*2A Session-AMBR     9.11.4.14    O    TLV    8*/
    // ELEM_OPT_TLV(0x2A, , DE_NAS_5GS_SM_SESSION_AMBR, NULL);
    consumed = dissect_opt_elem_tlv(nullptr, &ses_ambr, d, ctx);
    d.step(consumed);

    /*56    RQ timer value    GPRS timer     9.11.2.3    O    TV    2*/
    // ELEM_OPT_TV(0x56, , DE_GPRS_TIMER, " - PDU session release time");
    consumed = dissect_opt_elem_tv(nullptr, &rq_gprs_timer, d, ctx);
    d.step(consumed);

    /* 8-  Always-on PDU session indication 9.11.4.3  O    TV    1 */
    // ELEM_OPT_TV_SHORT(  0x80, , DE_NAS_5GS_SM_ALWAYS_ON_PDU_SES_IND, );
    consumed = dissect_opt_elem_tv_short(nullptr, &always_on_pdu_ses_ind, d, ctx);
    d.step(consumed);

    /*7A    Authorized QoS rules    QoS rules     9.11.4.13    O    TLV-E    3-65538*/
    // ELEM_OPT_TLV_E(  0x7A, , DE_NAS_5GS_SM_QOS_RULES, " - Authorized QoS rules");
    consumed = dissect_opt_elem_tlv_e(nullptr, &authorized_qos_rules, d, ctx);
    d.step(consumed);

    /*75 Mapped EPS  bearer contexts     9.11.4.5    O TLV-E    7-65538*/
    // ELEM_OPT_TLV_E(0x75, , DE_NAS_5GS_SM_MAPPED_EPS_B_CONT, );
    consumed = dissect_opt_elem_tlv_e(nullptr, &mapped_eps_b_cont, d, ctx);
    d.step(consumed);

    /*79 Authorized QoS flow descriptions     QoS flow descriptions 9.11.4.12 O TLV-E 6-65538*/
    // ELEM_OPT_TLV_E(  0x79, , DE_NAS_5GS_SM_QOS_FLOW_DES, " - Authorized");
    consumed = dissect_opt_elem_tlv_e(nullptr, &authorized_qos_flow_des, d, ctx);
    d.step(consumed);

    /*7B    Extended protocol configuration options  9.11.4.6    O    TLV-E    4-65538*/
    // ELEM_OPT_TLV_E(0x7B, , DE_ESM_EXT_PCO, NULL);
    consumed = dissect_opt_elem_tlv_e(nullptr, &ext_pco, d, ctx);
    d.step(consumed);

    /*xx Session-TMBR    9.11.4.19	O	TLV	8    */
   

    return uc.length;
}
namespace sm {




const value_string nas_5gs_sm_pf_type_values[] = {
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
int dissect_requested_qos_rules(dissector d, context* ctx) {
    return dissect_qos_rules(d, ctx);
}

const field_meta hf_sm_e = {
    "E bit",
    "nas_5gs.sm.e",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x40,
};
const field_meta hf_sm_nof_params = {
    "Number of parameters",
    "nas_5gs.sm.nof_params",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x3f,
};

static const value_string nas_5gs_sm_param_id_values[] = {
    {0x01, "5QI"},
    {0x02, "GFBR uplink"},
    {0x03, "GFBR downlink"},
    {0x04, "MFBR uplink"},
    {0x05, "MFBR downlink"},
    {0x06, "Averaging window"},
    {0x07, "EPS bearer identity"},
    {0, nullptr},
};
const field_meta hf_sm_param_id = {
    "Parameter identifier",
    "nas_5gs.sm.param_id",
    ft::ft_uint8,
    fd::base_dec,
    nas_5gs_sm_param_id_values,
    nullptr,
    nullptr,
    0x0,
};
const field_meta hf_sm_param_len = {
    "Length",
    "nas_5gs.sm.param_len",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x0,
};
const field_meta hf_sm_pal_cont = {
    "Parameters content",
    "nas_5gs.sm.pal_cont",
    ft::ft_uint8,
    fd::base_dec,
    nas_5gs_rule_param_cont,
    nullptr,
    nullptr,
    0x0,
};
const field_meta hf_averaging_wind = {
    "Average Window",
    "nas_5gs.sm.qos.param",
    ft::ft_uint16,
    fd::base_bin,
    nullptr,
    nullptr,
    nullptr,
    0,
};
const field_meta hf_eps_bearer_identity = {
    "EPS bearer identity",
    "nas_5gs.sm.qos.eps.bearid",
    ft::ft_uint8,
    fd::base_hex,
    nullptr,
    nullptr,
    nullptr,
    0,
};


} // namespace sm_pdu_ses_mod
