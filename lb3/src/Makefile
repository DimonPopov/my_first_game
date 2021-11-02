DWC = ./ClasesForProject/
DWT = ./Tests/
DWE = ./Elements/
DWS = ./ClasesForProject/UseStrategy/
DWF = ./Elements/Factory/

PROGRAM=main.o Map.o Cell.o Map_Iterator.o Player.o Bush.o Snowman.o Well.o BushFactory.o SnowmanFactory.o WellFactory.o BushUse.o SnowmanUse.o WellUse.o LogClass.o

all: MyGame

MyGame: $(PROGRAM)
	g++ $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system
	mv *.o ./ObjectFile/

main.o: main.cpp $(DWC)Map.h $(DWC)Map_Iterator.h $(DWC)Player.h 
	g++ -c $<

Map_Iterator.o: $(DWC)Map_Iterator.cpp $(DWC)Map_Iterator.h $(DWC)Map.h $(DWC)Cell.h
	g++ -c $< -I SFML/include

Map.o: $(DWC)Map.cpp $(DWC)Map.h $(DWC)Cell.h $(DWC)Map_Iterator.h $(DWE)Bush.h $(DWE)Snowman.h $(DWE)Well.h $(DWF)WellFactory.h $(DWF)SnowmanFactory.h $(DWF)BushFactory.h $(DWC)LogClass.h
	g++ -c $<

Cell.o:	$(DWC)Cell.cpp $(DWC)Cell.h $(DWF)WellFactory.h $(DWF)SnowmanFactory.h $(DWF)BushFactory.h
	g++ -c $<

Player.o: $(DWC)Player.cpp $(DWC)Player.h $(DWC)Map_Iterator.h $(DWE)IElements.h $(DWS)SnowmanUse.h $(DWS)WellUse.h $(DWS)BushUse.h
	g++ -c $<

Bush.o: $(DWE)Bush.cpp $(DWE)Bush.h
	g++ -c $<

Snowman.o: $(DWE)Snowman.cpp $(DWE)Snowman.h
	g++ -c $<

Well.o: $(DWE)Well.cpp $(DWE)Well.h
	g++ -c $<

BushFactory.o: $(DWF)BushFactory.cpp $(DWF)BushFactory.h $(DWE)IElements.h $(DWE)Bush.h
	g++ -c $<

SnowmanFactory.o: $(DWF)SnowmanFactory.cpp $(DWF)SnowmanFactory.h $(DWE)IElements.h $(DWE)Snowman.h
	g++ -c $<

WellFactory.o: $(DWF)WellFactory.cpp $(DWF)WellFactory.h $(DWE)IElements.h $(DWE)Well.h
	g++ -c $<

BushUse.o: $(DWS)BushUse.cpp $(DWS)BushUse.h $(DWS)IUsing.h
	g++ -c $<

WellUse.o: $(DWS)WellUse.cpp $(DWS)WellUse.h $(DWS)IUsing.h
	g++ -c $<

SnowmanUse.o: $(DWS)SnowmanUse.cpp $(DWS)SnowmanUse.h $(DWS)IUsing.h
	g++ -c $<

LogClass.o: $(DWC)LogClass.cpp $(DWC)LogClass.h $(DWC)Player.h
	g++ -c $<



UnitTest1.o: $(DWT)UnitTest1.cpp $(DWC)Cell.h $(DWT)UnitTest.h
	g++ -c $(DWT)UnitTest1.cpp

UnitTest.o: $(DWT)UnitTest.h
	g++ -c $(DWT)UnitTest.cpp
