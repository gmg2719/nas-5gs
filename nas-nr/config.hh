#pragma once
#include <cstdint>
#include <string>
#include <vector>

template <typename... Args> inline void unused(Args&&...) {}

struct tvbuff;

struct packet_info;
struct proto_node;
struct context;

struct protocol_meta;
struct field_meta;
struct tree_meta;

struct val_string;
struct true_false_string;
struct range_string;

using proto_tree = proto_node;
using proto_item = proto_node;
using string     = std::string;
using ustring    = std::vector< uint8_t >;

extern void diag(const char* format, ...);

namespace enc {
inline const uint32_t na   = 0;
inline const uint32_t be   = 1; // big endian
inline const uint32_t none = 4; // host order
} // namespace enc

struct dissector {
    packet_info* pinfo  = nullptr;
    proto_node*  tree   = nullptr;
    tvbuff*      tvb    = nullptr;
    int          offset = 0;
    int          length = 0;
    void*        data   = nullptr;

    dissector& step(int consumed) {
        offset += consumed;
        length -= consumed;
        return *this;
    }
    proto_node* add_item(int len, const field_meta* fm, uint32_t e = enc::be) const;
    proto_node* add_item(int len, const char* format, ...) const;
    void        add_bits(const field_meta* metas[]) const;
    void        extraneous_data_check(int max_len, context* ctx = nullptr) const;
    auto        safe_ptr() const -> const uint8_t*;
    auto        safe_length(int len) const -> int;
    auto        slice(int len) const -> dissector;
    auto        use_elem(void* elem) const -> dissector;
    auto        uint8() const -> uint8_t;
    auto        ntohs() const -> uint16_t;
    auto        uint32() const -> uint32_t;
};

struct use_tree { // NOLINT: special;-member-functions
    dissector&  d;
    proto_node* prev;
    use_tree(dissector& d, proto_node* p) : d(d), prev(d.tree) { d.tree = p; }
    ~use_tree() { d.tree = prev; }
};

typedef int (*dissect_fnc_t)(dissector, context* ctx);

struct context {
    uint32_t                   msg_auth_code        = 0;
    uint8_t                    payload_content_type = 0;
    std::vector< std::string > paths                = {};
    std::string  path() const;
};

struct use_context { // NOLINT: special-member-functions
    context*         ctx    = nullptr;
    int              offset = 0;
    int              length = 0;
    int              maxlen = 0;
    const dissector& d;

    use_context(context* ctx, const char* path, dissector const& d, const int maxlen = 0)
        : ctx(ctx), offset(d.offset), length(d.length), maxlen(maxlen), d(d) {
        if (!ctx) return;
        if (path == nullptr) path = ".";
        ctx->paths.emplace_back(path);
        diag("%s%s %d-%d\n",
             string(ctx->paths.size() << 1u, ' ').c_str(),
             path,
             offset,
             length);
    }
    ~use_context() {
        if (ctx) {
            ctx->paths.pop_back();
        }
        d.extraneous_data_check(maxlen, ctx);
    }
};
inline void store_payload_content_type(context* ctx, uint8_t pct) {
    if (ctx) ctx->payload_content_type = pct;
}

inline uint8_t retrieve_payload_content_type(context* ctx) {
    return ctx ? ctx->payload_content_type : 0;
}
// code is host order
inline void store_msg_auth_code(context*ctx, uint32_t code){
    if (ctx) ctx->msg_auth_code = code;
}
inline uint32_t retrieve_msg_auth_code(context*ctx){
    return ctx ? ctx->msg_auth_code : 0;
}

inline string paths(context* ctx) {
    if (!ctx) return string();
    return ctx->path();
}

inline uint8_t  n2uint8(const uint8_t* d) { return *d; };
inline uint16_t n2uint16(const uint8_t* data) {
    const uint16_t a = data[0];
    uint16_t b = data[1];
    return a << 8 | b;
};
inline uint32_t n2uint24(const uint8_t* data) {
    uint32_t a = data[0];
    uint32_t b = data[0 + 1];
    uint32_t c = data[0 + 2];
    return a << 16 | b << 8 | c;
};
inline uint32_t n2uint32(const uint8_t* data) {
    uint32_t a = data[0];
    uint32_t b = data[0 + 1];
    uint32_t c = data[0 + 2];
    uint32_t d = data[0 + 3];
    return a << 24 | b << 16 | c << 8 | d;
};
inline uint64_t n2uint48(const uint8_t* data) {
    uint64_t a = data[0];
    uint64_t b = data[0 + 1];
    uint64_t c = data[0 + 2];
    uint64_t d = data[0 + 3];
    uint64_t e = data[0 + 4];
    uint64_t f = data[0 + 5];
    return a << 40 | b << 32 | c << 24 | d << 16 | e << 8 | f;
};
inline uint64_t n2uint64(const uint8_t* data) {
    uint64_t a = data[0];
    uint64_t b = data[0 + 1];
    uint64_t c = data[0 + 2];
    uint64_t d = data[0 + 3];
    uint64_t e = data[0 + 4];
    uint64_t f = data[0 + 5];
    uint64_t g = data[0 + 4];
    uint64_t h = data[0 + 5];
    return a << 56 | b << 48 | c << 40 | d << 32 | e << 24 | f << 16 | g << 8 | h;
};

inline uint64_t n2_uint(const uint8_t* data, int len) {
    if (!len || !data) return 0;

    switch (len) {
    case 1:
        return n2uint8(data);
    case 2:
        return n2uint16(data);
    case 3:
        return n2uint24(data);
    case 4:
        return n2uint32(data);
    case 6:
        return n2uint48(data);
    case 8:
        return n2uint64(data);
    default:
        return 0;
    }
}

string format_hex(const uint8_t* data,
                  int            len,
                  const char*    sep = " ",
                  const char*    lf  = nullptr);

string format_bit(const uint8_t* data, int len, const char* sep = " ");

string format_bits(const uint8_t* data, int bits, const char* sep = nullptr);

string format_int_bit_mask(uint32_t    ftype,
                           uint64_t    v,
                           uint64_t    mask,
                           const char* sep = nullptr);

string format_int(uint64_t v, uint32_t ftype, uint32_t display);
string format_int_hex(uint64_t v, uint32_t ftype);
string format_int_dec(uint64_t v, uint32_t ftype);

string formats(const char* format, ...);
string vformat(const char* format, va_list);

const char* find_val_string(const val_string* strings,
                            uint32_t          id,
                            const char*       missing = "Unknown");
const char* find_r_string(const range_string* strings,
                          uint32_t            id,
                          const char*         missing = "Unknown");

std::vector< std::string > find_bits_string(const val_string* strings, uint32_t bits);

string join(const std::vector< string >& strings, const char* sep = " ");

string bits7_string(const uint8_t* data, int len);

ustring ts_23_038_7bits_string(const uint8_t* ptr, int bit_offset, int no_of_chars);

int ws_ctz(uint64_t mask);

uint32_t get_ext_ambr_unit(uint32_t unit, const char** unit_str);

string ambr_string(const uint8_t* d, int length);
string ambr_string(uint32_t val, uint32_t unit);

string bstrn_string(const uint8_t* d, int len);

string gprs_timer3_format(uint8_t oct);
string gprs_timer2_format(uint8_t oct);

string gprs_timer2_string(const uint8_t*d, int len);
string gprs_timer3_string(const uint8_t* d, int len);
string gprs_timer_string(const uint8_t* d, int len);

string ipv6_string(const uint8_t*d, int length);
string ipv6_link_local_string(const uint8_t* d, int length);

//  [3] 10.5.1.13 PLMN list TS24.008
string mcc_string(const uint8_t* d, int length = 3);
string mcc_mnc_string(const uint8_t* d, int length = 3);

// BCD number
string bcd_string(const uint8_t* d, int length);
string imei_string(const uint8_t* d, int length); // 0xf0 terminated if even
string timezone_time_string(const uint8_t* d, int length);
string timezone_string(const uint8_t* d);

int ext_length(const uint8_t* d);

string w2utf8(const wchar_t*str);