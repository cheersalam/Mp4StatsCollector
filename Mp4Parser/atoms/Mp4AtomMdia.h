//
// Created by cheer on 6/12/2020.
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMMDIA_H
#define MP4STATSCOLLECTOR_MP4ATOMMDIA_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomMdia : public Mp4Atom {
public:
    explicit Mp4AtomMdia(size_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("mdia", size, version,
                      true,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMMDIA_H
