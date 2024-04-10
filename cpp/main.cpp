#include <iostream>
#include <cpr/cpr.h>

int main() {
    cpr::Response r = cpr::Post(cpr::Url{"https://api.noisr.pt/generate"},
                                 cpr::Body("{\"count\": 5}"),
                                 cpr::Header{{"Content-Type", "application/json"}});
    std::cout << r.text << std::endl; // Print the response text
    return 0;
}