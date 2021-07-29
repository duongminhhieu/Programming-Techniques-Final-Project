#include "login.h"
#include "display_header.h"


int main() {
	int choose;
	Login a;
	do {
		
		printLoginMenu1();
		do
		{
			cin >> choose;
		} while (choose < 0 || choose > 3);

		if (choose == 1) {
			printLoginMenu2(1);
			a = login(1);
			if (a.id == 1) {
				a.who = 1;
				do
				{
					printMenuStaff1(a.username);
					choose_Login(a);
				} while (a.id == -2);
				
			}
		}
		else if (choose == 2)
		{
			printLoginMenu2(2);
			a = login(2);
			if (a.id == 1) {
				a.who = 2;
				do
				{
					printMenuStudents1(a.username);
					choose_Login(a);
				} while (a.id == -2 );
				
			}
		}
		else
		{
			break;
		}
	} while (a.id == -1);



	cout << endl << endl;
	system("pause");
	return 0;
}