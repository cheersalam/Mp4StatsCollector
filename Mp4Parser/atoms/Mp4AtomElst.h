//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMELST_H
#define MP4STATSCOLLECTOR_MP4ATOMELST_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomElst : public Mp4Atom {
public:
    explicit Mp4AtomElst(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("elts", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};


#endif //MP4STATSCOLLECTOR_MP4ATOMELST_H
