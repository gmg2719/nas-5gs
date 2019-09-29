#include "../common/ber.hh"
#include "../common/dissect_nas5g.hh"
#include "../common/dissect_sm_msg.hh"
#include "../common/use_context.hh"
#include "common/packet.hh"

using namespace nas;
using namespace sm;

/* 8.3.9 PDU session modification command */
int sm::dissect_pdu_session_modification_command(dissector d, context* ctx) {
    const use_context uc(ctx, "pdu-session-modification-command", d, 8);

    /* Direction: network to UE */
    down_link(d.packet);

    /* 59 5GSM cause 9.11.4.2    O    TV    2*/
    // ELEM_OPT_TV(0x59, , DE_NAS_5GS_SM_5Gnrsm_cause, NULL);
    auto consumed = dissect_opt_tv( &nrsm_cause, d, ctx);
    d.step(consumed);

    /* 2A Session-AMBR     9.11.4.14    O    TLV    8*/
    consumed = dissect_opt_tlv( &session_ambr, d, ctx);
    d.step(consumed);

    /*56    RQ timer value    GPRS timer     9.11.2.3    O    TV    2*/
    // ELEM_OPT_TV(0x56, , DE_GPRS_TIMER, " - PDU session release time");
    consumed = dissect_opt_tv( &rq_gprs_timer, d, ctx);
    d.step(consumed);

    /* 8-  Always-on PDU session indication 9.11.4.3  O    TV    1 */
    consumed = dissect_opt_tv_short( &alwayson_pdu_session_indication, d, ctx);
    d.step(consumed);

    /*7A    Authorized QoS rules    QoS rules     9.11.4.13    O    TLV-E    3-65538*/
    // ELEM_OPT_TLV_E(  0x7A, , DE_NAS_5GS_SM_QOS_RULES, " - Authorized QoS rules");
    consumed = dissect_opt_tlv_e( &authorized_qos_rules, d, ctx);
    d.step(consumed);

    /*75 Mapped EPS  bearer contexts     9.11.4.5    O TLV-E    7-65538*/
    consumed = dissect_opt_tlv_e( &mapped_eps_bearer_context, d, ctx);
    d.step(consumed);

    /*79 Authorized QoS flow descriptions     QoS flow descriptions 9.11.4.12 O TLV-E 6-65538*/
    // ELEM_OPT_TLV_E(  0x79, , DE_NAS_5GS_SM_QOS_FLOW_DES, " - Authorized");
    consumed = dissect_opt_tlv_e( &authorized_qos_flow_desc, d, ctx);
    d.step(consumed);

    /*7B    Extended protocol configuration options  9.11.4.6    O    TLV-E    4-65538*/
    consumed = dissect_opt_tlv_e( &extended_pco, d, ctx);
    d.step(consumed);

    /*xx Session-TMBR    9.11.4.19	O	TLV	8    */


    return uc.length;
}
namespace sm {

int dissect_requested_qos_rules(dissector d, context* ctx) {
    return dissect_qos_rules(d, ctx);
}





}