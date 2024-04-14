# How to use the MAGI Packages

## Introduction

The MAGI packages are pieces of code that ease the utilization of the noisr API. They are written in Python and C++ (for the moment) and are available on the magi-packages GitHub repository.

## Installation

To install the MAGI packages, you need to clone the repository and install the required dependencies. The following steps will guide you through the installation process.

### Cloning the repository

To clone the repository, you need to run the following command:

```bash
git clone https://github.com/noisr-ist/magi-packages.git
```

### Installing the dependencies

The only required dependencies are the requests and numpy Python packages. To install them, you need to run the following command:

```bash
pip install requests numpy
```

If you want to use the C++ packages, you need to have the g++ compiler installed on your system and the required libraries:

#### CPR

To install the [CPR library](https://github.com/libcpr/cpr) , you need to run the following commands:

```bash
sudo apt-get install libcurl4-openssl-dev libjsoncpp-dev
git clone https://github.com/whoshuu/cpr.git
cd cpr
cmake .
make
sudo make install
```

#### nlohmann/json

To install the [nlohmann/json](https://github.com/nlohmann/json) library, you need to run the following commands:

```bash
git clone https://github.com/nlohmann/json.git
cd json
mkdir build
cd build
cmake ..
make
sudo make install
```

## Usage

To use the MAGI packages, you need to import the desired package in your code. The following code snippet shows how to import the Python package:

```python
from MAGI import Api

api = Api()

print(api.generate(<number of 8bit numbers>))
```

To use the C++ packages, you need to include the desired header file in your code. The following code snippet shows how to include the C++ package:

```cpp
#include "MAGI/Api.h"

int main() {
    Api api;

    std::cout << api.generate(<number of 8bit numbers>) << std::endl;

    return 0;
}
```

To compile the C++ code, you need to run the following command:

```bash
g++ MAGI/Api.cpp <source file> -o <output file> -lcpr
```

There are example uses of the packages in the examples directory of the repository.
