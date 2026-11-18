#include <iostream>
#include <string>
using namespace std;

class BankException {
protected:
    string message;
public:
    BankException(const string& msg) : message(msg) {}
    string getMessage() const {
        return message;
    }
};

class InvalidAmountException : public BankException {
public:
    InvalidAmountException(double amount)
        : BankException("Invalid transaction amount: $" + to_string(amount) + ". Must be positive.") {}
};

class InsufficientFundsException : public BankException {
public:
    InsufficientFundsException(double balance, double attempted)
        : BankException("Insufficient funds: Balance is $" + to_string(balance) + ", tried to withdraw $" + to_string(attempted) + ".") {}
};

class AccountFrozenException : public BankException {
public:
    AccountFrozenException(const string& accountId)
        : BankException("Transaction blocked: Account [" + accountId + "] is currently frozen.") {}
};

class BankAccount {
private:
    string accountId;
    double balance;
    bool frozen;
public:
    BankAccount(string id, double initialBalance)
        : accountId(id), balance(initialBalance), frozen(false) {}

    void freezeAccount() { frozen = true; }

    void deposit(double amount) {
        if (frozen) throw AccountFrozenException(accountId);
        if (amount <= 0) throw InvalidAmountException(amount);
        balance += amount;
        cout << "Deposited $" << amount << ". New Balance: $" << balance << "\n";
    }

    void withdraw(double amount) {
        if (frozen) throw AccountFrozenException(accountId);
        if (amount <= 0) throw InvalidAmountException(amount);
        if (amount > balance) throw InsufficientFundsException(balance, amount);
        balance -= amount;
        cout << "Withdrew $" << amount << ". New Balance: $" << balance << "\n";
    }
};

int main() {
    BankAccount acc("ACC-9081", 500.00);

    try {
        acc.deposit(200.00);
        acc.withdraw(1000.00);
    }
    catch (const InsufficientFundsException& e) {
        cout << "[Funds Error] " << e.getMessage() << "\n";
    }
    catch (const BankException& e) {
        cout << "[Bank Error] " << e.getMessage() << "\n";
    }

    try {
        acc.deposit(-50.00);
    }
    catch (const InvalidAmountException& e) {
        cout << "[Amount Error] " << e.getMessage() << "\n";
    }

    try {
        acc.freezeAccount();
        acc.withdraw(100.00);
    }
    catch (const AccountFrozenException& e) {
        cout << "[Security Error] " << e.getMessage() << "\n";
    }
    catch (const BankException& e) {
        cout << "[General Bank Error] " << e.getMessage() << "\n";
    }

    return 0;
}
