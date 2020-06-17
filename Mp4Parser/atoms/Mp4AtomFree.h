//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMFREE_H
#define MP4STATSCOLLECTOR_MP4ATOMFREE_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomFree : public Mp4Atom {
public:
    explicit Mp4AtomFree(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("free", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMFREE_H
