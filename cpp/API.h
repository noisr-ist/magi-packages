#ifndef API_H
#define API_H

#include <string>
#include <vector>
#include <cpr/cpr.h>
#include <jsoncpp/json/json.h>

class Api {
public:
    Api();
    std::string repr() const;
    std::vector<int> get_numbers(int count, int bits = 8) const;

private:
    std::string base_url;
    cpr::Response get(const std::string& endpoint, const cpr::Parameters& params = {}) const;
    cpr::Response post(const std::string& endpoint, const Json::Value& data = {}) const;
};

#endif