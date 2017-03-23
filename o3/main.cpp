#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <iomanip>

using namespace std;
int main() {
	string name;
	string vorname;
	int alter;
	float groesse;

	cout << "Hello World\nHier bitte folgende Sachen eingeben:\nVorname Nachname:";
	cin >> vorname >> name;
	cout << "Alter: ";
	cin >> alter;
	cout << "Groesse in m (moeglichst genau): ";
	cin >> groesse;
	cout << "Sie heissen " << vorname << " " << name << ", sind " << alter << " Jahre alt und ";
	cout << setprecision(1) << groesse << "m (oder genauer " << setprecision(3) << groesse;
	cout << "m, noch genauer " << setprecision(10) << groesse << "m) gross.\n";

	cout << "\nDaten nochmal in schoen:\n" << setw(10) << "Vorname: " << vorname << endl;
	cout << setw(10) << "Nachname: " << name << endl;
	cout << setw(10) << "Groesse: " << setprecision(3) << groesse << endl;
	cout << setw(10) << "Alter: " << alter << endl;
	_getch();
}