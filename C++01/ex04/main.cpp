#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char ** argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: " << argv[0] << " filename s1 s2" << std::endl;
        return 1;
    }
    std::string fileName = argv[1];
    std::ifstream inputFile(fileName.c_str());

    if (inputFile.is_open() == false)
    {
        std::cout << "Failed to open " << fileName << std::endl;
        inputFile.close();
        return 1;
    }


    inputFile.close();
    return 0;
}
