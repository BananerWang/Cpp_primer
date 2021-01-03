//
// Created by Administrator on 2021/1/1.
//

#ifndef CPP_PRIMER_GRADE_H
#define CPP_PRIMER_GRADE_H

#include <vector>
#include "Student_info.h"
#include <stdexcept>

double grade(double midterm, double final, double avg_hw);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);

double median(std::vector<double>& hw);




#endif //CPP_PRIMER_GRADE_H
