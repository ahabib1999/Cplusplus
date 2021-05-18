#makefile Inheritance Project
CC = g++

main : Main.o Main.o Shape.o Square.o Rectangle.o Circle.o Triangle.o
	$(CC) -o main  Main.o Shape.o Square.o Rectangle.o Circle.o Triangle.o

Main.o : main.cpp
	$(CC) -c -std=c++11 main.cpp -o Main.o

Shape.o : Shape.h Shape.cpp
	$(CC) -c -std=c++11 Shape.h
	$(CC) -c -std=c++11 Shape.cpp

Square.o : Square.h Square.cpp
	$(CC) -c -std=c++11 Square.h
	$(CC) -c -std=c++11 Square.cpp

Rectangle.o : Rectangle.h Rectangle.cpp
	$(CC) -c -std=c++11 Rectangle.h
	$(CC) -c -std=c++11 Rectangle.cpp

Circle.o : Circle.h Circle.cpp
	$(CC) -c -std=c++11 Circle.h
	$(CC) -c -std=c++11 Circle.cpp

Triangle.o : Triangle.h Triangle.cpp
	$(CC) -c -std=c++11 Triangle.h
	$(CC) -c -std=c++11 Triangle.cpp