CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11



__start__: ./sorting
	
./sorting:obj obj/main.o obj/csv_functions.o obj/sequence.o obj/sorting_algorithms.o
	g++ -Wall -pedantic -std=c++11  -o ./sorting obj/main.o obj/csv_functions.o obj/sequence.o obj/sorting_algorithms.o

obj:
	mkdir -p obj

obj/main.o: src/main.cpp inc/csv_functions.hh inc/sequence.hh inc/element.hh inc/sorting_algorithms.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/csv_functions.o: inc/csv_functions.hh src/csv_functions.cpp inc/sequence.hh inc/element.hh
	g++ -c ${CXXFLAGS} -o obj/csv_functions.o src/csv_functions.cpp

obj/sequence.o: inc/sequence.hh src/sequence.cpp inc/element.hh
	g++ -c ${CXXFLAGS} -o obj/sequence.o src/sequence.cpp

obj/sorting_algorithms.o: inc/sorting_algorithms.hh src/sorting_algorithms.cpp inc/sequence.hh inc/element.hh
	g++ -c ${CXXFLAGS} -o obj/sorting_algorithms.o src/sorting_algorithms.cpp

clean:
	rm -f *.o ./sorting