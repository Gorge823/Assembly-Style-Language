#include "instructions.h"
#include "register.h"
#include <string>
#include <exception>
#include "stack.h"
#include "instructions.h"
#include "parser.h"
#include "run.h"


void instructions::inc() {

	registers reg;

	for (int i = 0; i < reg.regNameSize; i++) {
		if (instructionQueue.front() == reg.regNameArray[i]) {

			regMap[instructionQueue.front()] = regMap[instructionQueue.front()] + 1;
			instructionQueue.pop();
			break;
		}
	}

	return;
}