#ifndef ACCOUNTS_H
#define ACCOUNTS_H

class BankAccount
{
public:
	BankAccount();
	~BankAccount();
	double getBalance();
	int getAccountNumber();
	virtual void deposit(double);
	virtual void withdraw(double);
	
protected:
	double balance;
	int accountNumber;
	char* name;
	int type; //1: checking 2: Savings 0: for account, this should give an error.
	bool active;
	bool& operator==(BankAccount b){
		if (type == b.type && active == b.active)
	}
};

class CheckingAccount : public BankAccount 
{
public:
	CheckingAccount();
	CheckingAccount(int, double, double);
	~CheckingAccount();
	void applyFee();
	double getFee();
	void setFee(double);
	virtual void withdraw(double);
	virtual void deposit(double);


private:
	double fee;
	double NSF;
	double balance;
	int accountNumber;
};

class SavingsAccount : public BankAccount
{
public:
	SavingsAccount();
	SavingsAccount(int, double, double);
	~SavingsAccount();
	double getBalance();
	int getAccountNumber();
	void deposit(double);
	void withdraw(double);
private:
	double balance;
	int accountNumber;
	double interestRate;

};





#endif