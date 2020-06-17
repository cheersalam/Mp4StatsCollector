//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMSTBL_H
#define MP4STATSCOLLECTOR_MP4ATOMSTBL_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomStbl : public Mp4Atom {
public:
    explicit Mp4AtomStbl(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("stbl", size, version,
                      true,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMSTBL_H
