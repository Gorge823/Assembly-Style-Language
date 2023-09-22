#include "instructions.h"
#include "register.h"
#include <string>
#include <exception>
#include "stack.h"
#include "instructions.h"
#include "parser.h"
#include "run.h"

void instructions::ret() {
	if (returnMode) {
		codePtr = returnLine;
		returnMode = false;
	}

	return;
}