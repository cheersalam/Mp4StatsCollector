# Mp4StatsCollector
WIP: MP4 file parsing and stats collection
1. Get I frame count

# Usage
```
Mp4StatsCollector <filename> <options>
Options:
  -i: Count I frames
```

# Compilation
Compilation is fairly simple. `cmake` is used for building code. Code is platform independent. So it should work on any platforms.

## Building on LINUX or APPLE
```
mkdir out
cd out
cmake ..
make 
```

## Building on WIN
```
mkdir out
cd out
cmake ..
```
cmake generator will generate Visual Studio solution file if VS is default generator. Open `Mp4StatsCollector.sln` and build. 
Executable will be in [Debug/Release] folder

# Notes
* This is a very basic code. It is not a final design. 
* Parsing fragmented MP4 is not implemented.
* There are lot of atoms in MP4/fMP4/DASH format. Not all atoms are parsed.
