#include "../dissect_mm_msg.hh"
#include "../ts24007.hh"

namespace mm_dl_nas_transp {
extern const element_meta pld_cont_type;
extern const element_meta pld_cont;
extern const element_meta pdu_ses_id;
extern const element_meta add_inf;
extern const element_meta backoff_gprs_timer3;
} // namespace mm_dl_nas_transp

using namespace nas;
using namespace mm;

/*
 * 8.2.11 DL NAS transport
 */
int mm::dl_nas_transp(dissector d, context* ctx) {
    use_context uc(ctx, "dl-nas-transport");

    using namespace mm_dl_nas_transp;

    /* Initalize the private struct */
    // nas5gs_get_private_data(pinfo);

    /*Payload container type    Payload container type     9.11.3.40    M    V    1/2 H0*/
    /*Spare half octet    Spare half octet    9.5    M    V    1/2 H1*/
    d.tree->add_item(d.pinfo, d.tvb, d.offset, 1, hf_spare_half_octet, enc::be);

    // ELEM_MAND_V(DE_NAS_5GS_MM_PLD_CONT_TYPE,ei_nas_5gs_missing_mandatory_elemen);
    auto consumed = dissect_elem_v(nullptr, &pld_cont_type, d, ctx);
    d.offset += consumed;
    d.length -= consumed;

    /*Payload container    Payload container    9.11.3.39    M    LV-E    3-65537*/
    // ELEM_MAND_LV_E(DE_NAS_5GS_MM_PLD_CONT,ei_nas_5gs_missing_mandatory_elemen);
    consumed = dissect_elem_lv_e(nullptr, &pld_cont, d, ctx);
    d.offset += consumed;
    d.length -= consumed;

    /*12    PDU session ID    PDU session identity 2 9.11.3.37    C    TV    2 */
    // ELEM_OPT_TV( 0x12, , DE_NAS_5GS_MM_PDU_SES_ID_2, " - PDU session ID");
    consumed = dissect_opt_elem_tv(nullptr, &pdu_ses_id, d, ctx);
    d.offset += consumed;
    d.length -= consumed;

    /*24    Additional information    Additional information    9.10.2.1    O    TLV 3-n*/
    // ELEM_OPT_TLV(0x24, , DE_NAS_5GS_CMN_ADD_INF, NULL);
    consumed = dissect_opt_elem_tlv(nullptr, &add_inf, d, ctx);
    d.offset += consumed;
    d.length -= consumed;

    /*58    5GMM cause    5GMM cause 9.11.3.2    O    TV    2 */
    // ELEM_OPT_TV(0x58, NAS_5GS_PDU_TYPE_MM, DE_NAS_5GS_MM_5GMM_CAUSE, NULL);
    consumed = dissect_opt_elem_tv(nullptr, &mm_cause, d, ctx);
    d.offset += consumed;
    d.length -= consumed;

    /*37    Back-off timer value    GPRS timer 3 9.10.2.5    O    TLV    3 */
    // ELEM_OPT_TLV(0x37, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - Back-off timer value");
    consumed = dissect_opt_elem_tlv(nullptr, &backoff_gprs_timer3, d, ctx);
    d.offset += consumed;
    d.length -= consumed;

    d.extraneous_data_check(0);
    return d.tvb->length;
}

namespace mm_dl_nas_transp {
int dissect_pdu_ses_id(dissector d, context* ctx);
int dissect_add_inf(dissector d, context* ctx);

extern const element_meta pld_cont_type = {
    0xff,
    "Payload container type",
    dissect_pld_cont_type,
};
extern const element_meta pld_cont = {
    0xff,
    "Payload container",
    dissect_pld_cont,
};
extern const element_meta pdu_ses_id = {
    0x12,
    "PDU session ID",
    dissect_pdu_ses_id,
};
extern const element_meta add_inf = {
    0x24,
    "Additional information",
    dissect_add_inf,
};

int dissect_backoff_gprs_timer3(dissector d, context* ctx);

extern const element_meta backoff_gprs_timer3 = {
    0x37,
    "GPRS timer - Back-off timer",
    dissect_backoff_gprs_timer3,
};



/*
 *   9.11.3.41    PDU session identity 2
 */
int dissect_pdu_ses_id(dissector d, context* ctx) {
    d.add_item(1, hf_pdu_session_id, enc::be);
    return 1;
}

/* 9.10.2.1    Additional information*/
int dissect_add_inf(dissector d, context* ctx) {
    bug("no dissect for %s\n", "additional-information");
    return d.length;
}

int dissect_backoff_gprs_timer3(dissector d, context* ctx) {
    // no dissect
    return d.length;
}
} // namespace mm_dl_nas_transp