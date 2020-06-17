//
// Created by cheer on 6/12/2020.
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMILST_H
#define MP4STATSCOLLECTOR_MP4ATOMILST_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomIlst : public Mp4Atom {
public:
    explicit Mp4AtomIlst(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("ilst", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMILST_H
