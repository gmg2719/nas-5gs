#include "../dissect_mm_msg.hh"

namespace mm {

const val_string pdu_session_id_values[] = {
    {0x00, "No PDU session identity assigned"},
    {0x01, "Reserved"},
    {0x02, "Reserved"},
    {0x03, "Reserved"},
    {0x04, "Reserved"},
    {0x05, "PDU session identity value 5"},
    {0x06, "PDU session identity value 6"},
    {0x07, "PDU session identity value 7"},
    {0x08, "PDU session identity value 8"},
    {0x09, "PDU session identity value 9"},
    {0x0a, "PDU session identity value 10"},
    {0x0b, "PDU session identity value 11"},
    {0x0c, "PDU session identity value 12"},
    {0x0d, "PDU session identity value 13"},
    {0x0e, "PDU session identity value 14"},
    {0x0f, "PDU session identity value 15"},
    {0, nullptr},
};

const field_meta hf_pdu_session_id = {
    "PDU session identity",
    "nas_5gs.pdu_session_id",
    ft::ft_uint8,
    fd::base_dec,
    pdu_session_id_values,
    nullptr,
    nullptr,
    0x0,
};
}

// PDU session ID 2 9.11.3.41
int mm::dissect_pdu_ses_id(dissector d, context* ctx) {
    // identity value as defined in 3GPP TS 24.007 [11]
    d.add_item(1, &hf_pdu_session_id, enc::be);
    return 1;
}

// PDU session ID 2 9.11.3.41
extern const element_meta mm::pdu_ses_id = {
    0x12,
    "PDU session ID",
    dissect_pdu_ses_id,
    nullptr,
};


// PDU session identity 2 9.11.3.41
extern const element_meta mm::old_pdu_ses_id = {
    0x59,
    "Old PDU session ID",
    dissect_old_pdu_ses_id,
    nullptr,
};