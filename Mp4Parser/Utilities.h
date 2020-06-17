//
// 
//

#ifndef MP4STATSCOLLECTOR_UTILITIES_H
#define MP4STATSCOLLECTOR_UTILITIES_H

#include <cstdint>

//not dealing with endianess

class Utilities {
public:
    static uint32_t ConvertToUint32(const uint8_t *buffer) {
        return buffer[0] << 24 | buffer[1] << 16 | buffer[2] << 8 | buffer[3];
    }

    static uint32_t ConvertToUint32(unsigned char *buffer) {
        return buffer[0] << 24 | buffer[1] << 16 | buffer[2] << 8 | buffer[3];
    }

    static uint64_t ConvertToUint64(unsigned char *buffer) {
        return ((uint64_t)ConvertToUint32(buffer) << 32) | (ConvertToUint32(buffer + 4));
    }
};

#endif //MP4STATSCOLLECTOR_UTILITIES_H
