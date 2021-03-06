//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMCTTS_H
#define MP4STATSCOLLECTOR_MP4ATOMCTTS_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomCtts : public Mp4Atom {
public:
    explicit Mp4AtomCtts(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("ctts", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};


#endif //MP4STATSCOLLECTOR_MP4ATOMCTTS_H
