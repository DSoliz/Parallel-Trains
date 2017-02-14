#ifndef PARSER_H
#define	PARSER_H

#include <fstream>
#include <sstream>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

void file_open(string file_name){
	int a,b;
	string line;
	const char * fnc = file_name.c_str();
	ifstream myfile(fnc);
	cout << file_name << ":" << endl;
	myfile >> a >> b;
	getline(myfile, line);
	//myfile >> b;
	while(getline(myfile, line)){
		cout << line << endl;
	}
	cout << a << b << endl;
}
#endif
