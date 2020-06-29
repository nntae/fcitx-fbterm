
set(fcitx5_fbterm_SOURCES
    imapi.c
        fcitx-fbterm.cpp
    keycode.c
        keymap.cpp
    fcitx-fbterm.cpp)

add_executable(fcitx5-fbterm ${fcitx5_fbterm_SOURCES})
target_link_libraries(fcitx5-fbterm Fcitx5::GClient Fcitx5::Core Fcitx5::Config Fcitx5::Utils PkgConfig::Gio2)

install(TARGETS fcitx5-fbterm DESTINATION ${CMAKE_INSTALL_BINDIR})
