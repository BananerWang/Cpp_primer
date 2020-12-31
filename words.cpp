//
// Created by 87325 on 2020/12/28.
//
#include "words.h"
#include <algorithm>
#include <functional>
#include <cctype>

using std::vector; using std::string;
using std::max; using std::transform;
using std::search; using std::find;
using std::find_if;

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

bool equal(const std::string& s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}



bool not_url_char(char c)
{
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";

    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
    return find_if(b, e, not_url_char);
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
    static const string sep = "://";
    typedef string::const_iterator iter;
    iter i = b;
    while ((i = search(i, e, sep.begin(), sep.end())) != e) {
        if (i != b  && i + sep.size() != e) {
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
                beg--;
            if (beg != i && !not_url_char(i[sep.size()])) {
                return beg;
            }
        }
        i += sep.size();
    }
    return e;
}


vector<string> find_urls(const string& s)
{
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin();
    iter e = s.end();
    while (b != e)
    {
        b = url_beg(b, e);
        if (b != e) {
            iter end = url_end(b, e);
            ret.emplace_back(b, end);
           b = end;
        }
    }

    return ret;

}