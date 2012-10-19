#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "MappingPart.h"

class Reflector : public MappingPart {
public:
	char encode(char letter);
	Reflector();
};

#endif