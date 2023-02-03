// Lexing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ParseLexing.hpp"

/*
	std::vector<std::string> CheckChar(std::string const input);// put into TokenMatcher -
   //parses strings into Lexemes/Words with no applied information
	Pairs TokenMatcher(std::vector<std::string> lexemes);//put into TokenIntoStatement
   //Token matcher returns a vector of Pairs. The first value stores the string, the second the code.
   //It's done like this so that the information doesn't get lost. I could've used an unorderedmap/hashmap
	Statements_Ty TokenIntoStatements(Pairs const Tokens);//put into ReadStatement
   //Using semicolons, Token Into Statements seperates statements into a vector of pairs/strings.
   //this is only really done this way because variables and other structures have unique identifiers.
	void ReadStatement(Statements_Ty sentances);
	//ReadStatement is the Abstract Syntax Tree. There will be functions/data that is ONLY
*/
int main()
{
    std::vector<std::string> Lexemes;
    std::string input;
    std::getline(std::cin, input);
	//auto bruh = lex::CheckChar(input);
	//for (auto it : bruh) {
	//	std::cout << it<<"\n";
	//}
	lex::ReadStatement(lex::TokenIntoStatements( lex::TokenMatcher(lex::CheckChar(input))));


}
