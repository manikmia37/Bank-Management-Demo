#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dl;
#define MOD 1000000007
#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(5); cout.setf(ios::fixed,ios::floatfield);
#define mem(a,b) memset(a,b,sizeof(a));
const int inf = 2000000000;
const ll infLL = 9000000000000000000;

class BankAccount
{
public:
    string account_holder;
    string address;
    int account_number;
    int age;
protected:
    int account_balance;
private:
    string password;
public:
    friend class MyCash;
    BankAccount(string account_holder, string address, int age, string password)
    {
        this->account_holder=account_holder;
        this->address=address;
        this->age=age;
        this->password=password;
        this->account_balance=0;
        this->account_number=rand()%10000000;
        cout<<"Your account number is: "<<this->account_number<<endl<<endl;
    }

    int show_balance(string password)
    {
        if(this->password==password)
        {
            return this->account_balance;
        }
        else
        {
            return -1;
        }
    }

    bool add_money(string name, string password, int amount)
    {

        if(this->account_holder==name && this->password==password)
        {
            cout<<"The amount is added successfully"<<endl;
            this->account_balance+=amount;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool deposit_money(string name, string password, int amount)
    {
        if(this->account_holder==name && this->password==password)
        {
            if(amount>account_balance)
            {
                cout<<"Sorry! Insufficient Balance in your Bank Account"<<endl;
                return false;
            }
            else if(amount<0)
            {
                cout<<"Invalid amount!"<<endl;
                return false;
            }
            else
            {
                cout<<"Money Deposit is completed successfully"<<endl;
                this->account_balance -= amount;
                return true;
            }
        }
        else
        {
            cout<<"The credentials did not match! Please Try Again"<<endl;
            return false;
        }
    }
};



class MyCash
{
private:
    int cash;
public:
    MyCash()
    {
        this->cash=0;
    }
    bool money_Add_To_myCash_From_Bank(BankAccount *myaccount, string password, int amount)
    {
        if(myaccount->password==password)
        {
            if(amount>myaccount->account_balance)
            {
                cout<<"Insufficient Balance in your Bank Account"<<endl;
                return false;
            }
            else if(amount<0)
            {
                cout<<"Invalid Amount! Please Try Again"<<endl;
                return false;
            }
            else
            {
                this->cash += amount;
                myaccount->account_balance -= amount;
                return true;
            }
        }
        else
        {
            cout<<"Password did not match"<<endl;
            return false;
        }
    }
    int show_balance()
    {
        return cash;
    }
};



BankAccount* create_account()
{
    cout<<"*******Create Account*********"<<endl;
    string name,address,password;
    int age;
    cout<<"Enter The Account Holder Name: ";
    getline(cin,name);
    cout<<"Enter Address: ";
    getline(cin,address);
    cout<<"Enter The Account Password: ";
    getline(cin,password);
    cout<<"Enter Age: ";
    cin>>age;
    BankAccount *myaccount=new BankAccount(name,address,age,password);
    return myaccount;
}


void Add_money(BankAccount *myaccount)
{
    cout<<endl;
    string name,password;
    int amount;
    while(true)
    {
        cin.ignore();
        cout<<"Enter Account Holder Name: ";
        getline(cin,name);
        cout<<"Enter Password: ";
        getline(cin,password);
        cout<<"Enter Amount: ";
        cin>>amount;
        if(amount<0)
        {
            cout<<"Invalid Amount! Please give the all information again"<<endl;
            continue;
        }
        break;
    }
    if(myaccount->add_money(name,password,amount) != false)
    {
        cout<<"Bank Balance is: "<<myaccount->show_balance(password)<<endl;
    }
    else
    {
        cout<<"The credentials did not match ! Please try again"<<endl;
    }
}


void Deposit_money(BankAccount *myaccount)
{
    cout<<endl;
    string name,password;
    int amount;
    cin.ignore();
    cout<<"Enter Account Holder Name: ";
    getline(cin,name);
    cout<<"Enter Password: ";
    getline(cin,password);
    cout<<"Enter Amount: ";
    cin>>amount;
    if(myaccount->deposit_money(name,password,amount) != false)
    {
        cout<<"Bank Balance is: "<<myaccount->show_balance(password)<<endl;
    }
}


void Money_Add_To_MyCash_From_Bank(MyCash *mycash, BankAccount *myaccount)
{
    cout<<endl;
    string password;
    int amount;
    cout<<"Enter Amount: ";
    cin>>amount;
    cin.ignore();
    cout<<"Enter The password: ";
    getline(cin,password);
    bool result=mycash->money_Add_To_myCash_From_Bank(myaccount,password,amount);
    if(result)
    {
        cout<<amount<<" TK is added successfully To MyCash"<<endl;
        cout<<"Bank Balance is: "<<myaccount->show_balance(password)<<endl;
        cout<<"MyCash Balance is: "<<mycash->show_balance()<<endl;

    }
}


void Show_Bank_Balance(BankAccount *myaccount)
{
    cout<<endl;
    string password;
    cin.ignore();
    cout<<"Enter Password: ";
    getline(cin,password);
    int balance=myaccount->show_balance(password);
    if(balance != -1) cout<<"Bank Balance is: "<<balance<<endl;
    else cout<<"The password did not match! Please Try Again"<<endl;
}


void show_MyCash_balance(MyCash *mycash)
{
    cout<<"MyCash Balance is: "<<mycash->show_balance()<<endl;
}


int main()
{
    //optimize();
    BankAccount *MyAccount=create_account();
    MyCash *mycash = new MyCash();

    cout<<"Choose The Option From Option Menu"<<endl;
    cout<<"Choose 1: To Add Money in Bank Account"<<endl;
    cout<<"Choose 2: To Deposit Money From Bank Account"<<endl;
    cout<<"Choose 3: Add Money To MyCash From Bank Account"<<endl;
    cout<<"Choose 4: To Know Bank Balance"<<endl;
    cout<<"Choose 5: To Know MyCash Balance"<<endl;
    cout<<"Choose 0: To Exit"<<endl<<endl;
    int select;
    cout<<"Select The Option: ";
    cin>>select;
    while(select)
    {
        switch(select)
        {
        case 1:
            Add_money(MyAccount);
            break;
        case 2:
            Deposit_money(MyAccount);
            break;
        case 3:
            Money_Add_To_MyCash_From_Bank(mycash,MyAccount);
            break;
        case 4:
            Show_Bank_Balance(MyAccount);
            break;
        case 5:
            show_MyCash_balance(mycash);
            break;
        default:
            break;
        }
        cout<<endl;
        cout<<"Select The Option: ";
        cin>>select;
    }
    delete MyAccount;
    delete mycash;
    return 0;
}


