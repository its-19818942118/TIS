cmake_minimum_required ( VERSION 3.31 )

project ( Thalia_Installer_Instructions_Set )

# Set the C++ standard to C++23
set ( CMAKE_CXX_STANDARD 23 )
set ( CMAKE_BUILD_TYPE Release )
set ( CMAKE_CXX_COMPILER "clang++" )
set ( CMAKE_CXX_STANDARD_REQUIRED ON )  # Make it required

# Enable the use of pipes for compilation
set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe" )

#set ( CMAKE_VERBOSE_MAKEFILE ON )

include_directories ( include )
include_directories ( include/api )
include_directories ( include/log )
include_directories ( include/guards )
include_directories ( include/presets )
include_directories ( include/components )

find_package ( fmt REQUIRED )
# find_package ( Curses REQUIRED )
find_package ( spdlog REQUIRED )

include_directories ( ${CURSES_INCLUDE_DIR} )

set (
    SOURCES
    src/main.cpp
    include/api/src/api.cpp
    include/src/installer.cpp
    include/src/validator.cpp
    include/log/src/logger.cpp
    include/src/argsParser.cpp
    include/src/defPackages.cpp
    include/components/src/packageTypes.cpp
)

add_executable ( Installer ${SOURCES} )

target_link_libraries (
    Installer
    PRIVATE
    fmt::fmt
    spdlog::spdlog
    # ${CURSES_LIBRARIES}
)
