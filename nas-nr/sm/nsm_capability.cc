#include "../common/dissector.hh"
#include "../common/use_context.hh"

/*  9.11.4.1    5GSM capability */
int dissect_nrsm_capability(dissector d, context* ctx) {
    const use_context uc(&d, ctx, "5gsm-capability", -1);


    return 1;
}