#include <iostream>
#include <thread>
#include <fstream>
#include <queue>
#include <mutex>
#include "parser.h"

using namespace std;

queue < queue<int> > * train_routes;


Barrier b;
bool * track;
mutex queue_check;

bool allowed(int loc, int dest){
	bool allowed = true;
	queue_check.lock();
	queue<int> s_queue = station_q[loc];//copy of a stations queue

	while(!s_queue.empty()){
		if(s_queue.front() == dest){
			allowed = false;
		}
		s_queue.pop();
	}

	s_queue = station_q[dest];
	while(!s_queue.empty()){
		if(s_queue.front() == loc){
			allowed = false;
		}
		s_queue.pop();
	}
	if(allowed){
		station_q[loc].push(dest);
	}
	queue_check.unlock();
	return allowed;
}

void work(queue <int> route, int trainid){
	//initial location
	int location = route.front();
	route.pop();

	while(!route.empty()){
		int nex_loc = route.front();
		if(allowed(location, nex_loc)){
			cout << "At time step: " << b.step <<" Train " << trainid << " moving from station " << location << " to station " << nex_loc << endl;
			location = nex_loc;
			route.pop();
		}else{
			cout << "At time step: " << b.step << " Train "<< trainid <<" must stay at station " << location << endl;
		}
		b.barrier(train_n);
		queue_check.lock();
		if(route.empty()){
			train_n--;
			cout << "trains left= " << train_n << endl;
		}
		queue_check.unlock();
	}
}

int main(int argc, char* argv[]){
	if(argc==2){
		train_routes = new queue < queue<int> >;
		file_open(argv[1], train_routes);
	}else{
		cout << "No input file." << endl;
		return 0;
	}

	std::thread** t = new std::thread*[train_n];
	station_q = new queue<int>[station_n];

	for (int i=0 ; i<train_n ; i++){
		queue<int> i_route = train_routes->front();
		t[i] = new thread(work, i_route, i);
		train_routes->pop();
	}

	for (int i=0 ; i<train_n ; i++)
		t[i]->join();
	return 0;
}
