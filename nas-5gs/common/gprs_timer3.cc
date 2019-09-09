#include "../common.hh"

namespace{
/* * 3GPP TS 24.008 g10 10.5.7.4a */
static const value_string gsm_a_gm_gprs_timer3_unit_vals[] = {
    {0x00, "value is incremented in multiples of 10 minutes"},
    {0x01, "value is incremented in multiples of 1 hour"},
    {0x02, "value is incremented in multiples of 10 hours"},
    {0x03, "value is incremented in multiples of 2 seconds"},
    {0x04, "value is incremented in multiples of 30 seconds"},
    {0x05, "value is incremented in multiples of 1 minute"},
    {0x07, "value indicates that the timer is deactivated"},
    {0, nullptr},
};

const field_meta hf_gprs_timer3 = {
    "GPRS Timer 3",
    "gsm_a.gm.gmm.gprs_timer3",
    ft::ft_uint8,
    fd::timer3,
    nullptr,
    nullptr,
    nullptr,
    0x0,
};
} // namespace

/*  [10] 10.5.7.4a */
int cmn::dissect_gprs_timer3(dissector d, context *ctx) {
    use_context uc(ctx, "gprs-timer-3", d, -1);

    (void) d.tree->set_item(1, &hf_gprs_timer3, enc::be);
    d.step(1);

    return 1;
}
