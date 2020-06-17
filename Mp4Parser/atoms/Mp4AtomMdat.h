//
// Created by cheer on 6/12/2020.
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMMDAT_H
#define MP4STATSCOLLECTOR_MP4ATOMMDAT_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomMdat : public Mp4Atom {
public:
    explicit Mp4AtomMdat(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("mdat", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMMDAT_H
