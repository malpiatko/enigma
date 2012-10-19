#include "Plugboard.h"
#include <fstream>

using namespace std;

Plugboard::Plugboard(char *fileName){
	ifstream file;
	int a,b;
	for(int i = 0; i < LETTER_NUM; i++){
		mappingsForward[i] = i;
	}
	file.open(fileName);
	while (file>>a>>b){
		mappingsForward[a] = b;
		mappingsForward[b] = a;
	}
	file.close();
}

char Plugboard::encode(char letter){
	return mappingsForward[letter-'A'] + 'A';
}