DWC=./ClasesForProject/
DWT=./Tests/

all: MyGame

MyGame: main.o Map.o Cell.o Map_Iterator.o
	g++ main.o Map.o Cell.o Map_Iterator.o -o MyGame

main.o: main.cpp $(DWC)Map.h $(DWC)Map_Iterator.h
	g++ -c main.cpp

Map_Iterator.o: $(DWC)Map_Iterator.cpp $(DWC)Map_Iterator.h $(DWC)Map.h $(DWC)Cell.h
	g++ -c $(DWC)Map_Iterator.cpp

Map.o: $(DWC)Map.cpp $(DWC)Map.h $(DWC)Cell.h $(DWC)Map_Iterator.h
	g++ -c $(DWC)Map.cpp

Cell.o:	$(DWC)Cell.cpp $(DWC)Cell.h
	g++ -c $(DWC)Cell.cpp

UnitTest1.o: $(DWT)UnitTest1.cpp $(DWC)Cell.h $(DWT)UnitTest.h
	g++ -c $(DWT)UnitTest1.cpp

UnitTest.o: $(DWT)UnitTest.h
	g++ -c $(DWT)UnitTest.cpp




clean:
	rm -rf  *.o MyGame test



test: UnitTest1.o UnitTest.o Cell.o Map.o Map_Iterator.o
	g++ UnitTest1.o UnitTest.o Cell.o Map.o Map_Iterator.o -o test
