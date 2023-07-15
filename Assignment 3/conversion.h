//Name: Gurekpal Bhullar
//Email: gsbzm8@umsystem.edu
#pragma once

#include <string>

//Class for expressionManager
class ExpressionManager {
public:
	bool isBalanced(const std::string& expression);
	int getPrecedence(char userOperator);
	std::string infixToPostfix(const std::string& expression);
};