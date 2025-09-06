#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

void replaceAll(std::string& line, const std::string& s1, const std::string& s2) {
    std::string::size_type pos = 0;
    if (line.empty() || s1.empty())
        return;
    while ((pos = line.find(s1,pos)) != std::string::npos) {
        line.erase(pos, s1.length());
        line.insert(pos,s2);
        pos += s2.length();
    }
}

int main(int argc, char ** argv) {
    if (argc != 4) {
        std::cout << "Usage: " << argv[0] << " filename s1 s2" << std::endl;
        return 1;
    }
    std::string fileName = argv[1];
    std::ifstream inputFile(fileName.c_str());

    if (inputFile.is_open() == false) {
        std::cout << "Failed to open " << fileName << std::endl;
        return 1;
    }
    std::string outputFileName = fileName + ".replace";

    std::ofstream outputFile(outputFileName.c_str());
    if (outputFile.is_open() == false) {
        std::cout << "Failed to open " << outputFileName << std::endl;
        return 1;
    }
    std::string line;
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    while (std::getline(inputFile, line)) {
        replaceAll(line, s1, s2);
        outputFile << line << std::endl;
    }
    return 0;
}
