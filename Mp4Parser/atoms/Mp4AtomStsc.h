//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMSTSC_H
#define MP4STATSCOLLECTOR_MP4ATOMSTSC_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomStsc : public Mp4Atom {
public:
    explicit Mp4AtomStsc(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("stsc", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMSTSC_H
