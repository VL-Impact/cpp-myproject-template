#include "myproject.h"

namespace myproject {

    int my_mul(int a, int b) {
        int m = 0;
        for(int i = 0; i < b; i++)
            m += a;
        return m;
    }

    int my_mul_optimized(int a, int b) {
        return a * b;
    }

}