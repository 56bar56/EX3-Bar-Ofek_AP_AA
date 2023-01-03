
output: ServerRunner.o FileClass.o DistanceAndName.o DistanceList.o Vector_Algorithms.o
	g++ ServerRunner.o FileClass.o DistanceAndName.o DistanceList.o Vector_Algorithms.o -o server.out

ServerRunner.o: ServerRunner.cpp
	g++ -std=c++11 -g -c FileClass.cpp

FileClass.o: FileClass.cpp
	g++ -std=c++11 -g -c FileClass.cpp

DistanceAndName.o: DistanceAndName.cpp
	g++ -std=c++11 -g -c DistanceAndName.cpp

DistanceList.o: DistanceList.cpp
	g++ -std=c++11 -g -c DistanceList.cpp

Vector_Algorithms.o: Vector_Algorithms.cpp
	g++ -std=c++11 -g -c Vector_Algorithms.cpp

clean:
	rm -f *.o server.out