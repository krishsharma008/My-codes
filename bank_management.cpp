#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <unordered_map>
class Account
{
public:
    int accnumber;
    std::string holdername;
    std::string mobileno;
    std::string address;
    double balance;
    std::string pin;
};
class Transaction
{
public:
    int accnumber;
    std::string type;
    double amount;
    double balaftertransaction;
};
class Bank
{
private:
    std::unordered_map<int, Account> Accounts;
    std::vector<Transaction> Transactions;

public:
    void createaccount()
    {
        int id;
        std::string name;
        std::string phone;
        std::string addr;
        double bal;
        std::string pass;
        std::cout << "\n========== ADD NEW ACCOUNT ==========\n";
        std::cout << "Enter Account Number" << std::endl;
        std::cin >> id;
        auto it = Accounts.find(id);
        if (it == Accounts.end())
        {
            std::cout << "\n[Error]Account Already Exist\n"
                      << std::endl;
            return;
        }
        std::cout << "Enter Holder Name" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter Mobile no" << std::endl;
        std::getline(std::cin, phone);
        std::cout << "Enter Address" << std::endl;
        std::getline(std::cin, addr);
        std::cout << "Enter Balance" << std::endl;
        std::cin.ignore();
        std::cin >> bal;
        std::cout << "-------------------" << std::endl;
        while (bal <= 0)
        {
            std::cout << "\n[Error] Enter Valid Value\n"
                      << std::endl;
            std::cout << "Try Again!" << std::endl;
            std::cin >> bal;
        }
        std::cout << "Create PIN" << std::endl;
        std::getline(std::cin, pass);
        while (pass.length() != 4)
        {
            std::cout << "[Error]Enter only 4 Digit" << std::endl;
            std::cout << "Try Again..";
            std::getline(std::cin, pass);
        }

        Account acc; // class
        acc.accnumber = id;
        acc.holdername = name;
        acc.mobileno = phone;
        acc.address = addr;
        acc.balance = bal;
        acc.pin = pass;
        // store all data in map
        Accounts[id] = acc;
        //   savefile(); uncoment after make function
        std::cout << "\n[Success] Account Created\n"
                  << std::endl;
    }

    void depositmoney()
    {
        int id;
        double amount;
        std::cout << "\n========== DEPOSIT MONEY ==========\n";
        std::cout << "Enter Account Number" << std::endl;
        std::cin >> id;
        auto it = Accounts.find(id);
        if (it == Accounts.end())
        {
            std::cout << "\n[Error]Acccount Not Found!\n"
                      << std::endl;
            return;
        }
        std::cout << "Enter Amount" << std::endl;
        std::cin >> amount;
        std::cout << "-------------------" << std::endl;
        while (amount <= 0)
        {
            std::cout << "\n[Error]Invalid Amount!\n"
                      << std::endl;
            std::cout << "Try Again: ";
            std::cin >> amount;
        }
        it->second.balance += amount;
        // Transfer all data and info into vector
        Transaction t;
        t.accnumber = id;
        t.type = "Deposit";
        t.amount = amount;
        t.balaftertransaction = it->second.balance;
        Transactions[id] = t;
        // savefile(); umcoment  after  make function
        std::cout << "\n[Success] Deposited!\n"
                  << std::endl;
    }

    void withdraw()
    {
        int id;
        double amt;
        std::cout << "\n========== WITHDRAW MONEY ==========\n";
        std::cout << "Enter Acccount Number" << std::endl;
        std::cin >> id;
        auto it = Accounts.find(id);
        if (it == Accounts.end())
        {
            std::cout << "\n[Error] Account Not Found! \n"
                      << std::endl;
            return;
        }
        std::cout << "Enter Amount" << std::endl;
        std::cin >> amt;
        if (amt <= 0)
        {
            std::cout << "\n[Error]Invalid Amount!\n"
                      << std::endl;
            std::cout << "Try Again...";
            std::cin >> amt;
            return;
        }
        // Decrease the amount into the account
        it->second.balance -= amt;
        Transaction t;
        t.accnumber = id;
        t.type = "Withdraw";
        t.amount = amt;
        t.balaftertransaction = it->second.balance;
        Transactions.push_back(t);
        // savefile uncoment after make function
        std::cout << "\n[Success] Withdraw Money!\n"
                  << std::endl;
        std::cout << "---------------------------" << std::endl;
    }

    void searchaccount()
    {
        int id;
        std::cout << "Enter Account Number" << std::endl;
        std::cin >> id;
        auto it = Accounts.find(id);
        if (it == Accounts.end())
        {
            std::cout << "\n[Error] Account Not Found!\n"
                      << std::endl;
            return;
        }
        std::cout << "\n========== ACCOUNT DETAILS ==========\n";
        std::cout << "Account Number:    " << it->second.accnumber << std::endl;
        std::cout << "  Holder Name :    " << it->second.holdername << std::endl;
        std::cout << "        Phone :    " << it->second.mobileno << std::endl;
        std::cout << "       Address:     " << it->second.accnumber << std::endl;
        std::cout << "       Balance:     " << it->second.balance << std::endl;
        std::cout << "----------------------------------" << std::endl;
    }

    void checkbalance()
    {
        int id;
        std::cout << "Enter Account Number" << std::endl;
        std::cin >> id;
        auto it = Accounts.find(id);
        if (it == Accounts.end())
        {
            std::cout << "\n[Error]Account Not Found!\n"
                      << std::endl;
            return;
        }
        // Show holder name and balance
        std::cout << "----------------------------------" << std::endl;
        std::cout << "Holder Name:" << it->second.holdername << std::endl;
        std::cout << " Balance  :     " << it->second.balance << std::endl;
        std::cout << "----------------------------------" << std::endl;
    }

    void displayaccount()
    {
        if (Accounts.empty())
        {
            std::cout << "\n[Error] NO Accounts!\n"
                      << std::endl;
            return;
        }
        std::cout << "\n========== DISPLAY ACCOUNT ==========\n";
        for (auto it = Accounts.begin(); it != Accounts.end(); it++)
        {

            std::cout << "Accounts Number:     " << it->second.accnumber << std::endl;
            std::cout << " Holder Name  :     " << it->second.holdername << std::endl;
            std::cout << "    Address    :     " << it->second.address << std::endl;
            std::cout << "   Balance    :     " << it->second.balance << std::endl;
            std::cout << "----------------------------------" << std::endl;
        }
    }

    void deleteaccount()
    {
        int id;
        std::cout << "Enter Account NUmber" << std::endl;
        std::cin >> id;
        auto it = Accounts.find(id);
        if (it == Accounts.end())
        {
            std::cout << "\n[Error]Account Not existed!\n"
                      << std::endl;
            return;
        }
        Accounts.clear();
        // savefile(); uncoment after make function
        std::cout << "\n[Success] Account Deleted!\n"
                  << std::endl;
    }
    void transfermoney()
    {
        int senderid;
        int receiverid;
        std::string pin;
        double amt;
        int max_attempt = 3;
        int attempt = 0;
        std::cout << "Enter Account Number" << std::endl;
        std::cin >> senderid;
        auto it = Accounts.find(senderid);
        if (it == Accounts.end())
        {
            std::cout << "\n[Error] Accounts Not Found!\n"
                      << std::endl;
            return;
        }
        std::cout << "Enter send Money" << std::endl;
        std::cin >> receiverid;
        auto recit = Accounts.find(receiverid);
        if (recit == Accounts.end())
        {
            std::cout << "\n[Error]Account Not Found!\n"
                      << std::endl;
            return;
        }
        if (senderid == receiverid)
        {
            std::cout << "\n[Error]Invalid Transfer!\n"
                      << std::endl;
            return;
        }
        // create password(pin)and limits
        while (attempt < max_attempt)
        {
            std::cout << "Enter 4 Digit PIN" << std::endl;
            std::getline(std::cin, pin);
            while (pin.length() != 4)
            {
                std::cout << "\n[Error]Invalid PIN, Enter 4 didgit!\n"
                          << std::endl;
                std::cout << "Try Again..";
                std::getline(std::cin, pin);
            }
            if (pin == it->second.pin)
            {
                break;
            }
            attempt++;
            if (attempt == max_attempt)
            {
                std::cout << "\n[Error] Transfer Cancelled!\n"
                          << std::endl;
                return;
            }
            std::cout << "Enter Amount" << std::endl;
            std::cin >> amt;
            while (amt <= 0)
            {
                std::cout << "\n[Error]Invalid Amount!\n"
                          << std::endl;
                std::cout << "Try Again...";
                std::cin >> amt;
                return;
            }
            if (it->second.balance < amt)
            {
                std::cout << "\n[Error]Insufficent Balance!\n"
                          << std::endl;
                return;
            }
        }
        it->second.balance -= amt;
        it->second.balance += amt;
        Transaction t;
        t.accnumber = senderid;
        t.type = "Transfer";
        t.amount = amt;
        t.balaftertransaction = it->second.balance;
        Transactions.push_back(t);
        // savefile(); uncoment after amke function
        std::cout << "\n=========================================\n";
        std::cout << "          RECEIPT\n";
        std::cout << "=========================================\n";
        std::cout << "   From Account:          " << senderid << std::endl;
        std::cout << "   To Account  :          " << receiverid << std::endl;
        std::cout << "    Amount     :         " << amt << std::endl;
        std::cout << "Remaining Balance :         " << it->second.balance << std::endl;
        std::cout << "=========================================\n";
    }

    void transferhistory()
    {
        int id;
        std::cout << "Enter Account Number" << std::endl;
        std::cin >> id;
        auto it = Accounts.find(id);
        if (it == Accounts.end())
        {
            std::cout << "\n[Error]Acccount Not Found!\n"
                      << std::endl;
            return;
        }
        for (const auto &t : Transactions)
        {
            if (t.accnumber == id)
            {
                std::cout << "\n=========================================\n";
                std::cout << "          TRANSFER DETAILS\n";
                std::cout << "=========================================\n";
                std::cout << "Account Number:      " << t.accnumber << std::endl;
                std::cout << "     Type     :            " << t.type << std::endl;
                std::cout << "Transferd Amount:     " << t.amount << std::endl;
                std::cout << " Left Balance:     " << t.balaftertransaction << std::endl;
                std::cout << "=========================================\n";
            }
        }
    }
};
int main()
{
    Bank b;
    // b.createaccount();
    //  b.depositmoney();
    b.transfermoney();
    return 0;
}
