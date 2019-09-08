#include "../dissect_mm_msg.hh"


using namespace nas;

/* 9.11.3.18    Configuration update indication */
int mm::dissect_config_update_ind(dissector d, context* ctx) {
    static const field_meta* flags[] = {
        &hf_spare_b3,
        &hf_spare_b2,
        &hf_conf_upd_ind_red_b1,
        &hf_conf_upd_ind_ack_b0,
        nullptr,
    };
    d.add_bits(flags);

    return 1;
}
extern const element_meta mm::conf_upd_ind = {
    0xD0,
    "Configuration update indication",
    dissect_config_update_ind,
    nullptr,
};
