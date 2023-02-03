#include "ParseLexing.hpp"

lex::Statements_Ty lex::TokenIntoStatements(lex::Pairs const Tokens) {
	lex::Statements_Ty ret{};
	//seperate tokens into lists of statements, these statements are seperated by semicolons 
	std::vector<std::pair<std::string, int>> buffer;
	for (unsigned int count = 0; count < Tokens.size(); count++) {
		if (Tokens[count].second == SEMICOLON) {
			ret.push_back(buffer);
			buffer.clear();
		}
		else {
			buffer.push_back(Tokens[count]);
		}
	}
	return ret;

};