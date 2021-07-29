#include "login.h"
#include "display_header.h"
#include "func.h"

int checkStaff(string name) {
	ifstream ifs;
	
	ifs.open("staff.csv");

	if (!ifs) {
		ifs.close();
		return 0;
	}

	while (ifs.eof())
	{
		string tmp;
		ifs >> tmp;
		if (tmp == name) {
			ifs.close();
			return 1;
		}
	}


	ifs.close();
	return 0;
}


int createCourse(string userName) {

	int x;
	
	cin >> x;
	if (x == 3) return -2;

	if (x == 2) {
		system("cls");
		ifstream ifs;
		ifs.open("staff.csv");

		if (!ifs) {
			cout << endl << endl << " Nothing!" << endl;
			system("pause");
			return -2;
		}
		cout << endl << "\n============================= Danh sach  ====================================\n\n";
		cout << left << setw(15) << "Course ID"
			<< left << setw(25) << "Course Name"
			<< left << setw(20) << "Class"
			<< left << setw(20) << "Start Day"
			<< left << setw(20) << "End Day"
			<< left << setw(20) << "Day Of Week"
			<< left << setw(20) << "Start Hour"
			<< left << setw(20) << "End Hour"
			<< left << setw(20) << "Room";
		cout << endl;

		while(ifs.eof())
		{
			cout << endl;
			cout << left << setw(15) << k->data.maso
				<< left << setw(25) << k->data.hoten;

			if (k->data.GioiTinh == 1) {
				cout << left << setw(20) << " Nam ";
			}
			else
			{
				cout << left << setw(20) << " Nu ";
			}
			cout << left << k->data.NgaySinh.ng
				<< "/" << k->data.NgaySinh.th
				<< "/" << k->data.NgaySinh.nam;
			cout << "\t\t" << left << k->data.Diem;
		}
		cout << endl << endl;
	}


	ofstream ofs;
	ofs.open("staff.csv");

	Staff s;
	cout << endl << " Enter Course ID: ";
	cin.ignore();
	getline(cin, s.courseID);
	cout << " Enter Course Name: ";
	getline(cin, s.courseName);
	cout << " Enter Class: ";
	getline(cin, s.Class);
	s.name = userName;
	cout << " Enter start Day (Day, Month, Year): ";
	cin >> s.startDate.day;
	cin >> s.startDate.month;
	cin >> s.startDate.year;
	
	cout << " Enter End Day (Day, Month, Year): ";
	cin >> s.endDate.day;
	cin >> s.endDate.month;
	cin >> s.endDate.year;
	
	cin.ignore();
	cout << " Day Of Week: ";
	getline(cin, s.DayOfWeek);

	cout << " Enter Start Hour: ";
	getline(cin, s.startHour);
	cout << " Enter End Hour: ";
	getline(cin, s.endHour);

	cout << " Enter Room: ";
	getline(cin, s.room);

	ofs << s.courseID << "," << s.courseName << "," << s.Class << "," << s.name << "," << s.startDate.day
		<< "/" << s.startDate.month << "/" << s.startDate.year << "," << s.endDate.day
		<< "/" << s.endDate.month << "/" << s.endDate.year << "," << s.DayOfWeek << "," << s.startHour << ","
		<< s.endHour << "," << s.room << endl;

	ofs.close();


	cout << endl << endl << " Create Successfuly \n\n";
	system("pause");
	return -2;
}



