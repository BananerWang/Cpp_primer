//
// Created by Administrator on 2021/1/1.
//

#include "grade.h"

#include <stdexcept>
#include <algorithm>


using std::domain_error;  using std::vector;
using std::sort;

double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}


double median(vector<double>& hw)
{
    if (hw.empty()) {
        return 0;
    }
    int mid =  hw.size() / 2;
    sort(hw.begin(), hw.end());
    return hw.size() % 2 == 0 ? (hw[mid] + hw[mid - 1]) / 2 : hw[mid];
}

double grade(double midterm, double final, std::vector<double>& hw) {
    if (hw.empty())
        throw domain_error("Student has done no homework");
    return grade(midterm, final, median(hw));
}

double grade(const Student_info& s) {
    return s.grade;
}