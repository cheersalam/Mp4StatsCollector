//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMSMHD_H
#define MP4STATSCOLLECTOR_MP4ATOMSMHD_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomSmhd : public Mp4Atom {
public:
    explicit Mp4AtomSmhd(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("smhd", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMSMHD_H
