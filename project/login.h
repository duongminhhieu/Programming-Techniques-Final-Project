#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;

struct Login {
	string username;
	string password;
	int id;
	int who; // 1: staff , 2 : student 
	int link;
};

void printLoginMenu1();
void printLoginMenu2(int n);
bool isLoggedInStaff(Login &a );
bool isLoggedInStudents(Login &a);
Login login(int x);
void choose_Login(Login &a);
void choose_Login2(Login& a);
int findNumberLinesfile(int who);
void delete_line(const char* file_name, int n, string passNew);
void change_Pass(Login& a);