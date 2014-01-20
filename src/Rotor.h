#ifndef ROTOR_H
#define ROTOR_H

#include "MappingPart.h"
#include "Constants.h"

/*part of enigma machine used for mapping of one letter to the other in the machines alphabet
 * offset indicates by how many positions the rotor is rotated from its initial position
 * signal indicates if its the first or second time that the rotor is used in encoding a given letter, true = first time
 * mappingBackward is a mapping which is the opposite to the mappingsBackward mapping
 * Rotor is a constructor that takes a text file with LETTER_NUM numbers, for the i-th number mappingsForward[i] equals that number, it initialises offset to 0 and signal to true
 * getOffset - gives the offset of the rotor
 * increasOffset - increases offset by 1 and takes the modulus LETTER_NUM of the new offset
 * encode - maps the given letter to a letter in the alphabet of the machine, after rotations the mapping for the given character is taken from mappings*[letter + offset], if the signal is true it uses mappingsForward and if false it uses mappingsBackward */
class Rotor: public MappingPart{
	int offset;
	bool signal;
	int mappingsBackward[LETTER_NUM];
public:
	Rotor(char *filename);
	int getOffset();
	void increaseOffset();
	char encode(char letter);
};

#endif