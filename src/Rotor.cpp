#include "Rotor.h"
#include <fstream>
using namespace std;

Rotor::Rotor(char *fileName){
	ifstream file;
	offset = 0;
	signal = true;
	file.open(fileName);
	for(int i = 0, x; i<LETTER_NUM; i++){
		file >> x;
		x = x-i;
		if(x < 0){
			x = LETTER_NUM + x;
		}
		mappingsForward[i] = x;
		mappingsBackward[(x + i)%LETTER_NUM] = LETTER_NUM -x;
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
	letter = letter-'A';
	int x;
	if (signal == true){
		signal = false;
		return (letter+mappingsForward[(letter+offset)%LETTER_NUM])%LETTER_NUM + 'A';
	} else{
		signal = true;
		x = letter + offset;
		if(x < 0){
			x = LETTER_NUM + x;
		}
		return (letter +mappingsBackward[x%LETTER_NUM])%LETTER_NUM + 'A';
	}
}