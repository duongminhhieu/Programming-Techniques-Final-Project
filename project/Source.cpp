#include "login.h"

int main() {
	int choose, x = 1;
	do {
		
		printLoginMenu1();
		do
		{
			cin >> choose;
		} while (choose < 0 || choose > 3);

		if (choose == 1) {
			printLoginMenu2(1);
			x = login(1);
		}
		else if (choose == 2)
		{
			printLoginMenu2(2);
			x = login(2);
		}
		else
		{
			break;
		}
	} while (x == -1);



	cout << endl << endl;
	system("pause");
	return 0;
}