#include "Api.h"
#include <cpr/cpr.h>

Api::Api() {}

std::string Api::generate(int count) {
    cpr::Response r = cpr::Post(cpr::Url{"https://api.noisr.pt/generate"},
                                 cpr::Body("{\"count\": 5}"),
                                 cpr::Header{{"Content-Type", "application/json"}});
    return r.text;
}
