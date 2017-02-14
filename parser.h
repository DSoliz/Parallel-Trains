#ifndef PARSER_H
#define	PARSER_H

#include <fstream>
#include <sstream>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

void file_open(string file_name){
	int a;
	const char * fnc = file_name.c_str();
	fstream myfile(fnc, ios_base::in);
	cout << file_name << ": ";
	myfile >> a;
	cout << endl;
}
#endif
