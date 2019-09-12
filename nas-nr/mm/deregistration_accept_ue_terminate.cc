#include "../dissect_mm_msg.hh"

// no body
int mm::dissect_deregistration_accept_ue_term(dissector d, context* ctx) {
    const use_context uc(ctx, "deregistration-accept-ue-terminated", d, -1);
    // UE to network
    up_link(d.pinfo);

    return 0;
}