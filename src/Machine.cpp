#include "Machine.h"
#include <string>

using namespace std;

void Machine::initialiseRotors(int n, char **fileNames){
	for(int i = 0; i < n; i++){
		mappingParts.push_back(new Rotor(fileNames[i]));
	}
}

void Machine::initialisePlugboard(char *fileName){
	mappingParts.push_back(new Plugboard(fileName));
}

void Machine::initialiseReflector(){
	mappingParts.push_back(new Reflector());
}

//encodes letter using the mappings of the elements of the machine Plugboard, Rotors, Reflector in the order P(Rot)Ref(Rot)P
char Machine::encodeLetter(char letter){
	for(int i = 0; i < mappingParts.size(); i++){
		letter = mappingParts[i]->encode(letter);
	}
	for(int i = mappingParts.size()-2; i >=0; i--){
		letter = mappingParts[i] -> encode(letter);
	}
	turnRotor(1);
	return letter;
}

void Machine::turnRotor(int i){
	((Rotor*)mappingParts[i])->increaseOffset();
	if(((Rotor*)mappingParts[i])->getOffset() == 0){
		if(i < mappingParts.size()-2){
			turnRotor(i+1);
		}
	}
}

void Machine::deallocMemmory(){
	for(int i = 0; i < mappingParts.size(); i++){
		delete mappingParts[i];
	}
}