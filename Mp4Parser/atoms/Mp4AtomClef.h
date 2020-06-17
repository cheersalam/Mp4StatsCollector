//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMCLEF_H
#define MP4STATSCOLLECTOR_MP4ATOMCLEF_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomClef : public Mp4Atom {
public:
    explicit Mp4AtomClef(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("clef", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMCLEF_H
