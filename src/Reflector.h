#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "MappingPart.h"
#include "Constants.h"

/*its a part of the enigma machine
	*encodeLetter - it uses the following function to map an input at alphabet x to
	its output: r(x) = (x + 13)%26
*/
class Reflector : public MappingPart {
public:
	char encode(char letter);
	Reflector();
};

#endif