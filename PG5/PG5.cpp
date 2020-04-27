
//Jared VanEnkevort
// contains all the function def for all included in PG5.h
//I addded comments and I beleive I fixed returning old data from add &remove

#include <iostream>
#include <string>
#include <cstdlib>
#include<fstream>
#include "RBTree.h"
#include "DRT.h"
#include "PG5.h"
using namespace std;
//main method program enters and exits from
int main(int argc, char** argv) {
	/*string command;
	ifstream file("PG5-1.in.txt");
	if (!file.is_open()) {
		cout << "file failed to open!" << endl;
		exit(0);
	}
	Studs = new RBTree();
	while (!file.eof()) {
		getline(file, command);
		ProcessCommand(command);
	}
	file.close();
	delete Studs;
	return 0;*/
	Studs = new RBTree();
	while (ProcessCommand());
	delete Studs;
	return 0;
}

//handles identiying what commands are being inputted
bool ProcessCommand() {
	string cmd;
	getline(cin, cmd);
	if (cmd == "EXIT") return false;
	if (cmd == "PRINT") Print();
	else if (cmd == "RPRINT") RPrint();
	else if (cmd.substr(0, 3) == "ADD") AddCommand(cmd);
	else if (cmd.substr(0, 6) == "REMOVE") RemoveCommand(cmd);
	else if (cmd.substr(0, 6) == "LOOKUP") LookupCommand(cmd);
	else cout << "Invalid Command!" << endl;
	return true;
}

void Print() {
	//Handles forward printing command
	cout << "Printing list forwards:" << endl;
	DRT* T = Studs->search("");
	string k = T->getnext();
	while (k != "") {
		delete T;
		T = Studs->search(k);
		cout << "Name:  " << k << "\tCopies:  " << T->getdata() << endl;
		k = T->getnext();
	}
	delete T;
	cout << endl;
}
//Handles reverse print command
void RPrint() {

	cout << "Printing list backwards:" << endl;
	DRT* T = Studs->search("");
	string k = T->getprev();
	while (k != "") {
		delete T;
		T = Studs->search(k);
		cout << "Name:  " << k << "\tCopies:  " << T->getdata() << endl;
		k = T->getprev();
	}
	delete T;
	cout << endl;
}
//handles the add command
void AddCommand(string cmd) {
	int q1, q2;
	for (q1 = 0; cmd[q1] != '\"'; q1++);
	for (q2 = q1 + 1; cmd[q2] != '\"'; q2++);
	string k = cmd.substr(q1 + 1, q2 - q1 - 1);
	DRT* R = Studs->search(k);
	if (R->getdata() == "") {
		Studs->modify(k, "1");
		cout << "one copy of " << k << " has been added to the library!" << endl;
	}
	else {
		string modify = to_string(stoi(R->getdata()) + 1);
		Studs->modify(k, modify);
		cout << "one copy of " << k << " has been added to the library!" << endl;
	}
}

void RemoveCommand(string cmd) {

	int q1, q2;
	for (q1 = 0; cmd[q1] != '\"'; q1++);
	for (q2 = q1 + 1; cmd[q2] != '\"'; q2++);
	string k = cmd.substr(q1 + 1, q2 - q1 - 1);
	DRT* T = Studs->search(k);
	if (T->getdata() == "")
		cout << "\"" << k << "\" does not exist in the library." << endl;
	else {
		if (T->getdata() == "1") {
			delete T;
			T = Studs->modify(k, "");
		}
		else {
			string d = to_string(stoi(T->getdata()) - 1);
			delete T;
			T = Studs->modify(k, d);
		}
		cout << "1 copy of \"" << k << "\" has been removed from the library." << endl;
		delete T;
	}
}

void LookupCommand(string cmd) {
	int q1, q2;
	for (q1 = 0; cmd[q1] != '\"'; q1++);
	for (q2 = q1 + 1; cmd[q2] != '\"'; q2++);
	string k = cmd.substr(q1 + 1, q2 - q1 - 1);
	DRT* R = Studs->search(k);
	if (R->getdata() == "") {
		string before;
		string after;
		if (R->getnext() == "") {
			after = "end of the list";
		}
		else {
			after = R->getnext();
		}
		if (R->getprev() == "") {
			before = "beggining of the list";
		}
		else {
			before = R->getprev();
		}

		cout << k << "does not exist!\n " << "It would fall between  " << before << " and " << after << endl;
	}
	else {
		cout << "Number of copies: " << R->getdata() << endl;
	}
}
