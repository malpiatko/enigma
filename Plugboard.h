#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "MappingPart.h"
/*
part of the enigma machine used to encode letters, 
 * Plugboard is a constructor that takes a text file consisting of 2n numbers (n <= 13), first it initialises the mappingsForward[i] = i and then for each pair of numbers i,j maps the ith letter of the alphabet of the machine to j-th and the other wat round
 * encodes - for given letter returns a letter from the alphabet as indicated by the mappingsForward*/
class Plugboard: public MappingPart {
public:
	Plugboard(char *fileName);
	char encode(char letter);
};

#endif