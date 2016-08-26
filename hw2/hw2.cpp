// Name: Annie Sauer
// Auburn UserID: aes0051
// filename: hw2.cpp
// Development Environment: vim, g++, linux
// Compile: g++ -o hw2 hw2.cpp
// Sample usage: ./hw2

// Compiler pre-directives
 #include <iostream> //This is required for cin and cout

using namespace std;

int main() {

int amountKillMouse = 0; // Units in grams of artificial sweetener
int weightMouse = 0; // Units in kilograms
int weightDieter = 0; // Units in kilograms
int amountKillDieter = 0; // Calculated later.  Units in grams of diet soda.
float  RATE  = 0.001; //Proportion of each diet soda that consists of artificial sweeteners.
// Identify and initialize the necessary variables.

cout << "Enter the amount of artifial sweetener required to kill the mouse (in grams) " << endl;
cin >> amountKillMouse;
cout << "Enter the weight of the mouse (in kilograms) " << endl;
cin >> weightMouse;
cout << "Enter the desired weight of the dieter (in kilograms) " << endl;
cin >> weightDieter;


amountKillDieter = (amountKillMouse * weightDieter) / (weightMouse * RATE);

cout << "It is possible to drink " << amountKillDieter << " grams of diet soda before dying." << endl;

return 0;

}
