#ifndef PARSER_H
#define	PARSER_H

#include <fstream>
#include <sstream>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

void file_open(string file_name, queue< queue<int> > * m_queue){
	int a,b;
	string line;
	const char * fnc = file_name.c_str();
	ifstream myfile(fnc);
	cout << file_name << ":" << endl;
	myfile >> a >> b;
	getline(myfile, line);
	//myfile >> b;
	while(getline(myfile, line)){
		int c, length;
		queue<int> route;
		length = line.length();
		istringstream line_stream (line);
		while(line_stream >> c){
			cout << c;
			route.push(c);
		}
		cout << endl;
		m_queue->push(route);
	}
	cout << a << b << endl;
}

#endif
