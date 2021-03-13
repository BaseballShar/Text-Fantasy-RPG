rpg: main.o combat.o character.o skill_points.o
	g++ -pedantic-errors -std=c++11 main.o combat.o character.o skill_points.o -o rpg
character.o: character.h character.cpp
	g++ -pedantic-errors -std=c++11 -c character.cpp
combat.o: combat.h character.h combat.cpp
	g++ -pedantic-errors -std=c++11 -c combat.cpp
skill_points.o: character.h skill_points.h skill_points.cpp
	g++ -pedantic-errors -std=c++11 -c skill_points.cpp
main.o: character.h combat.h main.cpp
	g++ -pedantic-errors -std=c++11 -c main.cpp

clean:
	rm *.o
