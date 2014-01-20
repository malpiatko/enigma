#ifndef MACHINE_H
#define MACHINE_H

#include "Constants.h"
#include <vector>
#include "Rotor.h"
#include "Plugboard.h"
#include "Reflector.h"

/*Machine class implements the bahaviour of an Enigma machine as described in the specification
Machine consists of parts Rotor, Plugboard, Reflector
 * mappingParts stores all the parts of the machine that are used for mapping when encoding letters, the order they are stored is the same as when encoding a letter 
 * initialiseRotors method adds n new dynnamicaly created Rotors to the machine (to mappingsParts). Each pointer in the list specifies the name of a text file which consists of 26 numbers, the i-th number means that i-th number in the machines alphabet is mapped to that number
 * initialisePlugboard method adds a new dynnamicaly created Plugboard to the machine (to mappingParts) specified by a text file consisting of 2n numbers (n <= 13), a pair of numbers means that the two letters are swapped in Plugboard
 * encodeLetter encodes the given letter using the encode methods in the following order:
		-Plugboard
		-Rotors
		-Reflector
		-Rotors
		-Plugboard
 * deallocMemmory deallocates the memmory inside the vector mappingsParts
 * initialiseReflector adds a new dynnamicaly created Reflector to the machine (to mappingsParts)
 * turnRotors increases the offset of the first rotor and if the ith rotors offset is 0 then it also rotates (i+1)th rotor
		*/

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