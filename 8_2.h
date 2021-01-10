//
// Created by Administrator on 2021/1/11.
//

#ifndef CPP_PRIMER_8_2_H
#define CPP_PRIMER_8_2_H
#include <algorithm>

class algorithms {
public:
    // Input iterators
    template <class In1, class In2> static bool equal(In1 b, In1 e, In2 d)
    {
        while (b != e and *b == *d)
            b++;
        return b == e;
    }
    // Forward iterators
    template<class Fw1, class Fw2> static Fw1 search (Fw1 b1, Fw1 e1, Fw2 b2, Fw2 e2)
    {
        while (b1 != e1) {
            Fw1 cur_b1 = b1;
            Fw2 cur_b2 = b2;
            while (*cur_b1++ == *cur_b2++)
            {
                if (cur_b2 == e2) {
                    return b1;
                }
                if (cur_b1 == e1) {
                    return e1;
                }
            }
            b1++;
        }
        return e1;
    }
};
#endif //CPP_PRIMER_8_2_H
