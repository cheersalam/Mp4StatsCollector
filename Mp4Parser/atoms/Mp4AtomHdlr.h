//
// Created by cheer on 6/12/2020.
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMHDLR_H
#define MP4STATSCOLLECTOR_MP4ATOMHDLR_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomHdlr : public Mp4Atom {
public:
    explicit Mp4AtomHdlr(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("hdlr", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMHDLR_H
