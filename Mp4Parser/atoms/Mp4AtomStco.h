//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMSTCO_H
#define MP4STATSCOLLECTOR_MP4ATOMSTCO_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomStco : public Mp4Atom {
public:
    explicit Mp4AtomStco(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("stco", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMSTCO_H
