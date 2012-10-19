#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "MappingPart.h"

class Plugboard: public MappingPart {
public:
	Plugboard(char *fileName);
	char encode(char letter);
};

#endif