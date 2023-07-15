//Name: Gurekpal Bhullar
//Email: gsbzm8@umsystem.edu
#include <iostream>
#include "conversion.h"
#include "queue.h"
#include "function.h"

int main() {
	//Loops until user quits out of the program
	while (true) {
		int choice = mainMenu();																		//Takes input from user for the main Menu
		if (choice == 1) {																				//Runs if user's input is 1
			ExpressionManager expressionManager;														//Sets an object expression manager
			std::string infixExpression;																//Sets a string infixExpression

			//Takes in input for infix expression
			std::cout << "Please enter an infix expression: ";
			std::cin.ignore();
			getline(std::cin, infixExpression);

			//If the user given expression is not balanced this code runs
			if (!expressionManager.isBalanced(infixExpression)) {
				std::cout << "Invalid expression" << std::endl;
			}
			else {
				std::string postfixExpression = expressionManager.infixToPostfix(infixExpression);		//Sets string postfixExpression to the function call infixToPostfix's return value
				std::cout << "Postfix expression: " << postfixExpression << std::endl;					//Prints the postfix expression
			}
			continue;
		}

		else if (choice == 2) {																			//Runs if user's input is 2 from mainMenu function
			Queue queue;																				//Sets up the Queue object
			while (true) {																				//Loops until the break statement
				int qChoice = qMenu();																	//Takes input from user for Queue menu
				if (qChoice == 1) {																		//Runs if user's input is 1
					int item;																			//Sets integer type item
					std::cout << "What number would you like to add to the queue? ";					//Asks user for input on what they would like to add to queue
					std::cin >> item;
					queue.enQueue(item);																//Calls function enQueue and adds it to the queue
				}
				else if (qChoice == 2) {																//Runs if user's input is 2 from Queue Menu
					int what = queue.deQueue();															//Sets what to the item that was removed from Queue and also removes that item from the Queue
					std::cout << "Item: " << what <<  " was removed" << std::endl;						//Prints out what item was deleted from the queue
				}
				else if (qChoice == 3) {																//Runs if user's input is 3 for Queue menu
					std::cout << "Front Item: " << queue.front() << std::endl;							//Prints out the first item in the queue
				}
				else if (qChoice == 4) {																//Runs if user's input is 4 from the Queue menu
					int empty = queue.isEmpty();														//Sets empty int to what value is returned when isEmpty function is called
					if (empty == 1) {																	//If the function returns true then it is empty
						std::cout << "Queue is empty" << std::endl;
					}
					else {																				//Else it is not empty
						std::cout << "Queue is not empty" << std::endl;
					}
				}
				else if (qChoice == 5) {																//Runs if user's input is 5 from Queue Menu
					int size = queue.getSize();															//Sets size integer to the integer that is returned from getSize function
					std::cout << "The size of the queue is " << size << " element(s)" << std::endl;		//Prints the size of the queue
				}
				else if (qChoice == 6) {																//Runs if the user's input is 6 from Queue Menu
					std::cout << "Goodbye!!!" << std::endl;												
					break;																				//Breaks the loop
				}
				else {
					std::cout << "Invalid Input. Please Try Again." << std::endl;						//User inputed invalid input and restarts the loop
					continue;
				}
			}
		}
		else if (choice == 3) {																			//User input 3 from MainMenu function
			std::cout << "Goodbye!!!" << std::endl;
			break;																						//Breaks the loop and quits out of the program
		}
		else {
			std::cout << "Invalid Input. Please Try Again." << std::endl;								//User inputed an invalid input and the loop restarts
			continue;
		}
	}
}