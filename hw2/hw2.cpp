// Name: Annie Sauer
// Auburn UserID: aes0051
// filename: hw2.cpp
// Development Environment: vim, g++, linux
// Compile: g++ -o hw2 hw2.cpp
// Sample usage: ./hw2
// I did not receive any outside help on this assignment (other than talking to Professor Sardinas)

// Compiler pre-directives
 #include <iostream> //This is required for cin and cout

using namespace std;

int main() {

// Identify and initialize local variables.
double lethalKillMouse = 0.0;
double weightMouse = 0;
double weightDieter = 0; // Weight at which the dieter will stop dieting
double sodasKillDieter = 0; // Number of sodas dieter can drink without dieting
const double RATE = 0.001; // Portion of sweetener in diet soda

// User Input
cout << "What is the amount of artificial sweetener needed to kill a mouse:" << endl;
cin >> lethalKillMouse;
cout << "What is the weight of the mouse:  " << endl;
cin >> weightMouse;
cout << "What is the weight of the dieter:  " << endl;
cin >> weightDieter;

// Calculation of number of sodas that the dieter can drink
sodasKillDieter = (lethalKillMouse * weightDieter) / (weightMouse * RATE);

// Print results
cout << "You can drink  " << sodasKillDieter << " diet soda without dying as a result." << endl;

return 0;

}
