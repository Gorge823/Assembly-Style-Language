#include "instructions.h"
#include "fileParser.h"
#include "parser.h"
#include "run.h"

void instructions::jl() {

	for (const auto& label : jmpLabels) {

		if (currentComp != LESS) {
			return;
		}

		if (label.first == instructionQueue.front()) {
			codePtr = label.second;
			return;
		}
	}

	return;
}