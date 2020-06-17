//
// Created by cheer on 6/12/2020.
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMIODS_H
#define MP4STATSCOLLECTOR_MP4ATOMIODS_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomIods : public Mp4Atom {
public:
    explicit Mp4AtomIods(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("iods", size,
                      version, false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMIODS_H
