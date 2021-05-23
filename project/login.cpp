#include "login.h"


bool isLoggedIn()
{  
    string username, password, un, pw;
    system("cls");

    cout << "\n\n\n\n\n\n\t\t\t\t\t\t****** Login ******" << endl;


    cout << "\t\t\t\t\t\t";

    cout << " Enter username: ";
    cin >> username;
    cout << "\t\t\t\t\t         Enter password: ";
    cin >> password;

    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int login()
{
    int choice;
    cin >> choice;


    if (choice == 1)
    {
        string username, password;


        system("cls");
        
        cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t****** Login ******" << endl;
        cout << "\t\t\t\t\t\t    ";
        cout << "Select a username: ";
        cin >> username;
        cout << "\t\t\t\t\t              Select a password: ";
        cin >> password;


        ofstream file;
        file.open(username + ".txt", ios::out);
        if (file)
        {
            cout << "File created and data got written to file\n";
            file << username << endl << password << endl;
            file.close();
            return -1;
        }
        else
        {
            cout << "Error while creating the file\n";
        }

    }
    else if ( choice == 2)
    {
        if (isLoggedIn())
        {
            cout << "Successfully logged in!\n";
            return 1;
        }
        else
        {
            cout << "username or password is wrong\n";
            system("pause");
            return -1;
        }
    }
    else
    {
        return -1;
    }
    return 0;
}