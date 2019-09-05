#include "../dissect_mm_msg.hh"
#include "../ts24007.hh"

using namespace nas;
using namespace mm;

/*8.2.21 Identity request */
int mm::dissect_id_req(dissector d, context* ctx) {    
    use_context uc(ctx, "identity-request", d, -1);

    /* Identity type    5GS identity type 9.11.3.3    M    V    1/2 */
    const auto consumed = dissect_5gs_id_type(d, ctx);
    d.add_item(1, hf_spare_half_octet, enc::be);
    /* Spare half octet    Spare half octet 9.5    M    V    1/2 */
    d.step(1);
    
    return 1;
}

