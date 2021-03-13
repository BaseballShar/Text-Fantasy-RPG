rpg: main.o combat.o character.o
	g++ -pedantic-errors -std=c++11 main.o combat.o character.o -o rpg
character.o: character.h character.cpp
	g++ -pedantic-errors -std=c++11 -c character.cpp
combat.o: combat.h character.h combat.cpp
	g++ -pedantic-errors -std=c++11 -c combat.cpp
main.o: character.h combat.h main.cpp
	g++ -pedantic-errors -std=c++11 -c main.cpp

