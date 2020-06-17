//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMVMHD_H
#define MP4STATSCOLLECTOR_MP4ATOMVMHD_H

#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomVmhd : public Mp4Atom {
public:
    explicit Mp4AtomVmhd(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload) : Mp4Atom("vmhd", size,
                                                                                                         version,
                                                                                                         false,
                                                                                                         std::move(
                                                                                                                 payload)) {
        Parse();
    }

    void Parse() {}
};

#endif //MP4STATSCOLLECTOR_MP4ATOMVMHD_H
