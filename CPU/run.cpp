#include "run.h"
#include "parser.h"
#include <queue>
#include <iostream>
#include "instructions.h"
#include "stack.h"
#include "fileParser.h"


void runner::runASM(std::string input) {
	parser p;
	fileParser fp;

	fp.parseFile();

	for (const auto& label : jmpLabels) {
		if (label.first == "start") {
			codePtr = label.second;
			break;
		}
	}

	while (codePtr < code.size()) {

		p.parseInstruction(code[codePtr]);
		
		if (findInstruction()) {
			codePtr++;
		}

		while (!instructionQueue.empty()) {
			instructionQueue.pop();
		}
	}

	return;
}

bool runner::findInstruction() {
	registers reg;
	instructions instruct;

	if (instructionQueue.front()[0] == '%' || instructionQueue.front()[0] == ';') {
		return true;
	}
	
	if (instructionQueue.front() == "ret") {
		instructionQueue.pop();
		instruct.ret();
		return true;
	}

	/*
	if (instructionQueue.front() == "dump") {
		std::cout << "\n=-=-=-=-=-=\nRegister dump:\n";
		for (const auto& pair : regMap) {
			std::cout << "	Key: " << pair.first << ", Value: " << pair.second << '\n';
		}
		std::cout << "=-=-=-=-=-=\n";
		for (const auto& pair : stringRegMap) {
			std::cout << "	Key: " << pair.first << ", Value: \"" << pair.second << "\" \n";
		}
		std::cout << "=-=-=-=-=-=\n";
		return true;
	}
	*/

	if (instructionQueue.front() == "syscall") {
		instructionQueue.pop();
		instruct.syscall();
		return true;
	}

	if (instructionQueue.front() == "push") {
		instructionQueue.pop();
		instruct.push();
		return true;
	}

	if (instructionQueue.front() == "inc") {
		instructionQueue.pop();
		instruct.inc();
		return true;
	}

	if (instructionQueue.front() == "pop") {
		instructionQueue.pop();
		instruct.pop();
		return true;
	}

	if (instructionQueue.front() == "jmp") {
		instructionQueue.pop();
		instruct.jmp();
		return true;
	}

	if (instructionQueue.front() == "je") {
		instructionQueue.pop();
		instruct.je();
		return true;
	}

	if (instructionQueue.front() == "jl") {
		instructionQueue.pop();
		instruct.jl();
		return true;
	}

	if (instructionQueue.front() == "jg") {
		instructionQueue.pop();
		instruct.jg();
		return true;
	}

	if (instructionQueue.front() == "call") {
		instructionQueue.pop();
		instruct.call();
		return true;
	}

	if (instructionQueue.front() == "mov") {
		instructionQueue.pop();
		instruct.mov();
		return true;
	}

	if (instructionQueue.front() == "comp") {
		instructionQueue.pop();
		instruct.comp();
		return true;
	}

	if (instructionQueue.front() == "add") {
		instructionQueue.pop();
		instruct.add();
		return true;
	}

	if (instructionQueue.front() == "sub") {
		instructionQueue.pop();
		instruct.sub();
		return true;
	}

	return false;
}