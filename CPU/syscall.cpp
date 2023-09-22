#include "instructions.h"
#include "register.h"
#include <string>
#include <exception>
#include "stack.h"
#include "instructions.h"
#include "parser.h"
#include "run.h"
#include "stdlib.h"
#include "fileParser.h"

//
// ax = instruction code
// bx = arg1
// cx = arg2
// dx = arg3
// 
void instructions::syscall() {

	switch (regMap["iax"])
	{
	case 0: // Exit program
		exit(regMap["ibx"]);
		break;
	case 1: // Restart program
		for (const auto& label : jmpLabels) {
			if (label.first == "start") {
				codePtr = label.second;
				break;
			}
		}
		break;
	case 2: // Write
		std::cout << stringRegMap["sax"];
		break;
	case 3: // Read
		std::getline(std::cin, stringRegMap["sax"]);
		break;
	default:
		break;
	}

	return;
}