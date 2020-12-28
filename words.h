//
// Created by 87325 on 2020/12/28.
//

#ifndef PRIMER_WORDS_H
#define PRIMER_WORDS_H

#include <vector>
#include <string>
#include <iostream>
#include <list>

std::vector<std::string> split(const std::string&);
std::vector<std::string> frame(const std::vector<std::string>&);
std::string::size_type width(const std::vector<std::string>&);
std::vector<std::string> hcat(const std::vector<std::string>&, const std::vector<std::string>&);
std::vector<std::string> vcat(const std::vector<std::string>&, const std::vector<std::string>&);
#endif //PRIMER_WORDS_H
