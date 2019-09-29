#include "../common/dissect_mm_msg.hh"
#include "../common/use_context.hh"

using namespace cmn;
using namespace nas;
using namespace mm;

const bool_field hfm_mm_raai_b0 = {
    "Registration Area Allocation Indication (RAAI)",
    0x01,
    "all PLMN registration area not allocated",
    "all PLMN registration area allocated",
};

// In the network to UE and the UE to network direction:
const bool_field hf_mm_sprti = {
    "Strictly Periodic Registration Timer Indication (SPRTI)",
    0x02,
    "strictly periodic registration timer not supported",
    "strictly periodic registration timer supported",
};


/*  9.11.3.31    MICO indication */
int mm::dissect_mico_ind(dissector d, context* ctx) {
    const use_context uc(ctx, "mico-indication", d, -1);

    auto i = d.add_item( &hfm_mm_raai_b0);

    // In the UE to network direction bit 1 is spare. The UE shall set this bit to
    // zero. In the network to UE and the UE to network direction:
    (void) d.add_item( &hf_mm_sprti);

    return 1;
}


