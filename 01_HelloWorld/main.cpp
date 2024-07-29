#include <iostream>

#include "lib.h"

int main(int, char**) {
    std::cout << "Hello, from CI-CD-HelloWorld!\n"
              << "Version: " << ver::version() << '\n';
}
