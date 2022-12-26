#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool isLoggedIn()
{
    string username, password;
    cout << "Enter your username:";
    cin>>username;
    cout << "Enter the passoword:";
    cin>>password;
    string user, pass;
    ifstream infile;
    infile.open("Database\\"+username + ".txt");
    infile>>user;
    infile>>pass;

    if (username == user && password == pass)
        return true;
    else
        return false;
}
int main()
{
    int choice;
    cout << "Press \n 1 for Registration\n 2 for Login\nYour choice:";
    cin >> choice;
    if (choice == 1)
    {
        string username, password;
        cout << "Choose a username: ";
        cin>>username; 
        cout << "Choose a password (minimum 5 characters & no spaces):";
        cin>>password;
        while (password.length() < 5)
        {
            cout << "Password too weak.Enter again";
            cin >> password;
        }
        ofstream outfile("Database\\"+username + ".txt");
        outfile << username << endl;
        outfile << password;
        outfile.close();
        main();
    }
    if(choice==2)
    {
        bool b=isLoggedIn();
        if(!b)
        {
            cout<<"Invalid login !!"<<endl;
            return 0;
        }
        else
        {
            cout<<"Logged in successfully !"<<endl;
            return 1;
        }

    }
    
}


