//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMTKHD_H
#define MP4STATSCOLLECTOR_MP4ATOMTKHD_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomTkhd : public Mp4Atom {
public:
    explicit Mp4AtomTkhd(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("tkhd", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMTKHD_H
