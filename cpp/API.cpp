#include "Api.h"

Api::Api() : base_url("http://api.noisr.pt") {}

std::string Api::repr() const {
    auto response = get("");
    if (response.status_code == 200) {
        return "Connected to " + base_url;
    } else {
        return "Failed to connect to " + base_url;
    }
}

std::vector<int> Api::get_numbers(int count, int bits) const {
    Json::Value data;
    data["count"] = count;
    data["bits"] = bits;
    auto response = post("generate", data);
    if (response.status_code != 200) {
        throw std::runtime_error("HTTP error occurred while getting numbers");
    }
    Json::Value numbers;
    Json::Reader reader;
    reader.parse(response.text, numbers);
    std::vector<int> decimal_numbers;
    for (const auto& num : numbers["numbers"]) {
        decimal_numbers.push_back(std::stoi(num.asString(), nullptr, 2));
    }
    return decimal_numbers;
}

cpr::Response Api::get(const std::string& endpoint, const cpr::Parameters& params) const {
    return cpr::Get(cpr::Url{base_url + "/" + endpoint}, params);
}

cpr::Response Api::post(const std::string& endpoint, const Json::Value& data) const {
    Json::StreamWriterBuilder writer;
    std::string jsonData = Json::writeString(writer, data);
    return cpr::Post(cpr::Url{base_url + "/" + endpoint}, cpr::Body{jsonData}, cpr::Header{{"Content-Type", "application/json"}});
}