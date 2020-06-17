//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMSTSZ_H
#define MP4STATSCOLLECTOR_MP4ATOMSTSZ_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomStsz : public Mp4Atom {
public:
    explicit Mp4AtomStsz(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("stsz", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMSTSZ_H
