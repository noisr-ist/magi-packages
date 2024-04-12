//Api.h
#ifndef API_H
#define API_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Api {
    public:
        Api();
        json generate(int count);
    private:
        std::string url = "https://api.noisr.pt";
};
#endif