#include <stdexcept>
#include <iostream>
#include <string>

#include "Machine.h"

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
			cout << machine.encodeLetter(line[i]);
		}
	}
	machine.deallocMemmory();
  	return 0;
}