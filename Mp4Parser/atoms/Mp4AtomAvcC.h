//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMAVCC_H
#define MP4STATSCOLLECTOR_MP4ATOMAVCC_H

#include "Mp4Atom.h"

class Mp4AtomAvcC : public Mp4Atom {
public:
    explicit Mp4AtomAvcC(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("avcC", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMAVCC_H
