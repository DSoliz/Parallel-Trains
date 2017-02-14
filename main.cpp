#include <iostream>
#include <fstream>
#include <queue>
#include "parser.h"

using namespace std;

queue < queue<int> > * train_routes;

int main(int argc, char* argv[]){
	train_routes = new queue < queue<int> >;
	char * file_name;
	cout << "argc = " << argc << endl;
	for(int i = 0; i < argc; i++)
		cout << "argv[" << i << "] = " << argv[i] << endl;

	if(argc>0){
		file_open(argv[1], train_routes);
	}else{
		cout << "No input file." << endl;
	}
	return 0;
}
