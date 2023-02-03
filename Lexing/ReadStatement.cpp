#include "ParseLexing.hpp"

//Byte offsets by type code

long long StackAllocation = 0;//This number represents how many bytes of local memory has been allocated 
//variable lifetimes is going to be a pain
std::unordered_map<std::string, unsigned long long> ByteOffsets{
	{"char", 1},
	{"int", 2}
};
//memory allocation - creating a new variables alliases that variables with x address on the stack

std::vector<std::pair<std::string,long long>> VariableOffsets;
//offseting variables addresses is going to be a pain 

bool isVariableDeclaration(lex::Pairs sentance) {
	//both reads a sentance, and handles it. 
	//variable is registered, and pushed onto the stack
	//semicolons seperate statements, aka, they are stored within different indexes within sentances 
	if (sentance.size() == 2) {
		if (sentance[0].second == lex::TYPE && sentance[1].second == lex::WORD  ) {
			//std::cout << sentance[1].first << " = identifier\n";
			//std::cout << sentance[1].first << " has type :" << sentance[0].first << '\n';
			
			VariableOffsets.push_back({ sentance[1].first, StackAllocation });
			//Adds a new key-value pair, this first = identifier, second = stack address offset 
			StackAllocation += ByteOffsets[sentance[0].first];//offsets the next stack variable by how many bytes the first object uses for data
			//std::cout << VariableOffsets[sentance[1].first];//debugging stuff 
			
			return true;

		}
	}
	
	return false;
};
bool isIdentifierOperand(lex::Pairs sentance) {
	if (sentance.size() == 2) {
		bool is_in = false;
		for (auto it : VariableOffsets) {
			if (it.first == sentance[0].first) {
				is_in = true;
				break;
			}
		}
		if (is_in) {
			if (sentance[1].second == lex::OPERATOR) {
				std::cout << "doing an operation\n";
			}
		}

		//if (VariableOffsets[sentance[0].first] != "" && sentance[1].second == lex::OPERATOR) {
		//	std::cout << "is operand on varibale" << sentance[0].first << " \n";
		//}
		return false;
	}
	return false;
}

void lex::ReadStatement(lex::Statements_Ty sentances) {
	for (auto sentance : sentances) {
		if(isVariableDeclaration(sentance)){}
		else if(isIdentifierOperand(sentance)){}
	}

}