//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOMSTSS_H
#define MP4STATSCOLLECTOR_MP4ATOMSTSS_H

#include <iostream>
#include "Mp4Atom.h"
#include "../Utilities.h"

/*
 *
 * aligned(8) class SyncSampleBox
 *  extends FullBox(‘stss’, version = 0, 0) {
 *    unsigned int(32) entry_count;
 *    int i;
 *    for (i=0; i < entry_count; i++) {
 *      unsigned int(32) sample_number;
 *    }
 *  }
 *
 * This	box	provides a compact marking of the sync samples within the stream. The table is arranged in
 * strictly increasing	order of sample	number. If the sync	sample box is not present, every sample is a sync sample.
 */

class Mp4AtomStss : public Mp4Atom {
public:
    explicit Mp4AtomStss(uint64_t size, int version, std::unique_ptr<unsigned char[]> payload)
            : Mp4Atom("stss", size, version,
                      false,
                      std::move(payload)) {
        Parse();
    }

    void Parse() {
        size_t offset = 0;
        _version = _payload[offset];
        _flags = _payload[offset + 1];
        _entry_count = Utilities::ConvertToUint32(&_payload[offset + 4]);
    }

    uint32_t GetEntryCount() const {
        return _entry_count;
    }

private:
    uint32_t _entry_count;
};

#endif //MP4STATSCOLLECTOR_MP4ATOMSTSS_H
