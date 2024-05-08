#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT_split_3x6_3(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_ESC, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RALT, KC_BSPC, MO(1), KC_SPC, KC_ENT, MO(2), KC_LGUI),
                                                              [1] = LAYOUT_split_3x6_3(KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_LCTL, KC_PSCR, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_LSFT, KC_MPLY, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RALT, KC_BSPC, KC_TRNS, KC_SPC, KC_ENT, MO(3), KC_LGUI),
                                                              [2] = LAYOUT_split_3x6_3(KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD, KC_BSPC, MO(3), KC_SPC, KC_ENT, KC_TRNS, KC_LGUI),
                                                              [3] = LAYOUT_split_3x6_3(QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LGUI, KC_TRNS, KC_SPC, KC_ENT, KC_TRNS, KC_RALT)};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};

#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

// void keyboard_pre_init_user(void) {
//     // Set our LED pin as output
//     setPinOutput(24);
//     // Turn the LED off
//     // (Due to technical reasons, high is off and low is on)
//     writePinHigh(24);
// }
//
// void keyboard_post_init_user(void) {
//     // Initialize RGB to static black
//     rgblight_enable_noeeprom();
//     rgblight_sethsv_noeeprom(HSV_BLACK);
//     rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
// }
//
// Set rgb light
void housekeeping_task_user(void) {
    rgblight_setrgb(180, 159, 250);
}