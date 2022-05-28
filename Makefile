__start__: sort
	./sort

./sort:obj obj/main.o obj/csv_function.o obj/sequence.o obj/algorithms.o
	g++ -o ./sort obj/main.o obj/csv_function.o obj/sequence.o obj/algorithms.o

obj:
	mkdir -p obj

obj/main.o: src/main.cpp inc/csv_function.hh inc/sequence.hh inc/element.hh inc/algorithms.hh
	g++ -c -o obj/main.o src/main.cpp

obj/csv_function.o: inc/csv_function.hh src/csv_function.cpp inc/sequence.hh inc/element.hh
	g++ -c -o obj/csv_function.o src/csv_function.cpp

obj/sequence.o: inc/sequence.hh src/sequence.cpp inc/element.hh
	g++ -c -o obj/sequence.o src/sequence.cpp

obj/algorithms.o: inc/algorithms.hh src/algorithms.cpp inc/sequence.hh inc/element.hh
	g++ -c -o obj/algorithms.o src/algorithms.cpp

clean:
	rm -f *.o ./sort