#include "../dissect_mm_msg.hh"

using namespace cmn;
using namespace nas;
using namespace mm;

//  9.11.3.46    Rejected NSSAI
extern const element_meta mm::rejected_nssai = {
    0x11,
    "Rejected NSSAI",
    dissect_rejected_nssai,
    nullptr,
};


/* *   9.11.3.46    Rejected NSSAI page.389 */
int mm::dissect_rejected_nssai(dissector d, context* ctx) {
    const use_context uc(ctx, "rejected-nssai", d, 0);

    NASNR_AUTO(int) i = 1;
    while (d.length > 0) {
        NASNR_AUTO(proto_node*) const subtree = d.add_item(2, "Rejected S-NSSAI %u", i++);
        use_tree   ut(d, subtree);

        const NASNR_AUTO(int) len = int(d.uint8() >> 4u);
        NASNR_AUTO(proto_node*)       n   = d.add_item(1, &hf_rej_nssai_cause, enc::be);
        d.step(1);

        n = d.add_item(1, &hf_sst, enc::be);
        d.step(1);
        if (len == 1) continue; // len == 1 || len == 4

        n = d.add_item(3, &hf_sd, enc::be);

        unused(n);
        d.step(3);
    }
    return uc.length;
}

static const val_string ref_nssai_cause_values[] = {
    {0, "S-NSSAI not available in the current PLMN"},
    {1,
     "S-NSSAI not available in the current registration area All other values are "
     "reserved."},
    {0, nullptr},
};

const field_meta mm::hf_rej_nssai_cause = {
    "Cause",
    "nas.nr.mm.cause",
    ft::ft_uint8,
    fd::base_dec,
    ref_nssai_cause_values,
    nullptr,
    nullptr,
    0x0f,
};
