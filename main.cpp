#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "words.h"

using std::cin; using std::cout; using std::endl;
using std::vector; using std::string;
using std::getline;
int main() {



    string s;
    while (getline(cin, s)) {

       vector<string> string_vector =  find_urls(s);
        /*for (auto it : *string_vector.begin()) {
            cout<<it<<endl;
        }*/
        for(const auto& c : string_vector)
            cout<<c<<endl;
    }

    return 0;
}
