#include "Api.h"
#include <cpr/cpr.h>

using json = nlohmann::json;

Api::Api() {}

json Api::generate(int count) {
    cpr::Response r = cpr::Post(cpr::Url{"https://api.noisr.pt/generate"},
                                 cpr::Body("{\"count\": 5}"),
                                 cpr::Header{{"Content-Type", "application/json"}});

    json j = nlohmann::json::parse(r.text);


    
    return j;
}
