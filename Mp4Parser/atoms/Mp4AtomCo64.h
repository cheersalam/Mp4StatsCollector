//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMCO64_H
#define MP4STATSCOLLECTOR_MP4ATOMCO64_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomCo64 : public Mp4Atom {
public:
    explicit Mp4AtomCo64(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("co64", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};


#endif //MP4STATSCOLLECTOR_MP4ATOMCO64_H
