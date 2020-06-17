//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMDOPS_H
#define MP4STATSCOLLECTOR_MP4ATOMDOPS_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomDops : public Mp4Atom {
public:
    explicit Mp4AtomDops(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("dops", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMDOPS_H
