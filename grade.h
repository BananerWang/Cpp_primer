//
// Created by Administrator on 2021/1/1.
//

#ifndef CPP_PRIMER_GRADE_H
#define CPP_PRIMER_GRADE_H

#include <vector>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);




#endif //CPP_PRIMER_GRADE_H
