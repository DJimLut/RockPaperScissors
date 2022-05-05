
#include "RockPaperScissors.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string choice, cpuChoice;
bool again = false;
char yesOrNo;

void RockPaperScissors::Header()
{
	cout << "==|ROCK, PAPER, SCISSORS!|==" << endl << "Start? (Y/N): ";
	cin >> yesOrNo;
	yesOrNo = toupper(yesOrNo); //This is for case insensitivity and is used later on as well.
	
	while ((yesOrNo != 'Y') && (yesOrNo != 'N'))
	{
		cout << "Invalid input, try again." << endl << "Start? (Y/N): ";
		cin >> yesOrNo;
		yesOrNo = toupper(yesOrNo);
	}
	
	if (yesOrNo == 'Y')
	{
		again = true;
		while (again)
		{
			Body();
		}
		cout << "Goodbye." << endl;
	}
	
	else if (yesOrNo == 'N')
	{
		cout << "Goodbye." << endl;
		exit (EXIT_FAILURE);
	}
}

void RockPaperScissors::Body()
{
	cout << "Choose one, then type your choice." << endl << "ROCK, PAPER, or SCISSORS: ";
	cin >> choice;
	transform(choice.begin(), choice.end(), choice.begin(), ::toupper);
	
	switch (rand() % 2) // Running a random check for which option the cpu will choose.
	{
		case 0:
			cpuChoice = "ROCK";
			break;
		case 1:
			cpuChoice = "PAPER";
			break;
		case 2:
			cpuChoice = "SCISSORS";
			break;
		default:
			break;
	}
	
	while ((choice != "ROCK") && (choice != "PAPER") && (choice != "SCISSORS"))
	{
		cout << "Invalid input, try again." << endl << "ROCK, PAPER, or SCISSORS: ";
		cin >> choice;
		transform(choice.begin(), choice.end(), choice.begin(), ::toupper);
	}
	
	cout << Result() << endl; // Calculating result
	
	cout << "==|ROCK, PAPER, SCISSORS!|==" << endl << endl << "Again? (Y/N): ";
	cin >> yesOrNo;
	yesOrNo = toupper(yesOrNo);
	
	if (yesOrNo == 'Y')
		cout << endl;
	else if (yesOrNo == 'N')
		again = false;
	else
	{
		cout << "Invalid input, Goodbye." << endl;
		exit (EXIT_FAILURE);
	}
}

string RockPaperScissors::Result() // Iterating through all the outcomes to calculate and print the result.
{
	if ((choice == "ROCK") && (cpuChoice == "SCISSORS"))
		return "You Won!";
	else if ((choice == "ROCK") && (cpuChoice == "PAPER"))
		return "You Lost!";
	else if ((choice == "ROCK") && (cpuChoice == "ROCK"))
		return "Tie!";
	else if ((choice == "SCISSORS") && (cpuChoice == "SCISSORS"))
		return "Tie!";
	else if ((choice == "SCISSORS") && (cpuChoice == "PAPER"))
		return "You Won!";
	else if ((choice == "SCISSORS") && (cpuChoice == "ROCK"))
		return "You Lost!";
	else if ((choice == "PAPER") && (cpuChoice == "SCISSORS"))
		return "You Lost!";
	else if ((choice == "PAPER") && (cpuChoice == "PAPER"))
		return "Tie!";
	else if ((choice == "PAPER") && (cpuChoice == "ROCK"))
		return "You Won!";
}