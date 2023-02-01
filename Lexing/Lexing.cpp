// Lexing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
std::string SingleCharacterSep = "=+-/*[]{}().";

std::vector<std::string> CheckChar(std::string const input) {
    std::string buffer;
    std::vector<std::string> ret;

    bool early_break = false;
    for (auto character : input) {
        early_break = false;
        for (auto illegal : SingleCharacterSep) {
            if (character == illegal) {
                if (buffer.length() != 0) {
                    ret.push_back(buffer);
                }
                buffer = character;
                ret.push_back(buffer);
                early_break = true;
                buffer = "";
                break;
            }
        }
        if (!early_break) {
            if (character != ' ' and character != '\n') {
                buffer += character;

            }
            else {
                ret.push_back(buffer);
                buffer = "";
            }
        }
    }
    if (buffer.length() != 0) {
        ret.push_back(buffer);
    }
    return ret;
}
char fds432af34;
int main()
{
    std::vector<std::string> Lexemes;
    std::string input;
    std::getline(std::cin, input);
    Lexemes = CheckChar(input);
    for (auto x : Lexemes) {
        std::cout << x << "\n";
    }

    std::cout << "Hello World!\n";
}
