#ifndef MAPPINGPART_H
#define MAPPINGPART_H

#include "Constants.h"

/*its an abstract class which defines behaviour of parts in the machine which map a given letter to a different letter in the alphabet of the machine
mappingsForward is a mapping: ith letter in the machines alphabet is mapped to mappingsForward[i]
note: Reflector is not using mappingsForward and Rotors have also mappingsBackward*/
class MappingPart {
protected:
	int mappingsForward[LETTER_NUM];
public:
	virtual char encode(char letter)=0;
};

#endif 

