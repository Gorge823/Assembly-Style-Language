#include "parser.h"
#include "instructions.h"
#include "stack.h"

void pushInt() {

	registers reg;

	for (int i = 0; i < reg.regNameSize; i++) {
		if (instructionQueue.front() == reg.regNameArray[i]) {
			regStack.push(regMap[instructionQueue.front()]);
			break;
		};
	}

	instructionQueue.pop();

	return;
}

void pushString() {

	registers reg;

	for (int i = 0; i < reg.stringRegNameSize; i++) {
		if (instructionQueue.front() == reg.stringRegNameArray[i]) {
			regStackString.push(stringRegMap[instructionQueue.front()]);
			break;
		};
	}

	instructionQueue.pop();

	return;
}


void instructions::push() {

	if (instructionQueue.front()[0] == 'i') {
		pushInt();
	}

	if (instructionQueue.front()[0] == 's') {
		pushString();
	}

	return;
}