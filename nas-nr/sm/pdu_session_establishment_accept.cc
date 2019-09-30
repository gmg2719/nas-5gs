#include "../common/ber.hh"
#include "../common/common.hh"
#include "../common/dissect_sm_msg.hh"
#include "../common/use_context.hh"
#include "common/packet.hh"

using namespace nas;
using namespace sm;

// Selected SSC mode    SSC mode 9.11.4.16
extern const tag_field hfm_selected_ssc_mode = {
    "SSC mode - Selected",
    0xf0,
    (const v_string[]){
        {0x1, "SSC mode 1"},
        {0x2, "SSC mode 2"},
        {0x3, "SSC mode 3"},
        {0x4, "SSC mode 1"},
        {0x5, "SSC mode 2"},
        {0x6, "SSC mode 3"},
        {0, nullptr},
    },
};

extern const element_meta eap_message;

/* 8.3.2 PDU session establishment accept */
int sm::dissect_pdu_session_establishment_accept(dissector d, context* ctx) {
    const use_context uc(ctx, "pdu-session-establishment-accept", d, -1);

    /* Direction: network to UE */
    down_link(d.packet);

    /* Selected PDU session type    PDU session type 9.11.4.11    M    V    1/2 H0*/
    dissect_pdu_session_type(d, ctx);

    /* Selected SSC mode    SSC mode 9.11.4.16    M    V    1/2 H1*/
    (void) d.add_item(&hfm_selected_ssc_mode);
    d.step(1);

    /* Authorized QoS rules QoS rules 9.11.4.13 M LV-E 2-65537  */
    // ELEM_MAND_LV_E(,DE_NAS_5GS_SM_QOS_RULES, " - Authorized QoS rules",);
    auto consumed = dissect_lv_e( &authorized_qos_rules, d, ctx);
    d.step(consumed);

    /* Session-AMBR 9.11.4.14    M    LV    7 */
    consumed = dissect_lv( &session_ambr, d, ctx);
    d.step(consumed);

    /*59 5GSM cause 9.11.4.2    O    TV    2*/
    consumed = dissect_opt_tv( &nrsm_cause, d, ctx);
    d.step(consumed);

    /*29  PDU address 9.11.4.10    O    TLV    7 */
    consumed = dissect_opt_tlv( &pdu_address, d, ctx);
    d.step(consumed);

    /*56    RQ timer value    GPRS timer 9.11.2.3    O    TV    2*/
    // ELEM_OPT_TV(0x56, , DE_GPRS_TIMER, " - RQ timer value");
    consumed = dissect_opt_tv( &rq_gprs_timer, d, ctx);
    d.step(consumed);

    /* 22 S-NSSAI 9.11.2.8    O    TLV    3-6*/
    consumed = dissect_opt_tlv( &s_nssai, d, ctx);
    d.step(consumed);

    /* 8-    Always-on PDU session indication   9.11.4.3  O    TV    1 */
    consumed = dissect_opt_tv_short( &alwayson_pdu_session_indication, d, ctx);
    d.step(consumed);

    /* 75    Mapped EPS bearer contexts  9.11.4.8    O  TLV-E    7-65538 */
    consumed = dissect_opt_tlv_e( &mapped_eps_bearer_context, d, ctx);
    d.step(consumed);

    /*78    EAP message    EAP message 9.11.2.2    O    TLV-E    7-1503*/
    consumed = dissect_opt_tlv_e( &eap_message, d, ctx);
    d.step(consumed);

    /*79 Authorized QoS flow descriptions    QoS flow descriptions 9.11.4.12    O
     * TLV-E    6-65538 */
    // ELEM_OPT_TLV_E( 0x79, , DE_NAS_5GS_SM_QOS_FLOW_DES, " - Authorized");
    consumed = dissect_opt_tlv_e( &authorized_qos_flow_desc, d, ctx);
    d.step(consumed);

    /*7B  Extended protocol configuration options 9.11.4.6    O    TLV-E    4-65538*/
    consumed = dissect_opt_tlv_e( &extended_pco, d, ctx);
    d.step(consumed);

    /* 25 DNN 9.11.2.1A    O    TLV    3-102 */
    consumed = dissect_opt_tlv( &dnn, d, ctx);
    d.step(consumed);

    /*xx	5GSM network feature support 9.11.4.18	O	TLV	3-15
     * consumed = dissect_opt_tlv( &sm_network_feature_support, d, ctx);
     * d.step(consumed);
    xx	Session-TMBR	Session-TMBR 9.11.4.19	O	TLV	8
     consumed = dissect_opt_tlv( &session_tmbr, d, ctx);
     d.step(consumed);
    TBD	Serving PLMN rate control 9.11.4.20	O	TLV	4
     consumed = dissect_opt_tlv( &serving_plmn_rate_control, d, ctx);
     d.step(consumed);
    XX	ATSSS container 9.11.4.22	O	TLV-E	3-65538
     consumed = dissect_opt_tlv_e( &atsss_container, d, ctx);
     d.step(consumed);
    XX	Control plane only indication 9.11.4.23	O	TV	1
     consumed = dissect_opt_tv_short( &control_plane_only_indication, d, ctx);
     d.step(consumed);
    */
   // no data length check

    return uc.length;
}
