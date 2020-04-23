// contains all the function def for all included in DRT.h
//Jared VanEnkevort
#include <string>
#include "DRT.h"
using namespace std;

DRT::DRT(string d, string n, string p) {

	data = d; next = n; prev = p;
}
//returns the data in these fields
string DRT::getdata() { return data; }

string DRT::getnext() { return next; }

string DRT::getprev() { return prev; }