#include <iostream>
#include <fstream>

std::string replaceAll(std::string text, const std::string& s1, const std::string& s2) {
    std::string result;
    size_t pos = 0;
    size_t found;

    while ((found = text.find(s1, pos)) != std::string::npos) {
        result.append(text.substr(pos, found - pos));
        result.append(s2);
        pos = found + s1.length();
    }
    result.append(text.substr(pos));

    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::ifstream inFile(argv[1]);
    if (!inFile) {
        std::cerr << "Error: Cannot open file " << argv[1] << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::ofstream outFile((filename + ".replace").c_str());
    if (!outFile) {
        std::cerr << "Error: Cannot create output file" << std::endl;
        return 1;
    }

    std::string fileContent;
    std::string line;
    while (std::getline(inFile, line)) {
        fileContent += line;
        if (!inFile.eof()) fileContent += "\n";
    }

    if (argv[2][0] == '\0') {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return 1;
    }

    std::string replacedContent = replaceAll(fileContent, argv[2], argv[3]);
    outFile << replacedContent;

    inFile.close();
    outFile.close();

    return 0;
}
