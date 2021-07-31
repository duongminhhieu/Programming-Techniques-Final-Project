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

	while (!ifs.eof())
	{
		string tmp;
		ifs >> tmp;
		int n = tmp.find(",");
		string tmp2;
		for (size_t i = 0; i < n; i++)
		{
			tmp2 += tmp[i];
		}
		if (tmp2 == name) {
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
	
	// Create
	if (x == 1) {
		ofstream ofs;
		ofs.open("staff.csv", ios::app);

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

		ofs << s.name << "," << s.courseID << "," << s.courseName << "," << s.Class << "," << s.startDate.day
			<< "/" << s.startDate.month << "/" << s.startDate.year << "," << s.endDate.day
			<< "/" << s.endDate.month << "/" << s.endDate.year << "," << s.DayOfWeek << "," << s.startHour << ","
			<< s.endHour << "," << s.room << endl;

		ofs.close();

		ofstream ou;
		ou.open(s.courseID + "_Students.csv");
		ou.close();

		cout << endl << endl << " Create Successfuly \n\n";
		system("pause");
		return -2;
	}

	if (x == 2) {
		system("cls");
		ifstream ifs;
		ifs.open("staff.csv");

		if (!ifs.is_open()) {
			cout << endl << endl << " Nothing!" << endl;
			system("pause");
			return -2;
		}

		cout << endl << "\n\t\t\t============================= Danh sach  ====================================\n\n";
		cout << left << setw(10) << "No";
		cout << left << setw(15) << "Course ID"
			<< left << setw(25) << "Course Name"
			<< left << setw(15) << "Class"
			<< left << setw(15) << "Start Day"
			<< left << setw(15) << "End Day"
			<< left << setw(15) << "Day Of Week"
			<< left << setw(15) << "Start Hour"
			<< left << setw(15) << "End Hour"
			<< left << setw(15) << "Room";
		cout << endl;

		int count = 0;
		while (!ifs.eof())
		{
			string tmp;
			getline(ifs, tmp);
			int n = tmp.find(",");
			if (n == -1) break;
			string tmp2;
			for (size_t i = 0; i < n; i++)
			{
				tmp2 += tmp[i];
			}
			if (tmp2 == userName) {
				count += 1;
			}
		}
		ifs.close();
		ifs.open("staff.csv");

		int m = 0;
		int n;
		Staff* a = new Staff[count];
		while (!ifs.eof())
		{
			string tmp;
			getline(ifs, tmp);
			n = tmp.find(",");
			if (n == -1) break;
			string tmp2;
			for (size_t i = 0; i < n; i++)
			{
				tmp2 += tmp[i];
			}
			if (tmp2 == userName) {
				a[m].name = userName;

				for (int j = n + 1; j <= tmp.length(); j++)
				{
					if (tmp[j] == ',') {
						n = j;
						break;
					}
					a[m].courseID += tmp[j];
					n = j;
				}
				for (size_t j = n + 1; j <= tmp.length(); j++)
				{
					if (tmp[j] == ',') {
						n = j;
						break;
					}
					a[m].courseName += tmp[j];
					n = j;
				}
				for (size_t j = n + 1; j <= tmp.length(); j++)
				{
					if (tmp[j] == ',') {
						n = j;
						break;
					}
					a[m].Class += tmp[j];
					n = j;
				}

				string date = "";
				while (true)
				{
					if (tmp[n + 1] == '/') {
						n = n + 1;
						break;
					}
					date += tmp[n + 1];
					n = n + 1;
				}
				a[m].startDate.day = atoi(date.c_str());

				date = "";
				while (true)
				{
					if (tmp[n + 1] == '/') {
						n = n + 1;
						break;
					}
					date += tmp[n + 1];
					n = n + 1;
				}
				a[m].startDate.month = atoi(date.c_str());

				date = "";
				while (true)
				{
					if (tmp[n + 1] == '/' || tmp[n + 1] == ',') {
						n = n + 1;
						break;
					}
					date += tmp[n + 1];
					n = n + 1;
				}
				a[m].startDate.year = atoi(date.c_str());


				date = "";
				while (true)
				{
					if (tmp[n + 1] == '/') {
						n = n + 1;
						break;
					}
					date += tmp[n + 1];
					n = n + 1;
				}
				a[m].endDate.day = atoi(date.c_str());

				date = "";
				while (true)
				{
					if (tmp[n + 1] == '/') {
						n = n + 1;
						break;
					}
					date += tmp[n + 1];
					n = n + 1;
				}
				a[m].endDate.month = atoi(date.c_str());

				date = "";
				while (true)
				{
					if (tmp[n + 1] == '/' || tmp[n + 1] == ',') {
						n = n + 1;
						break;
					}
					date += tmp[n + 1];
					n = n + 1;
				}
				a[m].endDate.year = atoi(date.c_str());


				for (size_t j = n + 1; j <= tmp.length(); j++)
				{
					if (tmp[j] == ',') {
						n = j;
						break;
					}
					a[m].DayOfWeek += tmp[j];
					n = j;
				}

				for (size_t j = n + 1; j <= tmp.length(); j++)
				{
					if (tmp[j] == ',') {
						n = j;
						break;
					}
					a[m].startHour += tmp[j];
					n = j;
				}
				for (size_t j = n + 1; j <= tmp.length(); j++)
				{
					if (tmp[j] == ',') {
						n = j;
						break;
					}
					a[m].endHour += tmp[j];
					n = j;
				}
				for (size_t j = n + 1; j <= tmp.length(); j++)
				{
					if (tmp[j] == ',') {
						n = j;
						break;
					}
					a[m].room += tmp[j];
					n = j;
				}
				m += 1;
			}
		}

		for (size_t i = 0; i < count; i++)
		{
			string date1 = to_string((a + i)->startDate.day) + "/" + to_string((a + i)->startDate.month) + "/" + to_string((a + i)->startDate.year);
			string date2 = to_string((a + i)->endDate.day) + "/" + to_string((a + i)->endDate.month) + "/" + to_string((a + i)->endDate.year);
			cout << endl;
			cout << left << setw(10) << i + 1;
			cout << left << setw(15) << (a + i)->courseID
				<< left << setw(25) << (a + i)->courseName
				<< left << setw(15) << (a + i)->Class
				<< left << setw(15) << date1
				<< left << setw(15) << date2
				<< left << setw(15) << (a + i)->DayOfWeek
				<< left << setw(15) << (a + i)->startHour
				<< left << setw(15) << (a + i)->endHour
				<< left << setw(15) << (a + i)->room;
		}


		cout << endl << endl;
		printMenuMyCourse();
		int chose;
		cin >> chose;
		if (chose == 1) {
			cout << endl << " Enter Class No: ";
			cin >> chose;
			printViewListOfCourse();
			ifstream i;
			i.open(a[chose - 1].courseID + "_Students.csv");

			int countSt = 0;
			string test;
			while (i >> test)
			{
				countSt = 1;
				break;
			}
			if (countSt == 0) {
				cout << endl << "Nothing!" << endl;
				system("pause");
				return -2;
			}
			countSt = 0;
			i.close();
			i.open(a[chose - 1].courseID + "_Students.csv");

			while (!i.eof())
			{

				getline(i, test);
				countSt += 1;
			}

			i.close();
			i.open(a[chose - 1].courseID + "_Students.csv");
			//countSt = countSt - 1;
			Student* st = new Student[countSt];
			m = 0;
			while (!i.eof())
			{
				st[m].No = m + 1;

				string tmp;
				getline(i, tmp);
				int n = tmp.find(",");
				if (n == -1) break;
				test = "";
				for (size_t i = 0; i < n; i++)
				{
					test += tmp[i];
				}
				(st + m)->ID = atoi(test.c_str());

				for (size_t j = n + 1; j <= tmp.length(); j++)
				{
					if (tmp[j] == ',') {
						n = j;
						break;
					}
					(st + m)->name.lastName += tmp[j];
					n = j;
				}

				for (size_t j = n + 1; j <= tmp.length(); j++)
				{
					if (tmp[j] == ',') {
						n = j;
						break;
					}
					(st + m)->name.firstName += tmp[j];
					n = j;
				}
				for (size_t j = n + 1; j <= tmp.length(); j++)
				{
					if (tmp[j] == ',') {
						n = j;
						break;
					}
					(st + m)->Gender += tmp[j];
					n = j;
				}

				string sc = "";
				for (size_t j = n + 1; j <= tmp.length(); j++)
				{
					if (tmp[j] == ',') {
						n = j;
						break;
					}
					sc += tmp[j];
					n = j;
				}
				(st + m)->score.OtherMark = atoi(sc.c_str());

				sc = "";
				for (size_t j = n + 1; j <= tmp.length(); j++)
				{
					if (tmp[j] == ',') {
						n = j;
						break;
					}
					sc += tmp[j];
					n = j;
				}
				(st + m)->score.MidtermMark = atoi(sc.c_str());

				sc = "";
				for (size_t j = n + 1; j <= tmp.length(); j++)
				{
					if (tmp[j] == ',') {
						n = j;
						break;
					}
					sc += tmp[j];
					n = j;
				}
				(st + m)->score.FinalMark = atoi(sc.c_str());

				sc = "";
				for (size_t j = n + 1; j <= tmp.length(); j++)
				{
					if (tmp[j] == ',') {
						n = j;
						break;
					}
					sc += tmp[j];
					n = j;
				}
				(st + m)->score.TotalMark = atoi(sc.c_str());

				m += 1;
				if (m == countSt) break;
			}

			i.close();

			for (size_t i = 0; i < countSt; i++)
			{
				cout << left << setw(10) << i + 1;
				cout << left << setw(15) << (st + i)->ID
					<< left << setw(25) << (st + i)->name.lastName
					<< left << setw(15) << (st + i)->name.firstName
					<< left << setw(15) << (st + i)->Gender
					<< left << setw(15) << (st + i)->score.OtherMark
					<< left << setw(15) << (st + i)->score.MidtermMark
					<< left << setw(15) << (st + i)->score.FinalMark
					<< left << setw(15) << (st + i)->score.TotalMark;
				cout << endl;
			}

			cout << endl << endl;
			system("pause");
			return -2;

		}

		if (chose == 3) {
			cout << endl << "Enter Class No: ";
			cin >> chose;

			string test = a[chose - 1].courseID + "_Students.csv";
			remove(test.c_str());

			if (count == 1) {
				ofstream of;
				of.open("staff.csv");
				of << "";
				of.close();

				string test = a[0].courseID + "_Students.csv";
				remove(test.c_str());
				cout << endl << endl;
				cout << " Remove Successfully ! \n";
				system("pause");
				return -2;
			}

			Staff* b = new Staff[count];

			for (size_t i = 0; i < count; i++)
			{
				b[i] = a[i];
			}

			a = new Staff[count - 1];
			int h = 0;
			for (size_t i = 0; i < count; i++)
			{
				if (i == chose - 1) continue;
				a[h] = b[i];
				h += 1;
			}
			count = count - 1;

			ofstream ofs;
			ofs.open("staff.csv");

			for (size_t i = 0; i < count; i++)
			{
				ofs << a[i].name << "," << a[i].courseID << "," << a[i].courseName << "," << a[i].Class << "," << a[i].startDate.day
					<< "/" << a[i].startDate.month << "/" << a[i].startDate.year << "," << a[i].endDate.day
					<< "/" << a[i].endDate.month << "/" << a[i].endDate.year << "," << a[i].DayOfWeek << "," << a[i].startHour << ","
					<< a[i].endHour << "," << a[i].room << endl;
			}

			ofs.close();


			cout << endl << endl;
			cout << " Remove Successfully ! \n";
			system("pause");
			return -2;
		}
		if (chose == 4) return -2;
		
		
	}

	if (x == 3) return -2;

}



