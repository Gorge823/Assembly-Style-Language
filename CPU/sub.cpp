#include "instructions.h"
#include "register.h"
#include <string>
#include <exception>
#include "stack.h"
#include "parser.h"

void instructions::sub() {

	registers reg;

	int reg1;
	for (int i = 0; i < reg.regNameSize; i++) {
		if (instructionQueue.front() == reg.regNameArray[i]) {
			reg1 = i;
			instructionQueue.pop();
			break;
		}
	}

	int reg2;
	try {
		regMap[reg.regNameArray[reg1]] = regMap[reg.regNameArray[reg1]] - std::stoi(instructionQueue.front());
	}
	catch (const std::invalid_argument& e) {
		for (int i = 0; i < reg.regNameSize; i++) {
			if (instructionQueue.front() == reg.regNameArray[i]) {
				regMap[reg.regNameArray[reg1]] = regMap[reg.regNameArray[reg1]] - regMap[reg.regNameArray[i]];
				break;
			}
		}
	}

	return;
}