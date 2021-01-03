//
// Created by Administrator on 2021/1/1.
//

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::back_inserter;
using std::transform;

#include "Student_info.h"
#include "grade.h"
#include <iostream>
using std::cout; using std::endl;
using std::ostream;
#include <fstream>
using std::ifstream;



void write_analysis(ostream& out, const string& name, double method(const Student_info&),
                    const vector<Student_info>& did, const vector<Student_info>& didnt)
{
    out<<name<<"median(did)"<<analysis(did, method) << ", median(didnt)"<< analysis(didnt, method);
}

double optimistic_median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
    return median(grades);
}

vector<Student_info> extract(vector<Student_info>& students, bool criteria(const Student_info&))
{
    auto iter = stable_partition(students.begin(), students.end(), criteria);
    vector<Student_info> extracted(iter, students.end());
    students.erase(iter, students.end());

    return extracted;
}

int test_analysis(string file)
{
    ifstream in;
    vector<Student_info> students;
    vector<Student_info> did;
    vector<Student_info> didnt;
    in.open(file);

    read(in, students);
    for (const auto & student : students) {
        if (did_all_hw(student)) {
            did.push_back(student);
        } else {
            didnt.push_back(student);
        }
    }



    if (did.empty())
    {
        cout << "No student did all the homework!" << endl;
        return 1;
    }

    if (didnt.empty())
    {
        cout << "Every student did all the homework!" << endl;
        return 1;
    }

    write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);

    write_analysis(cout, "median", grade_aux, did, didnt);
    write_analysis(cout, "average", average_grade, did, didnt);
    return 0;
}

int test_general_extract(string file)
{
    vector<Student_info> did, didnt;
    Student_info student;

    ifstream infile;

    infile.open(file);
    read(infile, did);

    didnt = extract(did, did_all_hw);

    if (did.empty())
    {
        cout << "No student did all the homework!" << endl;
        return 1;
    }

    if (didnt.empty())
    {
        cout << "Every student did all the homework!" << endl;
        return 1;
    }
    write_analysis(cout, "median", grade_aux, did, didnt);
    write_analysis(cout, "average", average_grade, did, didnt);
    write_analysis(cout, "median of homework turned in", optimistic_median, did, didnt);
    return 0;
}

int ex6_8()
{
    return test_general_extract("C:\\Users\\Administrator\\Desktop\\myproject\\Cpp_primer\\students.txt");
}