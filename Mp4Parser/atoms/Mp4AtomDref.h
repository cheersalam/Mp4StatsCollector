//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMDREF_H
#define MP4STATSCOLLECTOR_MP4ATOMDREF_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomDref : public Mp4Atom {
public:
    explicit Mp4AtomDref(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            :  Mp4Atom("dref", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMDREF_H
