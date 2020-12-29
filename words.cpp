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
string::size_type width(const vector<string>& v)
{
    typedef string::size_type string_size;
    string_size max_size = 0;
    for(vector<string>::size_type i = 0 ; i != v.size();  i++)
    {
        max_size = max(max_size, v[i].size());
    }
    return max_size;
}
vector<string> frame(const vector<string>& v)
{
    vector<string> ret_frame;
    string::size_type max_length = width(v);
    string border(max_length + 4, '*');
    ret_frame.push_back(border);
    for (vector<string>::size_type i = 0; i != v.size() ; ++i) {
        ret_frame.push_back("* " + v[i] + string(max_length - v[i].size(), ' ') + " *");
    }
    ret_frame.push_back(border);
    return ret_frame;
}