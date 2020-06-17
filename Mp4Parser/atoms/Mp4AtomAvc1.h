//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMAVC1_H
#define MP4STATSCOLLECTOR_MP4ATOMAVC1_H

#include "Mp4Atom.h"

class Mp4AtomAvc1 : public Mp4Atom {
public:
    explicit Mp4AtomAvc1(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("avc1", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMAVC1_H
