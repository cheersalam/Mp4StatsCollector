//
// Created by cheer on 6/12/2020.
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMGMIN_H
#define MP4STATSCOLLECTOR_MP4ATOMGMIN_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomGmin : public Mp4Atom {
public:
    explicit Mp4AtomGmin(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("gmin", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMGMIN_H
