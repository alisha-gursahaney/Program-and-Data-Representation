#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
using namespace std;

// Declare the bankAccount class
class bankAccount {
public:
	bankAccount(); // default constructor
	bankAccount(double amount); 	// constructor with amount parameter
	~bankAccount(); // deconstructor
	double withdraw(double amount);	// method
	double deposit(double amount);	// method
	double getBalance();	// method
private:
	double balance;
};