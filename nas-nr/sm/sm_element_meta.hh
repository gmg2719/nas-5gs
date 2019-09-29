#pragma once
#include "../common/core.hh"
#include "sm_dissects.hh"

namespace sm {
extern const element_meta nrsm_cause;
extern const element_meta extended_pco;
extern const element_meta authorized_qos_rules;
extern const element_meta mapped_eps_bearer_context;
extern const element_meta backoff_gprs_timer3;
extern const element_meta nrsm_capability;
extern const element_meta max_supported_packet_filters;
extern const element_meta session_ambr;
extern const element_meta rq_gprs_timer;
extern const element_meta alwayson_pdu_session_indication;
extern const element_meta allowed_ssc_mode;
extern const element_meta congestion_reattempt;
extern const element_meta alwayson_pdu_session_requested;
extern const element_meta pdu_session_type;
extern const element_meta selected_pdu_session_type;
extern const element_meta pdu_address;
extern const element_meta integrity_protection_max_data_rate;
extern const element_meta ssc_mode;
extern const element_meta sm_pdu_dn_request_container;
extern const element_meta requested_qos_rules;
extern const element_meta authorized_qos_flow_desc; // Authorized QoS flow descriptions QoS
extern const element_meta requested_qos_flow_desc;  // Requested QoS flow descriptions QoS
extern const element_meta control_plane_only_indication;

// SM PDU DN request container 9.11.4.15
inline const element_meta sm_pdu_dn_request_container = {
    0x39u,
    "PDU DN request container",
    dissect_pdu_dn_request_container,
};

// Session-AMBR 9.11.4.14
const element_meta sm::session_ambr = {
    0x2A,
    "Session AMBR",
    sm::dissect_session_ambr,
};
}
