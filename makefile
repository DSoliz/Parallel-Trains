make:
	g++ -std=c++11 main.cpp -o trains -lpthread
test:
	g++ -std=c++11 main.cpp -o trains -lpthread
	./trains data.txt
	./trains data2.txt
clean:
	rm -f trains
