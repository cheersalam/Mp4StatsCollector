//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMENOF_H
#define MP4STATSCOLLECTOR_MP4ATOMENOF_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomEnof : public Mp4Atom {
public:
    explicit Mp4AtomEnof(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("enof", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};


#endif //MP4STATSCOLLECTOR_MP4ATOMENOF_H
