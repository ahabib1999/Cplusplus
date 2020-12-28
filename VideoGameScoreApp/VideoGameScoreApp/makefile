
#makefile VideoGameScore class
CC = g++

VideoGameScore : VideoGameScoreApp.o VideoGameScore.o
	$(CC) VideoGameScoreApp.o VideoGameScore.o -o VideoGameScore

VideoGameScoreApp.o : VideoGameScoreApp.cpp
	$(CC) -c VideoGameScoreApp.cpp

VideoGameScore.o : VideoGameScore.h VideoGameScore.cpp
	$(CC) -c VideoGameScore.h
	$(CC) -c VideoGameScore.cpp

clean:
	rm -rf *o VideoGameScore