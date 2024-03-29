// bankHackProgram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

// function declarations
int* printMenu();
void transaction(int* balance, int difference);

// global
int mode;

int main()
{
	int accountBalance = 500;
	int* rAccountBalance = &accountBalance;
	string userName;
	string* rUserName = &userName;

	cout << "Welcome to the bank, what's your name? ";
	cin >> *rUserName;
	cout << "\nWelcome, " << userName << ".\n";
	cout << "Your balance is : " << accountBalance << "\n\n";

	char loop = 'n';
	do {
		// print out menu and get/return transaction mode
		mode = *printMenu();

		if (mode == 1) {
			cout << "How much would you like to deposit?: \n";
		}
		else if (mode == 2) {
			cout << "How much would you like to withdrawal?: \n";
		}
		// get the difference
		int amount;
		cin >> amount;

		// carry out transaction
		transaction(rAccountBalance, amount);

		do {
			cout << "Would you like to make another transaction? (y/n): ";
			cin >> loop;
			cout << endl << endl;
		} while (loop != 'y' && loop != 'n');
	} while (loop == 'y');

	cout << "Thanks for coming!\n\n";
	system("pause");

	return 0;
}

int* printMenu() {
	int* pMode = &mode;

	do {
		cout << "To make a deposit:    press 1.\nTo make a withdrawal: press 2.\n";
		cin >> *pMode;
	} while (*pMode != 1 && *pMode != 2);
	cout << ">> You selected: ";
	if (*pMode == 1) {
		cout << "Deposit.\n\n";
	}
	else {
		cout << "Withdrawal\n\n";
	}
	return pMode;
}

void transaction(int* balance, int difference) {
	if (mode == 1) {
		// deposit
		*balance += difference;
	}
	else if (mode == 2) {
		// withdrawal
		*balance -= difference;
	}
	cout << "Your new balance is: " << *balance << "\n\n";
	return;
}