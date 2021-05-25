#include "login.h"


bool isLoggedInStaff(Login &a )
{  
    string username, password, un, pw;
    system("cls");

    cout << "\n\n\n\n\n\n\t\t\t\t\t\t****** Login ******" << endl;


    cout << "\t\t\t\t\t\t";

    cout << " Enter username: ";
    cin.ignore();
    getline(cin, username);
    cout << "\t\t\t\t\t         Enter password: ";
    getline(cin, password);

    ifstream read("Account staff.txt");


    while (!read.eof())
    {
        getline(read, un);
        getline(read, pw);

        if (un == username && pw == password)
        {
            a.username = un;
            a.password = pw;
            return true;
        }
    }

    return false;
}


bool isLoggedInStudents(Login &a)
{
    string Username, Password, un, pw;
    system("cls");

    cout << "\n\n\n\n\n\n\t\t\t\t\t\t****** Login ******" << endl;


    cout << "\t\t\t\t\t\t";

    cout << " Enter username: ";
    cin.ignore();
    getline(cin, Username);
    cout << "\t\t\t\t\t         Enter password: ";
    getline(cin, Password);

    ifstream read("Account students.txt");


    while (!read.eof())
    {
        getline(read, un);
        getline(read, pw);

        if (un == Username && pw == Password)
        {
            a.username = un;
            a.password = pw;
            return true;
        }
    }

    return false;
}

Login login(int x )
{
    Login a;
    int choice;
    cin >> choice;


    if (choice == 1)
    {
        if (x == 1) {
        


            system("cls");

            cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t****** Register Staff ******" << endl;
            cout << "\t\t\t\t\t\t    ";
            cout << "Select a username: ";
            cin.ignore();
            getline(cin, a.username);
            cout << "\t\t\t\t\t              Select a password: ";
            getline(cin, a.password);


            fstream file;
            file.open("Account staff.txt", ios::app);
      
            if (file)
            {
                cout << "File created and data got written to file\n";
                file << a.username << endl << a.password << endl;
                file.close();
                system("pause");
                a.id = -1;
                return a;
            }
            else
            {
                cout << "Error while creating the file\n";
            }
        }
        else
        {
            


            system("cls");

            cout << "\n\n\n\n\n\n\t\t\t\t\t****** Register Students ******" << endl;
            cout << "\t\t\t\t\t\t    ";
            cout << "Select a username: ";
            cin.ignore();
            getline(cin, a.username);
            cout << "\t\t\t\t\t              Select a password: ";
            getline(cin, a.password);


            fstream file;
            file.open("Account students.txt", ios::app);
 
            if (file)
            {
                cout << "File created and data got written to file\n";
                file << a.username << endl << a.password << endl;
                file.close();
                system("pause");
                a.id = -1;
                return a;
            }
            else
            {
                cout << "Error while creating the file\n";
            }
        }
    }
    else if ( choice == 2)
    {
        
        if (x == 1) {
            if (isLoggedInStaff(a))
            {
                cout << "Successfully logged in!\n";
                a.id = 1;
                _sleep(1000);
                return a;
            }
            else
            {
                cout << "username or password is wrong\n";
                system("pause");
                a.id = -1;
                return a;
            }
        }
        else
        {
            if (isLoggedInStudents(a))
            {
                cout << "Successfully logged in!\n";
                a.id = 1;
                _sleep(1000);
                return a;
            }
            else
            {
                cout << "username or password is wrong\n";
                system("pause");
                a.id = -1;
                return a;
            }
        }
    }
    else
    {
 
    a.id = -1;
        return a;
    }

}