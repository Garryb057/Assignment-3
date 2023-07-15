//Name: Gurekpal Bhullar
//Email: gsbzm8@umsystem.edu
#include "conversion.h"
#include <stack>

//Function to determine if the inputed expression has a balanced number of parenthesis
bool ExpressionManager::isBalanced(const std::string& expression) {
	std::stack<char> stack1;													//Sets a stack of characters

	for (char character : expression) {											//Loops while there is a character in the expression
		if (character == '(' || character == '[' || character == '{') {			//If the character is (, [, {
			stack1.push(character);												//The character gets pushed onto the stack
		}
		else if (character == ')' || character == ']' || character == '}') {	//Runs if the character is ), ], }
			if (stack1.empty() || stack1.top() != character - 1) {				//Runs if the stack is empty and if the top of the stack and one below it is not the opening parenthesis
				return false;													//Returns false
			}
			stack1.pop();														//Pops top item from stack
		}
	}
	return stack1.empty();														//Returns stack is empty. If it is then the parenthesis are balanced
}

//Function to get the precedence or order of operations for the operators 
int ExpressionManager::getPrecedence(char userOperator) {
	if (userOperator == '*' || userOperator == '/' || userOperator == '%') {	//If the operator is multiplication, division, or modulus the function returns 2
		return 2;
	}
	else if (userOperator == '+' || userOperator == '-') {						//If the operator is addition, or subtraction, the function returns 1
		return 1;
	}
	else {																		//All other cases it returns 0
		return 0;																
	}
}

//Function to convert an infix expression to a postfix expression
std::string ExpressionManager::infixToPostfix(const std::string& expression) {
	std::string postfix = "";													//Sets a postfix string to empty
	std::stack<char> stack2;													//Sets a stack of character

	for (char character : expression) {											//Loops while there is a character in the expression
		if (character == ' ' || character == '\t') {							//Continues the loop if the character is a blank space or tab
			continue;
		}
		else if (character == '(' || character == '[' || character == '{') {	//Pushes the character onto the stack if the character is (, [, {
			stack2.push(character);
		}
		else if (character == ')' || character == ']' || character == '}') {	//Runs if the character is a closing parenthesis
			while (!stack2.empty() && stack2.top() != '(' && stack2.top() != '[' && stack2.top() != '{') {		//Loops while the stack is full, the top of the stack isn't an opening parenthesis
				postfix += stack2.top();										//Adds the character at the top of the stack to the postfix string
				stack2.pop();													//Removes the top item from the stack
			}
			if (!stack2.empty() && ((character == ')' && stack2.top() == '(') || (character == ']' && stack2.top() == '[') || (character == '}' && stack2.top() == '{'))) { //If the stack is full and the character is any sort of parenthesis, it pops the character from the stack
				stack2.pop();
			}
			else {																//Else it returns an empty string
				return "";
			}
		}
		else if (character == '+' || character == '-' || character == '*' || character == '/' || character == '%') {			//If the character is an operator
			while (!stack2.empty() && stack2.top() != '(' && stack2.top() != '[' && stack2.top() != '{' && getPrecedence(character) <= getPrecedence(stack2.top())) {	//Loops while the stack is full, and the top of the stack is not an opening parenthesis, 
																																										//and the value returned from the getPrecedence function is less than or equal to the 
																																										//operator at the top of the stack
				postfix += stack2.top();										//Adds the character at the top of the stack to the postFix string
				stack2.pop();													//Removes the top item from the stack
			}
			stack2.push(character);												//Adds the character to the stack
		}
		else if (isalnum(character)) {											//If the character is alpha numeric, it gets added to the postfix string
			postfix += character;
		}
	}

	while (!stack2.empty()) {													//Loops while the stack is full
		if (stack2.top() == '(' || stack2.top() == '[' || stack2.top() == '{') {	//If the item at the top of the stack is an opening parenthesis, it returns an empty string
			return "";
		}
		postfix += stack2.top();												//The character at the top of the stack is added to the postFix string
		stack2.pop();															//The item at the top of the stack is removed
	}
	
	return postfix;																//Returns the postFix string
}