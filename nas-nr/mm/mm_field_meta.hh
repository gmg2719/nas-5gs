#pragma once
#include "../core.hh"

namespace mm {
extern const field_meta  hf_service_gap_control;
extern const field_meta  hf_header_compression_for_ctrl_plane;
extern const field_meta  hf_n3data_5;
extern const field_meta  hf_control_plane;
extern const field_meta  hf_restrict_ec;
extern const field_meta  hf_restrict_ec_support;
extern const field_meta  hf_lpp_capability;
extern const field_meta  hf_handover_attach;
extern const field_meta  hf_s1_mode_b0;
extern const field_meta  hf_mm_cause;
extern const field_meta  hf_identity_type;
extern const field_meta  hf_odd_even_indication;
extern const field_meta  hf_mac_address;
extern const field_meta  hf_supi_format;
extern const field_meta  hf_suci_nai;
extern const field_meta  hf_imei;
extern const field_meta  hf_imeisv;
extern const field_meta  hf_routing_indication;
extern const field_meta  hf_protection_scheme_id;
extern const field_meta  hf_public_key_identifier;
extern const field_meta  hf_msin;
extern const field_meta  hf_mm_scheme_output;
extern const field_meta  hf_amf_region_id;
extern const field_meta  hf_amf_set_id;
extern const field_meta  hf_amf_pointer;
extern const field_meta  hf_5g_tmsi;
extern const field_meta  hf_mps_indicator;
extern const field_meta  hf_interworking_without_n26;
extern const field_meta  hf_emergency_service_fallback_indicator;
extern const field_meta  hf_emergency_service_support_indicator;
extern const field_meta  hf_ims_voice_over_ps_session_indicator;
extern const field_meta  hf_emergency_service_support_n3gpp;
extern const field_meta  hf_mcs_indicator;
extern const field_meta  hf_5gcp_ciot;
extern const field_meta  hf_nwfs_n3data_b4;
extern const field_meta  hf_header_compression_control_plane;
extern const field_meta  hf_nwfs_5gup_ciot_b6;
extern const field_meta  hf_reg_res_sms_allowed;
extern const field_meta  hf_registration_result;
extern const field_meta  hf_gsm_a_n3en_ind;
extern const field_meta  hf_mobile_country_code;
extern const field_meta  hf_mobile_network_code;
extern const field_meta  hf_emergency_number_info;
extern const field_meta  hf_emergency_number_length;
extern const field_meta  hf_mountain_rescue;
extern const field_meta  hf_marine_guard;
extern const field_meta  hf_fire_brigade;
extern const field_meta  hf_ambulance;
extern const field_meta  hf_police;
extern const field_meta  hf_emergency_bcd_num;
extern const field_meta  hf_ext_emergency_number_list_validity;
extern const field_meta  hf_ext_emerge_num_len;
extern const field_meta  hf_emerge_num;
extern const field_meta  hf_ext_emerge_sub_serv_field_len;
extern const field_meta  hf_sub_services_field;
extern const field_meta  hf_sor_hdr0_ack;
extern const field_meta  hf_sor_hdr0_list_type;
extern const field_meta  hf_sor_hdr0_list_ind;
extern const field_meta  hf_sor_hdr0_sor_data_type;
extern const field_meta  hf_access_tech_utran;
extern const field_meta  hf_access_tech_eutran;
extern const field_meta  hf_access_tech_eutran_wb;
extern const field_meta  hf_access_tech_eutran_nb;
extern const field_meta  hf_access_tech_o1_b3;
extern const field_meta  hf_access_tech_o2_b7;
extern const field_meta  hf_access_tech_o2_b6;
extern const field_meta  hf_access_tech_o2_b5;
extern const field_meta  hf_access_tech_o2_b4;
extern const field_meta  hf_access_tech_o2_b3;
extern const field_meta  hf_acces_tech_o2_b2;
extern const field_meta  hf_rfu_b2;
extern const field_meta  hf_rfu_b1;
extern const field_meta  hf_rfu_b0;
extern const field_meta  hf_sor_mac_iue;
extern const field_meta  hf_sor_mac_iausf;
extern const field_meta  hf_counter_sor;
extern const field_meta  hf_sor_sec_pkt;
extern const field_meta  hf_nssai_inc_mode;
extern const field_meta  hf_mm_precedence;
extern const field_meta  hf_mm_op_defined_acd_oct6;
extern const field_meta  hf_mm_op_defined_acd_criteria;
extern const field_meta  hf_registration_type;
extern const field_meta  hf_nas_ksi;
extern const field_meta  hf_gsm_result;
extern const field_meta  hf_dtap_rand;
extern const field_meta  hf_dtap_autn;
extern const field_meta  hf_dtap_autn_sqn;
extern const field_meta  hf_dtap_autn_amf;
extern const field_meta  hf_dtap_autn_mac;
extern const field_meta  hf_sres;
extern const field_meta  hf_conf_upd_ind_reg_b1;
extern const field_meta  hf_conf_upd_ind_ack_b0;
extern const field_meta  hf_sal_allowed_type;
extern const field_meta  hf_sal_list_type;
extern const field_meta  hf_dst_adjustment;
extern const field_meta  hf_extension;
extern const field_meta  hf_coding_scheme;
extern const field_meta  hf_add_ci;
extern const field_meta  hf_number_of_spare_bits;
extern const field_meta  hf_text_string;
extern const field_meta  hf_precedence;
extern const field_meta  hf_sms_over_nas_ind;
extern const field_meta  hf_switch_off;
extern const field_meta  hf_reregistration_request;
extern const field_meta  hf_access_type;
extern const field_meta  hf_drx_param;
extern const field_meta  hf_ea0;
extern const field_meta  hf_ea1;
extern const field_meta  hf_ea2;
extern const field_meta  hf_ea3;
extern const field_meta  hf_nas_eps_emm_eea0;
extern const field_meta  hf_nas_eps_emm_128eea1;
extern const field_meta  hf_nas_eps_emm_128eea2;
extern const field_meta  hf_nas_eps_emm_eea3;
extern const field_meta  hf_nas_eps_emm_eea4;
extern const field_meta  hf_nas_eps_emm_eea5;
extern const field_meta  hf_nas_eps_emm_eea6;
extern const field_meta  hf_nas_eps_emm_eea7;
extern const field_meta  hf_nas_eps_emm_eia0;
extern const field_meta  hf_nas_eps_emm_128eia1;
extern const field_meta  hf_nas_eps_emm_128eia2;
extern const field_meta  hf_nas_eps_emm_eia3;
extern const field_meta  hf_nas_eps_emm_eia4;
extern const field_meta  hf_nas_eps_emm_eia5;
extern const field_meta  hf_nas_eps_emm_eia6;
extern const field_meta  hf_nas_eps_emm_eia7;
extern const field_meta  hf_nas_eps_emm_uea0;
extern const field_meta  hf_nas_eps_emm_uea1;
extern const field_meta  hf_nas_eps_emm_uea2;
extern const field_meta  hf_nas_eps_emm_uea3;
extern const field_meta  hf_nas_eps_emm_uea4;
extern const field_meta  hf_nas_eps_emm_uea5;
extern const field_meta  hf_nas_eps_emm_uea6;
extern const field_meta  hf_nas_eps_emm_uea7;
extern const field_meta  hf_nas_eps_emm_ucs2_supp;
extern const field_meta  hf_nas_eps_emm_uia1;
extern const field_meta  hf_nas_eps_emm_uia2;
extern const field_meta  hf_nas_eps_emm_uia3;
extern const field_meta  hf_nas_eps_emm_uia4;
extern const field_meta  hf_nas_eps_emm_uia5;
extern const field_meta  hf_nas_eps_emm_uia6;
extern const field_meta  hf_nas_eps_emm_uia7;
extern const field_meta  hf_nas_eps_emm_prose_dd_cap;
extern const field_meta  hf_nas_eps_emm_prose_cap;
extern const field_meta  hf_nas_eps_emm_h245_ash_cap;
extern const field_meta  hf_access_class_control_csfb_cap;
extern const field_meta  hf_nas_eps_emm_lpp_cap;
extern const field_meta  hf_nas_eps_emm_lcs_cap;
extern const field_meta  hf_nas_eps_emm_1xsrvcc_cap;
extern const field_meta  hf_nas_eps_emm_nf_cap;
extern const field_meta  hf_nas_eps_emm_epco_cap;
extern const field_meta  hf_nas_eps_emm_hc_cp_ciot_cap;
extern const field_meta  hf_nas_eps_emm_er_wo_pdn_cap;
extern const field_meta  hf_nas_eps_emm_s1u_data_cap;
extern const field_meta  hf_nas_eps_emm_up_ciot_cap;
extern const field_meta  hf_nas_eps_emm_cp_ciot_cap;
extern const field_meta  hf_nas_eps_emm_prose_relay_cap;
extern const field_meta  hf_nas_eps_emm_prose_dc_cap;
extern const field_meta  hf_nas_eps_15_bearers_cap;
extern const field_meta  hf_nas_eps_sgc_cap;
extern const field_meta  hf_nas_eps_n1mode_cap;
extern const field_meta  hf_nas_eps_dcnr_cap;
extern const field_meta  hf_nas_eps_cp_backoff_cap;
extern const field_meta  hf_nas_eps_restrict_ec_cap;
extern const field_meta  hf_nas_eps_v2x_pc5_cap;
extern const field_meta  hf_nas_eps_multiple_drb_cap;
extern const field_meta  hf_nas_eps_spare_bits;
extern const field_meta  hf_ue_usage_setting;
extern const field_meta  hf_ng_ran_rcu;
extern const field_meta  hf_pnb_ciot;
extern const field_meta  hf_sec_algo_enc;
extern const field_meta  hf_sec_algo_ip;
extern const field_meta  hf_mm_128_5g_ea1;
extern const field_meta  hf_mm_128_5g_ea2;
extern const field_meta  hf_mm_128_5g_ea3;
extern const field_meta  hf_mm_5g_ea4;
extern const field_meta  hf_mm_5g_ea5;
extern const field_meta  hf_mm_5g_ea6;
extern const field_meta  hf_mm_5g_ea7;
extern const field_meta  hf_mm_5g_ia0;
extern const field_meta  hf_mm_128_5g_ia1;
extern const field_meta  hf_mm_128_5g_ia2;
extern const field_meta  hf_mm_128_5g_ia3;
extern const field_meta  hf_mm_5g_ia4;
extern const field_meta  hf_mm_5g_ia5;
extern const field_meta  hf_mm_5g_ia6;
extern const field_meta  hf_mm_5g_ia7;
extern const field_meta  hf_mm_eea0;
extern const field_meta  hf_mm_128eea1;
extern const field_meta  hf_mm_128eea2;
extern const field_meta  hf_mm_eea3;
extern const field_meta  hf_mm_eea4;
extern const field_meta  hf_mm_eea5;
extern const field_meta  hf_mm_eea6;
extern const field_meta  hf_mm_eea7;
extern const field_meta  hf_mm_eia0;
extern const field_meta  hf_mm_128eia1;
extern const field_meta  hf_mm_128eia2;
extern const field_meta  hf_mm_eia3;
extern const field_meta  hf_mm_eia4;
extern const field_meta  hf_mm_eia5;
extern const field_meta  hf_mm_eia6;
extern const field_meta  hf_mm_eia7;
extern const field_meta  hf_mm_rinmr;
extern const field_meta  hf_mm_hdp;
extern const field_meta  hf_emm_eea0;
extern const field_meta  hf_emm_128eea1;
extern const field_meta  hf_emm_128eea2;
extern const field_meta  hf_emm_eea3;
extern const field_meta  hf_emm_eea4;
extern const field_meta  hf_emm_eea5;
extern const field_meta  hf_emm_eea6;
extern const field_meta  hf_emm_eea7;
extern const field_meta  hf_emm_eia0;
extern const field_meta  hf_emm_128eia1;
extern const field_meta  hf_emm_128eia2;
extern const field_meta  hf_emm_eia3;
extern const field_meta  hf_emm_eia4;
extern const field_meta  hf_emm_eia5;
extern const field_meta  hf_emm_eia6;
extern const field_meta  hf_emm_eia7;
extern const field_meta  hf_emm_uea0;
extern const field_meta  hf_emm_uea1;
extern const field_meta  hf_emm_uea2;
extern const field_meta  hf_emm_uea3;
extern const field_meta  hf_emm_uea4;
extern const field_meta  hf_emm_uea5;
extern const field_meta  hf_emm_uea6;
extern const field_meta  hf_emm_uea7;
extern const field_meta  hf_emm_uia1;
extern const field_meta  hf_emm_uia2;
extern const field_meta  hf_emm_uia3;
extern const field_meta  hf_emm_uia4;
extern const field_meta  hf_emm_uia5;
extern const field_meta  hf_emm_uia6;
extern const field_meta  hf_emm_uia7;
extern const field_meta  hf_emm_gea1;
extern const field_meta  hf_emm_gea2;
extern const field_meta  hf_emm_gea3;
extern const field_meta  hf_emm_gea4;
extern const field_meta  hf_emm_gea5;
extern const field_meta  hf_emm_gea6;
extern const field_meta  hf_emm_gea7;
extern const field_meta  hf_ul_data_sts_psi_7_b7;
extern const field_meta  hf_ul_data_sts_psi_6_b6;
extern const field_meta  hf_ul_data_sts_psi_5_b5;
extern const field_meta  hf_ul_data_sts_psi_4_b4;
extern const field_meta  hf_ul_data_sts_psi_3_b3;
extern const field_meta  hf_ul_data_sts_psi_2_b2;
extern const field_meta  hf_ul_data_sts_psi_1_b1;
extern const field_meta  hf_ul_data_sts_psi_0_b0;
extern const field_meta  hf_ul_data_sts_psi_15_b7;
extern const field_meta  hf_ul_data_sts_psi_14_b6;
extern const field_meta  hf_ul_data_sts_psi_13_b5;
extern const field_meta  hf_ul_data_sts_psi_12_b4;
extern const field_meta  hf_ul_data_sts_psi_11_b3;
extern const field_meta  hf_ul_data_sts_psi_10_b2;
extern const field_meta  hf_ul_data_sts_psi_9_b1;
extern const field_meta  hf_ul_data_sts_psi_8_b0;
extern const field_meta  hf_allow_pdu_ses_sts_psi_0_b0;
extern const field_meta  hf_allow_pdu_ses_sts_psi_1_b1;
extern const field_meta  hf_allow_pdu_ses_sts_psi_2_b2;
extern const field_meta  hf_allow_pdu_ses_sts_psi_3_b3;
extern const field_meta  hf_allow_pdu_ses_sts_psi_4_b4;
extern const field_meta  hf_allow_pdu_ses_sts_psi_5_b5;
extern const field_meta  hf_allow_pdu_ses_sts_psi_6_b6;
extern const field_meta  hf_allow_pdu_ses_sts_psi_7_b7;
extern const field_meta  hf_allow_pdu_ses_sts_psi_8_b0;
extern const field_meta  hf_allow_pdu_ses_sts_psi_9_b1;
extern const field_meta  hf_allow_pdu_ses_sts_psi_10_b2;
extern const field_meta  hf_allow_pdu_ses_sts_psi_11_b3;
extern const field_meta  hf_allow_pdu_ses_sts_psi_12_b4;
extern const field_meta  hf_allow_pdu_ses_sts_psi_13_b5;
extern const field_meta  hf_allow_pdu_ses_sts_psi_14_b6;
extern const field_meta  hf_allow_pdu_ses_sts_psi_15_b7;
extern const field_meta  hf_request_type;
extern const field_meta  hf_pdu_session_id;
extern const field_meta  hf_service_type;
extern const field_meta hf_element;
extern const field_meta hf_sal_num_e;
extern const field_meta  hf_security_context_type;
extern const field_meta hf_sms_requested;
extern const field_meta  hf_slice_differentiator;
extern const field_meta hfm_mm_raai_b0;
extern const field_meta hf_mm_sprti;
extern const field_meta  hf_tac;
extern const field_meta  hf_tal_num_e;
extern const field_meta  hf_tal_t_li;
extern const field_meta* hf_mm_raai_b0;
extern const field_meta  hf_payload_container_type;
extern const field_meta  hf_follow_on_req;
extern const field_meta  hf_abba;
extern const field_meta  hfm_nas_eps_nas_ksi;
extern const field_meta  hf_slice_service_type;
extern const field_meta hf_psac;
extern const field_meta hf_access_cat_n;
extern const field_meta hf_criteria;
extern const field_meta hf_standardize_access_cat;
extern const field_meta  hf_reject_nssai_cause;
extern const field_meta hf_pld_cont_entry_nie;
extern const field_meta hf_pld_cont_entry_contents;
extern const field_meta hf_upu_data_type;
extern const field_meta hf_ack;
extern const field_meta hf_reregistration;
extern const field_meta hf_pld_optional_ie;
extern const field_meta hf_upu_mac_i;
} // namespace mm
