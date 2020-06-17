//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMEDTS_H
#define MP4STATSCOLLECTOR_MP4ATOMEDTS_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomEdts : public Mp4Atom {
public:
    explicit Mp4AtomEdts(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("edts", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};


#endif //MP4STATSCOLLECTOR_MP4ATOMEDTS_H
