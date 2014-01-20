#include <stdexcept>
#include <iostream>
#include <string>

#include "Machine.h"

/*
arguments: list of names of files specifying rotors (can be an empty list) and last one specifying plugboard
initialises the enigma machine and adds all the parts of the machine that are described in the files which names are given as the arguments to main + the reflector, so that they are in an order Plugboard(Rotors)Reflector in the Machines vector
after setting up the machine it encodes the message given in the standard input, ignoring all characters different then upper case letters
lastly it deallocates the dynamically allocated memmory*/

using namespace std;

int main(int argc, char **argv){
	Machine machine;
	string line;
	argv = &argv[1];
	argc--;
	char letter;
	machine.initialisePlugboard(argv[argc-1]);
	if(argc!=1){
		machine.initialiseRotors(argc - 1, argv);
	}
	machine.initialiseReflector();
	while(getline(cin, line)){
		for(int i = 0; i <line.length(); i++){
			if(line[i]>='A'&&line[i]<='Z'){
				cout << machine.encodeLetter(line[i]);
			}
		}
	}
	machine.deallocMemmory();
  	return 0;
}