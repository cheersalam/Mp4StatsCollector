//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMFTYP_H
#define MP4STATSCOLLECTOR_MP4ATOMFTYP_H

#include "Mp4Atom.h"

class Mp4AtomFtyp : public Mp4Atom {
public:
    explicit Mp4AtomFtyp(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("ftyp", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMFTYP_H
