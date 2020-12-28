//
// Created by 87325 on 2020/12/28.
//
#include "words.h"
#include <algorithm>
#include <functional>
#include <cctype>

using std::vector; using std::string;
using std::max; using std::transform;


vector<string> split(const string& s)
{
    vector<string> ret;
    typedef std::string::size_type  string_size;
    string_size  i = 0;
    while (i < s.size() && isspace(s[i]))
        i++;
    string_size j;
    while (i < s.size())
    {
        j = i + 1;
        while (j < s.size() && !isspace(s[j]))
            j++;
        ret.push_back(s.substr(i, j - i));
        i = j;
        while (i < s.size() && isspace(s[i]))
            i++;
    }
    return ret;
}
