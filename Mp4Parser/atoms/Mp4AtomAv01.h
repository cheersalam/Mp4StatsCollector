//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMAV01_H
#define MP4STATSCOLLECTOR_MP4ATOMAV01_H

#include "Mp4Atom.h"

class Mp4AtomAv01 : public Mp4Atom {
public:
    explicit Mp4AtomAv01(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("av01", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMAV01_H
