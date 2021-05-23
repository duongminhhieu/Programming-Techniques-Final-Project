#include "login.h"

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

