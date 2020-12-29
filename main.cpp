#include <iostream>
#include <string>
#include <vector>
#include "words.h"

using std::cin; using std::cout; using std::endl;
using std::vector; using std::string;
using std::getline;
int main() {



    vector<string> v = {"I have a apple", "you have a pen", "apple pen"};
    vector<string> frame_v = frame(v);
    for (vector<string>::size_type i = 0; i != frame_v.size() ; ++i) {
        cout<<frame_v[i]<<endl;
    }

    return 0;
}
