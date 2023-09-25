#pragma once
#include <iostream>

extern int codePtr;
extern bool returnMode;
extern int returnLine;

enum compType {
	EQUAL,
	LESS,
	GREATER,
	NONE
};
extern compType currentComp;


class runner {
public:
	bool findInstruction();
	void runASM(std::string input);


};