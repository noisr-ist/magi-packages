#include <iostream>
#include "MAGI/Api.h"

int main() {
    Api api;
    int n = std::stoi(api.generate(5)["numbers"][0].get<std::string>(), nullptr, 2); // Convert binary string to decimal integer

    std::cout << n << std::endl;
    return 0;
}