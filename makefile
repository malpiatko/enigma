# edit this makefile so that running make compiles your enigma program
all: enigma

enigma: Main.o Rotor.o Machine.o Plugboard.o Reflector.o
	g++ Main.o Rotor.o Machine.o Plugboard.o Reflector.o -o enigma

Rotor.o: Rotor.cpp
	g++ -c Rotor.cpp

Main.o: Main.cpp
	g++ -c Main.cpp

Machine.o: Machine.cpp
	g++ -c Machine.cpp

Plugboard.o: Plugboard.cpp
	g++ -c Plugboard.cpp

Reflector.o: Reflector.cpp
	g++ -c Reflector.cpp



clean:
	rm -rf enigma *.o

.phony: clean
