#include "bulk_io.h"

#include <iostream>

// output
void bulk_io::print_greeting() const { std::cout << "Hallloo is this working??\n"; }

// input

void bulk_io::input_command() {
    std::cout << "The chain is working!" << std::endl;
    exit(0);
}