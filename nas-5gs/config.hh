#pragma once
#include <cstdint>

typedef unsigned int uint_t;
typedef int int_t;

struct tvbuff;
typedef tvbuff tvbuff_t;
typedef tvbuff buffer_t;

struct packet_info;
struct proto_node;
struct context;

struct protocol_meta;
struct field_meta;
struct tree_meta;
struct expert_meta;

struct val_string;
struct tf_string;
struct range_string;

typedef proto_node proto_tree;
typedef proto_node proto_item;

typedef int (
    *dissect_fnc_t)(packet_info*, proto_node*, tvbuff*, int offset, int len, context*);
typedef dissect_fnc_t dissect_msg_fnc_t;
typedef dissect_fnc_t dissect_elem_fnc_t;
