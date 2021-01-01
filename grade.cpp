//
// Created by Administrator on 2021/1/1.
//

#include "grade.h"

#include <stdexcept>
#include <vector>
#include <algorithm>


using std::domain_error;  using std::vector;


double grade(double midterm, double final, double homework) {
    return 0.2 *midterm + 0.4 * final + 0.4 * homework;
}


double median(const vector<double>& hw)
{
    if (hw.empty()) {
        return 0;
    }
    int

}

double grade(double midterm, double final, const std::vector<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("Student has done no homework");
    return grade(midterm, final, median(hw));
}

double grade(const Student_info& s) {
    return s.grade;
}