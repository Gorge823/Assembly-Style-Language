#include "register.h"
#include "stack.h"
#include "fileParser.h"
#include "parser.h"

std::stack<int> regStack;
std::stack<std::string> regStackString;
std::vector<std::string> code;
int codePtr;

bool returnMode = false;
int returnLine = 0;

std::unordered_map<std::string, int> regMap = {
	{"iax", 0},
	{"ibx", 0},
	{"icx", 0},
	{"idx", 0},
	{"iex", 0}
};

std::unordered_map<std::string, std::string> stringRegMap = {
	{"sax", "EMPTY"},
	{"sbx", "EMPTY"},
	{"scx", "EMPTY"},
	{"sdx", "EMPTY"}
};


extern std::unordered_map<std::string, int> jmpLabels{ };

std::queue<std::string> instructionQueue;