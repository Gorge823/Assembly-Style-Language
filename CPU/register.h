#pragma once
#include <unordered_map>
#include <iostream>

extern std::unordered_map<std::string, long int> regMap;
extern std::unordered_map<std::string, std::string> stringRegMap;

class registers {
public:

	int regNameSize = 6;
	std::string regNameArray[5] = { 
		"iax",
		"ibx",
		"icx",
		"idx",
		"iex"
	};

	int stringRegNameSize = 4;
	std::string stringRegNameArray[4] = {
		"sax",
		"sbx",
		"scx",
		"sdx"
	};
};