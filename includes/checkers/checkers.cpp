#include "checkers.h"

void check_correct_letter(char letter) {
    if (letter == '1') {
        throw std::runtime_error("ERROR");
    }
    if (alphabet.find(letter) == alphabet.end()) {
        throw std::runtime_error("ERROR");
    }
}

void check_correct_sym(char symbol) {
    if (alphabet.find(symbol) == alphabet.end()) {
        if (operations.find(symbol) == operations.end()) {
            throw std::runtime_error("ERROR");
        }
    }
}

void check_stack_size(const stack_of_vectors& stack, size_t size, bool equality) {
    if (equality) {
        if(stack.size() != size) {
            throw std::runtime_error("ERROR");
        }
    } else if (stack.size() < size) {
        throw std::runtime_error("ERROR");
    }
}
