cmake_minimum_required(VERSION 3.16)
project(spotify-music-dl CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(spotifymusicdl
    src/main.cpp
    src/matcher.cpp
    src/downloader.cpp
    src/tags.cpp
)

target_include_directories(spotifymusicdl PRIVATE include)

if(WIN32)
    target_link_libraries(spotifymusicdl PRIVATE userenv)
endif()
