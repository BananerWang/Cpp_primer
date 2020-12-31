//
// Created by Administrator on 2021/1/1.
//

#ifndef CPP_PRIMER_STUDENT_INFO_H
#define CPP_PRIMER_STUDENT_INFO_H
#include <string>
#include <vector>
#include <iostream>
using std::istream;
struct Student_info{
    std::string name;
    std::vector<double> homework;
    double midterm, final;
};

istream& read(istream& is, Student_info& s);
istream& read_hw(istream& is, std::vector<double>&);


#endif //CPP_PRIMER_STUDENT_INFO_H
