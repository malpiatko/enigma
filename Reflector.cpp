#include "Reflector.h"

Reflector::Reflector(){}

char Reflector::encode(char letter){
	return (letter - 'A' + 13)%LETTER_NUM + 'A';
}