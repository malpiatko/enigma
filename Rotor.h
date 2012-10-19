#ifndef ROTOR_H
#define ROTOR_H

#include "MappingPart.h"

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