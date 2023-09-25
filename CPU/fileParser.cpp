#include "fileParser.h" 
#include <fstream>
#include <string>

bool parse(std::string filePath) {
	std::ifstream file(filePath);

	if (!file.is_open()) {
		return false;
	}

	std::string line;
	while (std::getline(file, line)) {
		if (!line.empty() && line.find_first_not_of(" \t") != std::string::npos ) {
			if (line[line.length() - 1] == ':') {

				line.erase(line.length() - 1, 1);

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


bool fileParser::parseFile() {

	std::ifstream buildFile(".\\build.dat");

	if (!buildFile) {
		std::cerr << "Failed to open file\n";
		return false;
	}

	std::vector<std::string> files;
	{
		std::string newFile;
		while (std::getline(buildFile, newFile)) {
			if (newFile[0] != ';') {
			}
			files.push_back(newFile);
		}
	}
	
	for (std::string fileName : files) {
		parse(fileName);
	}

	return true;
}