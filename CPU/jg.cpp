#include "instructions.h"
#include "fileParser.h"
#include "parser.h"
#include "run.h"

void instructions::jg() {

	for (const auto& label : jmpLabels) {

		if (currentComp != GREATER) {
			return;
		}

		if (label.first == instructionQueue.front()) {
			codePtr = label.second;
			return;
		}
	}

	return;
}