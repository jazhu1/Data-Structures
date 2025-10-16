Proj4.exe: LinkedNodeClass.o SortedListClass.o LIFOStackClass.o FIFOQueueClass.o Proj4.o
	g++ LinkedNodeClass.o SortedListClass.o LIFOStackClass.o FIFOQueueClass.o Proj4.o -o Proj4.exe

LinkedNodeClass.o: LinkedNodeClass.cpp
	g++ -std=c++98 -Wall -c LinkedNodeClass.cpp -o LinkedNodeClass.o 
SortedListClass.o: SortedListClass.cpp
	g++ -std=c++98 -Wall -c SortedListClass.cpp -o SortedListClass.o 
LIFOClass.o: LIFOClass.cpp
	g++ -std=c++98 -Wall -c LIFOStackClass.cpp -o LIFOStackClass.o 
FIFOClass.o: FIFOClass.cpp
	g++ -std=c++98 -Wall -c FIFOQueueClass.cpp -o FIFOQueueClass.o 
Proj4.o: Proj4.cpp
	g++ -std=c++98 -Wall -c Proj4.cpp -o Proj4.o
	
clean:
	rm -rf LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o LIFOStackClass.o Proj4.o Proj4.exe
