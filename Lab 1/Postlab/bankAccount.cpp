#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include "bankAccount.h"
using namespace std;

// Constructors and destructors - no return types
bankAccount::bankAccount() : balance(0.00) {
}

bankAccount::bankAccount(double amount) : balance(amount) {
}

bankAccount::~bankAccount() {
}

// Regular methods, with return types
double bankAccount::withdraw(double amount) {
	if (amount>balance) {
		return balance;
	}
	else {
		balance -= amount;
		return balance;
	}
}

double bankAccount::deposit(double amount) {
	balance += amount;
	return balance;
}

double bankAccount::getBalance() {
	return balance;
}
