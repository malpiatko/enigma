#include "Rotor.h"
#include <fstream>
#include <iostream>
using namespace std;

Rotor::Rotor(char *fileName){
	ifstream file;
	offset = 0;
	signal = true;
	file.open(fileName);
	for(int i = 0; i<LETTER_NUM; i++){
		file >> mappingsForward[i];
		mappingsBackward[mappingsForward[i]] = i;
	}
	file.close();
}

int Rotor::getOffset(){
	return offset;
}

void Rotor::increaseOffset(){
	offset= offset+1;
	offset = offset%LETTER_NUM;
}

char Rotor::encode(char letter){
	int x;
	if (signal == true){
		signal = false;
		x = mappingsForward[(letter-'A' + offset)%LETTER_NUM] - offset;
		if(x <0){
			x = LETTER_NUM + x;
		}
		return x + 'A';
	} else{
		signal = true;
		x = letter - 'A' - offset;
		if(x < 0){
			x = LETTER_NUM + x;
		}
		return (mappingsBackward[x%LETTER_NUM] + offset)%LETTER_NUM + 'A';
	}
}