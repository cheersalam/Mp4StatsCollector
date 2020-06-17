//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMSTSD_H
#define MP4STATSCOLLECTOR_MP4ATOMSTSD_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomStsd : public Mp4Atom {
public:
    explicit Mp4AtomStsd(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("stsd", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMSTSD_H
