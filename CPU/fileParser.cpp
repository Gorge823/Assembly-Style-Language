#include "fileParser.h" 
#include <fstream>
#include <string>

bool fileParser::parseFile(std::string inputFile) {
	std::ifstream file(inputFile);

	if (!file.is_open()) {
		return false;
	}

	std::string line;
	while (std::getline(file, line)) {
		if (!line.empty() && line.find_first_not_of(" \t") != std::string::npos ) {
			if (line[0] == ':') {
				
				line.erase(0, 1);

				jmpLabels[line] = code.size();

				code.push_back("%LABEL");
			}
			else {
				code.push_back(line);
			}
		}
	}

	return true;
}