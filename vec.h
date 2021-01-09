//
// Created by Administrator on 2021/1/9.
//

#ifndef CPP_PRIMER_VEC_H
#define CPP_PRIMER_VEC_H

#include <vector>
#include <stdexcept>
#include <algorithm>
using std::vector;
template<class T>
T median(vector<T> v)
{
    typedef typename vector<T>::size_type vec_sz;
    vec_sz size = v.size();
    if (size == 0)
        throw std::domain_error("median of an empty vector");
    std::sort(v.begin(), v.end());
    vec_sz mid = size / 2;
    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}


#endif //CPP_PRIMER_VEC_H
