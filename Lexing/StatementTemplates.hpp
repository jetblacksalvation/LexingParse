#pragma once
#include "ParseLexing.hpp"
// goal- create functions that read statements, these functions will write out files/maybe invoke a 
//python program and redirect output from stdout into the CLAs of the python program?
std::array<int, 5> const VariableDeclaration = { lex::INT , lex::WORD, lex::ASSIGNMENT, lex::NUMBER, lex::SEMICOLON };