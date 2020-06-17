//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMDINF_H
#define MP4STATSCOLLECTOR_MP4ATOMDINF_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomDinf : public Mp4Atom {
public:
    explicit Mp4AtomDinf(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("dinf", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};


#endif //MP4STATSCOLLECTOR_MP4ATOMDINF_H
