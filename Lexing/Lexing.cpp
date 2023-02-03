// Lexing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ParseLexing.hpp"
int main()
{
    std::vector<std::string> Lexemes;
    std::string input;
    std::getline(std::cin, input);
    Lexemes = lex::CheckChar(input);
    for (auto x : Lexemes) {
        std::cout << x << "\n";
    }

    std::cout << "Hello World!\n";
}
