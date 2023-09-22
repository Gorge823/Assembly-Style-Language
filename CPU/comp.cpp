#include "instructions.h"
#include "register.h"
#include <string>
#include <exception>
#include "stack.h"
#include "instructions.h"
#include "parser.h"
#include "run.h"

//
// Checks if the left operand is bigger than the right then runs the next instruction if so
//


void instructions::comp() {
	registers reg;

	int reg1 = 0;
	int reg2 = 0;

	try {
		reg1 = std::stoi(instructionQueue.front());
		instructionQueue.pop();
	}
	catch (const std::invalid_argument& e) {
		for (int i = 0; i < reg.regNameSize; i++) {
			if (instructionQueue.front() == reg.regNameArray[i]) {
				instructionQueue.pop();
				reg1 = regMap[reg.regNameArray[i]];
				break;
			}
		}
	}

	try {
		reg2 = std::stoi(instructionQueue.front());
		instructionQueue.pop();
	}
	catch (const std::invalid_argument& e) {
		for (int i = 0; i < reg.regNameSize; i++) {
			if (instructionQueue.front() == reg.regNameArray[i]) {
				instructionQueue.pop();
				reg2 = regMap[reg.regNameArray[i]];
				break;
			}
		}
	}

	if (reg1 < reg2) {
		codePtr++;
	}

	return;
}