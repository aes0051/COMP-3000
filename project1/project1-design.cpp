// Name: Annie Sauer
// filename: project1-design.cpp
// Development Environment: vim, g++, linux
// Compile: g++ -o project1 project1-design.cpp
// Sample usage: ./project1

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <string>

using namespace std;

//Structs for the scoreboard
struct ScoreNode
{
	string name;
	int score;
};

typedef ScoreNode* ScoreNodePtr;
typedef unsigned short u_short;

struct ScoreBoard
{
	u_short num_of_scores;
	ScoreNodePtr my_score_array = new ScoreNode[100];
	~ScoreBoard()
		{
		delete[] my_score_array;
		}
};
//Functions for the scoreboard
ScoreBoard game_scoreboard = {0, NULL};
void ViewScores(Scoreboard scoreboard);
int LoadScores (Scoreboard& scoreboard, const char scoreboard_file[]);
int SaveScores (Scoreboard scoreboard, const char scoreboard_file[]);

//Class for the player
class Player 
{
public: //functions
	void SetMoney(int randomMoney); //Money will be a random value between 15 and 30
	void SetTime(int randomTime); //Time will be a random value between 20 and 30
	void SetIntel(int randomIntel); //Intel will be a random value between 15 and 30
	void SetSteps(int randomSteps);//Steps will be a random value between 20 and 30
	int GetMoney ();
	int GetTime();
	int GetIntel();
	int GetSteps();
private: //variables
	int money;
	int time;
	int intel;
	int steps;
};

void Player::SetMoney(int randomMoney)
{
	money = randomMoney;
	return;
}

void Player::SetTime(int randomTime);
{
	time = randomTime;
	return;
}

void Player::SetIntel (int randomIntel)
{
	intel = randomIntel;
	return;
}

void Player::SetSteps (int randomSteps)
{
	steps = randomSteps;
	return;
}

int Player::GetMoney()
{
	return money;
}

int Player::GetTime()
{
	return time;
}

int Player::GetIntel()
{
	return intel;
}

int Player::GetSteps()
{
	return steps;
}

class Menu
{
public:
	void InitializeMenu();
	void DisplayMenu();
	void AddMenuOption();
	void SelectMenuOption();
private:
	string menu_name;
	int num_of_options;
	int max_menu_size;
}; //Using this menu class will enable someone to update the menu without changing the source code

class Puzzle
{
public: 
	int penalty;
	int reward;
};

//FUNCTION PROTOTYPES

void Print_menu();
	// Prints the menu options
	// No test case required because it is a simple function

void invalid_menu_input(string input);
	//Run this function if the user input does not match any menu options
	//Prompt user for another input

bool all_positive(int money, int time, int intelligence);
	// returns true if all three values are above zero
	// used to indicate when the player has lost, when the function returns false

void test_all_positive()
{
	//Case 1, all positive	
	assert(all_positive(1,1,1) == true);
	//Case 2, money zero
	assert(all_positive(0,1,1) == false);
	//Case 3, time zero
	assert(all_positive(1,0,1) == false);
	//Case 4, intelligence zero
	assert(all_positive(1,1,0) == false);
	//Case 5, all zero
	assert(all_positive(0,0,0) == false);
return;
}

void read_technical_papers (int& intelligence, int& time, int reward =(rand()%10)+1);
	//Player does not move, gains intelligence, uses time
	//Last parameter is only specified for test cases

void test_read_technical_papers ()
{
	int intel = 4;
	int time = 4;
	//Case 1, subtract 1 time, add 2 intel
	read_technical_papers(intel, time, 2);
	assert(intel == 6 && time == 3);
	intel = 4;
	time = 4;
	//Case 2, subtract 1 time, add 9 intel
	read_technical_papers(intel, time, 9);
	assert(intel == 13 && time == 3);
return;
}
	
void search_for_loose_change(int& money, int& time, int reward=rand()%10+1);
	//Player does not move, gains money, loses time
	//Last paratmer is only specified for test cases

void test_search_for_loose_change()
{
	int money = 4;
	int time = 4;
	//Case 1, subtract 1 time, add 1 money
	search_for_loose_change(money, time, 1);
	assert(money == 5 && time == 3);
	money = 4;
	time = 4;
	//Case 2, subtract 1 time, add 7 money
	search_for_loose_change(money, time, 7);
	assert(money == 11 && time == 3);
return;
}

void View_character (int money, int intelligence, int time, int steps);
	//Prints the player's current stats and location
	//No test case required because it is a simple function

void Quit_game();
	//quits the game when called in the main function
	//Does not need test driver, can be tested by simply calling function in main

void Puzzle(int& money, int& intelligence, int& time, int input, int a=rand()%50, int b=rand()%50);
	//the puzzle adds integers a and b and asks the user to input the sum
	//correct answer adds 3 money and 3 time
	//incorrect answer subtracts 3 money and 3 intelligence
	//last two parameters will only be used for the test driver

void test_puzzle()
{
	int money = 4;
	int intelligence = 4;
	int time = 4;
	//Case 1, correct answer, add 3 money, add 3 time
	Puzzle(money, intelligence, time, 10, 5, 5);
	assert (money == 7 && intelligence == 4 && time == 7);
	money = 4;
	intelligence = 4;
	time = 4;
	//Case 2, incorrect answer, subtract 3 money, subtract 3 intelligence
	Puzzle(money, intelligence, time, 12, 5, 5);
	assert (money == 1 && intelligence == 1 && time == 4);
return;
}

void Move (int& money, int& intelligence, int& time, int& steps, int random=rand()%100);
/* subtract 1 from steps
 * 25% chance of nothing happening
 * 30% chance of encountering a puzzle, run puzzle function
 * 10% chance of encountering a professor, lose time, gain intelligence
 * 10% chance of encountering a grad student, lose time
 * 15% chance of getting grunt work, lose time, lose intelligence
 * 10% chance of grading papers, lose time, gain money
 *
 * last parameter is used for test cases
 * */

void test_move()
{
	int money = 4;
	int intelligence = 4;
	int time = 4;
	int steps = 4;
	//Case 1, nothing happens, lose 1 step
	Move (money, intelligence, time, steps, 15);
	assert (money==4 && intelligence==4 && time==4 && steps==3);
	money = 4;
	intelligence = 4;
	time = 4;
	steps = 4;
	//Case 2, encounter a professor, lose 1 time, gain 3 intel, lose 1 step
	Move (money, intelligence, time, steps, 60);
	assert (money==4 && intelligence==7 && time==3 && steps==3);
	money = 4;
	intelligence = 4;
	time = 4;
	steps = 4;
	//Case 3, encounter a grad student, lose 2 time, lose 1 step
	Move (money, intelligence, time, steps, 70);
	assert (money==4 && intelligence==4 && time==2 && steps==3);
	money = 4;
	intelligence = 4;
	time = 4;
	steps = 4;
	//Case 4, grade papers, lose 1 time, gain 3 money, lose 1 step
	Move (money, intelligence, time, steps, 95);
	assert (money==7 && intelligence==4 && time==3 && steps==3);
return;
}

int calculate_score (int time, int money, int intelligence);
	// multiplies all three values to calculate the total score 	

void test_calculate_score()
{
	//Case 1
	assert (calculate_score(1,1,1)==1);
	//Case 2
	assert (calculate_score(2,5,3)==30);
	//Case 3
	assert (calculate_score(4,4,2)==32);
return;
}	









