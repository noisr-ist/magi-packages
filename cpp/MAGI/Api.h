//Api.h
#ifndef API_H
#define API_H

#include <string>


class Api {
    public:
        Api();
        std::string generate(int count);
    private:
        std::string url = "https://api.noisr.pt";
};
#endif