cmake_minimum_required(VERSION 3.16)
project(Mp4Parser)

set(CMAKE_CXX_STANDARD 14)

add_library(Mp4Parser atoms/Mp4Atom.h Mp4Parser.cpp Mp4Parser.h Utilities.h atoms/Mp4AtomFtyp.h atoms/Mp4AtomAv01.h atoms/Mp4AtomAv1C.h atoms/Mp4AtomAvc1.h atoms/Mp4AtomAvcC.h atoms/Mp4AtomClef.h atoms/Mp4AtomCo64.h atoms/Mp4AtomCslg.h atoms/Mp4AtomCtts.h atoms/Mp4AtomDinf.h atoms/Mp4AtomDops.h atoms/Mp4AtomDref.h atoms/Mp4AtomEdts.h atoms/Mp4AtomElst.h atoms/Mp4AtomEnof.h atoms/Mp4AtomEsds.h atoms/Mp4AtomFree.h atoms/Mp4AtomTkhd.h atoms/Mp4AtomMinf.h atoms/Mp4AtomSmhd.h atoms/Mp4AtomStbl.h atoms/Mp4AtomStsd.h atoms/Mp4AtomStts.h atoms/Mp4AtomStsc.h atoms/Mp4AtomStsz.h atoms/Mp4AtomStco.h atoms/Mp4AtomVmhd.h atoms/Mp4AtomStss.h atoms/Mp4AtomUuid.h atoms/Mp4AtomSdtp.h)