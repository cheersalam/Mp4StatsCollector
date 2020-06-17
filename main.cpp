#include <iostream>
#include <cstring>
#include <Mp4Parser.h>


void PrintUsage(char **argv) {
    std::cout << " Usage: " << std::endl;
    std::cout << "\t" << argv[0] << " [FILE] [OPTION] " << std::endl;
    std::cout << "Options: " << std::endl;
    std::cout << " \t-i: count I frames" << std::endl;
}

int main(int argc, char **argv) {
    Mp4Parser mp4Parser;
    if (argc < 3) {
        PrintUsage(argv);
        return 0;
    }
    std::string filepath(argv[1]);
    if (!mp4Parser.ParseFile(filepath)) {
        std::cout << "Mp4 file parsing failed" << std::endl;
        return 0;
    }

    if (strncmp(argv[2], "-i", 2) == 0) {
        std::cout << "Number of I frames: " << mp4Parser.GetIframeCount() << std::endl;
    }
    return 0;
}
