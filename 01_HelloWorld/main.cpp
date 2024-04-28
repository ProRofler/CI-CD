#include <iostream>
#include "lib.h"

int main(int, char**){
    int ver = version();
    std::cout << "Hello, from CI-CD-HelloWorld!\n"
              << "Version: " << ver << '\n';
}
