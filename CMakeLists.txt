cmake_minimum_required(VERSION 3.16)

project(AnyNMEAMessage LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AnyNMEAMessage main.cpp
    AnyNMEAMessage.h
    NMEAExtractionStream.cpp NMEAExtractionStream.h NMEAInsertionStream.cpp NMEAInsertionStream.h
    ImmutableBuffer.cpp ImmutableBuffer.h MutableBuffer.cpp MutableBuffer.h
    Register32Bits.h
    NMEACommon.cpp NMEACommon.h
    traits.h


)

include(GNUInstallDirs)
install(TARGETS AnyNMEAMessage
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
