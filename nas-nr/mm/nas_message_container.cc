#include "../common/dissector.hh"
#include "../common/use_context.hh"


/* 9.11.3.33    NAS message container */
int dissect_nas_message_container(dissector d, context* ctx) {
    /* The purpose of the NAS message container IE is to
     * encapsulate a plain 5GS NAS message. */
    /* a NAS message without NAS security header */

    const use_context uc(ctx, "nas-msg-container", d, -1);

    dissect_nas5g(d, ctx);
    return uc.length;
}
