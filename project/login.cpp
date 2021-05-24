#include "login.h"


bool isLoggedInStaff()
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

    ifstream read("Acount staff.txt");


    while (!read.eof())
    {
        getline(read, un);
        getline(read, pw);

        if (un == username && pw == password)
        {
            return true;
        }
    }

    return false;
}


bool isLoggedInStudents()
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

    ifstream read("Acount students.txt");


    while (!read.eof())
    {
        getline(read, un);
        getline(read, pw);

        if (un == username && pw == password)
        {
            return true;
        }
    }

    return false;
}

int login(int x )
{
    int choice;
    cin >> choice;


    if (choice == 1)
    {
        if (x == 1) {
            string username, password;


            system("cls");

            cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t****** Register Staff ******" << endl;
            cout << "\t\t\t\t\t\t    ";
            cout << "Select a username: ";
            cin.ignore();
            getline(cin, username);
            cout << "\t\t\t\t\t              Select a password: ";
            getline(cin, password);


            fstream file;
            file.open("Acount staff.txt", ios::app);
      
            if (file)
            {
                cout << "File created and data got written to file\n";
                file << username << endl << password << endl;
                file.close();
                system("pause");
                return -1;
            }
            else
            {
                cout << "Error while creating the file\n";
            }
        }
        else
        {
            string username, password;


            system("cls");

            cout << "\n\n\n\n\n\n\t\t\t\t\t****** Register Students ******" << endl;
            cout << "\t\t\t\t\t\t    ";
            cout << "Select a username: ";
            cin.ignore();
            getline(cin, username);
            cout << "\t\t\t\t\t              Select a password: ";
            getline(cin, password);


            fstream file;
            file.open("Acount students.txt", ios::app);
 
            if (file)
            {
                cout << "File created and data got written to file\n";
                file << username << endl << password << endl;
                file.close();
                system("pause");
                return -1;
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
            if (isLoggedInStaff())
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
            if (isLoggedInStudents())
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
    }
    else
    {
        return -1;
    }
    return 0;
}