cmake_minimum_required (
    VERSION 3.31
)

project (
    Thalia_Installer_Instructions_Set
    VERSION 0.13.0
    LANGUAGES CXX
)

set ( CMAKE_LANGUAGE CXX )

# Set the C++ standard to C++23
set ( CMAKE_CXX_STANDARD 23 )
set ( CMAKE_BUILD_TYPE Debug )
set ( CMAKE_CXX_COMPILER "g++" )
set ( CMAKE_CXX_STANDARD_REQUIRED ON )  # Make it required

# Enable the use of pipes for compilation
set (
    CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS}-pipe -g -v -march=native -mtune=native"
)

set ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/ )
set ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin )
set ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/ )

#set ( CMAKE_VERBOSE_MAKEFILE ON )

include_directories (
    include
    include/api
    include/log
    include/guards
    include/presets
    include/components
)

# find_package ( fmt REQUIRED )
# find_package ( Curses REQUIRED )
find_package ( spdlog REQUIRED )

# include_directories ( ${CURSES_INCLUDE_DIR} )

set (
    SOURCES
    src/main.cpp
    src/api/api.cpp
    src/log/logger.cpp
    src/guards/installer.cpp
    src/guards/validator.cpp
    src/guards/argsParser.cpp
    src/guards/defPackages.cpp
    src/guards/packagesString.cpp
    src/components/packageTypes.cpp
    #include/guards/src/execCommand.cpp
)

add_executable ( Installer ${SOURCES} )

target_link_libraries (
    Installer
    PRIVATE
    spdlog::spdlog
    # fmt::fmt
    # ${CURSES_LIBRARIES}
)
