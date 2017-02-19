make:
	g++ -std=c++11 main.cpp -o trains -lpthread 
thread:
	g++ -std=c++11 threads.c -o thread -lpthread
clean:
	rm -f trains
	rm -f thread
