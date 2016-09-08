// Name: Annie Sauer
// filename: hw3.cpp
// Development Environment: vim, g++, linux
// Compile: g++ -o hw3 hw3.cpp
// Sample usage: ./hw3
// I did not receive any outside help on this assignment.

// Compiler pre-directives
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
// Initialize variables
double loanAmount = 0.0;
double interestRate = 0.0;
double monthlyInterestRate = 0.0;
double monthlyPayment = 0.0;
double balance = 0.0;
double interest = 0.0; //amount of interest paid each month
double principal = 0.0; //monthly payment after interest is deducted
int month = 0; //increment for loop
double interestTotal = 0.0;

//Magic Formula - make all decimals two places
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

//Get user input
cout << "Loan amount: ";
cin >> loanAmount;
cout << "Interest Rate (% per year): ";
cin >> interestRate;
cout << "Monthly payments: ";
cin >> monthlyPayment;

monthlyInterestRate = interestRate/12.0; //divide by twelve to get per month
balance = loanAmount; //initial balance is equal to the loan amount

if (monthlyPayment < ((monthlyInterestRate/100.0)*balance))
{
// Error Message
cout << "Error.  Regular payment is less than monthly interest." << endl;
}

else
{
//Print Heading
cout << "*****************************************************************" << endl;
cout << "          Amortization Table" << endl;
cout << "*****************************************************************" << endl;
//Print Headings for each column
cout << left << setw(10) << "Month" << left << setw(10) << "Balance" << left << setw(10) <<  "Payment" << left << setw(10) << "Rate" << left << setw(10) << "Interest" << left << setw(10) << "Principal" << endl;
//Print first line
cout << left << setw(10) << month << left << setw(10) <<  balance << left << setw(10) << "N/A" << left << setw(10) << "N/A" << left << setw(10) << "N/A" << left << setw(10) << "N/A" << endl;

while ((balance + balance*(monthlyInterestRate/100.0)) > monthlyPayment) {
interest = (monthlyInterestRate/100.0)*balance;
principal = monthlyPayment - interest;
balance = balance - principal;
month = month+1;
interestTotal = interestTotal + interest;
cout << left << setw(10) << month << left << setw(10) << balance << left << setw(10) << monthlyPayment << left << setw(10) << monthlyInterestRate << left << setw(10) << interest << left << setw(10) << principal << endl;
}

//Loop breaks for final payment
month = month+1;
interest = (monthlyInterestRate/100.0)*balance;
principal = balance;
monthlyPayment = balance + interest;
balance = 0.00;
interestTotal = interestTotal + interest;
cout << left << setw(10) << month << left << setw(10) << balance << left << setw(10) << monthlyPayment << left << setw(10) << monthlyInterestRate << left << setw(10) << interest << left << setw(10) << principal << endl;

cout << "*****************************************************************" << endl;

//Print totals
cout << "It takes " << month << " months to pay off the loan." << endl;
cout << "Total intereset paid is $" << interestTotal << endl;
}
return 0;
}
