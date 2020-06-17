//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMESDS_H
#define MP4STATSCOLLECTOR_MP4ATOMESDS_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomEsds : public Mp4Atom {
public:
    explicit Mp4AtomEsds(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("esds", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMESDS_H
