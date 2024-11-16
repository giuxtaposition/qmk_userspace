#include QMK_KEYBOARD_H
#define TAPPING_TERM 200

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// layer 1 - nav
// layer 2 - mouse
// layer 3 - symbols
// layer 4 - numbers
// layer 5 - media
// layer 6 - functions

enum combos {
  ESC_SPACE_TAB,
  ENT_BSPC_DEL,
};

const uint16_t PROGMEM esc_combo[] = {LT(1, KC_ESC), LT(2, KC_SPC), COMBO_END};
const uint16_t PROGMEM del_combo[] = {LT(3, KC_ENT), LT(4, KC_BSPC), COMBO_END};

combo_t key_combos[] = {
  [ESC_SPACE_TAB] = COMBO(esc_combo, LT(5, KC_TAB)),
  [ENT_BSPC_DEL] = COMBO(del_combo, LT(6, KC_DEL)),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌────────┬────────┬────────┬────────┬────────────┐                             ┌─────────────┬────────┬────────┬────────┬───────────┐
//    │   q    │   w    │   e    │   r    │     t      │                             │      y      │   u    │   i    │   o    │     p     │
//    ├────────┼────────┼────────┼────────┼────────────┤                             ├─────────────┼────────┼────────┼────────┼───────────┤
//    │ HOME_A │ HOME_S │ HOME_D │ HOME_F │     g      │                             │      h      │ HOME_J │ HOME_K │ HOME_L │ HOME_SCLN │
//    ├────────┼────────┼────────┼────────┼────────────┤                             ├─────────────┼────────┼────────┼────────┼───────────┤
//    │   z    │   x    │   c    │   v    │     b      │                             │      n      │   m    │   ,    │   .    │     /     │
//    └────────┴────────┴────────┴────────┼────────────┼────────────┐   ┌────────────┼─────────────┼────────┴────────┴────────┴───────────┘
//                                        │ LT(1, esc) │ LT(2, spc) │   │ LT(3, ent) │ LT(4, bspc) │
//                                        └────────────┴────────────┘   └────────────┴─────────────┘
[0] = LAYOUT_split_3x5_2(
  KC_Q   , KC_W   , KC_E   , KC_R   , KC_T          ,                                     KC_Y           , KC_U   , KC_I    , KC_O   , KC_P     ,
  HOME_A , HOME_S , HOME_D , HOME_F , KC_G          ,                                     KC_H           , HOME_J , HOME_K  , HOME_L , HOME_SCLN,
  KC_Z   , KC_X   , KC_C   , KC_V   , KC_B          ,                                     KC_N           , KC_M   , KC_COMM , KC_DOT , KC_SLSH  ,
                                      LT(1, KC_ESC) , LT(2, KC_SPC) ,     LT(3, KC_ENT) , LT(4, KC_BSPC)
),

//    ┌──────┬──────┬──────┬──────┬─────┐               ┌──────┬──────┬─────────┬───────────┬─────┐
//    │      │      │      │      │     │               │      │      │         │           │     │
//    ├──────┼──────┼──────┼──────┼─────┤               ├──────┼──────┼─────────┼───────────┼─────┤
//    │ lgui │ lalt │ lsft │ lctl │     │               │ left │ down │   up    │   rght    │     │
//    ├──────┼──────┼──────┼──────┼─────┤               ├──────┼──────┼─────────┼───────────┼─────┤
//    │      │      │      │      │     │               │ ins  │ home │ pAGE_UP │ pAGE_DOWN │ end │
//    └──────┴──────┴──────┴──────┼─────┼─────┐   ┌─────┼──────┼──────┴─────────┴───────────┴─────┘
//                                │     │     │   │     │      │
//                                └─────┴─────┘   └─────┴──────┘
[1] = LAYOUT_split_3x5_2(
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                         KC_TRNS , KC_TRNS , KC_TRNS    , KC_TRNS      , KC_TRNS,
  KC_LGUI , KC_LALT , KC_LSFT , KC_LCTL , KC_TRNS ,                         KC_LEFT , KC_DOWN , KC_UP      , KC_RIGHT     , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                         KC_INS  , KC_HOME , KC_PAGE_UP , KC_PAGE_DOWN , KC_END ,
                                          KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS
),

//    ┌──────┬──────┬──────┬──────┬─────┐                ┌──────┬──────┬──────┬──────┬─────┐
//    │      │      │      │      │     │                │      │      │      │      │     │
//    ├──────┼──────┼──────┼──────┼─────┤                ├──────┼──────┼──────┼──────┼─────┤
//    │ lgui │ lalt │ lsft │ lctl │     │                │ ms_l │ ms_d │ ms_u │ ms_r │     │
//    ├──────┼──────┼──────┼──────┼─────┤                ├──────┼──────┼──────┼──────┼─────┤
//    │      │      │      │      │     │                │ wh_l │ wh_d │ wh_u │ wh_r │     │
//    └──────┴──────┴──────┴──────┼─────┼─────┐   ┌──────┼──────┼──────┴──────┴──────┴─────┘
//                                │     │     │   │ btn1 │ btn2 │
//                                └─────┴─────┘   └──────┴──────┘
[2] = LAYOUT_split_3x5_2(
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                         KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_LGUI , KC_LALT , KC_LSFT , KC_LCTL , KC_TRNS ,                         KC_MS_L , KC_MS_D , KC_MS_U , KC_MS_R , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                         KC_WH_L , KC_WH_D , KC_WH_U , KC_WH_R , KC_TRNS,
                                          KC_TRNS , KC_TRNS ,     KC_BTN1 , KC_BTN2
),

//    ┌─────┬───┬───┬───┬─────┐               ┌─────┬──────┬──────┬──────┬──────┐
//    │  `  │ ' │ < │ > │  ;  │               │     │      │      │      │      │
//    ├─────┼───┼───┼───┼─────┤               ├─────┼──────┼──────┼──────┼──────┤
//    │  {  │ } │ ( │ ) │  @  │               │     │ rctl │ rsft │ lalt │ rgui │
//    ├─────┼───┼───┼───┼─────┤               ├─────┼──────┼──────┼──────┼──────┤
//    │     │ ! │ [ │ ] │     │               │     │      │      │      │  \   │
//    └─────┴───┴───┴───┼─────┼─────┐   ┌─────┼─────┼──────┴──────┴──────┴──────┘
//                      │     │     │   │     │     │
//                      └─────┴─────┘   └─────┴─────┘
[3] = LAYOUT_split_3x5_2(
  KC_GRV  , KC_QUOT , KC_LT   , KC_GT   , KC_SCLN ,                         KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_LCBR , KC_RCBR , KC_LPRN , KC_RPRN , KC_AT   ,                         KC_TRNS , KC_RCTL , KC_RSFT , KC_LALT , KC_RGUI,
  KC_TRNS , KC_EXLM , KC_LBRC , KC_RBRC , KC_TRNS ,                         KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_BSLS,
                                          KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS
),

//    ┌──────┬───┬───┬───┬──────┐               ┌─────┬──────┬──────┬──────┬──────┐
//    │ kp_/ │ 7 │ 8 │ 9 │ kp_+ │               │     │      │      │      │      │
//    ├──────┼───┼───┼───┼──────┤               ├─────┼──────┼──────┼──────┼──────┤
//    │  0   │ 4 │ 5 │ 6 │  -   │               │     │ rctl │ rsft │ lalt │ rgui │
//    ├──────┼───┼───┼───┼──────┤               ├─────┼──────┼──────┼──────┼──────┤
//    │ kp_* │ 1 │ 2 │ 3 │  =   │               │     │      │      │      │      │
//    └──────┴───┴───┴───┼──────┼─────┐   ┌─────┼─────┼──────┴──────┴──────┴──────┘
//                       │      │     │   │     │     │
//                       └──────┴─────┘   └─────┴─────┘
[4] = LAYOUT_split_3x5_2(
  KC_PSLS , KC_7 , KC_8 , KC_9 , KC_PPLS  ,                         KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_0    , KC_4 , KC_5 , KC_6 , KC_MINUS ,                         KC_TRNS , KC_RCTL , KC_RSFT , KC_LALT , KC_RGUI,
  KC_PAST , KC_1 , KC_2 , KC_3 , KC_EQL   ,                         KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
                                 KC_TRNS  , KC_TRNS ,     KC_TRNS , KC_TRNS
),

//    ┌─────┬────┬────┬────┬─────┐               ┌─────┬──────┬──────┬──────┬──────┐
//    │     │ f7 │ f8 │ f9 │ f10 │               │     │      │      │      │      │
//    ├─────┼────┼────┼────┼─────┤               ├─────┼──────┼──────┼──────┼──────┤
//    │     │ f4 │ f5 │ f6 │ f11 │               │     │ rctl │ rsft │ lalt │ rgui │
//    ├─────┼────┼────┼────┼─────┤               ├─────┼──────┼──────┼──────┼──────┤
//    │     │ f1 │ f2 │ f3 │ f12 │               │     │      │      │      │      │
//    └─────┴────┴────┴────┼─────┼─────┐   ┌─────┼─────┼──────┴──────┴──────┴──────┘
//                         │     │     │   │     │     │
//                         └─────┴─────┘   └─────┴─────┘
[5] = LAYOUT_split_3x5_2(
  KC_TRNS , KC_F7 , KC_F8 , KC_F9 , KC_F10  ,                         KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_F4 , KC_F5 , KC_F6 , KC_F11  ,                         KC_TRNS , KC_RCTL , KC_RSFT , KC_LALT , KC_RGUI,
  KC_TRNS , KC_F1 , KC_F2 , KC_F3 , KC_F12  ,                         KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
                                    KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS
),

//    ┌──────┬──────┬──────┬──────┬─────┐               ┌─────────┬─────────┬──────────────┬────────────────┬─────────┐
//    │      │      │      │      │     │               │ RGB_TOG │ RGB_MOD │   RGB_HUI    │    RGB_SAI     │ RGB_VAI │
//    ├──────┼──────┼──────┼──────┼─────┤               ├─────────┼─────────┼──────────────┼────────────────┼─────────┤
//    │ lgui │ lalt │ lsft │ lctl │     │               │  mprv   │  mnxt   │ kB_VOLUME_UP │ kB_VOLUME_DOWN │  pscr   │
//    ├──────┼──────┼──────┼──────┼─────┤               ├─────────┼─────────┼──────────────┼────────────────┼─────────┤
//    │      │      │      │      │     │               │  mply   │ kB_MUTE │              │                │         │
//    └──────┴──────┴──────┴──────┼─────┼─────┐   ┌─────┼─────────┼─────────┴──────────────┴────────────────┴─────────┘
//                                │     │     │   │     │         │
//                                └─────┴─────┘   └─────┴─────────┘
[6] = LAYOUT_split_3x5_2(
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                         RGB_TOG , RGB_MOD    , RGB_HUI         , RGB_SAI           , RGB_VAI,
  KC_LGUI , KC_LALT , KC_LSFT , KC_LCTL , KC_TRNS ,                         KC_MPRV , KC_MNXT    , KC_KB_VOLUME_UP , KC_KB_VOLUME_DOWN , KC_PSCR,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                         KC_MPLY , KC_KB_MUTE , KC_TRNS         , KC_TRNS           , KC_TRNS,
                                          KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS
)
};

// Set rgb light
void housekeeping_task_user(void) {
    rgblight_setrgb(180, 159, 250);
}
