cmake_minimum_required(VERSION 3.16)

project(TemporalFissures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TemporalFissures main.cpp
    my_thread.h my_thread.cpp
    calcs.h
    README.md
    measure.h
)

include(GNUInstallDirs)
install(TARGETS TemporalFissures
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
