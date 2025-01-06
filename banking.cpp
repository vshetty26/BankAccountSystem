//Q.Bank working system

// #include <iostream>
// using namespace std;
// class BankAccount
// {
//     private:
//     string accountHolderName;
//     int accountNumber;
//     double balance;
//     public:
//     BankAccount(string name,int number,double initialBalance)
//     {
//         accountHolderName=name;
//         accountNumber=number;
//         balance=initialBalance;
//     }
//     void credit(double amount){
//         if (amount>0){
//             balance +=amount;
//             cout<<"Amount credited:"<<amount<<".New balance"<<balance<<endl;
//         }else{
//             cout<<"Invalid amount. Please enter the positive Value. \n";
//         }
//     }
//     void debit(double amount){
//         if (amount>0 && amount <=balance){
//             balance-= amount;
//             cout<<"Amount debited:"<<amount<<". New Balance:"<<balance<<endl;
//         }else{
//             cout<<"Insufficient funds or invalid amount.\n";
//         }
//     }
//     void displayAccoountDetails()const{
//         cout<<"Account Holder:"<<accountHolderName
//             <<"\nAccount Number:"<<accountNumber
//             <<"\nCurrent Balance:"<< balance;
//     }
// };

// int main(){
//     BankAccount myaccount("John",123456789123,500.0);
//     cout<<"Initial accout details:\n";
//     myaccount.displayAccoountDetails();
//     cout<<"\nPerforming operations:\n";
//     myaccount.credit(1500.0);
//     myaccount.debit(1200.0);
//     myaccount.debit(200.0);
//     cout<<"\nFinal account details:\n";
//     myaccount.displayAccoountDetails();
//     return 0;

// }

//Q.Bank working system (user input)
#include<iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
using namespace std;

class profile
{
    private:
    string name;
    long int accno;

    public:
    void getname(){
        cout<<"Enter Your Name : ";
        getline(cin,name);
    }
    void getnumber(){
        while (true)
        {
            cout<<"\nEnter Your Account Number : ";
            cin>>accno;
            if (accno>=100000000000 && accno<=999999999999)
            {
                cout<<"Accound Valid : Proceed Ahead"<<endl;
                break;
            }
            else
            {
                cout<<"Invalid Account Number! Must be 12 Digits. Try Again"<<endl;
            } 
        }
    }
};
class display:public profile{
    private:
    int bankBalance;  // Bank balance
    public:
     display() {
        // Seed the random number generator with current time for random values
        srand(time(0));
        // Generate random balance between 10000 and 100000
        bankBalance = 10000 + (rand() % (100000 - 10000 + 1));
    }
    void showbalance(){
        cout << "Your bank balance is: ₹" << bankBalance << endl;
    }
    int getBalance(){
        return bankBalance;
    }
    void setBalance(int newBalance){
        bankBalance = newBalance;
    }
};

class credit {
public:
    // Function to deposit money into the account
    void deposit(display &user, int amount) {
        int currentBalance = user.getBalance();
        user.setBalance(currentBalance + amount);
        cout << "₹" << amount << " has been deposited. New balance: ₹" << user.getBalance() << endl;
    }
};

// Class to handle debiting (withdrawing) money
class debit {
public:
    // Function to withdraw money from the account, ensuring minimum balance is maintained
    void withdraw(display &user, int amount) {
        int currentBalance = user.getBalance();
        if (currentBalance - amount >= 10000) {
            user.setBalance(currentBalance - amount);
            cout << "₹" << amount << " has been withdrawn. New balance: ₹" << user.getBalance() << endl;
        } else {
            cout << "Insufficient funds! You must maintain a minimum balance of ₹10,000." << endl;
        }
    }
};

int main() {
    display userProfile;         // Create a display object (inherits from profile)
    credit creditManager;        // Create a credit object
    debit debitManager;          // Create a debit object

    userProfile.getname();       // Get user name
    userProfile.getnumber();     // Get account number
    // userProfile.showbalance();   // Show random bank balance

    int choice, amount;
    bool exit = false;  // To control the loop

    // Menu system to give choices to the user
    while (!exit) {
        cout << "\n----- Menu -----" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Check Balance
                userProfile.showbalance();
                break;

            case 2:
                // Deposit Money
                cout << "Enter amount to deposit: ₹";
                cin >> amount;
                creditManager.deposit(userProfile, amount);
                break;

            case 3:
                // Withdraw Money
                cout << "Enter amount to withdraw: ₹";
                cin >> amount;
                debitManager.withdraw(userProfile, amount);
                break;

            case 4:
                // Exit
                cout << "Exiting... Thank you!" << endl;
                exit = true;
                break;

            default:
                // Invalid choice
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    }
    return 0;
}