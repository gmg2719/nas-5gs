#pragma once
#include "core.hh"
#include "field_meta.hh"

// protocol dissect entry
int dissect_nas_5gs(dissector d, context* ctx = nullptr);

// dissect_msg_fnc_t
int dissect_sm_msg(dissector d, context* ctx = nullptr);
int dissect_mm_msg(dissector d, context* ctx = nullptr);

int dissect_nas_5gs_plain(dissector d, context* ctx = nullptr);

inline const message_meta* find_dissector(uint8_t iei, const message_meta* meta) {
    while (meta->type) {
        if (meta->type == iei) return meta;
        meta++;
    }
    return nullptr;
}

namespace nas {
extern const field_meta* hf_msg_elem;
extern const field_meta* hf_spare_half_octet;
extern const field_meta* hf_epd;
extern const field_meta* hf_pdu_session_id;
extern const field_meta* hf_mm_msg_type;
extern const field_meta* hf_sm_msg_type;
extern const field_meta* hf_sec_header_type;

int dissect_eap_msg(dissector d, context* ctx);

// as specified in IETF RFC 3748
__declspec(selectany) extern const element_meta eap_msg = {
    0x78,
    "EAP message",
    dissect_eap_msg,
};

__declspec(selectany) extern const field_meta hf_sal_num_e = {
    "Number of elements",
    "nas_5gs.mm.sal_num_e",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x1f,
};

extern const field_meta* hf_msg_auth_code;
extern const field_meta* hf_mm_follow_on_req;
extern const field_meta  hf_sms_requested;
extern const field_meta  hf_5gs_reg_type;
extern const field_meta  hf_tsc;
extern const field_meta  hf_tsc_h1;
extern const field_meta  hf_nas_key_set_id_h1;
extern const field_meta  hf_5gmm_cause;
extern const field_meta  hf_nas_5gs_mm_sst;
extern const field_meta  hf_nas_key_set_id;
extern const field_meta  hf_follow_on_req;
extern const field_meta  hf_mm_sal_t_li;
extern const field_meta  hf_nas_5gs_mm_sal_al_t;
extern const field_meta  hf_nas_5gs_mm_s1_mode_reg_b0;
extern const field_meta  hf_nas_5gs_mm_n1_mode_reg_b1;
extern const field_meta  hf_sst;

__declspec(selectany) extern const field_meta hf_sd = {
    "Slice differentiator (SD)",
    "nas_5gs.mm.mm_sd",
    ft::ft_uint24,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x0,
};

__declspec(selectany) extern const field_meta hf_mapped_conf_sst = {
    "Mapped configured SST",
    "nas_5gs.mm.mapped_conf_sst",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x0,
};

__declspec(selectany) extern const field_meta hf_mapped_conf_ssd = {
    "Mapped configured SD",
    "nas_5gs.mm.mapped_conf_ssd",
    ft::ft_uint24,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x0,
};

__declspec(selectany) extern const field_meta hf_dnn = {
    "DNN",
    "nas_5gs.cmn.dnn",
    ft::ft_bytes,
    fd::base_none,
    nullptr,
    nullptr,
    nullptr,
    0x0,
};
int dissect_dnn(dissector d, context* ctx);
int dissect_s_nssai(dissector d, context* ctx);

__declspec(selectany) extern const field_meta hf_spare_b7 = {
    "Spare",
    "nas_5gs.spare_b7",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x80,
};
__declspec(selectany) extern const field_meta hf_spare_b6 = {
    "Spare",
    "nas_5gs.spare_b6",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x40,
};
__declspec(selectany) extern const field_meta hf_spare_b5 = {
    "Spare",
    "nas_5gs.spare_b5",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x20,
};
__declspec(selectany) extern const field_meta hf_spare_b4 = {
    "Spare",
    "nas_5gs.spare_b4",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x10,
};
__declspec(selectany) extern const field_meta hf_spare_b3 = {
    "Spare",
    "nas_5gs.spare_b3",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x08,
};
__declspec(selectany) extern const field_meta hf_spare_b2 = {
    "Spare",
    "nas_5gs.spare_b2",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x04,
};
__declspec(selectany) extern const field_meta hf_spare_b1 = {
    "Spare",
    "nas_5gs.spare_b1",
    ft::ft_uint8,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x02,
};

__declspec(selectany) extern const true_false_string tfs_allowed_not_allowed = {
    "Allowed",
    "Not Allowed",
};
} // namespace nas
