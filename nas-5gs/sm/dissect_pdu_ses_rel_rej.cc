#include "../dissect_nas5g.hh"
#include "../dissect_sm_msg.hh"
#include "../ts24007.hh"

/*
 * 8.3.13 PDU session release reject
 */
int sm::dissect_pdu_ses_rel_rej(dissector d, context* ctx) {    
    const use_context uc(ctx, "pdu-session-release-reject", d, 0);

    /* Direction: network to UE */
    down_link(d.pinfo);    

    /* 5GSM cause 9.11.4.2    M    V    1 */
    auto consumed = dissect_elem_v(nullptr, &sm_cause, d, ctx);
    d.step(consumed);

    /* 7B    Extended protocol configuration options   9.11.4.6    O    TLV - E    4 - 65538*/
    consumed = dissect_opt_elem_tlv_e(nullptr, &ext_pco, d, ctx);
    d.step(consumed);

    return uc.length;
}