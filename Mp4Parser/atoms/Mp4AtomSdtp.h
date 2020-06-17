//
// .
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMSDTP_H
#define MP4STATSCOLLECTOR_MP4ATOMSDTP_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomSdtp : public Mp4Atom {
public:
    explicit Mp4AtomSdtp(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("sdtp", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMSDTP_H
