CC = g++
CFLAG = -std=c++17 -Wall
OBJ = main.o Map.o Cell.o Iterator.o Player.o Object.o Factory.o Using.o LogClass.o Game.o
DWM = ./Map/
DWI = ./Iterator/
DWP = ./Player/
DWE = ./Elements/
DWF = ./Elements/Factory/
DWS = ./Player/Strategy/
DWL = ./LogClass/
E = ./Enum/


all: myGame

myGame: $(OBJ)
	$(CC) $(CFLAG) $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp $(DWM)Game.h
	$(CC) $(CFLAG) -c $<

Map.o: $(DWM)Map.cpp $(DWM)Map.h $(DWM)Cell.h $(E)CellAndElemENUM.h $(DWF)Factory1.h $(DWL)LogClass.h
	$(CC) $(CFLAG) -c $<

Cell.o: $(DWM)Cell.cpp $(DWM)Cell.h $(E)CellAndElemENUM.h
	$(CC) $(CFLAG) -c $<

Iterator.o: $(DWI)Iterator.cpp $(DWI)Iterator.h $(DWM)Map.h $(DWM)Cell.h $(E)CellAndElemENUM.h
	$(CC) $(CFLAG) -c $<

Player.o: $(DWP)Player.cpp $(DWP)Player.h $(DWI)Iterator.h $(E)CellAndElemENUM.h $(DWS)Using.h $(DWM)Map.h
	$(CC) $(CFLAG) -c $<

Object.o: $(DWE)Object.cpp $(DWE)Object.h $(E)CellAndElemENUM.h
	$(CC) $(CFLAG) -c $<

Factory.o: $(DWF)Factory.cpp $(DWF)Factory1.h $(DWE)Object.h
	$(CC) $(CFLAG) -c $<

Using.o: $(DWS)Using.cpp $(DWS)Using.h
	$(CC) $(CFLAG) -c $<

LogClass.o: $(DWL)LogClass.cpp $(DWL)LogClass.h $(DWE)Object.h $(DWP)Player.h
	$(CC) $(CFLAG) -c $<

Game.o: $(DWM)Game.cpp $(DWM)Game.h $(DWP)Player.h
	$(CC) $(CFLAG) -c $<
	
.PHONY: clean

clean:
	rm *.o *.log