#pragma once
#include "../core.hh"

namespace mm {
extern const field_meta  hf_sgc_7;
extern const field_meta  hf_hccp_ciot_6;
extern const field_meta  hf_n3data_5;
extern const field_meta  hf_5gcp_ciot_4;
extern const field_meta  hf_restrict_ec_3;
extern const field_meta  hf_lpp_b2;
extern const field_meta  hf_ho_attach_b1;
extern const field_meta  hf_s1_mode_b0;
extern const field_meta* flags[];
extern const field_meta  hf_mm_cause;
extern const field_meta  hf_id_type;
extern const field_meta  hfm_mm_type_id;
extern const field_meta  hf_mm_odd_even;
extern const field_meta  hf_mm_type_id;
extern const field_meta* flags_odd_even_tid[];
extern const field_meta  hf_mac_address;
extern const field_meta  hf_nas_5gs_mm_supi_fmt;
extern const field_meta  hf_nas_5gs_mm_suci_nai;
extern const field_meta  hf_nas_5gs_mm_imei;
extern const field_meta* flags_supi_fmt_tid[];
extern const field_meta  hf_nas_5gs_mm_imeisv;
extern const field_meta  hf_nas_5gs_amf_set_id;
extern const field_meta  hf_nas_5gs_amf_pointer;
extern const field_meta  hf_mm_routing_ind;
extern const field_meta  hf_mm_prot_scheme_id;
extern const field_meta  hf_mm_pki;
extern const field_meta  hf_mm_supi_null_scheme;
extern const field_meta  hf_mm_scheme_output;
extern const field_meta  hf_amf_region_id;
extern const field_meta  hf_amf_set_id;
extern const field_meta  hf_amf_pointer;
extern const field_meta  hf_5g_tmsi;
extern const field_meta  hf_nw_feat_sup_mpsi_b7;
extern const field_meta  hf_nw_feat_sup_ims_iwk_n26_b6;
extern const field_meta  hf_nw_feat_sup_ims_emf_b5b4;
extern const field_meta  hf_nw_feat_sup_ims_emc_b3b2;
extern const field_meta  hf_nw_feat_sup_ims_vops_b1b0;
extern const field_meta  hf_nwfs_emcn3_b0;
extern const field_meta  hf_nwfs_mcsi_b1;
extern const field_meta  hf_nwfs_restrict_ec_b2;
extern const field_meta  hf_nwfs_5gcp_ciot_b3;
extern const field_meta  hf_nwfs_n3data_b4;
extern const field_meta  hf_nwfs_5ghc_cp_ciot_b5;
extern const field_meta  hf_nwfs_5gup_ciot_b6;
extern const field_meta  hf_nwfs_b7;
extern const field_meta* oct4[];
extern const field_meta* hf_reg_req_flags;
extern const field_meta  hf_mm_for;
extern const field_meta  hf_reg_res_sms_allowed;
extern const field_meta  hf_registration_result;
extern const field_meta  hf_gsm_a_n3en_ind;
extern const field_meta  hf_mobile_country_code;
extern const field_meta  hf_mobile_network_code;
extern const field_meta  hf_gsma_eni;
extern const field_meta  hf_gsma_eni_length;
extern const field_meta  hf_gsma_svc_cat_b4;
extern const field_meta  hf_gsma_svc_cat_b3;
extern const field_meta  hf_gsma_svc_cat_b2;
extern const field_meta  hf_gsma_svc_cat_b1;
extern const field_meta  hf_gsma_svc_cat_b0;
extern const field_meta  hf_gsma_emergency_bcd_num;
extern const field_meta  hf_ext_emerge_num_list_eenlv;
extern const field_meta  hf_ext_emerge_num_len;
extern const field_meta  hf_emerge_num;
extern const field_meta  hf_ext_emerge_sub_serv_field_len;
extern const field_meta  hf_emm_emerg_num_list_sub_svc_field;
extern const field_meta  hf_sor_hdr0_ack;
extern const field_meta  hf_sor_hdr0_list_type;
extern const field_meta  hf_sor_hdr0_list_ind;
extern const field_meta  hf_sor_hdr0_sor_data_type;
extern const field_meta  hf_acces_tech_o1_b7;
extern const field_meta  hf_acces_tech_o1_b6;
extern const field_meta  hf_acces_tech_o1_b5;
extern const field_meta  hf_acces_tech_o1_b4;
extern const field_meta  hf_acces_tech_o1_b3;
extern const field_meta  hf_acces_tech_o2_b7;
extern const field_meta  hf_acces_tech_o2_b6;
extern const field_meta  hf_acces_tech_o2_b5;
extern const field_meta  hf_acces_tech_o2_b4;
extern const field_meta  hf_acces_tech_o2_b3;
extern const field_meta  hf_acces_tech_o2_b2;
extern const field_meta  hf_rfu_b2;
extern const field_meta  hf_rfu_b1;
extern const field_meta  hf_rfu_b0;
extern const field_meta  hf_sor_mac_iue;
extern const field_meta  hf_sor_mac_iausf;
extern const field_meta  hf_counter_sor;
extern const field_meta  hf_sor_sec_pkt;
extern const field_meta* flags_dt0[];
extern const field_meta* flags_dt1[];
extern const field_meta* flags_acces_tech_1[];
extern const field_meta* flags_acces_tech_2[];
extern const field_meta  hf_nssai_inc_mode;
extern const field_meta  hf_mm_precedence;
extern const field_meta  hf_mm_op_defined_acd_oct6;
extern const field_meta  hf_mm_op_defined_acd_psac; // NOLINT
extern const field_meta  hf_mm_op_defined_acd_criteria;
extern const field_meta  hf_5gs_reg_type;
extern const field_meta  hf_ngksi_nas_ksi;
extern const field_meta  hf_gsma_dtap_res;
extern const field_meta  hf_dtap_rand;
extern const field_meta  hf_dtap_autn;
extern const field_meta  hf_dtap_autn_sqn;
extern const field_meta  hf_dtap_autn_amf;
extern const field_meta  hf_dtap_autn_mac;
extern const field_meta  hf_dtap_sres;
extern const field_meta  hf_conf_upd_ind_red_b1;
extern const field_meta  hf_conf_upd_ind_ack_b0;
extern const field_meta  hf_sal_al_t;
extern const field_meta  hf_sal_t_li;
extern const field_meta  hf_dst_adjustment;
extern const field_meta  hf_a_extension;
extern const field_meta  hf_coding_scheme;
extern const field_meta  hf_add_ci;
extern const field_meta  hf_number_of_spare_bits;
extern const field_meta  hf_text_string;
extern const field_meta  hf_precedence;
extern const field_meta  hf_sms_indic_sai;
extern const field_meta  hf_switch_off;
extern const field_meta  hf_re_reg_req;
extern const field_meta  hf_acc_type;
extern const field_meta  hf_drx_param;
extern const field_meta  hf_nas_5gs_mm_5g_ea0;
extern const field_meta  hf_nas_5gs_mm_5g_ea1;
extern const field_meta  hf_nas_5gs_mm_5g_ea2;
extern const field_meta  hf_nas_5gs_mm_5g_ea3;
extern const field_meta  hf_nas_5gs_mm_5g_ea4;
extern const field_meta  hf_nas_5gs_mm_5g_ea5;
extern const field_meta  hf_nas_5gs_mm_5g_ea6;
extern const field_meta  hf_nas_5gs_mm_5g_ea7;
extern const field_meta  hf_nas_5gs_mm_5g_ia0;
extern const field_meta  hf_nas_5gs_mm_5g_ia1;
extern const field_meta  hf_nas_5gs_mm_5g_ia2;
extern const field_meta  hf_nas_5gs_mm_5g_ia3;
extern const field_meta  hf_nas_5gs_mm_5g_ia4;
extern const field_meta  hf_nas_5gs_mm_5g_ia5;
extern const field_meta  hf_nas_5gs_mm_5g_ia6;
extern const field_meta  hf_nas_5gs_mm_5g_ia7;
extern const field_meta  hf_nas_5gs_mm_eea0;
extern const field_meta  hf_nas_5gs_mm_eea1;
extern const field_meta  hf_nas_5gs_mm_eea2;
extern const field_meta  hf_nas_5gs_mm_eea3;
extern const field_meta  hf_nas_5gs_mm_eea4;
extern const field_meta  hf_nas_5gs_mm_eea5;
extern const field_meta  hf_nas_5gs_mm_eea6;
extern const field_meta  hf_nas_5gs_mm_eea7;
extern const field_meta  hf_nas_5gs_mm_eia0;
extern const field_meta  hf_nas_5gs_mm_eia1;
extern const field_meta  hf_nas_5gs_mm_eia2;
extern const field_meta  hf_nas_5gs_mm_eia3;
extern const field_meta  hf_nas_5gs_mm_eia4;
extern const field_meta  hf_nas_5gs_mm_eia5;
extern const field_meta  hf_nas_5gs_mm_eia6;
extern const field_meta  hf_nas_5gs_mm_eia7;
extern const field_meta* oct3_flags[];
extern const field_meta* oct4_flags[];
extern const field_meta* oct5_flags[];
extern const field_meta* oct6_flags[];
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
extern const field_meta  hf_nas_eps_emm_acc_csfb_cap;
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
extern const field_meta* oct7_flags[];
extern const field_meta* oct8_flags[];
extern const field_meta* oct9_flags[];
extern const field_meta  hf_nas_5gs_ul_data_sts_psi_7_b7;
extern const field_meta  hf_nas_5gs_ul_data_sts_psi_6_b6;
extern const field_meta  hf_nas_5gs_ul_data_sts_psi_5_b5;
extern const field_meta  hf_nas_5gs_ul_data_sts_psi_4_b4;
extern const field_meta  hf_nas_5gs_ul_data_sts_psi_3_b3;
extern const field_meta  hf_nas_5gs_ul_data_sts_psi_2_b2;
extern const field_meta  hf_nas_5gs_ul_data_sts_psi_1_b1;
extern const field_meta  hf_nas_5gs_ul_data_sts_psi_0_b0;
extern const field_meta  hf_nas_5gs_ul_data_sts_psi_15_b7;
extern const field_meta  hf_nas_5gs_ul_data_sts_psi_14_b6;
extern const field_meta  hf_nas_5gs_ul_data_sts_psi_13_b5;
extern const field_meta  hf_nas_5gs_ul_data_sts_psi_12_b4;
extern const field_meta  hf_nas_5gs_ul_data_sts_psi_11_b3;
extern const field_meta  hf_nas_5gs_ul_data_sts_psi_10_b2;
extern const field_meta  hf_nas_5gs_ul_data_sts_psi_9_b1;
extern const field_meta  hf_nas_5gs_ul_data_sts_psi_8_b0;
extern const field_meta* psi_0_7_flags[];
extern const field_meta* psi_8_15_flags[];
extern const field_meta  hf_nas_5gs_spare_b4;
extern const field_meta  hf_nas_5gs_mm_ue_usage_setting;
extern const field_meta  hf_ng_ran_rcu;
extern const field_meta  hf_pnb_ciot;
extern const field_meta  hf_sec_algo_enc;
extern const field_meta  hf_sec_algo_ip;
extern const field_meta  hf_mm_5g_ea0;
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
extern const field_meta  hf_req_type;
extern const field_meta  hf_pdu_session_id;

extern const field_meta hfm_nas_5gs_mm_conf_upd_ind_red_b1;
extern const field_meta hfm_mm_nas_sec_algo_enc;
extern const field_meta hfm_mm_nas_sec_algo_ip;
// extern const field_meta hfm_nas_5gs_mm_conf_upd_ind_red_b1;
extern const field_meta hfm_mm_s1_mode_b0;
extern const field_meta hfm_mm_ho_attach_b1;
extern const field_meta hfm_mm_lpp_cap_b2;
extern const field_meta hfm_mm_odd_even;
extern const field_meta hfm_mm_length;
extern const field_meta hfm_mm_abba;
extern const field_meta hfm_mm_pld_cont;
extern const field_meta hfm_mm_req_type;
extern const field_meta hfm_mm_serv_type;
extern const field_meta hfm_mm_5g_ea0;
extern const field_meta hfm_mm_128_5g_ea1;
extern const field_meta hfm_mm_128_5g_ea2;
extern const field_meta hfm_mm_128_5g_ea3;
extern const field_meta hfm_mm_5g_ea4;
extern const field_meta hfm_mm_5g_ea5;
extern const field_meta hfm_mm_5g_ea6;
extern const field_meta hfm_mm_5g_ea7;
extern const field_meta hfm_mm_5g_ia0;
extern const field_meta hfm_mm_5g_128_ia1;
extern const field_meta hfm_mm_5g_128_ia2;
extern const field_meta hfm_mm_5g_128_ia3;
extern const field_meta hfm_mm_5g_ia4;
extern const field_meta hfm_nas_5gs_mm_5g_ia5;
extern const field_meta hfm_nas_5gs_mm_5g_ia6;
extern const field_meta hfm_nas_5gs_mm_5g_ia7;
extern const field_meta hfm_nas_5gs_mm_eea0;
extern const field_meta hfm_nas_5gs_mm_128eea1;
extern const field_meta hfm_nas_5gs_mm_128eea2;
extern const field_meta hfm_nas_5gs_mm_eea3;
extern const field_meta hfm_nas_5gs_mm_eea4;
extern const field_meta hfm_nas_5gs_mm_eea5;
extern const field_meta hfm_nas_5gs_mm_eea6;
extern const field_meta hfm_nas_5gs_mm_eea7;
extern const field_meta hfm_nas_5gs_mm_eia0;
extern const field_meta hfm_nas_5gs_mm_128eia1;
extern const field_meta hfm_nas_5gs_mm_128eia2;
extern const field_meta hfm_nas_5gs_mm_eia3;
extern const field_meta hfm_nas_5gs_mm_eia4;
extern const field_meta hfm_nas_5gs_mm_eia5;
extern const field_meta hfm_nas_5gs_mm_eia6;
extern const field_meta hfm_nas_5gs_mm_eia7;
extern const field_meta hf_mm_sal_t_li;
extern const field_meta hf_element;
extern const field_meta hf_mm_sal_al_t;
extern const field_meta hf_sal_num_e;
extern const field_meta hf_tsc;
extern const field_meta hf_sms_requested;
extern const field_meta hf_sd;

extern const field_meta hf_nas_key_set_id_h1;
extern const field_meta hf_tsc_h1;
extern const field_meta hf_nas_key_set_id;
extern const field_meta hfm_mm_raai_b0;
extern const field_meta hf_mapped_conf_sst;
extern const field_meta hf_mapped_conf_ssd;
extern const field_meta hf_mm_sprti;

extern const field_meta  hf_tac;
extern const field_meta  hf_tal_num_e;
extern const field_meta  hf_tal_t_li;
extern const field_meta* hf_mm_raai_b0;
extern const field_meta  hf_plt_cont_type;
extern const field_meta  hf_payload_container_type;
extern const field_meta  hfm_nas_eps_tsc;
extern const field_meta* hf_nas_eps_tsc;
extern const field_meta  hf_follow_on_req;

extern const field_meta  hf_abba;
extern const field_meta  hfm_mm_conf_upd_ind_ack_b0;
extern const field_meta  hfm_nas_eps_nas_ksi;
extern const field_meta* hf_nas_eps_nas_ksi;
extern const field_meta  hf_mm_length;
extern const field_meta  hf_mm_sst;
extern const field_meta  hf_sst;
} // namespace mm
