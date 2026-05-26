build: src/Main.o src/Logica_matematica.o
	g++ src/Main.o src/Logica_matematica.o -o programa

src/Main.o: src/Main.cpp src/Funciones_matematicas.hpp
	g++ -c src/Main.cpp -o src/Main.o

src/Logica_matematica.o: src/Logica_matematica.cpp src/Funciones_matematicas.hpp
	g++ -c src/Logica_matematica.cpp -o src/Logica_matematica.o

run: build
	./programa

clean:
	rm -f src/*.o programa programa.exe
