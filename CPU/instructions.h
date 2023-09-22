#pragma once
#include "register.h"
#include <queue>
#include <iostream>

class instructions {
public:

	//
	// Stack instructions
	//

	// Pops a register from the top of the stack
	void pop();

	// Pushs a register to the stack
	void push();

	//
	// Logical instructions
	//

	// Checks if left is bigger than right runs next line if true
	void comp();

	// Moves right value into left register
	void mov();

	//
	// Flow instructions
	//
	
	// Moves current execution line to label specified
	void jmp();

	// Moves current execution line to label specified
	void call();

	// Returns current execution line to pre call line
	void ret();

	//
	// Math instructions
	//
	
	// Increments input
	void inc();

	// Adds second value to first register
	void add();

	// Subtracts second value from first register
	void sub();

	// Makes a system call
	void syscall();
};