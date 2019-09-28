#include "../common/dissect_mm_msg.hh"
#include "../common/use_context.hh"

using namespace cmn;
using namespace nas;
using namespace mm;

// 9.11.3.32	NAS key set identifier
int mm::dissect_nas_ksi(dissector d, context* ctx) {
    use_context uc(ctx, "NAS key set identifier", d, -1);

    static const field_meta* flags[] = {
        &hf_security_context_type,
        &hf_eps_nas_ksi,
        nullptr,
    };

    /* NAS key set identifier IEI   TSC     NAS key set identifier */
    d.add_bits(flags);
    d.step(1);

    return 1;
}

struct nas_ksi_t {
    uint8_t security_context_type;
    uint8_t nas_ksi;
};

/* NAS key set identifier (octet 1) Bits 3  2   1 */
extern const v_string mm::nas_ksi_values[] = {
    {0, "0"},
    {1, "1"},
    {2, "2"},
    {3, "3"},
    {4, "4"},
    {5, "5"},
    {6, "6"},
    {7, "No key is available"},
    {0, nullptr},
};

// only spare half octet
const field_meta mm::hf_nas_ksi = {
    "NAS key set identifier - ngKSI",
    "nas.nr.mm.ngksi",
    ft::ft_uint8,
    fd::base_dec,
    nas_ksi_values,
    nullptr,
    nullptr,
    0xF0,
};

// NAS key set identifier 9.11.3.32
extern const element_meta mm::nas_ksi = {
    0xff,
    "NAS key set identifier - ngKSI",
    dissect_nas_ksi,
    nullptr,
};
