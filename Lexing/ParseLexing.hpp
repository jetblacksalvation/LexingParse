#ifndef lexable
#define lexable
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <unordered_map>
namespace lex {

	typedef std::vector<std::pair<std::string, int>> Pairs;
	typedef std::vector<std::vector<std::pair<std::string, int >>> Statements_Ty;
	enum {
	TYPE =1,
	CONDITIONAL,
	LBRACKET,
	RBRACKET,
	WORD,
	NUMBER,
	SEPERATOR,
	ASSIGNMENT,
	OPERATOR,
	CUR_R_BRKT,
	CUR_L_BRKT,
	SEMICOLON
	};
	const std::unordered_map<int, std::string>  TokenIdString{
	{TYPE, "type"},
	{CONDITIONAL, "conditional"},
	{LBRACKET, "lbracket"},
	{RBRACKET, "rbracket"},
	{OPERATOR, "operator"},
	{WORD, "word"},
	{NUMBER, "number"},
	{SEPERATOR, "seperator"},
	{ASSIGNMENT, "assignment"},
	{CUR_R_BRKT, "curl right bracket"},
	{CUR_L_BRKT, "curl left bracket"},
	{SEMICOLON, "semicolon"}
	};
	const std::unordered_map<std::string, int>  Tokens({
	{"int", TYPE},
	{"char", TYPE},
	{"if", CONDITIONAL},
	{",", SEPERATOR},
	{"=", ASSIGNMENT},
	{";", SEMICOLON},
	{"{", CUR_L_BRKT},
	{"}", CUR_R_BRKT},
	{"+", OPERATOR},
	{"-", OPERATOR}
	});

	//declarations
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
	//used by it. 

};
#endif
