//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMMINF_H
#define MP4STATSCOLLECTOR_MP4ATOMMINF_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomMinf : public Mp4Atom {
public:
    explicit Mp4AtomMinf(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("minf", size, version,
                      true,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMMINF_H
