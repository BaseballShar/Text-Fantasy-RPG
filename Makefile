rpg: main.o combat.o character.o skill_points.o list.o shop.o
	g++ -pedantic-errors -std=c++11 main.o combat.o character.o skill_points.o list.o shop.o -o rpg
character.o: character.h character.cpp
	g++ -pedantic-errors -std=c++11 -c character.cpp
combat.o: combat.h character.h combat.cpp
	g++ -pedantic-errors -std=c++11 -c combat.cpp
skill_points.o: character.h skill_points.h skill_points.cpp
	g++ -pedantic-errors -std=c++11 -c skill_points.cpp
list.o: list.h list.cpp
	g++ -pedantic-errors -std=c++11 -c list.cpp
shop.o: shop.h shop.cpp
	g++ -pedantic-errors -std=c++11 -c shop.cpp
main.o: character.h combat.h main.cpp
	g++ -pedantic-errors -std=c++11 -c main.cpp

clean:
	rm *.o
