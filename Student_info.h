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
istream& read(istream& is, std::vector<Student_info>& s);
istream& read_hw(istream& is, std::vector<double>&);
bool did_all_hw(const Student_info& s);
bool compare(const Student_info& x, const Student_info& y);

double grade_aux(const Student_info&);
double optimistic_median(const Student_info&);
double average_grade(const Student_info&);
double median_analysis(const std::vector<Student_info>&);
double analysis(const std::vector<Student_info>& s, double method(const Student_info&));
double average_analysis(const std::vector<Student_info>&);
void write_analysis(std::ostream&, const std::string&, double analysis(const std::vector<Student_info>&),
                    const std::vector<Student_info>&, const std::vector<Student_info>&);
bool fgrade(const Student_info&);
bool pgrade(const Student_info&);

std::vector<Student_info> extract_fails(std::vector<Student_info>& students);


#endif //CPP_PRIMER_STUDENT_INFO_H
