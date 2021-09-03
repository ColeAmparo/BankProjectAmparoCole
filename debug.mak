//Uses clean to make sure that the next the project is ran, it will be in DEBUG mode.
clean:
	rm user_interface.o llist.o
	g++ -DDEBUG -ansi -pedantic-errors -Wall -c llist.cpp
	g++ -DDEBUG -ansi -pedantic-errors -Wall -c user_interface.cpp
	g++ -DDEBUG -o project_debug llist.o user_interface.o


llist.o: llist.cpp
	g++ -DDEBUG -ansi -pedantic-errors -Wall -c llist.cpp

user_interface.o: user_interface.cpp
	g++ -DDEBUG -ansi -pedantic-errors -Wall -c user_interface.cpp
