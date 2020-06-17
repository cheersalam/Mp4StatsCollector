//
// Created by cheer on 6/12/2020.
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMVHD_H
#define MP4STATSCOLLECTOR_MP4ATOMVHD_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomMvhd : public Mp4Atom {
public:
    explicit Mp4AtomMvhd(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("mvhd", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMVHD_H
