//
// Created by Administrator on 2021/1/1.
//

#include "Student_info.h"
#include "grade.h"
#include <sstream>
#include <algorithm>
#include <numeric>
using std::vector; using std::string;
using std::domain_error; using std::transform;
using std::back_inserter; using std::stringstream;
using std::remove_copy; using::std::remove_copy_if;
using std::remove_if; using std::ostream;
using std::endl;
istream& read(istream& is, Student_info& s)
{
    is>>s.name>>s.midterm>>s.final;
    read_hw(is, s.homework);
    return is;
}

istream& read(istream& is, std::vector<Student_info>& s)
{
    const int BUFF_SIZE = 80;
    stringstream ss;
    char buff[BUFF_SIZE];

    while (is.getline(buff, BUFF_SIZE)) {
        ss << buff;
        Student_info studentInfo;
        read(ss, studentInfo);
        s.push_back(studentInfo);
    }
    return is;
}

istream& read_hw(istream& in, vector<double>& hw)
{
    if (in)
    {
        in.clear();
        double x;
        while (in>>x)
            hw.push_back(x);

        in.clear();
    }
    return in;
}

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name > y.name;
}

bool did_all_hw(const Student_info& s)
{
    return find(s.homework.begin(), s.homework.end(), 0 ) == s.homework.end();
}

double grade_aux(const Student_info& s)
{
    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

double median_analysis(const std::vector<Student_info>& s)
{
    vector<double> grades;
    transform(s.begin(), s.end(), back_inserter(grades), grade_aux);
    return median(grades);

}

double analysis(const std::vector<Student_info>& s, double method(const Student_info&))
{
    vector<double> grades;
    transform(s.begin(), s.end(), back_inserter(grades), method);
    return median(grades);
}


double optimistic_median(const Student_info& student)
{
    vector<double> nonzero;
    remove_copy(student.homework.begin(), student.homework.end(), back_inserter(nonzero), 0);
    if (nonzero.empty()) {
        return grade(student.midterm, student.final, 0);
    } else {
        return grade(student.midterm, student.final, median(nonzero));
    }

}

bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

bool pgrade(const Student_info& s)
{
    return !fgrade(s);
}

void write_analysis(ostream& out, const string& name, double analysis(const vector<Student_info>&),
                    const vector<Student_info>& did, const vector<Student_info>& didnt)
{
    out << name << ": median(did) = " << analysis(did) << ", median(didnt) = " << analysis(didnt) << endl;
}

double average(const vector<double>& hw)
{
    return std::accumulate(hw.begin(), hw.end(), 0.0) / hw.size();
}



double average_grade(const Student_info& s)
{
    return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    transform(students.begin(), students.end(),
              back_inserter(grades), average_grade);
    return median(grades);
}

vector<Student_info> extract_fails(std::vector<Student_info>& students)
{
    vector<Student_info> fails;
    remove_copy_if(students.begin(), students.end(), back_inserter(fails), pgrade);
    students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());
    return fails;
}
