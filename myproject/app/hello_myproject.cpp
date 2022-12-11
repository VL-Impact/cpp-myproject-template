#include "myproject.h"
#include <iostream>

int main(int argc, char** argv) {
    
    // check number of arguments
    if(argc != 3) {
        std::cout << "Usage: " << argv[0] << " <a> <b>" << std::endl;
        return 1;
    }

    // read 2 numbers from command line
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    // call my_mul
    int m = myproject::my_mul(a, b);

    // print result
    std::cout << m << std::endl;
    
    return 0;
}