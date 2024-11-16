#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬───┬───┬───┬──────┬───────┐               ┌───────┬──────┬───┬───┬───┬──────┐
//    │ lalt │ q │ w │ e │  r   │   t   │               │   y   │  u   │ i │ o │ p │ ralt │
//    ├──────┼───┼───┼───┼──────┼───────┤               ├───────┼──────┼───┼───┼───┼──────┤
//    │ lctl │ a │ s │ d │  f   │   g   │               │   h   │  j   │ k │ l │ ; │  '   │
//    ├──────┼───┼───┼───┼──────┼───────┤               ├───────┼──────┼───┼───┼───┼──────┤
//    │ lsft │ z │ x │ c │  v   │   b   │               │   n   │  m   │ , │ . │ / │ rsft │
//    └──────┴───┴───┴───┼──────┼───────┼─────┐   ┌─────┼───────┼──────┼───┴───┴───┴──────┘
//                       │ bspc │ MO(1) │ spc │   │ ent │ MO(2) │ lgui │
//                       └──────┴───────┴─────┘   └─────┴───────┴──────┘
[0] = LAYOUT_split_3x6_3(
  KC_LALT , KC_Q , KC_W , KC_E , KC_R    , KC_T  ,                       KC_Y  , KC_U    , KC_I    , KC_O   , KC_P    , KC_RALT,
  KC_LCTL , KC_A , KC_S , KC_D , KC_F    , KC_G  ,                       KC_H  , KC_J    , KC_K    , KC_L   , KC_SCLN , KC_QUOT,
  KC_LSFT , KC_Z , KC_X , KC_C , KC_V    , KC_B  ,                       KC_N  , KC_M    , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT,
                                 KC_BSPC , MO(1) , KC_SPC ,     KC_ENT , MO(2) , KC_LGUI
),

//    ┌──────┬──────┬─────┬────┬──────┬──────┐               ┌───────┬──────┬────┬──────┬────┬──────┐
//    │ lalt │  1   │  2  │ 3  │  4   │  5   │               │   6   │  7   │ 8  │  9   │ 0  │ ralt │
//    ├──────┼──────┼─────┼────┼──────┼──────┤               ├───────┼──────┼────┼──────┼────┼──────┤
//    │ lctl │ pscr │ no  │ no │ mrwd │ mffd │               │ left  │ down │ up │ rght │ no │  no  │
//    ├──────┼──────┼─────┼────┼──────┼──────┤               ├───────┼──────┼────┼──────┼────┼──────┤
//    │ lsft │ tab  │ del │ no │  no  │ mply │               │  no   │  no  │ no │  no  │ no │ rsft │
//    └──────┴──────┴─────┴────┼──────┼──────┼─────┐   ┌─────┼───────┼──────┼────┴──────┴────┴──────┘
//                             │ bspc │      │ spc │   │ esc │ MO(3) │ lgui │
//                             └──────┴──────┴─────┘   └─────┴───────┴──────┘
[1] = LAYOUT_split_3x6_3(
  KC_LALT , KC_1    , KC_2   , KC_3  , KC_4    , KC_5    ,                       KC_6    , KC_7    , KC_8  , KC_9    , KC_0  , KC_RALT,
  KC_LCTL , KC_PSCR , KC_NO  , KC_NO , KC_MRWD , KC_MFFD ,                       KC_LEFT , KC_DOWN , KC_UP , KC_RGHT , KC_NO , KC_NO  ,
  KC_LSFT , KC_TAB  , KC_DEL , KC_NO , KC_NO   , KC_MPLY ,                       KC_NO   , KC_NO   , KC_NO , KC_NO   , KC_NO , KC_RSFT,
                                       KC_BSPC , KC_TRNS , KC_SPC ,     KC_ESC , MO(3)   , KC_LGUI
),

//    ┌──────┬────┬────┬────┬──────┬───────┐               ┌─────┬──────┬───┬───┬───┬─────┐
//    │ tab  │ !  │ @  │ #  │  $   │   %   │               │  ^  │  &   │ * │ ( │ ) │ del │
//    ├──────┼────┼────┼────┼──────┼───────┤               ├─────┼──────┼───┼───┼───┼─────┤
//    │ lctl │ no │ no │ no │  no  │  no   │               │  -  │  =   │ [ │ ] │ \ │  `  │
//    ├──────┼────┼────┼────┼──────┼───────┤               ├─────┼──────┼───┼───┼───┼─────┤
//    │ lsft │ no │ no │ no │  no  │  no   │               │  _  │  +   │ { │ } │ | │  ~  │
//    └──────┴────┴────┴────┼──────┼───────┼─────┐   ┌─────┼─────┼──────┼───┴───┴───┴─────┘
//                          │ bspc │ MO(3) │ spc │   │ ent │     │ rgui │
//                          └──────┴───────┴─────┘   └─────┴─────┴──────┘
[2] = LAYOUT_split_3x6_3(
  KC_TAB  , KC_EXLM , KC_AT , KC_HASH , KC_DLR  , KC_PERC ,                       KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_DEL ,
  KC_LCTL , KC_NO   , KC_NO , KC_NO   , KC_NO   , KC_NO   ,                       KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS , KC_GRV ,
  KC_LSFT , KC_NO   , KC_NO , KC_NO   , KC_NO   , KC_NO   ,                       KC_UNDS , KC_PLUS , KC_LCBR , KC_RCBR , KC_PIPE , KC_TILD,
                                        KC_BSPC , MO(3)   , KC_SPC ,     KC_ENT , KC_TRNS , KC_RGUI
),

//    ┌────┬─────┬─────┬────┬──────┬──────┐               ┌──────┬──────┬──────┬──────┬─────┬────┐
//    │ no │ f1  │ f2  │ f3 │  f4  │  f5  │               │  f6  │  f7  │  f8  │  f9  │ f10 │ no │
//    ├────┼─────┼─────┼────┼──────┼──────┤               ├──────┼──────┼──────┼──────┼─────┼────┤
//    │ no │ f11 │ f12 │ no │  no  │  no  │               │ ms_l │ ms_d │ ms_u │ ms_r │ no  │ no │
//    ├────┼─────┼─────┼────┼──────┼──────┤               ├──────┼──────┼──────┼──────┼─────┼────┤
//    │ no │ no  │ no  │ no │ btn1 │ btn2 │               │ wh_l │ wh_d │ wh_u │ wh_r │ no  │ no │
//    └────┴─────┴─────┴────┼──────┼──────┼─────┐   ┌─────┼──────┼──────┼──────┴──────┴─────┴────┘
//                          │ lgui │      │ spc │   │ ent │      │ ralt │
//                          └──────┴──────┴─────┘   └─────┴──────┴──────┘
[3] = LAYOUT_split_3x6_3(
  KC_NO , KC_F1  , KC_F2  , KC_F3 , KC_F4   , KC_F5   ,                       KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10 , KC_NO,
  KC_NO , KC_F11 , KC_F12 , KC_NO , KC_NO   , KC_NO   ,                       KC_MS_L , KC_MS_D , KC_MS_U , KC_MS_R , KC_NO  , KC_NO,
  KC_NO , KC_NO  , KC_NO  , KC_NO , KC_BTN1 , KC_BTN2 ,                       KC_WH_L , KC_WH_D , KC_WH_U , KC_WH_R , KC_NO  , KC_NO,
                                    KC_LGUI , KC_TRNS , KC_SPC ,     KC_ENT , KC_TRNS , KC_RALT
)
};


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
