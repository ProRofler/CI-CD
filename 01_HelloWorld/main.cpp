#include <iostream>
#include "version.h"

int main(int, char**){
    std::cout << "Hello, from CI-CD-HelloWorld!\n"
              << "Version: " << version << '\n';
}
