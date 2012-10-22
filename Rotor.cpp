#include "Rotor.h"
#include <fstream>
#include <iostream>
using namespace std;

Rotor::Rotor(char *fileName){
	ifstream file;
	offset = 0;
	signal = true;
	file.open(fileName);
	for(int i = 0, x; i<LETTER_NUM; i++){
		file >> x;
		cout<<"x= "<<x;
		x = x-i;
		if(x < 0){
			x = LETTER_NUM + x;
		}
		mappingsForward[i] = x;
		mappingsBackward[(x + i)%LETTER_NUM] = LETTER_NUM -x;
	}
	
	for(int i = 0; i <LETTER_NUM; i++){
		cout<<"forward: " <<mappingsForward[i]<<endl;
	}
	cout<<endl;/*
	for(int i = 0; i <LETTER_NUM; i++){
	cout<<"backward: " <<mappingsBackward[i]<<endl;
	}*/
	file.close();
}

int Rotor::getOffset(){
	return offset;
}

void Rotor::increaseOffset(){
	offset= offset+1;
	offset = offset%LETTER_NUM;
}

/*char Rotor::encode(char letter){
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
}*/

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