
#include "login.h"

struct Date
{
	int day;
	int month;
	int year;
};

struct Name {
	string firstName;
	string lastName;
};

struct mark
{
	float TotalMark, FinalMark, MidtermMark, OtherMark;
	mark() :TotalMark(), FinalMark(), MidtermMark(), OtherMark()
	{
		FinalMark = 0; 
		MidtermMark = 0;
		MidtermMark = 0;
		TotalMark = 0;
	}
};

struct Student
{
	int No;
	int ID;
	string Gender;
	Date birth;
	Name name;
	mark score;
};


struct Staff {
	int No;
	string name ;
	string courseID;
	string courseName;
	string Class;
	Date startDate;
	Date endDate;
	string DayOfWeek;
	string startHour;
	string endHour;
	string room;
};


int checkStaff(string name);
int createCourse(string userName);
int registerCourse(string userName);
void readStaffFile(ifstream& i, Staff*& a, int& n);
int registerCourse(string userName);
void readAStudentsFormFile(ifstream& i, Student*& st, int& counSt);