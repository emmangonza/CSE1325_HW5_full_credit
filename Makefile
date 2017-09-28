# CSE_1325 Homework 4

output: main.o publication.o library.o genre.o media.o age.o
	g++ --std=c++11 main.o publication.o library.o genre.o media.o age.o -o output

main.o: main.cpp
	g++ --std=c++11 -c main.cpp

publication.o: publication.cpp publication.h
	g++ --std=c++11 -c publication.cpp

library.o: library.cpp library.h
	g++ --std=c++11 -c library.cpp

genre.o: genre.cpp genre.h
	g++ --std=c++11 -c genre.cpp

media.o: media.cpp media.h
	g++ --std=c++11 -c media.cpp

age.o: age.cpp age.h
	g++ --std=c++11 -c age.cpp

clean:
	rm *.o output
