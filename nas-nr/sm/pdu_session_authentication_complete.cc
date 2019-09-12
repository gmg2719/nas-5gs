#include "../dissect_sm_msg.hh"
#include "../ber.hh"
#include "../common.hh"

/*  8.3.5 PDU session authentication complete */
int sm::dissect_pdu_ses_authentication_cmpl(dissector d, context* ctx) {
    const use_context uc(ctx, "pdu-session-authentication-complete", d, 0);    

    /* Direction: UE to network */
    up_link(d.pinfo);    

    /* EAP message 9.11.2.2    M    LV-E    6-1502 */
    auto consumed = dissect_lv_e(nullptr, &cmn::eap_msg, d, ctx);
    d.step(consumed);

    /*7B    Extended protocol configuration options 9.11.4.6    O    TLV - E    4 - 65538*/
    consumed = dissect_opt_tlv_e(nullptr, &ext_pco, d, ctx);
    d.step(consumed);  

    return uc.length;
}