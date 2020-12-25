#include <iostream>
#include "reg_exp.h"


int RegExpAnalyzer::check_letter_k_times() {

    check_correct_letter(letter);

    for (char current_symbol : reg_exp) {
        check_correct_sym(current_symbol);
        add_to_stack(current_symbol);
    }

    check_stack_size(count_stack, 1, true);

    std::vector<int> last = count_stack.top();
    return last[k];
}


void RegExpAnalyzer::add_to_stack(char current_symbol) {

    std::vector<int> new_word(k + 1, 0);

    if (alphabet.find(current_symbol) != alphabet.end()) {
        add_symbol(current_symbol, new_word);
    } else {
        make_operation(current_symbol, new_word);
    }

    count_stack.push(new_word);
}


void RegExpAnalyzer::add_symbol(char current_symbol, std::vector<int>& new_word) const {

    if (current_symbol == letter) {
        if (k > 0) {
            new_word[1] = 1;
        }
    } else {
        new_word[0] = 1;
    }
}


void RegExpAnalyzer::make_operation(char operation, std::vector<int>& new_word) {

    if (operation == '*') {
        check_stack_size(count_stack, 1);
        std::vector<int> last = count_stack.top();
        count_stack.pop();
        new_word[0] = 1;
        for (int j = 1; j < k + 1; ++j) {
            if (last[j]) {
                for (int i = 1, step = j, index = j; index < k + 1; ++i) {
                    if (new_word[index] == 0 || new_word[index] > last[j] * i) {
                        new_word[index] = last[j] * i;
                    }
                    index += step;
                }
            }
        }
    } else {
        check_stack_size(count_stack, 2);

        std::vector<int> last = count_stack.top();
        count_stack.pop();
        std::vector<int> second_to_last = count_stack.top();
        count_stack.pop();

        if (operation == '.') {
            for (unsigned int j = 0; j < k + 1; ++j) {
                for (unsigned int t = 0; t < k + 1; ++t) {
                    if ((j + t < k + 1) && (last[j] > 0) && (second_to_last[t] > 0)) {
                        if (new_word[j + t] == 0 || new_word[j + t] > last[j] + second_to_last[t]) {
                            new_word[j + t] = last[j] + second_to_last[t];
                        }
                    }
                }
            }
        } else { // operation == '+'
            for (unsigned int j = 0; j < k + 1; ++j) {
                if (new_word[j] == 0 or new_word[j] > std::min(last[j], second_to_last[j])) {
                    new_word[j] = std::min(last[j], second_to_last[j]);
                }
            }
        }
    }
}