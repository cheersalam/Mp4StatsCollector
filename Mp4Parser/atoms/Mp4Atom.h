//
// 
//

#ifndef MP4STATSCOLLECTOR_MP4ATOM_H
#define MP4STATSCOLLECTOR_MP4ATOM_H

#include <utility>
#include <string>
#include <memory>

class Mp4Atom {
public:
    Mp4Atom() = default;

    virtual ~Mp4Atom() = default;

    Mp4Atom(Mp4Atom &) = delete;

    Mp4Atom &operator=(Mp4Atom &) = delete;

    Mp4Atom(Mp4Atom &&) = delete;

    Mp4Atom &operator=(Mp4Atom &&) = delete;

    bool IsParent() const { return _parent; }

    uint64_t GetSize() const { return _size; }

    std::string &GetName() { return _name; }

    Mp4Atom(std::string name,
            uint64_t size,
            int version,
            bool parent,
            std::unique_ptr<unsigned char[]> payload)
            : _name(std::move(name)),
              _size(size),
              _version(version),
              _parent(parent),
              _payload(std::move(payload)),
              _parentAtom(nullptr),
              _rightSibling(nullptr) {
    }

protected:

    Mp4Atom(std::string name,
            uint64_t size,
            int version,
            bool parent,
            std::unique_ptr<unsigned char[]> payload,
            std::unique_ptr<Mp4Atom> parentAtom,
            std::unique_ptr<Mp4Atom> rightSibling)
            : _name(std::move(name)),
              _size(size),
              _version(version),
              _parent(parent),
              _payload(std::move(payload)),
              _parentAtom(std::move(parentAtom)),
              _rightSibling(std::move(rightSibling)) {
    }

    std::string _name;
    uint64_t _size{};
    int _version{};
    int _flags;
    bool _parent{};
    std::unique_ptr<unsigned char[]> _payload;
    std::unique_ptr<Mp4Atom> _parentAtom;
    std::unique_ptr<Mp4Atom> _rightSibling;
};

#endif //MP4STATSCOLLECTOR_MP4ATOM_H
