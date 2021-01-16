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
    // Input iterators
    template<class In, class X> static In find(In b, In e, const X& t)
    {
        while (b != e)
        {
            if (*b == t)
                return b;
            b++;
        }
        return b;

    }
    // Input iterators
    template <class In, class P> static In find_if(In b, In e, P p)
    {
        while (b != e && *b != p(*b))
        {
            b++;
        }
        return b;
    }

    template<class In, class Out> static Out copy(In b, In e, Out d)
    {
        while (b != e)
            *d++ = *b++;
        return d;
    }

    template<class In, class Out, class X> static Out remove_copy(In b, In e, Out d, const X& t)
    {
        while (b != e)
        {
            if (*b != t)
                *d++ = *b;
            b++;
        }

    }

    template<class In, class Out, class P> static Out remove_copy_if(In b, In e, Out d, P p)
    {
        while (b != e)
        {
            if (!p(*b))
                *d++ = *b;
            b++;
        }
        return d;
    }
    template<class Fw, class X> static Fw remove(Fw b, Fw e, const X& t)
    {
        Fw b_in = b;
        while (b_in != e)
        {
            if (*b_in != t)
                *b++ = *b_in;
            b_in++;
        }
        return b;
    }
    template <class Fw, class P> static Fw transform(Fw b, Fw e, P p)
    {
        Fw b_out = b;
        while (b != e)
        {
            *b_out++ = p(*b++);
        }
        return b_out;
    }
    template <class Fw, class P> static Fw partition(Fw b, Fw e, P p)
    {
        Fw b_out = b;
        while (b != e)
        {
            if (p(*b))
                std::iter_swap(b, b_out++);
            b++;
        }
        return b_out;
    }
    template <class In, class X> static X accumulate(In b, In e, X t)
    {
        while (b != e)
        {
            t += *b++;
        }
        return t;
    }

};
#endif //CPP_PRIMER_8_2_H
