#ifndef MAPPINGPART_H
#define MAPPINGPART_H

#define LETTER_NUM 26

class MappingPart {
protected:
	int mappingsForward[LETTER_NUM];
public:
	virtual char encode(char letter)=0;
};

#endif 

