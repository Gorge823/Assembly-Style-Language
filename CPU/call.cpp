#include "instructions.h"
#include "fileParser.h"
#include "parser.h"
#include "run.h"

void instructions::call() {

	for (const auto& label : jmpLabels) {
		if (label.first == instructionQueue.front()) {
			returnMode = true;
			returnLine = codePtr;
			codePtr = label.second;
			break;
		}
	}

	return;
}