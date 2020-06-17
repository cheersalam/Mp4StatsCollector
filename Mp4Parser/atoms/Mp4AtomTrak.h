//
// Created by cheer on 6/12/2020.
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMTRAK_H
#define MP4STATSCOLLECTOR_MP4ATOMTRAK_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomTrak : public Mp4Atom {
public:
    explicit Mp4AtomTrak(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("trak", size, version,
                      true,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMTRAK_H
