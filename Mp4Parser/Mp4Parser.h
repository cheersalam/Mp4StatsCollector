//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4PARSER_H
#define MP4STATSCOLLECTOR_MP4PARSER_H


#include <string>
#include "map"
#include "atoms/Mp4Atom.h"

class Mp4Parser {
public:
    bool ParseFile(std::string &filePath);

    size_t GetIframeCount();

private:
    size_t _bytesRead = 0;
    bool _parsed;
    std::map<std::string, Mp4Atom *> _mp4Items;

    void ParseAtom(std::string &name, size_t size, std::unique_ptr<unsigned char[]> payload);

    Mp4Atom *SaveAtom(std::string &name, size_t size, std::unique_ptr<unsigned char[]> payload);

};


#endif //MP4STATSCOLLECTOR_MP4PARSER_H
