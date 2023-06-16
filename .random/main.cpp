#include <iostream>
#include <algorithm>
#include <memory> // For std::unique_ptr
#include <vector>
#include <string>


class BankAccount{
protected:
    double balance;

public:
    BankAccount(){}
    BankAccount(double initial_balance) : balance(initial_balance) {}
    virtual ~BankAccount(){}

    void deposit(double amount){
        balance += amount;
    }

    void withdrawal(double amount){
        if (balance < amount){
            throw std::runtime_error("Insufficient funds");
        } else {
            balance -= amount;
        }
    }

    virtual double getBalance() {
        return balance;
    }

    friend std::ostream& operator<<(std::ostream& os, const BankAccount& obj);

};

std::ostream& operator<<(std::ostream& os, const BankAccount& obj){
    os << obj.balance;
    return os;
}


class CheckingAccount : public BankAccount {
public:
    // CheckingAccount() : BankAccount() {}
    CheckingAccount(double initial_balance = 0.0) : BankAccount(initial_balance) {}

    void withdrawal(double amount){

        double fee = std::max(2.0, amount*0.01);
        if (balance < amount + fee){
                throw std::runtime_error("Insufficient funds");
            } else {
                balance -= amount + fee;
            }
        }
};

class SavingsAccount : public BankAccount {
public:
    // SavingsAccount() : BankAccount() {}
    SavingsAccount(double initial_balance = 0.0) : BankAccount(initial_balance) {}

    void deposit(double amount){
        double interest = 0.02;

        balance += amount * (1+interest);
    }

    void withdrawal(double amount){
        double penalty = std::max(5.0, amount*0.05);

        if (balance < amount + penalty){
            throw std::runtime_error("Insufficient funds");
        } else {
            balance -= amount + penalty;
        }
    }
};    

struct Customer{

    std::string name;
    SavingsAccount savings;
    CheckingAccount checking;

};

Customer makeCustomer(std::string name, double savings = 0.0, double checking = 0.0){
    Customer c;
    c.name = name;
    c.savings = SavingsAccount(savings);
    c.checking = CheckingAccount(checking);
    return c;
}

int main(){
    std::vector<Customer> customers_vec;

    customers_vec.push_back(makeCustomer("George"));
    customers_vec.push_back(makeCustomer("John"));
    customers_vec.push_back(makeCustomer("Thomas"));

    try {
        customers_vec[0].savings.deposit(500.0);

        std::cout << customers_vec[0].checking << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl; 
    }
    std::cout << customers_vec[0].checking<< std::endl;



    return 0;
}