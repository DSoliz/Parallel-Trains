#ifndef BARRIER_H
#define BARRIER_H

#include <condition_variable>
#include <mutex>
#include <queue>

using namespace std;

queue<int> * station_q;
int train_n, station_n;

void barrier(int& bCounter, std::mutex& bMutex,
	std::condition_variable& bCV, int numExpectedAtBarrier)
{
	std::unique_lock<std::mutex> ulbm(bMutex);

	bCounter++;
	if (bCounter != numExpectedAtBarrier)
		bCV.wait(ulbm);
	else
	{
		bCounter = 0;
		bCV.notify_all();
	}
}

/* Usage:
	1. Create an instance of a Barrier class (called, say, "b") that
	   is accessible to, but outside the scope of any thread code that
	   needs to use it.
	2. In the thread code where barrier synchronization is to occur,
	   each thread in the "barrier group" must execute:

	   b.barrier(num); // where "num" is the number of threads in
	                   // the "barrier group"
*/


int finished=0;

class Barrier
{
public:
	Barrier() : barrierCounter(0) {}
	virtual ~Barrier() {}

	int step = 0;

	void barrier(int numExpectedAtBarrier)
	{
		std::unique_lock<std::mutex> ulbm(barrierMutex);

		barrierCounter++;
		if (barrierCounter != numExpectedAtBarrier){
			barrierCV.wait(ulbm);
		}else
		{
			step++;
			station_q = new queue<int>[station_n];
			barrierCounter = 0;
			train_n-=finished;
			finished = 0;
			barrierCV.notify_all();
		}
	}

private:
	int barrierCounter;
	std::mutex barrierMutex;
	std::condition_variable barrierCV;
};

#endif
