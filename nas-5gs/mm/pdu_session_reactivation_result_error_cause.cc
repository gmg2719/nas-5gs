#include "../dissect_mm_msg.hh"

extern const element_meta mm::pdu_ses_react_res_error_c = {
    0x72,
    "PDU session reactivation result error cause",
    dissect_pdu_ses_react_res_err_c,
    nullptr,
};

//  *   9.11.3.43    PDU session reactivation result error cause
int mm::dissect_pdu_ses_react_res_err_c(dissector d, context* ctx) {
    const use_context uc(ctx, "pdu-session-reactivation-result-error", d, 0);
    
    /*Partial service area list*/
    while (d.length > 0) {
        d.add_item(1, &hf_pdu_session_id, enc::be);
        d.step(1);
        d.add_item(1, &hf_mm_cause, enc::be);
        d.step(1);
    }
    return uc.length;
}

