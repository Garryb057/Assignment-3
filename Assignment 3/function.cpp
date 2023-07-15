//Name: Gurekpal Bhullar
//Email: gsbzm8@umsystem.edu
#include "function.h"
#include <iostream>

//Main Menu for the program
//Determines which part of the assignment is run
int mainMenu() {
	int choice;
	std::cout << std::endl;
	std::cout << "Welcome to Assignment 3" << std::endl;
	std::cout << "1. Expression Manager" << std::endl;
	std::cout << "2. Queue" << std::endl;
	std::cout << "3. Quit" << std::endl;
	std::cout << "What part of the assignment would you like to do? ";
	std::cin >> choice;
	return choice;
}
//Queue menu for the program
//Determines what you do with the Queue based on the user's input from this menu
int qMenu() {
	int qChoice;
	std::cout << std::endl;
	std::cout << "Welcome to the Queue" << std::endl;
	std::cout << "1. Enter an item into the queue" << std::endl;
	std::cout << "2. Remove item from queue" << std::endl;
	std::cout << "3. Print first item in queue" << std::endl;
	std::cout << "4. Check if Queue is empty" << std::endl;
	std::cout << "5. Get size of Queue" << std::endl;
	std::cout << "6. Quit" << std::endl;
	std::cout << "What would you like to do? ";
	std::cin >> qChoice;
	return qChoice;
}