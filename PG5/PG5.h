//Jared VanEnkevort
//contains all the function prototypes for the deinftions in PG5.cpp
#ifndef _PG5_
#define _PG5_

#include <string>
#include <cstdlib>
#include "Database.h"
using namespace std;

Database* Studs;

int main(int argc, char** argv);
bool ProcessCommand(string cmd);
void Print();
void RPrint();
void AddCommand(string cmd);
void RemoveCommand(string cmd);
void LookupCommand(string cmd);

#endif