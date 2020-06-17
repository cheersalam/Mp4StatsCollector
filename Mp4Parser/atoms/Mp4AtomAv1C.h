//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMAV1C_H
#define MP4STATSCOLLECTOR_MP4ATOMAV1C_H

#include "Mp4Atom.h"

class Mp4AtomAv1C : public Mp4Atom {
public:
    explicit Mp4AtomAv1C(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("av1c", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMAV1C_H
