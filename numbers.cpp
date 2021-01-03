//
// Created by Administrator on 2021/1/3.
//

#include "numbers.h"
#include <stdexcept>
using std::domain_error;

int nrand(int n)
{
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");

    const int bucket_size = RAND_MAX / n;
    int r;

    do r = rand() / bucket_size;
    while (r >= n);

    return r;

}