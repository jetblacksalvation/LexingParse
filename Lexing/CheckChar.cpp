#pragma once
#include "ParseLexing.hpp"

std::string SingleCharacterSep = "=+-/*[]{}().,;<>";

std::vector<std::string> lex::CheckChar(std::string const input) {
    std::string buffer;
    std::vector<std::string> ret;

    bool early_break = false;
    for (auto character : input) {
        early_break = false;
        for (auto illegal : SingleCharacterSep) {
            if (character == illegal) {
                if (buffer.length() != 0) {
                    ret.push_back(buffer);
                    buffer = "";
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
                if (buffer != "") {
                    ret.push_back(buffer);
                }

                buffer = "";
            }
        }

    }

    if (buffer.length() != 0) {

        ret.push_back(buffer);
    }
    return ret;
}