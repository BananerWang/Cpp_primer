//
// Created by Administrator on 2021/1/1.
//

#ifndef CPP_PRIMER_STUDENT_INFO_H
#define CPP_PRIMER_STUDENT_INFO_H
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using std::istream;


struct Student_info{
    std::string name;
    std::vector<double> homework;
    double midterm, final, grade;
};

istream& read(istream& is, Student_info& s);
istream& read_hw(istream& is, std::vector<double>&);
bool did_all_hw(const Student_info& s);
bool compare(const Student_info& x, const Student_info& y);


#endif //CPP_PRIMER_STUDENT_INFO_H
