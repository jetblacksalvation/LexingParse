#include "ParseLexing.hpp"

//Byte offsets by type code

long long StackAllocation = 0;//This number represents how many bytes of local memory has been allocated 
//variable lifetimes is going to be a pain
std::unordered_map<std::string, unsigned long long> ByteOffsets{
	{"char", 1},
	{"int", 2}
};
//memory allocation - creating a new variables alliases that variables with x address on the stack

std::unordered_map<std::string, unsigned long long> VariableOffsets;
//offseting variables addresses is going to be a pain 

bool isVariableDeclaration(std::vector<std::pair<std::string, int>> sentance) {
	//both reads a sentance, and handles it. 
	//variable is registered, and pushed onto the stack
	for (auto it : sentance) {
		std::cout << it.second<<"\n";
	}
	std::cout << sentance.size()<<"is size\n";

	if (sentance.size() == 3) {
		if (sentance[0].second == lex::TYPE && sentance[1].second == lex::WORD && sentance[2].second == lex::SEMICOLON ) {
			std::cout << sentance[1].first << " = identifier\n";
			std::cout << sentance[1].first << " has type :" << sentance[0].first << '\n';
			
			VariableOffsets[sentance[1].first] = StackAllocation;//Adds a new key-value pair, this first = identifier, second = stack address offset 
			StackAllocation += ByteOffsets[sentance[0].first];//offsets the next stack variable by how many bytes the first object uses for data
			std::cout << VariableOffsets[sentance[1].first];
		}
	}
	
	return true;
};


void lex::ReadStatement(lex::Statements_Ty sentances) {
	for (auto sentance : sentances) {
		isVariableDeclaration(sentance);
	}

}