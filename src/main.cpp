#include <iostream>
#include <string>
#include "reg_exp.h"

int main() {
    std::string reg_exp;
    char letter;
    unsigned int k;
    std::cin >> reg_exp >> letter >> k;

    auto* analyzer = new RegExpAnalyzer(reg_exp, letter, k);

    try {
        int result = analyzer->check_letter_k_times();
        if (result != 0) {
            std::cout << result << '\n';
        } else {
            std::cout << "INF" << '\n';
        }
    } catch (const std::runtime_error& error) {
        std::cout << "ERROR" << '\n';
    }

    return 0;
}