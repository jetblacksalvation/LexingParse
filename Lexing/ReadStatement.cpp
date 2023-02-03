#include "ParseLexing.hpp"
#include "StatementTemplates.hpp"

bool isVariableDeclaration(std::vector<std::pair<std::string, int>> sentance) {
	if (sentance.size() != 5) {
		return false;
	}
	if (sentance[1].second == lex::WORD) {
		std::cout << sentance[1].first << " with the type " << sentance[0].first << std::endl;
		std::cout << "with a value of " << sentance[3].first << std::endl;
	}
};

void ReadStatement(lex::Statements_Ty sentances) {
	for (auto sentance : sentances) {
		isVariableDeclaration(sentance);
	}

}