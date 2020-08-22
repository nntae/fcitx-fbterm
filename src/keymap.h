/*
 * original from ibus-fbterm
 */

#include <fcitx-utils/key.h>

FcitxKeySym linux_keysym_to_fcitx_keysym(unsigned short keysym, unsigned short keycode);

fcitx::KeyStates calculate_modifiers(fcitx::KeyStates state, FcitxKeySym keyval, char down);