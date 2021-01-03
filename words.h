//
// Created by 87325 on 2020/12/28.
//

#ifndef PRIMER_WORDS_H
#define PRIMER_WORDS_H

#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <map>



typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

std::vector<std::string> split(const std::string&);
std::vector<std::string> frame(const std::vector<std::string>&);
std::string::size_type width(const std::vector<std::string>&);
std::vector<std::string> hcat(const std::vector<std::string>&, const std::vector<std::string>&);
std::vector<std::string> vcat(const std::vector<std::string>&, const std::vector<std::string>&);
bool equal(const std::string& );
std::vector<std::string> find_urls(const std::string&);
std::map<std::string, std::vector<int>> xref(std::istream& in, std::vector<std::string> find_words(const std::string&)=split);
bool bracket(const std::string& s);
Grammar read_grammar(std::istream& in);
void gen_aux(const Grammar& g, const std::string& word, std::vector<std::string>& ret);
#endif //PRIMER_WORDS_H
