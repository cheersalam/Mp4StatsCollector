//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMUUID_H
#define MP4STATSCOLLECTOR_MP4ATOMUUID_H
#include <iostream>
#include "Mp4Atom.h"

class Mp4AtomUuid : public Mp4Atom {
public:
    explicit Mp4AtomUuid(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
    : Mp4Atom("uuid", size, version,
                                                                                               false,
                                                                                               std::move(payload)) {
        Parse();
    }

    void Parse()  {}
};
#endif //MP4STATSCOLLECTOR_MP4ATOMUUID_H
