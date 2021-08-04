#include "login.h"
#include "display_header.h"
#include "func.h"

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

            // check thử tài khoản đã tồn tại chưa
            fstream file;
            file.open("Account staff.txt", ios::in);

            while (!file.eof()) {
                string tmp;
                getline(file, tmp);
                if (tmp == a.username) {
                    cout << " Account already exists!\n";
                    system("pause");
                    a.id = -1;
                    return a;
                }
            }
            file.close();

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


            // check thử tài khoản đã tồn tại chưa
            fstream file;
            file.open("Account students.txt", ios::in);

            while (!file.eof()) {
                string tmp;
                getline(file, tmp);
                if (tmp == a.username) {
                    cout << " Account already exists!\n";
                    system("pause");
                    a.id = -1;
                    return a;
                }
            }
            file.close();

            Student st;
            cout << endl << " Enter ID: ";
            cin >> st.ID;
            cout << " Enter LastName: ";
            cin.ignore();
            getline(cin, st.name.lastName);
            cout << " Enter FirstName: ";
            getline(cin, st.name.firstName);
            cout << " Enter Gender: ";
            getline(cin, st.Gender);
            cout << " Enter Day of Birth ( day, month, year): ";
            cin >> st.birth.day >> st.birth.month >> st.birth.year;
            
            file.open("Account students.txt", ios::app);
 
            if (file)
            {
                cout << "File created and data got written to file\n";
                file << a.username << endl << a.password << endl;
                file.close();

                file.open("Students.csv", ios::app);
                file << st.ID << "," << st.name.lastName << "," << st.name.firstName << "," << st.Gender << "," << st.birth.day
                    << "/" << st.birth.month << "/" << st.birth.year << "," << st.score.OtherMark
                    << "," << st.score.MidtermMark << "," << st.score.FinalMark << "," << st.score.TotalMark << endl;

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
                cout << endl;
                system("pause");
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
                system("pause");
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



int findNumberLinesfile(int who) {

    if (who == 1){
        ifstream f1;
        char c;
        int numlines;

        f1.open("Account staff.txt");
        numlines = 0;
        f1.get(c);
        while (f1) {
  
            numlines = numlines + 1;
            f1.get(c);
        }
        f1.close();
        return numlines;
    }
    else
    {
        ifstream f1;
        char c;
        int numlines;

        f1.open("Account Students.txt");
        numlines = 0;
        f1.get(c);
        while (f1) {

            numlines = numlines + 1;
            f1.get(c);
        }
        f1.close();
        return numlines;
    }
    
}

void delete_line(const char* file_name, int n)
{
    // open file in read mode or in mode
    ifstream is(file_name);

    // open file in write mode or out mode
    ofstream ofs;
    ofs.open("temp.txt", ofstream::out);

    // loop getting single characters
    char c;
    int line_no = 1;
    while (is.get(c))
    {
        // if a newline character
        if (c == '\n')
            line_no++;

        // file content not to be deleted
        if (line_no != n)
            ofs << c;
    }

    // closing output file
    ofs.close();

    // closing input file
    is.close();

    // remove the original file
    remove(file_name);

    // rename the file
    rename("temp.txt", file_name);
}

void insertLine(const char* file_name, int n, string passNew ) {
    // open file in read mode or in mode
    ifstream is(file_name);

    // open file in write mode or out mode
    ofstream ofs;
    ofs.open("temp.txt", ofstream::out);

    int check = 0;
    
    while (!is.eof())
    {
        string tmp;
        getline(is, tmp);
        check += 1;
        if (check == n) {
            ofs << tmp << endl ;
            ofs << passNew << endl ;
        }
        else
        {
            ofs << tmp << "\n";
        }

    }

    // closing output file
    ofs.close();

    // closing input file
    is.close();

    // remove the original file
    remove(file_name);

    // rename the file
    rename("temp.txt", file_name);

}

void change_Pass(Login &a) {
    int x;
    cin >> x;
    if (x == 2) {
        a.id = -2;
        return ;
    }
    else
    {
        string tmp;
        cout << "\n\n\n\n\n\n\t\t\t\t\t****** Change Password ******" << endl;
        cin.ignore();
        do {
            cout << "\n\t\t\t\t\t\t Enter password: " ;
            getline(cin, tmp);
        } while (tmp != a.password);
       
        cout << "\t\t\t\t\t\t Enter new password: ";
        tmp = "";
        getline(cin, tmp);
        
        fstream file;
        int numLines = findNumberLinesfile(a.who); //number of lines in the file

        

       //tim dong can doi mk
        int line = 0;
        if (a.who == 1) {
            file.open("Account staff.txt", ios::in);
        }
        else
        {
            file.open("Account Students.txt", ios::in);
        }

        while (!file.eof())
        {
            string tmp2;
            getline(file, tmp2);
            if (tmp2 == a.username) {
                line += 2;
                file.close();
                break;
            }
            line += 1;
        }
        //================
        
        
        if (a.who == 1) {
            insertLine("Account staff.txt", line, tmp);
            delete_line("Account staff.txt", line);
        }
        else
        {
            insertLine("Account Students.txt", line, tmp);
            delete_line("Account Students.txt", line);
        }
        cout << "\n\n" << " Password changed Successfully\n";
        cout  << " You Must Login Again !\n\n";
        system("pause");
        a.id = -1;
        return;
    }
}

void choose_Login(Login &a) {
   
    int x;
    cin >> x;

    switch (x)
    {
    case 1 :
          printUserMenu(a.username, a.password);
          change_Pass(a);
          break;

    case 2:
           printMenuCreateCourse();
           a.id = createCourse(a.username);
        break;
    case 3 :
        a.id = -1;
        break;
    default:
        break;
    }

    return;
}


void choose_Login2(Login& a) {

    int x;
    cin >> x;

    switch (x)
    {
    case 1:
        printUserMenu(a.username, a.password);
        change_Pass(a);
        break;

    case 2:
        printMenuRegisterCourse();
        a.id = registerCourse(a.username);
        break;
    case 3:
        a.id = -1;
        break;
    default:
        break;
    }

    return;
}

