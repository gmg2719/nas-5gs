#include "../dissect_mm_msg.hh"

/*  8.2.27 Security mode reject */
int mm::dissect_security_mode_reject(dissector d, context* ctx) {    
    use_context uc(ctx, "security-mode-reject", d, -1);
    // UE to network
    up_link(d.pinfo);

    /* 5GMM cause 9.11.3.2    M    V    1 */
    (void) dissect_mm_cause(d, ctx);
    d.step(1);

    return 1;
}