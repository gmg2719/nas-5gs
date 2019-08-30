#include "../dissect_mm_msg.hh"
#include "../ts24007.hh"

namespace mm_service_req {
extern const field_meta*  hf_service_type;
extern const element_meta key_set_id;
extern const element_meta s_tmsi;
extern const element_meta uplink_data_status;
extern const element_meta allowed_pdu_ses_status;
} // namespace mm_service_req

using namespace nas;
using namespace mm;

/*
 * 8.2.16 Service request
 */
int mm::service_req(dissector d, context* ctx) {
    use_context uc(ctx, "service-request");

    using namespace mm_service_req;

    /* Service type    Service type 9.11.3.46    M    V    1/2 */
    // proto_tree_add_item(
    //    tree, hf_nas_5gs_mm_serv_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
    d.tree->add_item(d.pinfo, d.tvb, d.offset, 1, hf_service_type, enc::be);

    /*  ELEM_MAND_V(,DE_NAS_5GS_MM_NAS_KEY_SET_ID," - ngKSI", );*/
    /* ngKSI     NAS key set identifier 9.11.3.29    M    V    1/2 */
    auto consumed = dissect_elem_v(nullptr, &key_set_id, d, ctx);
    d.offset += consumed;
    d.length -= consumed;

    /* 5G-S-TMSI    5GS mobile identity 9.11.3.4    M    LV    6 */
    /*ELEM_MAND_LV_E(,DE_NAS_5GS_MM_5GS_MOBILE_ID, );*/
    consumed = dissect_elem_lv_e(nullptr, &s_tmsi, d, ctx);
    d.offset += consumed;
    d.length -= consumed;

    /*40    Uplink data status    Uplink data status         9.11.3.53    O    TLV    4 -
     * 34*/
    // ELEM_OPT_TLV(0x40, , DE_NAS_5GS_MM_UL_DATA_STATUS, NULL);
    consumed = dissect_opt_elem_tlv(nullptr, &uplink_data_status, d, ctx);
    d.offset += consumed;
    d.length -= consumed;

    /*50    PDU session status    PDU session status         9.11.3.40    O    TLV    4 -
     * 34*/
    // ELEM_OPT_TLV(0x50, , DE_NAS_5GS_MM_PDU_SES_STATUS, NULL);
    consumed = dissect_opt_elem_tlv(nullptr, &pdu_ses_status, d, ctx);
    d.offset += consumed;
    d.length -= consumed;

    /*25    Allowed PDU session status    Allowed PDU session status         9.11.3.11
     * O    TLV    4 - 34*/
    // ELEM_OPT_TLV(0x25, , DE_NAS_5GS_MM_ALLOW_PDU_SES_STS, NULL);
    consumed = dissect_opt_elem_tlv(nullptr, &allowed_pdu_ses_status, d, ctx);
    d.offset += consumed;
    d.length -= consumed;

    /* 71    NAS message container    NAS message container 9.11.3.33    O    TLV-E    4-n
     */
    // ELEM_OPT_TLV_E(0x71, NAS_5GS_PDU_TYPE_MM, DE_NAS_5GS_MM_NAS_MSG_CONT, NULL);
    consumed = dissect_opt_elem_tlv_e(nullptr, &nas_msg_cont, d, ctx);
    d.offset += consumed;
    d.length -= consumed;

    d.extraneous_data_check(0);

    return d.tvb->length;
}
namespace mm_service_req {
/*
 *     9.11.3.50    Service type
 */

/* Used inline as H1 (Upper nibble)*/
const val_string nas_5gs_mm_serv_type_vals[] = {
    {0x00, "Signalling"},
    {0x01, "Data"},
    {0x02, "Mobile terminated services"},
    {0x03, "Emergency services"},
    {0x04, "Emergency services fallback"},
    {0x05, "High priority access"},
    {0, nullptr},
};

extern const field_meta hfm_service_type = {
    "Service type",
    "nas_5gs.mm.serv_type",
    ft::ft_uint8,
    fd::base_dec,
    nas_5gs_mm_serv_type_vals,
    nullptr,
    nullptr,
    0x70,
};
const field_meta* hf_service_type = &hfm_service_type;

int                dissect_key_set_id(dissector d, context* ctx);
const element_meta key_set_id = {
    0xff,
    "NAS key set identifier - ngKSI",
    dissect_key_set_id,
};

int                dissect_s_tmsi(dissector d, context* ctx);
const element_meta s_tmsi = {
    0xff,
    "5G-S-TMSI",
    dissect_s_tmsi,
};

int                dissect_uplink_data_status(dissector d, context* ctx);
const element_meta uplink_data_status = {
    0x40,
    "Uplink data status",
    dissect_uplink_data_status,
};

int dissect_allowed_pdu_ses_status(dissector d, context* ctx);

const element_meta allowed_pdu_ses_status = {
    0x25,
    "Allowed PDU session status",
    dissect_allowed_pdu_ses_status,
};

// *   9.11.3.32    NAS key set identifier
int dissect_key_set_id(dissector d, context* ctx) {
    static const field_meta* flags[] = {
        &hf_tsc,
        &hf_nas_key_set_id,
        nullptr,
    };
    /* NAS key set identifier IEI   TSC     NAS key set identifier */
    d.add_bits(flags);
    return 1;
}

int dissect_s_tmsi(dissector d, context* ctx) { return dissect_mobile_id(d, ctx); }

/*
 * 9.11.3.57    Uplink data status
 */

const true_false_string tfs_nas_5gs_ul_data_sts_psi = {
    "uplink data are pending",
    "no uplink data are pending",
};
const field_meta hf_ul_data_sts_psi_7_b7 = {
    "PSI(7)",
    "nas_5gs.ul_data_sts_psi_7_b7",
    ft::ft_boolean,
    fd::base_dec
    ,nullptr,&tfs_nas_5gs_ul_data_sts_psi,nullptr,
    0x80,
};
const field_meta hf_ul_data_sts_psi_6_b6 = {
    "PSI(6)",
    "nas_5gs.ul_data_sts_psi_6_b6",
    ft::ft_boolean,
    fd::base_dec
    ,nullptr,&tfs_nas_5gs_ul_data_sts_psi,nullptr,
    0x40,
};
const field_meta hf_ul_data_sts_psi_5_b5 = {
    "PSI(5)",
    "nas_5gs.ul_data_sts_psi_5_b5",
    ft::ft_boolean,
    fd::base_dec
    ,nullptr,&tfs_nas_5gs_ul_data_sts_psi,nullptr,
    0x20,
};
const field_meta hf_ul_data_sts_psi_4_b4 = {
    "PSI(4)",
    "nas_5gs.ul_data_sts_psi_4_b4",
    ft::ft_boolean,
    fd::base_dec
    ,nullptr,&tfs_nas_5gs_ul_data_sts_psi,nullptr,
    0x10,
};
const field_meta hf_ul_data_sts_psi_3_b3 = {
    "PSI(3)",
    "nas_5gs.ul_data_sts_psi_3_b3",
    ft::ft_boolean,
    fd::base_dec
    ,nullptr,&tfs_nas_5gs_ul_data_sts_psi,nullptr,
    0x08,
};
const field_meta hf_ul_data_sts_psi_2_b2 = {
    "PSI(2)",
    "nas_5gs.ul_data_sts_psi_2_b2",
    ft::ft_boolean,
    fd::base_dec
    ,nullptr,&tfs_nas_5gs_ul_data_sts_psi,nullptr,
    0x04,
};
const field_meta hf_ul_data_sts_psi_1_b1 = {
    "PSI(1)",
    "nas_5gs.ul_data_sts_psi_1_b1",
    ft::ft_boolean,
    fd::base_dec
    ,nullptr,&tfs_nas_5gs_ul_data_sts_psi,nullptr,
    0x02,
};
const field_meta hf_ul_data_sts_psi_0_b0 = {
    "Spare",
    "nas_5gs.ul_data_sts_psi_0_b0",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x01,
};

const field_meta hf_ul_data_sts_psi_15_b7 = {
    "PSI(15)",
    "nas_5gs.ul_data_sts_psi_15_b7",
    ft::ft_boolean,
    fd::base_dec
    ,nullptr,&tfs_nas_5gs_ul_data_sts_psi,nullptr,
    0x80,
};
const field_meta hf_ul_data_sts_psi_14_b6 = {
    "PSI(14)",
    "nas_5gs.ul_data_sts_psi_14_b6",
    ft::ft_boolean,
    fd::base_dec
    ,nullptr,&tfs_nas_5gs_ul_data_sts_psi,nullptr,
    0x40,
};
const field_meta hf_ul_data_sts_psi_13_b5 = {
    "PSI(13)",
    "nas_5gs.ul_data_sts_psi_13_b5",
    ft::ft_boolean,
    fd::base_dec
    ,nullptr,&tfs_nas_5gs_ul_data_sts_psi,nullptr,
    0x20,
};
const field_meta hf_ul_data_sts_psi_12_b4 = {
    "PSI(12)",
    "nas_5gs.ul_data_sts_psi_12_b4",
    ft::ft_boolean,
    fd::base_dec
    ,nullptr,&tfs_nas_5gs_ul_data_sts_psi,nullptr,
    0x10,
};
const field_meta hf_ul_data_sts_psi_11_b3 = {
    "PSI(11)",
    "nas_5gs.ul_data_sts_psi_11_b3",
    ft::ft_boolean,
    fd::base_dec
    ,nullptr,&tfs_nas_5gs_ul_data_sts_psi,nullptr,
    0x08,
};
const field_meta hf_ul_data_sts_psi_10_b2 = {
    "PSI(10)",
    "nas_5gs.ul_data_sts_psi_10_b2",
    ft::ft_boolean,
    fd::base_dec
    ,nullptr,&tfs_nas_5gs_ul_data_sts_psi,nullptr,
    0x04,
};
const field_meta hf_ul_data_sts_psi_9_b1  = {
    "PSI(9)",
    "nas_5gs.ul_data_sts_psi_9_b1",
    ft::ft_boolean,
    fd::base_dec
    ,nullptr,&tfs_nas_5gs_ul_data_sts_psi,nullptr,
    0x02,
};
const field_meta hf_ul_data_sts_psi_8_b0  = {
    "PSI(8)",
    "nas_5gs.ul_data_sts_psi_8_b0",
    ft::ft_boolean,
    fd::base_dec
    ,nullptr,&tfs_nas_5gs_ul_data_sts_psi,nullptr,
    0x01,
};

//  * 9.11.3.57    Uplink data status
int dissect_uplink_data_status(dissector d, context* ctx) {
    auto offset = d.offset;

    static const field_meta* psi_0_7_flags[] = {
        &hf_ul_data_sts_psi_7_b7,
        &hf_ul_data_sts_psi_6_b6,
        &hf_ul_data_sts_psi_5_b5,
        &hf_ul_data_sts_psi_4_b4,
        &hf_ul_data_sts_psi_3_b3,
        &hf_ul_data_sts_psi_2_b2,
        &hf_ul_data_sts_psi_1_b1,
        &hf_ul_data_sts_psi_0_b0,
        nullptr,
    };

    static const field_meta* psi_8_15_flags[] = {
        &hf_ul_data_sts_psi_15_b7,
        &hf_ul_data_sts_psi_14_b6,
        &hf_ul_data_sts_psi_13_b5,
        &hf_ul_data_sts_psi_12_b4,
        &hf_ul_data_sts_psi_11_b3,
        &hf_ul_data_sts_psi_10_b2,
        &hf_ul_data_sts_psi_9_b1,
        &hf_ul_data_sts_psi_8_b0,
        nullptr,
    };

    d.add_bits(psi_0_7_flags);
    d.step(1);

    d.add_bits(psi_8_15_flags);
    d.step(1);

    d.extraneous_data_check(0);

    return 2;

}
/*
 *  9.11.3.13    Allowed PDU session status
 */
static true_false_string tfs_nas_5gs_allow_pdu_ses_sts_psi = {
    "user-plane resources of corresponding PDU session "
    "can be re-established over 3GPP access",
    "user-plane resources of corresponding PDU session "
    "is not allowed to be re-established over 3GPP access",
};
const field_meta hf_allow_pdu_ses_sts_psi_0_b0 = {
    "Spare",
    "nas_5gs.allow_pdu_ses_sts_psi_0_b0",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,
    nullptr,
    nullptr,
    0x01,
};
const field_meta hf_allow_pdu_ses_sts_psi_1_b1 = {
    "PSI(1)",
    "nas_5gs.allow_pdu_ses_sts_psi_1_b1",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,&tfs_nas_5gs_allow_pdu_ses_sts_psi,nullptr,
    0x02,
};
const field_meta hf_allow_pdu_ses_sts_psi_2_b2 = {
    "PSI(2)",
    "nas_5gs.allow_pdu_ses_sts_psi_2_b2",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,&tfs_nas_5gs_allow_pdu_ses_sts_psi,nullptr,
    0x04,
};
const field_meta hf_allow_pdu_ses_sts_psi_3_b3 = {
    "PSI(3)",
    "nas_5gs.allow_pdu_ses_sts_psi_3_b3",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,&tfs_nas_5gs_allow_pdu_ses_sts_psi,nullptr,
    0x08,
};
const field_meta hf_allow_pdu_ses_sts_psi_4_b4 = {
    "PSI(4)",
    "nas_5gs.allow_pdu_ses_sts_psi_4_b4",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,&tfs_nas_5gs_allow_pdu_ses_sts_psi,nullptr,
    0x10,
};
const field_meta hf_allow_pdu_ses_sts_psi_5_b5 = {
    "PSI(5)",
    "nas_5gs.allow_pdu_ses_sts_psi_5_b5",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,&tfs_nas_5gs_allow_pdu_ses_sts_psi,nullptr,
    0x20,
};
const field_meta hf_allow_pdu_ses_sts_psi_6_b6 = {
    "PSI(6)",
    "nas_5gs.allow_pdu_ses_sts_psi_6_b6",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,&tfs_nas_5gs_allow_pdu_ses_sts_psi,nullptr,
    0x40,
};
const field_meta hf_allow_pdu_ses_sts_psi_7_b7 = {
    "PSI(7)",
    "nas_5gs.allow_pdu_ses_sts_psi_7_b7",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,&tfs_nas_5gs_allow_pdu_ses_sts_psi,nullptr,
    0x80,
};
const field_meta hf_allow_pdu_ses_sts_psi_8_b0 = {
    "PSI(8)",
    "nas_5gs.allow_pdu_ses_sts_psi_8_b0",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,&tfs_nas_5gs_allow_pdu_ses_sts_psi,nullptr,
    0x01,
};
const field_meta hf_allow_pdu_ses_sts_psi_9_b1 = {
    "PSI(9)",
    "nas_5gs.allow_pdu_ses_sts_psi_9_b1",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,&tfs_nas_5gs_allow_pdu_ses_sts_psi,nullptr,
    0x02,
};
const field_meta hf_allow_pdu_ses_sts_psi_10_b2 = {
    "PSI(10)",
    "nas_5gs.allow_pdu_ses_sts_psi_10_b2",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,&tfs_nas_5gs_allow_pdu_ses_sts_psi,nullptr,
    0x04,
};
const field_meta hf_allow_pdu_ses_sts_psi_11_b3 = {
    "PSI(11)",
    "nas_5gs.allow_pdu_ses_sts_psi_11_b3",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,&tfs_nas_5gs_allow_pdu_ses_sts_psi,nullptr,
    0x08,
};
const field_meta hf_allow_pdu_ses_sts_psi_12_b4 = {
    "PSI(12)",
    "nas_5gs.allow_pdu_ses_sts_psi_12_b4",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,&tfs_nas_5gs_allow_pdu_ses_sts_psi,nullptr,
    0x10,
};
const field_meta hf_allow_pdu_ses_sts_psi_13_b5 = {
    "PSI(13)",
    "nas_5gs.allow_pdu_ses_sts_psi_13_b5",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,&tfs_nas_5gs_allow_pdu_ses_sts_psi,nullptr,
    0x20,
};
const field_meta hf_allow_pdu_ses_sts_psi_14_b6 = {
    "PSI(14)",
    "nas_5gs.allow_pdu_ses_sts_psi_14_b6",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,&tfs_nas_5gs_allow_pdu_ses_sts_psi,nullptr,
    0x40,
};
const field_meta hf_allow_pdu_ses_sts_psi_15_b7 = {
    "PSI(15)",
    "nas_5gs.allow_pdu_ses_sts_psi_15_b7",
    ft::ft_boolean,
    fd::base_dec,
    nullptr,&tfs_nas_5gs_allow_pdu_ses_sts_psi,nullptr,
    0x80,
};

/*
 *  9.11.3.13    Allowed PDU session status
 */


int dissect_allowed_pdu_ses_status(dissector d, context* ctx) {

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

    d.extraneous_data_check(0);
    return 2;
}

} // namespace mm_service_req