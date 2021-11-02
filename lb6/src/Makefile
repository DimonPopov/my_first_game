CC = g++
CFLAG = -std=c++17 -Wall
OBJ = main.o Map.o Cell.o Iterator.o Player.o Object.o Factory.o Using.o LogClass.o Game.o Enemy1.o Enemy2.o Enemy3.o Aggressive.o Neutral.o Passive.o SaveClass.o
DWM = ./Map/
DWI = ./Iterator/
DWP = ./Player/
DWE = ./Elements/
DWF = ./Elements/Factory/
DWS = ./Player/Strategy/
DWL = ./LogClass/
DWB = ./Enemy/Behavior/
E = ./Enum/
B = ./Enemy/Behavior/
DWENEMY = ./Enemy/
SAVE = ./Save/

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

Game.o: $(DWM)Game.cpp $(DWM)Game.h $(DWP)Player.h $(DWM)GameSetting.h $(DWENEMY)Enemy1.h $(DWENEMY)Enemy2.h $(DWENEMY)Enemy3.h
	$(CC) $(CFLAG) -c $<

Enemy1.o: $(DWENEMY)Enemy1.cpp $(DWENEMY)Enemy1.h $(B)Behavior.h
	$(CC) $(CFLAG) -c $<

Enemy2.o: $(DWENEMY)Enemy2.cpp $(DWENEMY)Enemy2.h $(B)Behavior.h
	$(CC) $(CFLAG) -c $<

Enemy3.o: $(DWENEMY)Enemy3.cpp $(DWENEMY)Enemy3.h $(E)CellAndElemENUM.h $(B)Behavior.h
	$(CC) $(CFLAG) -c $<

Aggressive.o: $(DWB)Aggressive.cpp $(DWB)Behavior.h $(E)CellAndElemENUM.h $(DWI)Iterator.h
	$(CC) $(CFLAG) -c $<

Neutral.o: $(DWB)Neutral.cpp $(DWB)Behavior.h $(E)CellAndElemENUM.h $(DWI)Iterator.h
	$(CC) $(CFLAG) -c $<

Passive.o: $(DWB)Passive.cpp $(DWB)Behavior.h $(E)CellAndElemENUM.h $(DWI)Iterator.h
	$(CC) $(CFLAG) -c $<

SaveClass.o: $(SAVE)SaveClass.cpp $(SAVE)SaveClass.h $(DWP)Player.h $(DWM)Map.h
	$(CC) $(CFLAG) -c $<

.PHONY: clean

clean:
	rm *.o *.log