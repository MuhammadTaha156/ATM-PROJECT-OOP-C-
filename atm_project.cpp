#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class user
{
private:
    string name;
    string password;

public:
    double balance = 0;

public:
    user(string a, string b)
    {
        name = a;
        password = b;
    }

    bool checkpassword(string pass)
    {
        if (pass == password)
        {
            cout << "Correct Password \n";
            return 1;
        }
        else
        {
            cout << " Wrong Password \n";
            return 0;
        }
    }

    bool checkname(string nam)
    {
        if (nam == name)
        {
            cout << "Correct Name\n";
            return 1;
        }
        else
        {
            cout << "Wrong Name\n";
            return 0;
        }
    }

    void savedata(){
        ofstream userfile("user.txt");
        userfile<<" username : "<<name<<endl<<" Password : "<<password<<endl<<" Balance : "<<balance<<endl;
        userfile.close();
    }
};

int startmenu()
{
    cout << "*****Main Menu*****\n";

    cout << " 1 - Balance \n";
    cout << " 2 - Deposit \n";
    cout << " 3 - Withdraw \n";
    cout << " 4 - Exit \n";
    cout << " Selection :  \n";

    int op;
    cin >> op;

    return op;
}

int main()
{
    user u1 = user("Taha", "1234");
    string n, p;

    cout << " *** WECLOME TO MY ATM APPLICATION ***\n";
    cout << " *** Enter UserName ***\n";
    cin >> n;

    cout << " *** Enter Password ***\n";
    cin >> p;

    if (u1.checkname(n) && u1.checkpassword(p))
    {
    start:
        int i;
        i = startmenu();

        switch (i)
        {
        case 1:
        {
            cout << " Your Current Account Balance is " << u1.balance << endl;
        }
        break;
        case 2:
        {
            double dep;
            cout << "Enter the amount to deposit : ";
            cin >> dep;
            u1.balance += dep;
            break;
        }
        case 3:
        {
            double wd;
            cout << "Enter the amount to withdraw : ";
            cin >> wd;
            if (wd > u1.balance)
            {
                cout << "insuffient funds\n";
            }
            else
                u1.balance -= wd;
            break;
        }

        default:
            break;  
        }
        cout << "** Would you like to continue : **\n";
        cout << " 1 - Yes \n";
        cout << " 2 - No \n";
        cout << " Selection : \n";

        int in;
        cin >> in;

        if (in == 1)
        {
            system("pause");
            goto start;
        }
    }

    u1.savedata();

    system("pause");
    system("CLS");
    return 0;
}