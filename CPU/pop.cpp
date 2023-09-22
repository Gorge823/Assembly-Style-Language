#include "parser.h"
#include "instructions.h"
#include "stack.h"
	
extern std::stack<int> stack;

void popInt() {

	registers reg;

	for (int i = 0; i < reg.regNameSize; i++) {
		if (instructionQueue.front() == reg.regNameArray[i]) {
			
			if (regStack.empty()) {
				return;
			}

			regMap[reg.regNameArray[i]] = regStack.top();
			regStack.pop();
			instructionQueue.pop();
			return;
		}
	}
}

void popString() {

	registers reg;

	for (int i = 0; i < reg.stringRegNameSize; i++) {
		if (instructionQueue.front() == reg.stringRegNameArray[i]) {

			if (regStackString.empty()) {
				return;
			}

			stringRegMap[reg.stringRegNameArray[i]] = regStackString.top();
			regStackString.pop();
			instructionQueue.pop();
			return;
		}
	}
}

void instructions::pop() {

	if (instructionQueue.front()[0] == 'i') {
		popInt();
	}

	if (instructionQueue.front()[0] == 's') {
		popString();
	}


	return;
}
