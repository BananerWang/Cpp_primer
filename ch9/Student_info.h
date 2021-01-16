//
// Created by Administrator on 2021/1/16.
//

#ifndef CPP_PRIMER_STUDENT_INFO_H
#define CPP_PRIMER_STUDENT_INFO_H

#include <string>
#include <iostream>
#include <vector>
class Student_info {

private:
    std::string n;
    double midterm, final;
    std::vector<double> homework;

public:
    Student_info();
    Student_info(std::istream&);

    std::istream& read(std::istream&);
    double grade() const;
    std::string name() const {return n;}
    bool valid() const {return !homework.empty();}
};
bool compare(const Student_info&, const Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);


#endif //CPP_PRIMER_STUDENT_INFO_H
