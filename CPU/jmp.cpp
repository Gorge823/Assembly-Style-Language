#include "instructions.h"
#include "fileParser.h"
#include "parser.h"
#include "run.h"

void instructions::jmp() {

	for (const auto& label : jmpLabels) {
		if (label.first == instructionQueue.front()) {
			codePtr = label.second;
			return;
		}
	}

	return;
}