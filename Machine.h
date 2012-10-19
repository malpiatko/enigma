#ifndef MACHINE_H
#define MACHINE_H

#include <vector>
#include "Rotor.h"
#include "Plugboard.h"
#include "Reflector.h"

class Machine{
	std::vector<MappingPart*> mappingParts;
	void turnRotor(int i);
public:
	void initialiseRotors(int n,char **fileNames);
	void initialisePlugboard(char *fileName);
	char encodeLetter(char letter);
	void deallocMemmory();
	void initialiseReflector();
};


#endif