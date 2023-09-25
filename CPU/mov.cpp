#include "instructions.h"
#include "register.h"
#include <string>
#include <exception>
#include "stack.h"
#include "instructions.h"
#include "parser.h"

void movInt() {
	registers reg;
	int reg1;
	for (int i = 0; i < 6; i++) {
		if (instructionQueue.front() == reg.regNameArray[i]) {
			reg1 = i;
			instructionQueue.pop();
			break;
		}
	}

	if (instructionQueue.front()[0] == 's') {
		try {
			regMap[reg.regNameArray[reg1]] = std::stoi(stringRegMap[instructionQueue.front()]);
			return;
		}
		catch (const std::invalid_argument&) {

		}
	}

	try {
		regMap[reg.regNameArray[reg1]] = std::stoi(instructionQueue.front());
		instructionQueue.pop();
		return;
	}
	catch (const std::invalid_argument&) {
		for (int i = 0; i < 6; i++) {
			if (instructionQueue.front() == reg.regNameArray[i]) {
				regMap[reg.regNameArray[reg1]] = regMap[reg.regNameArray[i]];
				instructionQueue.pop();
				return;
			}
		}
	}

	instructionQueue.pop();

	return;
}

void movString() {

	registers reg;
	int reg1;

	for (int i = 0; i < 6; i++) {
		if (instructionQueue.front() == reg.stringRegNameArray[i]) {
			reg1 = i;
			instructionQueue.pop();
			break;
		}
	}

	if (instructionQueue.front()[0] == 'i') {
		stringRegMap[reg.stringRegNameArray[reg1]] = std::to_string(regMap[instructionQueue.front()]);
		return;
	}

	if (instructionQueue.front()[0] != '"') {
		return;
	}

	std::string stringInput;

	for (int i = 1; !instructionQueue.empty(); i++) {

		if (instructionQueue.front()[i] == '"') {
			break;
		}
		
		if (i == instructionQueue.front().length()) {
			instructionQueue.pop();
			stringInput.push_back(' ');
			i = 0;

			if (instructionQueue.front()[i] == '"') {
				break;
			}
		}

		if (instructionQueue.front()[i] == '\\' && instructionQueue.front()[i+1] == 'n') {
			stringInput.push_back('\n');
			i++;
			continue;
		}
		
		stringInput.push_back(instructionQueue.front()[i]);
	}

	stringRegMap[reg.stringRegNameArray[reg1]] = stringInput;

	return;
}

void instructions::mov() {

	if (instructionQueue.front()[0] == 'i') {
		movInt();
		return;
	}

	if (instructionQueue.front()[0] == 's') {
		movString();
		return;
	}

	return;
}