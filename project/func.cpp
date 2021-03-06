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
	
	// Create Course
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

	// My Crouse
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
				a[m].startDate.day = atof(date.c_str());

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
				a[m].startDate.month = atof(date.c_str());

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
				a[m].startDate.year = atof(date.c_str());


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
				a[m].endDate.day = atof(date.c_str());

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
				a[m].endDate.month = atof(date.c_str());

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
				a[m].endDate.year = atof(date.c_str());


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

		// View List
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
				if (test == "") break;
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
				(st + m)->ID = atof(test.c_str());

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
				(st + m)->birth.day = atof(date.c_str());

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
				(st + m)->birth.month = atof(date.c_str());

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
				(st + m)->birth.year = atof(date.c_str());

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
				(st + m)->score.OtherMark = atof(sc.c_str());

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
				(st + m)->score.MidtermMark = atof(sc.c_str());

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
				(st + m)->score.FinalMark = atof(sc.c_str());

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
				(st + m)->score.TotalMark = atof(sc.c_str());

				m += 1;
				if (m == countSt) break;
			}

			i.close();

			for (size_t i = 0; i < countSt; i++)
			{
				string date1 = to_string((st + i )->birth.day) + "/" + to_string((st + i )->birth.month)
					+ "/" + to_string((st + i )->birth.year);
				cout << left << setw(10) << i + 1;
				cout << left << setw(15) << (st + i )->ID
					<< left << setw(25) << (st + i )->name.lastName
					<< left << setw(15) << (st + i )->name.firstName
					<< left << setw(15) << (st + i )->Gender
					<< left << setw(15) << date1
					<< left << setw(15) << (st + i )->score.OtherMark
					<< left << setw(15) << (st + i )->score.MidtermMark
					<< left << setw(15) << (st + i )->score.FinalMark
					<< left << setw(15) << (st + i )->score.TotalMark;
				cout << endl;
			}

			cout << endl << endl;
			system("pause");
			return -2;

		}

		// Update File
		if (chose == 2) {
			printUpdateOfCourse();
			cin >> chose;

			// Add students from file
			if (chose == 1) {
				
				cout << endl << " Enter Class No: ";
				cin >> chose;

				ifstream i;
				
				ofstream ofs;
				i.open("FileImportStudents.csv");
				ofs.open(a[chose - 1].courseID + "_Students.csv", ios:: app);

				string test;
				int countSt = 0;
				while (!i.eof())
				{
					getline(i, test);
					if (test == "") break;
					countSt += 1;
				}

				i.close();
				i.open("FileImportStudents.csv");
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
					(st + m)->ID = atof(test.c_str());

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
					(st + m)->birth.day = atof(date.c_str());

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
					(st + m)->birth.month = atof(date.c_str());

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
					(st + m)->birth.year = atof(date.c_str());


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
					(st + m)->score.OtherMark = atof(sc.c_str());

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
					(st + m)->score.MidtermMark = atof(sc.c_str());

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
					(st + m)->score.FinalMark = atof(sc.c_str());

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
					(st + m)->score.TotalMark = atof(sc.c_str());

					m += 1;
					if (m == countSt) break;
				}

				for (size_t i = 0; i < countSt; i++)
				{
					ofs << (st + i )->ID << "," << (st + i )->name.lastName << "," << (st + i )->name.firstName
						<< "," << (st + i )->Gender << "," << (st + i )->birth.day
						<< "/" << (st + i )->birth.month << "/" << (st + i )->birth.year << ","
						<< (st + i )->score.OtherMark << "," << (st + i )->score.MidtermMark << "," 
						<< (st + i )->score.FinalMark << "," << (st + i )->score.TotalMark << endl;
				}

				i.close();
				ofs.close();
				
				cout << endl << "Add Students Successfully!" << endl;
				system("pause");
				return -2;
			}

			// Import Score
			if (chose == 2) {
				cout << endl << " Enter Class No: ";
				cin >> chose;

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
					if (test == "") break;
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
					(st + m)->ID = atof(test.c_str());

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
					(st + m)->birth.day = atof(date.c_str());

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
					(st + m)->birth.month = atof(date.c_str());

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
					(st + m)->birth.year = atof(date.c_str());

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
					(st + m)->score.OtherMark = atof(sc.c_str());

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
					(st + m)->score.MidtermMark = atof(sc.c_str());

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
					(st + m)->score.FinalMark = atof(sc.c_str());

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
					(st + m)->score.TotalMark = atof(sc.c_str());

					m += 1;
					if (m == countSt) break;
				}
				i.close();

				for (size_t i = 0; i < countSt; i++)
				{
					cout << endl << " Nhap diem cho sinh vien: ";
					cout << (st + i )->ID << "--" << (st + i )->name.lastName << " " << (st + i )->name.firstName << endl;
					cout << " Other Mark: ";
					cin >> (st + i )->score.OtherMark;
					cout << " MidtermMark: ";
					cin >> (st + i )->score.MidtermMark;
					cout << " FinalMark: ";
					cin >> (st + i )->score.FinalMark;

					(st + i )->score.TotalMark = (st[i].score.OtherMark + st[i].score.MidtermMark * 2 + st[i].score.FinalMark * 3) / 6;
					cout << endl;
				}

				ofstream ofs;
				ofs.open(a[chose - 1].courseID + "_Students.csv");

				for (size_t i = 0; i < countSt; i++)
				{
					ofs << (st + i )->ID << "," << (st + i )->name.lastName << "," << (st + i )->name.firstName
						<< "," << (st + i )->Gender << "," << (st + i )->birth.day
						<< "/" << (st + i )->birth.month << "/" << (st + i )->birth.year << ","
						<< (st + i )->score.OtherMark << "," << (st + i )->score.MidtermMark << ","
						<< (st + i )->score.FinalMark << "," << (st + i )->score.TotalMark << endl;
				}

				cout << endl << " Import ScoreBoard Successfully!" << endl;
				system("pause");
				return -2;
			}

			// Update a students result
			if (chose == 3) {
				cout << endl << " Enter Class No: ";
				cin >> chose;

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
					if (test == "") break;
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
					(st + m)->ID = atof(test.c_str());

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
					(st + m)->birth.day = atof(date.c_str());

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
					(st + m)->birth.month = atof(date.c_str());

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
					(st + m)->birth.year = atof(date.c_str());

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
					(st + m)->score.OtherMark = atof(sc.c_str());

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
					(st + m)->score.MidtermMark = atof(sc.c_str());

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
					(st + m)->score.FinalMark = atof(sc.c_str());

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
					(st + m)->score.TotalMark = atof(sc.c_str());

					m += 1;
					if (m == countSt) break;
				}
				i.close();

				system("cls");
				printViewListOfCourse();
				for (size_t i = 0; i < countSt; i++)
				{
					string date1 = to_string((st + i)->birth.day) + "/" + to_string((st + i)->birth.month)
						+ "/" + to_string((st + i)->birth.year);
					cout << left << setw(10) << i + 1;
					cout << left << setw(15) << (st + i)->ID
						<< left << setw(25) << (st + i)->name.lastName
						<< left << setw(15) << (st + i)->name.firstName
						<< left << setw(15) << (st + i)->Gender
						<< left << setw(15) << date1
						<< left << setw(15) << (st + i)->score.OtherMark
						<< left << setw(15) << (st + i)->score.MidtermMark
						<< left << setw(15) << (st + i)->score.FinalMark
						<< left << setw(15) << (st + i)->score.TotalMark;
					cout << endl;
				}


				ofstream ofs;
				ofs.open(a[chose - 1].courseID + "_Students.csv");

				cout << endl << " Enter Student No: ";
				cin >> chose;
				chose = chose - 1;
				cout << endl << " Update student " << (st + chose )->ID  << "--"
					<< (st + chose )->name.lastName << " " << (st + chose )->name.firstName << endl;

				cout << " Other Mark: ";
				cin >> (st + chose)->score.OtherMark;
				cout << " MidtermMark: ";
				cin >> (st + chose )->score.MidtermMark;
				cout << " FinalMark: ";
				cin >> (st + chose )->score.FinalMark;

				(st + chose )->score.TotalMark = (st[chose].score.OtherMark + st[chose].score.MidtermMark * 2 + st[chose].score.FinalMark * 3) / 6;
				cout << endl;

				for (size_t i = 0; i < countSt; i++)
				{
					ofs << (st + i)->ID << "," << (st + i)->name.lastName << "," << (st + i)->name.firstName
						<< "," << (st + i)->Gender << "," << (st + i)->birth.day
						<< "/" << (st + i)->birth.month << "/" << (st + i)->birth.year << ","
						<< (st + i)->score.OtherMark << "," << (st + i)->score.MidtermMark << ","
						<< (st + i)->score.FinalMark << "," << (st + i)->score.TotalMark << endl;
				}
				
				cout << endl << " Update Successfully! \n";
				system("pause");
				return -2;
				
			}

			// Export A Course to CSV file
			if (chose == 4) {
				cout << " Enter Class No: ";
				cin >> chose;

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
					if (test == "") break;
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
					(st + m)->ID = atof(test.c_str());

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
					(st + m)->birth.day = atof(date.c_str());

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
					(st + m)->birth.month = atof(date.c_str());

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
					(st + m)->birth.year = atof(date.c_str());

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
					(st + m)->score.OtherMark = atof(sc.c_str());

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
					(st + m)->score.MidtermMark = atof(sc.c_str());

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
					(st + m)->score.FinalMark = atof(sc.c_str());

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
					(st + m)->score.TotalMark = atof(sc.c_str());

					m += 1;
					if (m == countSt) break;
				}
				i.close();
				

				ofstream ofs;
				test = "Export Course ID " + a[chose - 1].courseID + " to CSVfile.csv";
				ofs.open(test);
				ofs << "Student ID,LastName,FirstName,Gender,DayOfBirth,OtherMark,MidtermMark,FinalMark,TotalMark" << endl;
				for (size_t i = 0; i < countSt; i++)
				{
					ofs << (st + i )->ID << "," << (st + i )->name.lastName << "," << (st + i )->name.firstName
						<< "," << (st + i )->Gender << "," << (st + i )->birth.day
						<< "/" << (st + i )->birth.month << "/" << (st + i )->birth.year << ","
						<< (st + i )->score.OtherMark << "," << (st + i )->score.MidtermMark << ","
						<< (st + i )->score.FinalMark << "," << (st + i )->score.TotalMark << endl;
				}
				
				ofs.close();

				cout << endl << " Export file Successfully!\n File Name: ";
				cout << test << endl;
				system("pause");
				return -2;

			}

			if (chose == 5) return -2;

		}

		//  Remove file
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


void readStaffFile(ifstream& i, Staff* &a, int& count) {

	tm* today; // struct gom ngay, thang, nam, ...
	time_t t;
	t = time(NULL);
	today = localtime(&t); // Lấy thời gian của hệ thống 

	string test;
	while (!i.eof())
	{
		getline(i, test);
		if (test == "") {
			break;
		}

		count += 1;
	}

	int m = 0;
	a = new Staff[count];

	i.close();
	i.open("staff.csv");

	int n;
	while (!i.eof())
	{
		string tmp;
		getline(i, tmp);
		n = tmp.find(",");
		if (n == -1) break;
		string tmp2;
		for (size_t i = 0; i < n; i++)
		{
			tmp2 += tmp[i];
		}
		a[m].name = tmp2;
		
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

	int k = 0;
	for (int i = 0; i < count; i++)
	{
		if ((today->tm_year + 1900) > a[i].startDate.year && (today->tm_year + 1900) < a[i].endDate.year) {

			k += 1;
		}
		else if ((today->tm_year + 1900) == a[i].startDate.year) {
			if ((today->tm_mon + 1) > a[i].startDate.month) {
				k += 1;
			}
			else if ((today->tm_mon + 1) == a[i].startDate.month) {
				if (today->tm_mday >= a[i].startDate.day) {
					k += 1;
				}
			}
		
		}
		else if ((today->tm_year + 1900) == a[i].endDate.year) {
			if ((today->tm_mon + 1) < a[i].endDate.month) {
				k += 1;
			}
			else if ((today->tm_mon + 1) == a[i].endDate.month) {
				if (today->tm_mday <= a[i].endDate.day) {
					k += 1;
				}
			}
		}
	}

	Staff* b = new Staff[k];
	k = 0;
	for (int i = 0; i < count; i++)
	{
		if ((today->tm_year + 1900) > a[i].startDate.year && (today->tm_year + 1900) < a[i].endDate.year) {
			b[k] = a[i];
			k += 1;
		}
		else if ((today->tm_year + 1900) == a[i].startDate.year) {
			if ((today->tm_mon + 1) > a[i].startDate.month) {
				b[k] = a[i];
				k += 1;
			}
			else if ((today->tm_mon + 1) == a[i].startDate.month) {
				if (today->tm_mday >= a[i].startDate.day) {
					b[k] = a[i];
					k += 1;
				}
			}

		}
		else if ((today->tm_year + 1900) == a[i].endDate.year) {
			if ((today->tm_mon + 1) < a[i].endDate.month) {
				b[k] = a[i];
				k += 1;
			}
			else if ((today->tm_mon + 1) == a[i].endDate.month) {
				if (today->tm_mday <= a[i].endDate.day) {
					b[k] = a[i];
					k += 1;
				}
			}
		}
	}

	count = k;
	a = new Staff[count];
	for (size_t i = 0; i < count; i++)
	{
		a[i] = b[i];
	}

}

void readAStudentsFormFile(ifstream& i, Student& st, string userName) {
	
	int m = 0;
	string test;
	while (!i.eof())
	{
		
		st.No = m + 1;
		string tmp;
		getline(i, tmp);
		int n = tmp.find(",");
		if (n == -1) break;
		test = "";
		for (size_t i = 0; i < n; i++)
		{
			test += tmp[i];
		}
		st.ID = atof(test.c_str());

		test = "";
		for (size_t j = n + 1; j <= tmp.length(); j++)
		{
			if (tmp[j] == ',') {
				n = j;
				break;
			}
			test += tmp[j];
			n = j;
		}
		st.name.lastName = test;

		test = "";
		for (size_t j = n + 1; j <= tmp.length(); j++)
		{
			if (tmp[j] == ',') {
				n = j;
				break;
			}
			test += tmp[j];
			n = j;
		}
		st.name.firstName = test;

		string a;
		a = st.name.lastName + " " + st.name.firstName;
		if (a != userName) continue;

		test = "";
		for (size_t j = n + 1; j <= tmp.length(); j++)
		{
			if (tmp[j] == ',') {
				n = j;
				break;
			}
			test += tmp[j];
			n = j;
		}
		st.Gender = test;

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
		st.birth.day = atof(date.c_str());

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
		st.birth.month = atof(date.c_str());

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
		st.birth.year = atof(date.c_str());

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
		st.score.OtherMark = atof(sc.c_str());

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
		st.score.MidtermMark = atof(sc.c_str());

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
		st.score.FinalMark = atof(sc.c_str());

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
		st.score.TotalMark = atof(sc.c_str());

		break;
	}


}

int registerCourse(string userName) {
	int x;
	cin >> x;

	// Register
	if (x == 1) {
		system("cls");
		cout << endl << "\n\t\t\t============================= List of open Courses ====================================\n\n";
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


		ifstream ifs;

		ifs.open("staff.csv");

		if (!ifs.is_open()) {
			cout << endl << " Nothing! " << endl;
			system("pause");
			ifs.close();
			return -2;
		}

		Staff* a;
		int n = 0;
		readStaffFile(ifs, a, n);
		ifs.close();
		for (size_t i = 0; i < n; i++)
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

		ifstream i;
		i.open("Students.csv");
		Student st;
		readAStudentsFormFile(i, st, userName);
		i.close();
		
		ofstream ofs;
		string test = "Course Of Student " + st.name.lastName + " " + st.name.firstName + "---" + to_string(st.ID) + ".csv";
		ifs.open(test.c_str());
		int z = 0;
		string test1;
		while (!ifs.eof())
		{
			getline(ifs, test1);
			if (test1 == "") break;
			z += 1;
		}
		ifs.close();

		int x1;
		cout << endl << "\n\n\n1. Enter Register Course ";
		cout << endl << "2. Back";
		cout << endl << "Choice: ";
		cin >> x1;

		if (x1 == 1) {

			if (z == 5) {
				cout << endl << " You can only register for a maximum of 5 courses! ";
				cout << endl << "You currently have 5 courses" << endl;
				system("pause");
				return -2;
			}
			cout << endl << endl << " Enter No: ";
			cin >> x1;

			ofs.open(test.c_str(), ios::app);
			ofs << a[x1 - 1].name << "," << a[x1 - 1].courseID << "," << a[x1 - 1].courseName << "," << a[x1 - 1].Class << "," << a[x1 - 1].startDate.day
				<< "/" << a[x1 - 1].startDate.month << "/" << a[x1 - 1].startDate.year << "," << a[x1 - 1].endDate.day
				<< "/" << a[x1 - 1].endDate.month << "/" << a[x1 - 1].endDate.year << "," << a[x1 - 1].DayOfWeek << "," << a[x1 - 1].startHour << ","
				<< a[x1 - 1].endHour << "," << a[x1 - 1].room << endl;
			ofs.close();

			ofs.open(a[x1 - 1].courseID + "_Students.csv", ios::app);

			ofs << st.ID << "," << st.name.lastName << "," << st.name.firstName
				<< "," << st.Gender << "," << st.birth.day
				<< "/" << st.birth.month << "/" << st.birth.year << ","
				<< st.score.OtherMark << "," << st.score.MidtermMark << ","
				<< st.score.FinalMark << "," << st.score.TotalMark << endl;
			ofs.close();

			cout << endl << " Register Successfully! \n";
			system("pause");
			return -2;

		}


		if (x1 == 2) return -2;
	}

	// My course
	if (x == 2) {

		printMyCourseStudents();
		cin >> x;

		// Print My course
		if (x == 1) {

			ifstream i;
			i.open("Students.csv");
			Student st;
			readAStudentsFormFile(i, st, userName);
			i.close();

			system("cls");
			ifstream ifs;
			string test = "Course Of Student " + userName + "---" + to_string(st.ID) + ".csv";
			ifs.open(test.c_str());

			if (!ifs.is_open()) {
				cout << endl << endl << " Nothing!" << endl;
				system("pause");
				return -2;
			}

			cout << endl << "\n\t\t\t============================= Registered List  ====================================\n\n";
			cout << left << setw(10) << "No";
			cout << left << setw(25) << "Teacher Name";
			cout << left << setw(15) << "Course ID"
				<< left << setw(25) << "Course Name"
				<< left << setw(15) << "Day Of Week"
				<< left << setw(15) << "Start Hour"
				<< left << setw(15) << "End Hour"
				<< left << setw(15) << "Room";
			cout << endl;

			int count = 0;
			string test1;
			while (!ifs.eof())
			{
				getline(ifs, test1);
				if (test1 == "") break;
				count += 1;

			}

			ifs.close();
			ifs.open(test.c_str());

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

				a[m].name = tmp2;

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
				a[m].startDate.day = atof(date.c_str());

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
				a[m].startDate.month = atof(date.c_str());

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
				a[m].startDate.year = atof(date.c_str());


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
				a[m].endDate.day = atof(date.c_str());

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
				a[m].endDate.month = atof(date.c_str());

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
				a[m].endDate.year = atof(date.c_str());


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
				if (m == count) break;
			}

			// In danh sach 
			cout << endl << endl;
			for (size_t i = 0; i < count; i++)
			{
				cout << left << setw(10) << i + 1;
				cout << left << setw(25) << a[i].name;
				cout << left << setw(15) << a[i].courseID
					<< left << setw(25) << a[i].courseName
					<< left << setw(15) << a[i].DayOfWeek
					<< left << setw(15) << a[i].startHour
					<< left << setw(15) << a[i].endHour
					<< left << setw(15) << a[i].room;
				cout << endl;

			}

			cout << endl << endl;
			system("pause");
			return -2;
		}


		// Remove Course
		if (x == 2) {

			// In ra danh sach
			ifstream i;
			i.open("Students.csv");
			Student st;
			readAStudentsFormFile(i, st, userName);
			i.close();

			system("cls");
			ifstream ifs;
			string test = "Course Of Student " + userName + "---" + to_string(st.ID) + ".csv";
			ifs.open(test.c_str());

			if (!ifs.is_open()) {
				cout << endl << endl << " Nothing!" << endl;
				system("pause");
				return -2;
			}

			cout << endl << "\n\t\t\t============================= Registered List  ====================================\n\n";
			cout << left << setw(10) << "No";
			cout << left << setw(25) << "Teacher Name";
			cout << left << setw(15) << "Course ID"
				<< left << setw(25) << "Course Name"
				<< left << setw(15) << "Day Of Week"
				<< left << setw(15) << "Start Hour"
				<< left << setw(15) << "End Hour"
				<< left << setw(15) << "Room";
			cout << endl;

			int count = 0;
			string test1;
			while (!ifs.eof())
			{
				getline(ifs, test1);
				if (test1 == "") break;
				count += 1;

			}

			ifs.close();
			ifs.open(test.c_str());

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

				a[m].name = tmp2;

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
				a[m].startDate.day = atof(date.c_str());

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
				a[m].startDate.month = atof(date.c_str());

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
				a[m].startDate.year = atof(date.c_str());


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
				a[m].endDate.day = atof(date.c_str());

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
				a[m].endDate.month = atof(date.c_str());

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
				a[m].endDate.year = atof(date.c_str());


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
				if (m == count) break;
			}

			// In danh sach 
			cout << endl << endl;
			for (size_t i = 0; i < count; i++)
			{
				cout << left << setw(10) << i + 1;
				cout << left << setw(25) << a[i].name;
				cout << left << setw(15) << a[i].courseID
					<< left << setw(25) << a[i].courseName
					<< left << setw(15) << a[i].DayOfWeek
					<< left << setw(15) << a[i].startHour
					<< left << setw(15) << a[i].endHour
					<< left << setw(15) << a[i].room;
				cout << endl;

			}
			//=========================================================

			cout << endl << endl << " Remove Course No: ";
			cin >> x;


			// xoa file a[x - 1].courseID + "_Students.csv"
			i.open(a[x - 1].courseID + "_Students.csv");
			int countSt = 0;
			while (!i.eof())
			{
				getline(i, test);
				if (test == "") break;
				countSt += 1;
			}
			i.close();
			
			if (countSt == 1 || countSt == 0) {
				ofstream ofs;
				ofs.open(a[x - 1].courseID + "_Students.csv");

				ofs << "";
				ofs.close();

			}
			else
			{
				i.open(a[x - 1].courseID + "_Students.csv");
				//countSt = countSt - 1;

				Student* z = new Student[countSt];
				m = 0;
				while (!i.eof())
				{
					z[m].No = m + 1;

					string tmp;
					getline(i, tmp);
					int n = tmp.find(",");
					if (n == -1) break;
					test = "";
					for (size_t i = 0; i < n; i++)
					{
						test += tmp[i];
					}
					(z + m)->ID = atof(test.c_str());

					for (size_t j = n + 1; j <= tmp.length(); j++)
					{
						if (tmp[j] == ',') {
							n = j;
							break;
						}
						(z + m)->name.lastName += tmp[j];
						n = j;
					}

					for (size_t j = n + 1; j <= tmp.length(); j++)
					{
						if (tmp[j] == ',') {
							n = j;
							break;
						}
						(z + m)->name.firstName += tmp[j];
						n = j;
					}
					for (size_t j = n + 1; j <= tmp.length(); j++)
					{
						if (tmp[j] == ',') {
							n = j;
							break;
						}
						(z + m)->Gender += tmp[j];
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
					(z + m)->birth.day = atof(date.c_str());

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
					(z + m)->birth.month = atof(date.c_str());

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
					(z + m)->birth.year = atof(date.c_str());

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
					(z + m)->score.OtherMark = atof(sc.c_str());

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
					(z + m)->score.MidtermMark = atof(sc.c_str());

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
					(z + m)->score.FinalMark = atof(sc.c_str());

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
					(z + m)->score.TotalMark = atof(sc.c_str());

					m += 1;
					if (m == countSt) break;
				}

				Student* zt = new Student[countSt];

				for (size_t i = 0; i < countSt; i++)
				{
					zt[i] = z[i];
				}

				z = new Student[countSt - 1];
				int h = 0;
				for (size_t i = 0; i < countSt; i++)
				{
					if (i == x - 1) continue;
					z[h] = zt[i];
					h += 1;
				}
				countSt = countSt - 1;
				i.close();

				ofstream o;
				o.open(a[x - 1].courseID + "_Students.csv");

				for (size_t i = 0; i < countSt; i++)
				{
					o << z[i].ID << "," << z[i].name.lastName << "," << z[i].name.firstName
						<< "," << z[i].Gender << "," << z[i].birth.day
						<< "/" << z[i].birth.month << "/" << z[i].birth.year << ","
						<< z[i].score.OtherMark << "," << z[i].score.MidtermMark << ","
						<< z[i].score.FinalMark << "," << z[i].score.TotalMark << endl;
				}

				o.close();

			}

			// xoas file "Course Of Student " + userName + "---" + to_string(st.ID) + ".csv";
			test = "Course Of Student " + userName + "---" + to_string(st.ID) + ".csv";

			if (count == 1) {
				ofstream of;
				of.open(test);
				of << "";
				of.close();

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
				if (i == x - 1) continue;
				a[h] = b[i];
				h += 1;
			}
			count = count - 1;

			ofstream ofs;
			ofs.open(test);

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

		// print Score and GPA
		if (x == 3) {
			
			ifstream i;
			i.open("Students.csv");
			Student st;
			readAStudentsFormFile(i, st, userName);
			i.close();


			cout << endl << "\n\t\t\t============================= Scoreboard of " << userName << " ====================================\n\n";
			cout << left << setw(10) << "No";
			cout << left << setw(25) << "Teacher Name";
			cout << left << setw(15) << "Course ID"
				<< left << setw(25) << "Course Name"
				<< left << setw(15) << "Other Mark"
				<< left << setw(15) << "Midterm Mark"
				<< left << setw(15) << "Final Mark"
				<< left << setw(15) << "Total Mark";
			cout << endl << endl << endl;

			ifstream ifs;
			
			string test = "Course Of Student " + userName + "---" + to_string(st.ID) + ".csv";
			int count = 0;
			string test1;
			ifs.open(test.c_str());
			while (!ifs.eof())
			{
				getline(ifs, test1);
				if (test1 == "") break;
				count += 1;

			}

			ifs.close();
			ifs.open(test.c_str());

			int m = 0;
			int n;
			// danh sach khoa hoc da dang ki 
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

				a[m].name = tmp2;

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
				a[m].startDate.day = atof(date.c_str());

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
				a[m].startDate.month = atof(date.c_str());

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
				a[m].startDate.year = atof(date.c_str());


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
				a[m].endDate.day = atof(date.c_str());

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
				a[m].endDate.month = atof(date.c_str());

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
				a[m].endDate.year = atof(date.c_str());


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
				if (m == count) break;
			}

			// diem cua sinh vien
			int countMark = 0;
			mark* scores = new mark[count];
			Student* z;
			for (size_t r = 0; r < count; r++)
			{
				ifstream ii;
				test = "";
				int countSt = 0;
				ii.open(a[r].courseID + "_Students.csv");
				while (!ii.eof())
				{
					getline(ii, test);
					if (test == "") break;
					countSt += 1;
				}
				
				ii.close();
				ii.open(a[r].courseID + "_Students.csv");
				//countSt = countSt - 1;
				z = new Student[countSt];
				m = 0;
				while (!ii.eof())
				{
					z[m].No = m + 1;

					string tmp;
					getline(ii, tmp);
					int n = tmp.find(",");
					if (n == -1) break;
					test = "";
					for (size_t i = 0; i < n; i++)
					{
						test += tmp[i];
					}
					(z + m)->ID = atof(test.c_str());

					for (size_t j = n + 1; j <= tmp.length(); j++)
					{
						if (tmp[j] == ',') {
							n = j;
							break;
						}
						(z + m)->name.lastName += tmp[j];
						n = j;
					}

					for (size_t j = n + 1; j <= tmp.length(); j++)
					{
						if (tmp[j] == ',') {
							n = j;
							break;
						}
						(z + m)->name.firstName += tmp[j];
						n = j;
					}
					for (size_t j = n + 1; j <= tmp.length(); j++)
					{
						if (tmp[j] == ',') {
							n = j;
							break;
						}
						(z + m)->Gender += tmp[j];
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
					(z + m)->birth.day = atof(date.c_str());

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
					(z + m)->birth.month = atof(date.c_str());

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
					(z + m)->birth.year = atof(date.c_str());

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
					(z + m)->score.OtherMark = atof(sc.c_str());

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
					(z + m)->score.MidtermMark = atof(sc.c_str());

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
					(z + m)->score.FinalMark = atof(sc.c_str());

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
					(z + m)->score.TotalMark = atof(sc.c_str());

					if (st.ID == (z + m)->ID) {
						scores[countMark] = (z + m)->score;
						countMark += 1;
					}

					m += 1;
					if (m == countSt) break;
				}
				

				cout << left << setw(10) << r + 1;
				cout << left << setw(25) << a[r].name;
				cout << left << setw(15) << a[r].courseID
					<< left << setw(25) << a[r].courseName
					<< left << setw(15) << scores[r].OtherMark
					<< left << setw(15) << scores[r].MidtermMark
					<< left << setw(15) << scores[r].FinalMark
					<< left << setw(15) << scores[r].TotalMark;
				cout << endl;
				ii.close();
			}

			cout << endl << endl << endl << "\t\t\t\t";
			cout << " Tong diem trung binh GPA = ";
			float GPA = 0;
			for (size_t i = 0; i < countMark; i++)
			{
				GPA += scores[i].TotalMark;
			}

			cout << GPA / countMark << endl << endl;

			system("pause");
			return -2;
		}

		if (x == 4) return -2;
	}

}
	



