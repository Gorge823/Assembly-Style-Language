#include "instructions.h"
#include "fileParser.h"
#include "parser.h"
#include "run.h"

void instructions::je() {

	for (const auto& label : jmpLabels) {

		if (currentComp != EQUAL) {
			return;
		}

		if (label.first == instructionQueue.front()) {
			codePtr = label.second;
			return;
		}
	}

	return;
}