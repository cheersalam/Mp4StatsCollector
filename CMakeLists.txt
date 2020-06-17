cmake_minimum_required(VERSION 3.16)
project(Mp4StatsCollector)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Mp4Parser)

include_directories(Mp4Parser)
add_executable(Mp4StatsCollector main.cpp )
target_link_libraries(Mp4StatsCollector Mp4Parser )