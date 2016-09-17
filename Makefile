COMPILER = g++
FLAGS = -std=c++11 -Wall -g
EXECUTABLE = predictors


all: Project1.o BimodalSingleBit.o BimodalDoubleBit.o Gshare.o TournamentPredict.o
	$(COMPILER) $(FLAGS) -o $(EXECUTABLE) Project1.o BimodalSingleBit.o BimodalDoubleBit.o Gshare.o TournamentPredict.o

Project1.o: Project1.cpp
	$(COMPILER) $(FLAGS) -c Project1.cpp

BimodalSingleBit.o: BimodalSingleBit.cpp
	$(COMPILER) $(FLAGS) -c BimodalSingleBit.cpp

BimodalDoubleBit.o: BimodalDoubleBit.cpp
	$(COMPILER) $(FLAGS) -c BimodalDoubleBit.cpp

Gshare.o: Gshare.cpp
	$(COMPILER) $(FLAGS) -c Gshare.cpp

TournamentPredict.o: TournamentPredict.cpp
	$(COMPILER) $(FLAGS) -c TournamentPredict.cpp

clean:
	rm -rf *.o $(EXECUTABLE) $(EXECUTABLE).dSYM output.txt