#include "login.h"
#include "display_header.h"

void printLoginMenu1() {

	system("cls");

	cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t****** LOGIN ******" << endl;

	cout << "\t\t\t\t\t*********************************************" << endl;

	cout << "\t\t\t\t\t*\t    ";

	cout << " 1. Academic staff  ";

	cout << "            *" << endl;

	cout << "\t\t\t\t\t*            2. Students                    *" << endl;
	cout << "\t\t\t\t\t*            3. Exit                        *" << endl;
	cout << "\t\t\t\t\t*********************************************" << endl;
	cout << "\t\t\t\t\t             Your choice: ";

	return;

}

void printLoginMenu2(int n) {

	if (n == 1) {
		system("cls");

		cout << "\n\n\n\n\n\n\t\t\t\t\t\t****** Academic staff ******" << endl;

		cout << "\t\t\t\t\t*********************************************" << endl;

		cout << "\t\t\t\t\t*\t    ";

		cout << "    1: Register  ";

		cout << "               *" << endl;

		cout << "\t\t\t\t\t*               2: Login                    *" << endl;
		cout << "\t\t\t\t\t*               3. Back                     *" << endl;
		cout << "\t\t\t\t\t*********************************************" << endl;
		cout << "\t\t\t\t\t              Your choice: ";
	}
	else if ( n == 2)
	{
		system("cls");

		cout << "\n\n\n\n\n\n\t\t\t\t\t\t    ****** Students ******" << endl;

		cout << "\t\t\t\t\t*********************************************" << endl;

		cout << "\t\t\t\t\t*\t    ";

		cout << "    1: Register  ";

		cout << "               *" << endl;

		cout << "\t\t\t\t\t*               2: Login                    *" << endl;
		cout << "\t\t\t\t\t*               3. Back                     *" << endl;
		cout << "\t\t\t\t\t*********************************************" << endl;
		cout << "\t\t\t\t\t              Your choice: ";
	}
	else
	{
		return;
	}
		return;
}



void printMenuStaff1(string username) {
	system("cls");

	time_t now = time(0);
	char* dt = ctime(&now);
	cout << "The local date and time is: " << dt << endl;
	cout << "\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t Xin chao " + username + " ! \n\n";

	cout <<	"\t\t\t\t\t   ************** Staff ***************" << endl;
	cout << "\t\t\t\t\t*********************************************" << endl;
	cout << "\t\t\t\t\t*               1: User Account             *" << endl;
	cout << "\t\t\t\t\t*               2: My Course                *" << endl;
	cout << "\t\t\t\t\t*               3. Log out                  *" << endl;
	cout << "\t\t\t\t\t*********************************************" << endl;
	cout << "\t\t\t\t\t              Your choice: ";


	return;
}

void printMenuStudents1(string username) {
	system("cls");

	time_t now = time(0);
	char* dt = ctime(&now);
	cout << "The local date and time is: " << dt << endl;
	cout << "\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t Xin chao " + username + " ! \n\n";

	cout << "\t\t\t\t\t   ************** Students ***************" << endl;
	cout << "\t\t\t\t\t*********************************************" << endl;
	cout << "\t\t\t\t\t*               1: User Account             *" << endl;
	cout << "\t\t\t\t\t*               2: Register For The Course  *" << endl;
	cout << "\t\t\t\t\t*               3. Log out                  *" << endl;
	cout << "\t\t\t\t\t*********************************************" << endl;
	cout << "\t\t\t\t\t              Your choice: ";


	return;
}

void printUserMenu(string username, string password) {
	system("cls");

	time_t now = time(0);
	char* dt = ctime(&now);
	cout << "The local date and time is: " << dt << endl;
	cout << "\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t Xin chao " + username + " ! \n\n";

	cout << "\t\t\t\t\t   ************** User Account ***************" << endl;
	cout << "\t\t\t\t\t*********************************************" << endl;
	cout << "\t\t\t\t\t*               1: Change The Password      *" << endl;
	cout << "\t\t\t\t\t*               2. Back                     *" << endl;
	cout << "\t\t\t\t\t*********************************************" << endl;
	cout << "\t\t\t\t\t              Your choice: ";


	return;
}


void printMenuCreateCourse() {
	system("cls");

	time_t now = time(0);
	char* dt = ctime(&now);
	cout << "The local date and time is: " << dt << endl;
	cout << "\n\n\n\n\n\n";

	cout << "\t\t\t\t\t   ************** User Account ***************" << endl;
	cout << "\t\t\t\t\t*********************************************" << endl;
	cout << "\t\t\t\t\t*               1: Create Course            *" << endl;
	cout << "\t\t\t\t\t*               2. My Course                *" << endl;
	cout << "\t\t\t\t\t*               3. Back                     *" << endl;
	cout << "\t\t\t\t\t*********************************************" << endl;
	cout << "\t\t\t\t\t              Your choice: ";


	return;
}



void printMenuMyCourse() {
	cout << endl << endl << endl;
	cout << "\t\t\t\t\t   ************** My Course ***************" << endl;
	cout << "\t\t\t\t\t*********************************************" << endl;
	cout << "\t\t\t\t\t*               1: View List of Courses     *" << endl;
	cout << "\t\t\t\t\t*               2. Update Course            *" << endl;
	cout << "\t\t\t\t\t*               3. Remove                   *" << endl;
	cout << "\t\t\t\t\t*               4. Back                     *" << endl;
	cout << "\t\t\t\t\t*********************************************" << endl;
	cout << "\t\t\t\t\t              Your choice: ";
}


void printViewListOfCourse() {
	cout << endl << "\n\t\t\t============================= Danh sach lop hoc  ====================================\n\n";
	cout << left << setw(10) << "No";
	cout << left << setw(15) << "ID"
		<< left << setw(25) << "Last Name"
		<< left << setw(15) << "First Name"
		<< left << setw(15) << "Gender"
		<< left << setw(15) << "Date Of Birth"
		<< left << setw(15) << "OtherMark"
		<< left << setw(15) << "MidtermMark"
		<< left << setw(15) << "FinalMark"
		<< left << setw(15) << "|TotalMark|";
	cout << endl << endl;
}

void printUpdateOfCourse() {
	cout << endl << endl << endl;
	cout << "\t\t\t\t\t   ************** Update Course ***************" << endl;
	cout << "\t\t\t\t\t*********************************************" << endl;
	cout << "\t\t\t\t\t*               1: Add Students From File   *" << endl;
	cout << "\t\t\t\t\t*               2. Import the scoreboard    *" << endl;
	cout << "\t\t\t\t\t*               3. Update a student result  *" << endl;
	cout << "\t\t\t\t\t*               4. Export to a CSV file     *" << endl;
	cout << "\t\t\t\t\t*               5. Back                     *" << endl;
	cout << "\t\t\t\t\t*********************************************" << endl;
	cout << "\t\t\t\t\t              Your choice: ";
}




void printMenuRegisterCourse() {
	system("cls");

	time_t now = time(0);
	char* dt = ctime(&now);
	cout << "The local date and time is: " << dt << endl;
	cout << "\n\n\n\n\n\n";

	cout << "\t\t\t\t\t   ************ Register Course *************" << endl;
	cout << "\t\t\t\t\t*********************************************" << endl;
	cout << "\t\t\t\t\t*               1: Register Course          *" << endl;
	cout << "\t\t\t\t\t*               2. My Course                *" << endl;
	cout << "\t\t\t\t\t*               3. Back                     *" << endl;
	cout << "\t\t\t\t\t*********************************************" << endl;
	cout << "\t\t\t\t\t              Your choice: ";


	return;
}