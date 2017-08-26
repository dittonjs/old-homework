#include "Accounts.h"
#include <iostream>

using namespace std;

BankAccount::BankAccount(){
	accountNumber = 0;
	balance = 0.00;
}

BankAccount::~BankAccount(){
	 
}

int BankAccount::getAccountNumber(){
	return accountNumber;
}

double BankAccount::getBalance(){
	return balance;
}
