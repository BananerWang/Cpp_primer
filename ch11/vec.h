//
// Created by Administrator on 2021/1/19.
//

#ifndef CPP_PRIMER_VEC_H
#define CPP_PRIMER_VEC_H

#include <memory>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
using namespace stdext;
template<class T> class Vec {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    Vec() {create();}
    explicit Vec(size_type n, const T& val = T()) {create(n, val);}

    Vec(const Vec& v) {}

    T& operator[](size_type i) {return data[i];}
    const T& operator[](size_type i)const {return data[i];}

    iterator begin() {return data;}
    const_iterator begin() const {return data;}

    iterator end() {return limit;}
    const_iterator end() const {return limit;}

    ostream& print_vec(std::ostream&);



private:
    iterator data;
    iterator limit;
    iterator avail;
    //
    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);

    //

    void uncreate();
    //
    void grow(bool double_grow);
    //
    void uncheck_append(const T&);

    std::allocator<T> alloc;

};

template <class T>
void Vec<T>::create()
{
    data = avail = limit = 0;
}

template <class T>
void Vec<T>::create(Vec::size_type n, const T& val) {
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(Vec::const_iterator i, Vec::const_iterator j)
{
    data = alloc.allocate(i, j);
    stdext::checked_array_iterator<T*> check_data(data, (j - i));
    limit = avail = (std::uninitialized_copy(i, j, check_data))._Unchecked();
}

template <class T>
void Vec<T>::uncreate() {
    if (data){
        iterator it = avail;
        while (it != data)
            alloc.destroy(--it);
        alloc.deallocate(data, limit - data);
    }
    data = limit = avail = 0;
}


template <class T>
void Vec<class T>::grow(bool double_grow) {
    size_type new_size;
    if (double_grow)
    {
        new_size = std::max(2 * (limit - data), ptrdiff_t(1));
    } else
        new_size = limit - data + 1;
    iterator new_data = alloc.allocate(new_size);
    stdext::checked_array_iterator<T*> checked_data(new_data, new_size);
    iterator new_avail = (std::uninitialized_copy(data, avail, checked_data))._Unchecked();

    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}


template <class T> void Vec<T>::uncheck_append(const T & val) {
    alloc.template construct(avail++, val);
}

template <class T>
std::ostream& Vec<T>::print_vec(std::ostream& os)
{
    if (avail - data > 0)
    {
        iterator iter = data;

        os<<*iter;

        while (iter != avail) {
            os <<", "<<*iter++;
        }
        os<<std::endl;
    }
}




#endif //CPP_PRIMER_VEC_H
