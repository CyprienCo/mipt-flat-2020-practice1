#pragma once
#include <stack>
#include <utility>
#include <vector>
#include <string>
#include "checkers.h"

class RegExpAnalyzer {
public:
    RegExpAnalyzer(std::string  reg_exp, char letter, unsigned int k) :
            reg_exp(std::move(reg_exp)), letter(letter), k(k), count_stack() {}

    int check_letter_k_times();

    void add_to_stack(char current_symbol);
    void add_symbol(char current_symbol, std::vector<int>& new_word) const;
    void make_operation(char operation, std::vector<int>& new_word);
private:
    char letter;
    unsigned int k;
    std::string reg_exp;

    stack_of_vectors count_stack;
};