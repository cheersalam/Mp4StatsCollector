//
// 
//

#include <iostream>
#include <cstring>
#include "Mp4Parser.h"
#include "Utilities.h"
#include "atoms/Mp4Atom.h"
#include "atoms/Mp4AtomFtyp.h"
#include "atoms/Mp4AtomMoov.h"
#include "atoms/Mp4AtomMvhd.h"
#include "atoms/Mp4AtomIods.h"
#include "atoms/Mp4AtomTrak.h"
#include "atoms/Mp4AtomUdta.h"
#include "atoms/Mp4AtomMdat.h"
#include "atoms/Mp4AtomTkhd.h"
#include "atoms/Mp4AtomMdia.h"
#include "atoms/Mp4AtomMdhd.h"
#include "atoms/Mp4AtomHdlr.h"
#include "atoms/Mp4AtomMinf.h"
#include "atoms/Mp4AtomSmhd.h"
#include "atoms/Mp4AtomDinf.h"
#include "atoms/Mp4AtomStbl.h"
#include "atoms/Mp4AtomStsd.h"
#include "atoms/Mp4AtomStts.h"
#include "atoms/Mp4AtomStsz.h"
#include "atoms/Mp4AtomStco.h"
#include "atoms/Mp4AtomStsc.h"
#include "atoms/Mp4AtomVmhd.h"
#include "atoms/Mp4AtomUuid.h"
#include "atoms/Mp4AtomCtts.h"
#include "atoms/Mp4AtomStss.h"
#include "atoms/Mp4AtomEdts.h"
#include "atoms/Mp4AtomSdtp.h"
#include "atoms/Mp4AtomFree.h"

bool Mp4Parser::ParseFile(std::string &filePath) {
    try {
        FILE *fp = nullptr;
        fp = fopen(filePath.c_str(), "rb");
        if (fp == nullptr) {
            std::cerr << "File opening failed " << filePath << std::endl;
            return false;
        }

        char shortHeader[9] = {'\0'};
        _bytesRead = 0;
        while (fread(shortHeader, 1, 8, fp) == 8) {
            uint64_t size = Utilities::ConvertToUint32(reinterpret_cast<unsigned char *>(&shortHeader[0]));
            std::string name(&shortHeader[4], 4);

            if (size == 1) { //extended size
                fread(shortHeader, 1, 8, fp);
                long currentIndex = ftell(fp);
                fseek(fp, currentIndex - 8, SEEK_SET);
                size = Utilities::ConvertToUint64(reinterpret_cast<unsigned char *>(shortHeader));
            } else if (size == 0) { //last box in a file
                long currentIndex = ftell(fp);
                fseek(fp, 0L, SEEK_END);
                size = ftell(fp) - currentIndex + 8;
                fseek(fp, currentIndex, SEEK_SET);
            } else { ; }
            unsigned char *payload = nullptr;
            if (strncmp(name.c_str(), "mdat", name.length()) == 0) {
                long currentIndex = ftell(fp);
                fseek(fp, currentIndex + size, SEEK_SET);
            } else {
                payload = new unsigned char[size];
                fread(payload, 1, size - 8, fp);
            }
            ParseAtom(name, size, std::unique_ptr<unsigned char[]>(payload));
            fseek(fp, _bytesRead, SEEK_SET);
        }
    }
    catch (const std::exception &ex) {
        std::cout << ex.what() << std::endl;
        return false;
    }
    return true;
}

void Mp4Parser::ParseAtom(std::string &name, size_t size, std::unique_ptr<unsigned char[]> payload) {
    auto atom = SaveAtom(name, size, std::move(payload));
    if (atom != nullptr) {
        if (atom->IsParent()) {
            _bytesRead += 8;
        } else {
            _bytesRead += atom->GetSize();
        }
    }
}

Mp4Atom *Mp4Parser::SaveAtom(std::string &name, size_t size, std::unique_ptr<unsigned char[]> payload) {
    Mp4Atom *mp4Atom = nullptr;
    if (!strncmp(name.c_str(), "ftyp", name.length())) {
        mp4Atom = new Mp4AtomFtyp(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "free", name.length())) {
        mp4Atom = new Mp4AtomFree(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "moof", name.length())) {
        throw std::runtime_error("Fragmented mp4 file parsing not implemented at the moment");
    } else if (!strncmp(name.c_str(), "uuid", name.length())) {
        mp4Atom = new Mp4AtomUuid(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "moov", name.length())) {
        mp4Atom = new Mp4AtomMoov(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "edts", name.length())) {
        mp4Atom = new Mp4AtomEdts(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "mvhd", name.length())) {
        mp4Atom = new Mp4AtomMvhd(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "trak", name.length())) {
        mp4Atom = new Mp4AtomTrak(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "ctts", name.length())) {
        mp4Atom = new Mp4AtomCtts(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "udta", name.length())) {
        mp4Atom = new Mp4AtomUdta(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "iods", name.length())) {
        mp4Atom = new Mp4AtomIods(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "mdat", name.length())) {
        mp4Atom = new Mp4AtomMdat(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "tkhd", name.length())) {
        mp4Atom = new Mp4AtomTkhd(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "mdia", name.length())) {
        mp4Atom = new Mp4AtomMdia(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "mdhd", name.length())) {
        mp4Atom = new Mp4AtomMdhd(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "hdlr", name.length())) {
        mp4Atom = new Mp4AtomHdlr(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "minf", name.length())) {
        mp4Atom = new Mp4AtomMinf(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "smhd", name.length())) {
        mp4Atom = new Mp4AtomSmhd(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "vmhd", name.length())) {
        mp4Atom = new Mp4AtomVmhd(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "dinf", name.length())) {
        mp4Atom = new Mp4AtomDinf(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "stbl", name.length())) {
        mp4Atom = new Mp4AtomStbl(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "stsd", name.length())) {
        mp4Atom = new Mp4AtomStsd(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "stts", name.length())) {
        mp4Atom = new Mp4AtomStts(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "sdtp", name.length())) {
        mp4Atom = new Mp4AtomSdtp(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "stss", name.length())) {
        mp4Atom = new Mp4AtomStss(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "stsc", name.length())) {
        mp4Atom = new Mp4AtomStsc(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "stsz", name.length())) {
        mp4Atom = new Mp4AtomStsz(size, 0, std::move(payload));
    } else if (!strncmp(name.c_str(), "stco", name.length())) {
        mp4Atom = new Mp4AtomStco(size, 0, std::move(payload));
    } else {
        std::cout<<"Mp4 atom " + name + " parsing not implemented"<<std::endl;
        mp4Atom = new Mp4Atom(name, size, 0, false, std::move(payload));

    }

    _mp4Items[mp4Atom->GetName()] = mp4Atom;
    return mp4Atom;
}

size_t Mp4Parser::GetIframeCount() {
    Mp4AtomStss *atom = dynamic_cast<Mp4AtomStss *>(_mp4Items["stss"]);
    if(atom == nullptr) {
        std::cerr<<"stss atom not found. Cannnot calculate I frames"<<std::endl;
        return 0;
    }
    atom->Parse();
    return atom->GetEntryCount();
}

