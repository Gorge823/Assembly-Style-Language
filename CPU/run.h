#pragma once
#include <iostream>

extern int codePtr;
extern bool returnMode;
extern int returnLine;

class runner {
public:
	bool findInstruction();
	void runASM(std::string input);
};