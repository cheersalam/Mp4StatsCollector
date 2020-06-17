//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMCSLG_H
#define MP4STATSCOLLECTOR_MP4ATOMCSLG_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomCslg : public Mp4Atom {
public:
    explicit Mp4AtomCslg(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("cslg", size, version,
                      false,
                      std::move(payload)) {
        Parse();

    }

    void Parse() {}
};


#endif //MP4STATSCOLLECTOR_MP4ATOMCSLG_H
