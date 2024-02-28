# How to use the API in C++

## Introduction

Installation of needed packages and libraries is required to use the API in C++. The following steps will guide you through the process.7

```bash
sudo apt-get install libcurl4-openssl-dev libjsoncpp-dev
git clone https://github.com/whoshuu/cpr.git
cd cpr
cmake .
make
sudo make install
```
<div style="page-break-after: always;"></div>
## Usage

API.cpp:

```cpp
#include "API.h"
#include <sstream>
#include <stdexcept>
#include <iostream>

API::API(const std::string& url) : base_url(url) {}

cpr::Response API::get(const std::string& endpoint, const cpr::Parameters& params) {
    cpr::Response response = cpr::Get(cpr::Url{base_url + "/" + endpoint}, params);
    if (response.status_code != 200) {
        throw std::runtime_error("Failed to connect to " + base_url);
    }
    return response;
}

cpr::Response API::post(const std::string& endpoint, const Json::Value& data, const cpr::Header& headers) {
    std::string payload_string = Json::writeString(Json::StreamWriterBuilder(), data);
    cpr::Response response = cpr::Post(cpr::Url{base_url + "/" + endpoint}, cpr::Body{payload_string}, headers);
    if (response.status_code != 200) {
        throw std::runtime_error("Failed to connect to " + base_url);
    }
    return response;
}

std::string API::repr() {
    try {
        get("");
        return "Connected to " + base_url;
    } catch (std::runtime_error&) {
        return "Failed to connect to " + base_url;
    }
}

std::vector<int> API::get_numbers(int count, int bits) {
    try {
        Json::Value payload;
        payload["count"] = count;
        payload["bits"] = bits;
        cpr::Response response = post("generate", payload, cpr::Header{{"Content-Type", "application/json"}});
        Json::Value jsonData;
        Json::CharReaderBuilder jsonReader;
        std::string errors;
        std::istringstream iss(response.text);
        if (!Json::parseFromStream(jsonReader, iss, &jsonData, &errors)) {
            throw std::runtime_error("Failed to parse JSON response!");
        }
        std::vector<int> decimal_numbers;
        for (const auto& num : jsonData["numbers"]) {
            decimal_numbers.push_back(std::stoi(num.asString(), nullptr, 2));
        }
        return decimal_numbers;
    } catch (std::runtime_error&) {
        std::cerr << "HTTP error occurred while getting numbers" << std::endl;
        return {};
    }
}
```
<div style="page-break-after: always;"></div>
API.h:

```cpp
#include <string>
#include <vector>
#include <jsoncpp/json/json.h>
#include <cpr/cpr.h>

class API {
private:
    std::string base_url;

    cpr::Response get(const std::string& endpoint, const cpr::Parameters& params = cpr::Parameters{});
    cpr::Response post(const std::string& endpoint, const Json::Value& data, const cpr::Header& headers);

public:
    API(const std::string& url);
    std::string repr();
    std::vector<int> get_numbers(int count, int bits = 8);
};
```
<div style="page-break-after: always;"></div>
main.cpp:

```cpp
#include "API.h"
#include <iostream>

int main() {
    API api("http://api.noisr.pt");
    std::vector<int> numbers = api.get_numbers(5);
    for (int num : numbers) {
        std::cout << num << std::endl;
    }
    return 0;
}
```
Compile and run the program:

```bash
g++ -std=c++17 main.cpp API.cpp -lcpr -lcurl -ljsoncpp -o noisr.exe
