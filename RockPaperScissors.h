
#pragma once
#include <string>
using namespace std;

class RockPaperScissors
{
public:
	void Header(); // Method to construct the header of the game, handle invalid input checking, and output the game to the console.
	void Body(); // Method to handle majority of the games content, including the invalid input checking, assignment of the computer's option choice, and handle playing again.
	string Result(); // String method that calculates the result of the game after player and computer have chosen options.
private:
	string choice, cpuChoice;
	bool again;
	char yesOrNo;
};