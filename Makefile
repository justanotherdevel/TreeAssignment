all: TreeAssignment

TreeAssignment: *.o
	g++ *.o -o TreeAssignment -std=c++14

*.o: *.cpp
	g++ -c *.cpp -std=c++14

clean:
	rm *.o TreeAssignment

