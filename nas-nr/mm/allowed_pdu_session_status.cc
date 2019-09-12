#include "../dissect_mm_msg.hh"

using namespace cmn;
using namespace mm;

// Allowed PDU session status
const element_meta mm::allowed_pdu_ses_status = {
    0x25,
    "Allowed PDU session status",
    dissect_allowed_pdu_ses_status,
    nullptr,
};


/*  9.11.3.13    Allowed PDU session status */
int mm::dissect_allowed_pdu_ses_status(dissector d, context* ctx) {
    const use_context uc(ctx, "allowed-pdu-session-status", d, 30);

    static const field_meta* psi_0_7_flags[] = {
        &hf_allow_pdu_ses_sts_psi_7_b7,
        &hf_allow_pdu_ses_sts_psi_6_b6,
        &hf_allow_pdu_ses_sts_psi_5_b5,
        &hf_allow_pdu_ses_sts_psi_4_b4,
        &hf_allow_pdu_ses_sts_psi_3_b3,
        &hf_allow_pdu_ses_sts_psi_2_b2,
        &hf_allow_pdu_ses_sts_psi_1_b1,
        &hf_allow_pdu_ses_sts_psi_0_b0,
        nullptr,
    };

    static const field_meta* psi_8_15_flags[] = {
        &hf_allow_pdu_ses_sts_psi_15_b7,
        &hf_allow_pdu_ses_sts_psi_14_b6,
        &hf_allow_pdu_ses_sts_psi_13_b5,
        &hf_allow_pdu_ses_sts_psi_12_b4,
        &hf_allow_pdu_ses_sts_psi_11_b3,
        &hf_allow_pdu_ses_sts_psi_10_b2,
        &hf_allow_pdu_ses_sts_psi_9_b1,
        &hf_allow_pdu_ses_sts_psi_8_b0,
        nullptr,
    };

    d.add_bits(psi_0_7_flags);
    d.step(1);

    d.add_bits(psi_8_15_flags);
    d.step(1);

    // All bits in octet 5 to 34 are spare and shall be coded as zero, if the respective
    // octet is included in the information element.

    return uc.length;
}

/* 9.11.3.13    Allowed PDU session status */
const true_false_string tfs_nas_5gs_allow_pdu_ses_sts_psi = {
    "user-plane resources of corresponding PDU session "
    "can be re-established over 3GPP access",
    "user-plane resources of corresponding PDU session "
    "is not allowed to be re-established over 3GPP access",
};
const field_meta mm::hf_allow_pdu_ses_sts_psi_0_b0 = {
    "Spare",
    "nas.nr.allow_pdu_ses_sts_psi_0_b0",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x01,
};
const field_meta mm::hf_allow_pdu_ses_sts_psi_1_b1 = {
    "PSI(1)",
    "nas.nr.allow_pdu_ses_sts_psi_1_b1",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,
    &tfs_nas_5gs_allow_pdu_ses_sts_psi,
    nullptr,
    0x02,
};
const field_meta mm::hf_allow_pdu_ses_sts_psi_2_b2 = {
    "PSI(2)",
    "nas.nr.allow_pdu_ses_sts_psi_2_b2",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,
    &tfs_nas_5gs_allow_pdu_ses_sts_psi,
    nullptr,
    0x04,
};
const field_meta mm::hf_allow_pdu_ses_sts_psi_3_b3 = {
    "PSI(3)",
    "nas.nr.allow_pdu_ses_sts_psi_3_b3",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,
    &tfs_nas_5gs_allow_pdu_ses_sts_psi,
    nullptr,
    0x08,
};
const field_meta mm::hf_allow_pdu_ses_sts_psi_4_b4 = {
    "PSI(4)",
    "nas.nr.allow_pdu_ses_sts_psi_4_b4",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,
    &tfs_nas_5gs_allow_pdu_ses_sts_psi,
    nullptr,
    0x10,
};
const field_meta mm::hf_allow_pdu_ses_sts_psi_5_b5 = {
    "PSI(5)",
    "nas.nr.allow_pdu_ses_sts_psi_5_b5",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,
    &tfs_nas_5gs_allow_pdu_ses_sts_psi,
    nullptr,
    0x20,
};
const field_meta mm::hf_allow_pdu_ses_sts_psi_6_b6 = {
    "PSI(6)",
    "nas.nr.allow_pdu_ses_sts_psi_6_b6",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,
    &tfs_nas_5gs_allow_pdu_ses_sts_psi,
    nullptr,
    0x40,
};
const field_meta mm::hf_allow_pdu_ses_sts_psi_7_b7 = {
    "PSI(7)",
    "nas.nr.allow_pdu_ses_sts_psi_7_b7",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,
    &tfs_nas_5gs_allow_pdu_ses_sts_psi,
    nullptr,
    0x80,
};
const field_meta mm::hf_allow_pdu_ses_sts_psi_8_b0 = {
    "PSI(8)",
    "nas.nr.allow_pdu_ses_sts_psi_8_b0",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,
    &tfs_nas_5gs_allow_pdu_ses_sts_psi,
    nullptr,
    0x01,
};
const field_meta mm::hf_allow_pdu_ses_sts_psi_9_b1 = {
    "PSI(9)",
    "nas.nr.allow_pdu_ses_sts_psi_9_b1",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,
    &tfs_nas_5gs_allow_pdu_ses_sts_psi,
    nullptr,
    0x02,
};
const field_meta mm::hf_allow_pdu_ses_sts_psi_10_b2 = {
    "PSI(10)",
    "nas.nr.allow_pdu_ses_sts_psi_10_b2",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,
    &tfs_nas_5gs_allow_pdu_ses_sts_psi,
    nullptr,
    0x04,
};
const field_meta mm::hf_allow_pdu_ses_sts_psi_11_b3 = {
    "PSI(11)",
    "nas.nr.allow_pdu_ses_sts_psi_11_b3",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,
    &tfs_nas_5gs_allow_pdu_ses_sts_psi,
    nullptr,
    0x08,
};
const field_meta mm::hf_allow_pdu_ses_sts_psi_12_b4 = {
    "PSI(12)",
    "nas.nr.allow_pdu_ses_sts_psi_12_b4",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,
    &tfs_nas_5gs_allow_pdu_ses_sts_psi,
    nullptr,
    0x10,
};
const field_meta mm::hf_allow_pdu_ses_sts_psi_13_b5 = {
    "PSI(13)",
    "nas.nr.allow_pdu_ses_sts_psi_13_b5",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,
    &tfs_nas_5gs_allow_pdu_ses_sts_psi,
    nullptr,
    0x20,
};
const field_meta mm::hf_allow_pdu_ses_sts_psi_14_b6 = {
    "PSI(14)",
    "nas.nr.allow_pdu_ses_sts_psi_14_b6",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,
    &tfs_nas_5gs_allow_pdu_ses_sts_psi,
    nullptr,
    0x40,
};
const field_meta mm::hf_allow_pdu_ses_sts_psi_15_b7 = {
    "PSI(15)",
    "nas.nr.allow_pdu_ses_sts_psi_15_b7",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,
    &tfs_nas_5gs_allow_pdu_ses_sts_psi,
    nullptr,
    0x80,
};