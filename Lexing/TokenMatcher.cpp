#pragma once
#include "ParseLexing.hpp"
lex::Pairs lex::TokenMatcher(std::vector<std::string> lexemes) {
	lex::Pairs ret;
	auto Tokens = lex::Tokens;//including a header twice creates the same variable twice.
	//to guard against that use the const/constexpr keyword.
	for (auto lexeme : lexemes) {
		if (Tokens[lexeme] != 0) {
			ret.emplace_back(lexeme, Tokens[lexeme]);
		}
		else {
			bool early_break = false;
			for (unsigned int x = 0; x < lexeme.length(); x++) {
				if (lexeme[x] >= '0' and lexeme[x] <= '9') {

				}
				else {
					early_break = true;
					break;
				}
			}
			if (early_break) {
				ret.emplace_back(lexeme, lex::WORD);
			}
			else {
				ret.emplace_back(lexeme, lex::NUMBER);
			}
		}

	}
	return ret;
};