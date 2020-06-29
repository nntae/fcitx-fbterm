cmake_minimum_required(VERSION 3.6)
set(FCITX5_FBTERM_VERSION 4.99.0)
project(fcitx5-fbterm VERSION ${FCITX5_FBTERM_VERSION})

find_package(PkgConfig REQUIRED)
find_package(Gettext REQUIRED)
find_package(Fcitx5Utils REQUIRED)
find_package(Fcitx5Core REQUIRED)
find_package(Fcitx5Config REQUIRED)
find_package(Fcitx5GClient REQUIRED)

include(FindPkgConfig)
include(GNUInstallDirs)
include("${FCITX_INSTALL_CMAKECONFIG_DIR}/Fcitx5Utils/Fcitx5CompilerSettings.cmake")

pkg_check_modules(Gio2 REQUIRED IMPORTED_TARGET "gio-2.0")

# uninstall target
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)

if(NOT DEFINED LIB_INSTALL_DIR)
    set(LIB_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/lib)
endif()

set(prefix      ${CMAKE_INSTALL_PREFIX})
set(exec_prefix ${CMAKE_INSTALL_PREFIX})
set(bindir ${prefix}/bin)
set(libdir ${LIB_INSTALL_DIR})
set(localedir ${CMAKE_INSTALL_PREFIX}/share/locale)
set(includedir  ${CMAKE_INSTALL_PREFIX}/include)

set(libdir ${LIB_INSTALL_DIR})

add_subdirectory(src)
add_subdirectory(scripts)
