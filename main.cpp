#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <sstream>
using std::stringstream;
#include "words.h"
#include "cha6.h"
#include "8_2.h"
using std::cin; using std::cout; using std::endl;
using std::vector; using std::string;
using std::getline; using std::domain_error;
using std::back_inserter;

template<class In> string print_vec(In b, In e)
{
    if (b == e)
        throw domain_error("Empty range");
    stringstream ss;
    ss <<"[ " <<*b++;
    while (b != e)
        ss << ", " <<*b++;
    ss<<" ]";
    return ss.str();
}
int main() {



    return 0;


}
