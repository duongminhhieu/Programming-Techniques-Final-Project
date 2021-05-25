#pragma once

#include <iostream>
#include <fstream>
#include <string>



using namespace std;

struct Login {
	string username;
	string password;
	int id;
};

void printLoginMenu1();
void printLoginMenu2(int n);
bool isLoggedInStaff(Login &a );
bool isLoggedInStudents(Login &a);
Login login(int x);
