//
// Created by cheer on 6/12/2020.
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMMOOV_H
#define MP4STATSCOLLECTOR_MP4ATOMMOOV_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomMoov : public Mp4Atom {
public:
    explicit Mp4AtomMoov(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("moov", size, version,
                      true,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMMOOV_H
