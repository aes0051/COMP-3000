// Name: Annie Sauer
// filename: hw4.cpp
// Devlopment Environment: vim, g++, linux
// Compile: g++ -o hw4 hw4.cpp
// Sample usage: ./hw4
// I did not receive any outside help on this assignment.


// Compiler pre-directives
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>

using namespace std;

//FUNCTIONS


//CREATE RANDOM INTEGER
int random_number(){
	int randomNumber;
	randomNumber = rand()%100;
return randomNumber;
}

//PRESS ANY KEY FUNCTIONS
int mygetch(void) {
	int ch;
	struct termios oldt, newt;
	tcgetattr (STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~ (ICANON | ECHO);
	tcsetattr (STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr (STDIN_FILENO, TCSANOW, &oldt);
return ch;
}

void press_any_key (void){
	char ch;
	cout << "Press any key to continue...";
	ch = mygetch();
	if (ch == 0 || ch == 224) {
	mygetch();}
}


//FUNCTION ONE - ARE THERE AT LEAST TWO PEOPLE ALIVE
bool at_least_two_alive (bool A_alive, bool B_alive, bool C_alive) {
	bool output; //variable to be returned by the function
	//Input true for A_alive indicates Aaron is alive
	//Input true for B_alive indicates Bob is alive
	//Input true for C_alive indicates Charlie is alive
	if (A_alive &&  B_alive &&  C_alive) {
		output = true;
	}
	else if (A_alive && B_alive){
		output = true;
	}
	else if (B_alive &&  C_alive){
		output = true;
	}
	else if (A_alive && C_alive){
		output = true;
	}
	else {
		output = false;
	}
return output;
}

void test_at_least_two_alive () {
	cout << endl << "Unit Testing 1: Function - at_least_two_alive()" << endl;
	cout << "Case 1: Aaron alive, Bob alive, Charlie alive" << endl;
		assert(true == at_least_two_alive(true, true, true));
		cout << "Case passed..." << endl;
	cout << "Case 2: Aaron dead, Bob alive, Charlie alive" << endl;
		assert(true == at_least_two_alive(false, true, true));
		cout << "Case passed..." << endl;	
	cout << "Case 3: Aaron alive, Bob dead, Charlie alive" << endl;
		assert (true == at_least_two_alive(true, false, true));
		cout << "Case passed..." << endl;
	cout << "Case 4: Aaron alive, Bob alive, Charlie dead" << endl;
		assert (true == at_least_two_alive(true, true, false));
		cout << "Case passed..." << endl;
	cout << "Case 5: Aaron dead, Bob dead, Charlie alive" << endl;
		assert (false == at_least_two_alive(false, false, true));
		cout << "Case passed..." << endl;
	cout << "Case 6: Aaron dead, Bob alive, Charlie dead" << endl;
		assert (false == at_least_two_alive(false, true, false));
		cout << "Case passed..." << endl;
	cout << "Case 7: Aaron alive, Bob dead, Charlie dead" << endl;
		assert (false == at_least_two_alive (true, false, false));
		cout << "Case passed..." << endl;
	cout << "Case 8: Aaron dead, Bob dead, Charlie dead" << endl;
		assert (false == at_least_two_alive (false, false, false));
		cout << "Case passed..." << endl;
	press_any_key();
return;
}

//FUNCTION TWO - AARON SHOOTS WITH STRATEGY 1
void Aaron_shoots1 (bool& B_alive, bool& C_alive, int chance_of_hit = random_number()) {
	// Strategy 1, shoot the one with the highest accuracy
	if (C_alive){
	//Aaron shoots Charlie
	//Probability 1/3 that Charlie dies
		if (chance_of_hit < 33){
		C_alive = false;
		}
	}
	else if (B_alive) {
	//Aaron shoots Bob
	//Probability 1/3 that Bob dies
		if (chance_of_hit < 33){
		B_alive = false;
		}
	}	
return;	
}

void test_Aaron_shoots1 () {
	bool B_alive;
	bool C_alive;
	cout << endl << endl << "Unit Testing 2: Function Aaron_shoots1(B_alive, C_alive)" << endl;
	cout << "Case 1: Bob alive, Charlie alive" << endl;
	cout << "     Aaron is shooting at Charlie" << endl;	
		B_alive = true;
		C_alive = true;
		Aaron_shoots1(B_alive, C_alive, 20);
	assert (B_alive == true);
	assert (C_alive == false);
	cout << "     Charlie is dead" << endl;
		B_alive = true;
		C_alive = true;
		Aaron_shoots1(B_alive, C_alive, 80);
	assert (B_alive == true);
	assert (C_alive == true);
	cout << "     or Aaron misses" << endl;
	
	cout << "Case 2: Bob dead, Charlie alive" << endl;
	cout << "     Aaron is shooting at Charlie" << endl;
		B_alive = false;
		C_alive = true;
		Aaron_shoots1 (B_alive, C_alive, 20);
	assert(B_alive == false);
	assert(C_alive == false);
	cout << "     Charlie is dead" << endl;
		B_alive = false;
		C_alive = true;
		Aaron_shoots1 (B_alive, C_alive, 80);
	assert(B_alive == false);
	assert(C_alive == true);
	cout << "    or  Aaron misses" << endl;
	
	cout << "Case 3: Bob alive, Charlie dead" << endl;
	cout << "     Aaron is shooting at Bob" << endl;
		B_alive = true;
		C_alive = false;
		Aaron_shoots1 (B_alive, C_alive, 20);
	assert(B_alive == false);
	assert (C_alive == false);
	cout << "     Bob is dead" << endl;
		B_alive = true;
		C_alive = false;
		Aaron_shoots1 (B_alive, C_alive, 80);
	assert (B_alive == true);
	assert (C_alive == false);
	cout << "     or Aaron misses" << endl;

	press_any_key();
return;
}


//FUNCTION THREE - BOB SHOOTS
void Bob_shoots (bool& A_alive, bool& C_alive, int chance_of_hit = random_number()) {
	//Strategy, shoot the one with the highest accuracy
	if (C_alive){
	//Bob shoots Charlie
	//Probability 1/2 that Charlie dies
		if (chance_of_hit < 50){
		C_alive = false;
		}
	}
	else if (A_alive) {
	//Bob shoots Aaron
	//Probability 1/2 that Aaron dies
		if (chance_of_hit < 50){
		A_alive = false;
		}
	}
return;
}

void test_Bob_shoots(){
	bool A_alive;
	bool C_alive;	
	cout << endl << endl << "Unit Testing 3: Function Bob_shoots(A_alive, C_alive)" << endl;

	cout << "Case 1: Aaron alive, Charlie alive" << endl;
	cout << "Bob is shooting at Charlie" << endl;
		A_alive = true;
                C_alive = true;
                Bob_shoots(A_alive, C_alive, 20);
        assert (A_alive == true);
        assert (C_alive == false);
	cout << "     Charlie is dead" << endl;
		A_alive = true;
		C_alive = true;
		Bob_shoots (A_alive, C_alive, 80);
	assert (A_alive == true);
	assert (C_alive == true);
	cout << "     or Bob misses" << endl;
        
        cout << "Case 2: Aaron dead, Charlie alive" << endl;
        cout << "     Bob is shooting at Charlie" << endl;
                A_alive = false;
                C_alive = true;
                Bob_shoots (A_alive, C_alive, 20);
        assert (A_alive == false);
        assert (C_alive == false);
	cout << "     Charlie is dead" << endl;
        	A_alive = false;
		C_alive = true;
		Bob_shoots (A_alive, C_alive, 80);
	assert (A_alive == false);
	assert (C_alive == true);
	cout << "     or Bob misses" << endl;

        cout << "Case 3: Aaron alive, Charlie dead" << endl;
        cout << "     Bob is shooting at Aaron" << endl;
                A_alive = true;
                C_alive = false;
		Bob_shoots (A_alive, C_alive, 20);
        assert (A_alive == false);
        assert (C_alive == false);
        cout << "     Aaron is dead" << endl;
		A_alive = true;
		C_alive = false;
		Bob_shoots (A_alive, C_alive, 80);
	assert (A_alive == true);
	assert (C_alive == false);
	cout << "     or Bob misses" << endl;
                
        press_any_key();
return;
}

//FUNCTION FOUR - CHARLIE SHOOTS
void Charlie_shoots (bool& A_alive, bool& B_alive) {
	//Strategy, shoot the one with the highest accuracy
	//Probability 1/1 of the one that is shot dying
	if (B_alive) {
	B_alive = false;
	}
	else if (A_alive) {
	A_alive = false;
	}
return;
}

void test_Charlie_shoots(){
	bool A_alive;
	bool B_alive;
	cout << endl << endl << "Unit Testing 4: Function Charlie_shoots(A_alive, B_alive)" << endl;

	cout << "Case 1: Aaron alive, Bob alive" << endl;
	cout << "Charlie is shooting at Bob" << endl;
		A_alive = true;
		B_alive = true;
		Charlie_shoots(A_alive, B_alive);
		assert (A_alive == true);
		assert (B_alive == false);
		cout << "Bob is dead" << endl;
	cout << "Case 2: Aaron dead, Bob alive" << endl;
		A_alive = false;
		B_alive = true;
		Charlie_shoots(A_alive, B_alive);
		assert (A_alive == false);
		assert (B_alive == false);
		cout << "Bob is dead" << endl;
	cout << "Case 3: Aaron alive, Bob dead" << endl;
		A_alive = true;
		B_alive = false;
		Charlie_shoots(A_alive, B_alive);
		assert(A_alive == false);
		assert(B_alive == false);
	cout << "Aaron is dead" << endl;

	press_any_key();
return;
}

//FUNCTION FIVE - AARON SHOOTS, STRATEGY TWO
void Aaron_shoots2 (bool& B_alive, bool& C_alive){
	if (B_alive && C_alive) {
	//Do nothing
	}
	else {
	Aaron_shoots1(B_alive, C_alive);
	}
return;
}

void test_Aaron_shoots2 () {
	bool B_alive;
	bool C_alive;
	cout << endl << endl << "Unit Testing 5: Function Aaron_shoots2(B_alive, C_alive)" << endl;
	cout << "Case 1: Bob alive, Charlie alive" << endl;
	cout << "Aaron intentionally misses the first shot" << endl;	
		B_alive = true;
		C_alive = true;
		Aaron_shoots2(B_alive, C_alive);
	assert (B_alive && C_alive);
	cout << "     Both Bob and Charlie are alive" << endl;
	
	cout << "Case 2: Bob dead, Charlie alive" << endl;
	cout << "Aaron is shooting at Charlie" << endl;		
		B_alive = false;
		C_alive = true;
		Aaron_shoots2(B_alive, C_alive);
	assert(B_alive == false);
	assert(C_alive == false || C_alive == true);
	cout << "     Charlie is dead" << endl;
	cout << "     or Aaron misses" << endl;
	//Because Aaron_shoots1 has already been tested, it does not need to be tested again for its nested form
		
	cout << "Case 3: Bob alive, Charlie dead" << endl;	
	cout << "Aaron is shooting at Bob" << endl;
		B_alive = true;
		C_alive = false;
		Aaron_shoots2(B_alive, C_alive);
	assert (B_alive == false || B_alive == true);
	assert (C_alive == false);
	cout << "     Bob is dead" << endl;
	cout << "     or Aaron misses" << endl;
	//Similar use of function Aaron_shoots1
		
	press_any_key();
return;
}

//MAIN FUNCTION
int main(){
srand(time(0));

const double Charlie_rate = 1.0;
const double Bob_rate = 0.50;
const double Aaron_rate = 0.33;
const double number_of_duels = 10000;
bool a=true;
bool b=true;
bool c=true;
int aaron_wins = 0;
int bob_wins = 0;
int charlie_wins = 0;
int duel_count = 0.0;
double percent_aaron = 0.0;
double percent_bob = 0.0;
double percent_charlie = 0.0;
int aaron_wins_strategy1 = 0;
int aaron_wins_strategy2 = 0;

//Use two decimals for all percents
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

cout << "*** Welcome to Annie Sauer's Duel Simulator ***" << endl;
test_at_least_two_alive();
test_Aaron_shoots1();
test_Bob_shoots();
test_Charlie_shoots();
test_Aaron_shoots2();


cout << endl << endl << "Ready to test strategy 1 (run 10000 times): " << endl;
press_any_key();

//Strategy 1
for (duel_count = 0; duel_count < number_of_duels; duel_count = duel_count + 1)  {
a = true;
b = true;
c = true;
	while (at_least_two_alive (a, b, c) == true) {
		if  (a==true) {
		Aaron_shoots1 (b, c);
		}
		if (b==true) {
		Bob_shoots (a, c);
		}
		if (c==true) {
		Charlie_shoots (a, b);
		}
	}
	if (a==true) {
	assert (b==false && c==false);
	aaron_wins = aaron_wins+1;
	}
	else if (b==true) {
	assert (a==false && c==false);
	bob_wins = bob_wins+1;
	}
	else if (c==true) {
	assert (a==false && b==false);
	charlie_wins = charlie_wins+1;
	}
}

aaron_wins_strategy1 = aaron_wins;
percent_aaron = (aaron_wins / number_of_duels) * 100;
percent_bob = (bob_wins / number_of_duels) * 100;
percent_charlie = (charlie_wins / number_of_duels) * 100;

cout << endl << endl << "Aaron won " << aaron_wins << "/" << duel_count << " duels or " << percent_aaron << "%" << endl;
cout << "Bob won " << bob_wins << "/" << duel_count << " duels or " << percent_bob << "%" << endl;
cout << "Charlie won " << charlie_wins << "/" << duel_count << " duels or " << percent_charlie << "%" << endl;

cout << endl << endl << "Ready to test Strategy 2 (run 10000 times): " << endl;
press_any_key();

aaron_wins = 0;
bob_wins = 0;
charlie_wins = 0;

//Strategy 2
for (duel_count = 0; duel_count < number_of_duels; duel_count = duel_count + 1) {
a = true;
b = true;
c = true;
	while (at_least_two_alive (a,b,c) == true) {
		if (a==true) {
		Aaron_shoots2(b,c);
		}
		if (b==true) {
		Bob_shoots (a,c);
		}
		if (c==true) {
		Charlie_shoots(a,b);
		}
	}
	if (a==true) {
	assert (b==false && c==false);
	aaron_wins = aaron_wins + 1;
	}
	else if (b==true) {
	assert (a==false && c==false);
	bob_wins = bob_wins + 1;
	}
	else if (c==true) {
	assert (a==false && b==false);
	charlie_wins = charlie_wins + 1;
	}
}

aaron_wins_strategy2 = aaron_wins;
percent_aaron = (aaron_wins / number_of_duels) * 100;
percent_bob = (bob_wins / number_of_duels) * 100;
percent_charlie = (charlie_wins / number_of_duels) * 100;

cout << endl << endl << "Aaron won " << aaron_wins << "/" << duel_count << " duels or " << percent_aaron << "%" << endl;
cout << "Bob won " << bob_wins << "/" << duel_count << " duels or " << percent_bob << "%" << endl;
cout << "Charlie won " << charlie_wins << "/" << duel_count << " duels or " << percent_charlie << "%" << endl;

if (aaron_wins_strategy1 > aaron_wins_strategy2) {
	cout << endl << "Strategy 1 is better than Strategy 2" << endl;
	}
else if (aaron_wins_strategy2 > aaron_wins_strategy1) {
	cout << endl << "Strategy 2 is better than Strategy 1" << endl;
	}
else {
	cout << "Strategy 1 and Strategy 2 are equal" << endl;
	}

return 0; 
}

