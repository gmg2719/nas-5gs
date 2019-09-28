#include "../common/dissect_mm_msg.hh"
#include "../common/use_context.hh"

// no body
int mm::dissect_deregistration_accept_ue_origin(dissector d, context* ctx) {
    const use_context uc(ctx, "deregistration-accept-ue-origin", d, -1);
    // network to UE
    down_link(d.packet);

    return 0;
}

struct deregistration_accept_ue_origin_t {};
