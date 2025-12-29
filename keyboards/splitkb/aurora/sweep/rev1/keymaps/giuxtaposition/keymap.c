#include QMK_KEYBOARD_H
#define TAPPING_TERM 200

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)

// Right-hand home row mods
#define HOME_N RCTL_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I RALT_T(KC_I)
#define HOME_O RGUI_T(KC_O)

enum layers {
    _BASE,
    _NAV,
    _MOUSE,
    _SYMB,
    _NUMB,
    _MEDIA,
    _FUNC,
    _GAME
};

#define LAYER_ESC LT(_MOUSE, KC_ESC)
#define LAYER_SPACE LT(_NAV, KC_SPC)
#define LAYER_ENT LT(_SYMB, KC_ENT)
#define LAYER_BSPC LT(_NUMB, KC_BSPC)
#define LAYER_V LT(_FUNC, KC_V)
#define LAYER_K LT(_MEDIA, KC_K)

enum unicode_names {
    GRAVE_A_LOWER,
    GRAVE_A_UPPER,
    GRAVE_E_LOWER,
    GRAVE_E_UPPER,
    GRAVE_I_LOWER,
    GRAVE_I_UPPER,
    GRAVE_O_LOWER,
    GRAVE_O_UPPER,
    GRAVE_U_LOWER,
    GRAVE_U_UPPER,
    ACUTE_E_LOWER,
    ACUTE_E_UPPER,
};

const uint32_t unicode_map[] PROGMEM = {
    [GRAVE_A_LOWER]   = 0x00E0,  // à
    [GRAVE_A_UPPER]   = 0x00C0,  // À
    [GRAVE_E_LOWER]   = 0x00E8,  // è
    [GRAVE_E_UPPER]   = 0x00C8,  // È
    [GRAVE_I_LOWER]   = 0x00EC,  // ì
    [GRAVE_I_UPPER]   = 0x00CC,  // Ì
    [GRAVE_O_LOWER]   = 0x00F2,  // ò
    [GRAVE_O_UPPER]   = 0x00D2,  // Ò
    [GRAVE_U_LOWER]   = 0x00F9,  // ù
    [GRAVE_U_UPPER]   = 0x00D9,  // Ù
    [ACUTE_E_LOWER]   = 0x00E9,  // é
    [ACUTE_E_UPPER]   = 0x00C9,  // É
};

#define GRAVE_A UP(GRAVE_A_LOWER, GRAVE_A_UPPER)
#define GRAVE_E UP(GRAVE_E_LOWER, GRAVE_E_UPPER)
#define GRAVE_I UP(GRAVE_I_LOWER, GRAVE_I_UPPER)
#define GRAVE_O UP(GRAVE_O_LOWER, GRAVE_O_UPPER)
#define GRAVE_U UP(GRAVE_U_LOWER, GRAVE_U_UPPER)
#define ACUTE_E UP(ACUTE_E_LOWER, ACUTE_E_UPPER)

enum combos {
    ESC_SPACE_TAB,
    ENT_BSPC_DEL,
    A_G_GRAVE_A,
    E_G_GRAVE_E,
    I_G_GRAVE_I,
    O_G_GRAVE_O,
    U_G_GRAVE_U,
    E_A_ACUTE_E,
    GAME_MODE
};

const uint16_t PROGMEM esc_combo[] = {LAYER_ESC, LAYER_SPACE, COMBO_END};
const uint16_t PROGMEM del_combo[] = {LAYER_ENT, LAYER_BSPC, COMBO_END};
const uint16_t PROGMEM grave_a_combo[] = {HOME_A, KC_G, COMBO_END};
const uint16_t PROGMEM grave_e_combo[] = {HOME_E, KC_G, COMBO_END};
const uint16_t PROGMEM grave_i_combo[] = {HOME_I, KC_G, COMBO_END};
const uint16_t PROGMEM grave_o_combo[] = {HOME_O, KC_G, COMBO_END};
const uint16_t PROGMEM grave_u_combo[] = {KC_U, KC_G, COMBO_END};
const uint16_t PROGMEM acute_e_combo[] = {HOME_E, HOME_A, COMBO_END};
const uint16_t PROGMEM toggle_gamemode[] = {KC_Q, KC_Z, COMBO_END};

combo_t key_combos[] = {
    [ESC_SPACE_TAB] = COMBO(esc_combo, KC_TAB),
    [ENT_BSPC_DEL]  = COMBO(del_combo, KC_DEL),
    [A_G_GRAVE_A]  = COMBO(grave_a_combo, GRAVE_A),
    [E_G_GRAVE_E]  = COMBO(grave_e_combo, GRAVE_E),
    [I_G_GRAVE_I]  = COMBO(grave_i_combo, GRAVE_I),
    [O_G_GRAVE_O]  = COMBO(grave_o_combo, GRAVE_O),
    [U_G_GRAVE_U]  = COMBO(grave_u_combo, GRAVE_U),
    [E_A_ACUTE_E]  = COMBO(acute_e_combo, ACUTE_E),
    [GAME_MODE]  = COMBO(toggle_gamemode, TG(_GAME)),
};

enum tap_dance {
    TD_ESC_END,
    TD_SPACE_TAB
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_END] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_END),
    [TD_SPACE_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_TAB),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌────────┬────────┬────────┬────────┬───────────┐                             ┌────────────┬────────┬────────┬────────┬────────┐
//    │   q    │   w    │   f    │   p    │     b     │                             │     j      │   l    │   u    │   y    │   ;    │
//    ├────────┼────────┼────────┼────────┼───────────┤                             ├────────────┼────────┼────────┼────────┼────────┤
//    │ HOME_A │ HOME_R │ HOME_S │ HOME_T │     g     │                             │     m      │ HOME_N │ HOME_E │ HOME_I │ HOME_O │
//    ├────────┼────────┼────────┼────────┼───────────┤                             ├────────────┼────────┼────────┼────────┼────────┤
//    │   z    │   x    │   c    │   d    │  LAYER_V  │                             │  LAYER_K   │   h    │   ,    │   .    │   /    │
//    └────────┴────────┴────────┴────────┼───────────┼─────────────┐   ┌───────────┼────────────┼────────┴────────┴────────┴────────┘
//                                        │ LAYER_ESC │ LAYER_SPACE │   │ LAYER_ENT │ LAYER_BSPC │
//                                        └───────────┴─────────────┘   └───────────┴────────────┘
[_BASE] = LAYOUT_split_3x5_2(
  KC_Q   , KC_W   , KC_F   , KC_P   , KC_B      ,                               KC_J       , KC_L   , KC_U    , KC_Y   , KC_SCLN,
  HOME_A , HOME_R , HOME_S , HOME_T , KC_G      ,                               KC_M       , HOME_N , HOME_E  , HOME_I , HOME_O ,
  KC_Z   , KC_X   , KC_C   , KC_D   , LAYER_V   ,                               LAYER_K    , KC_H   , KC_COMM , KC_DOT , KC_SLSH,
                                      LAYER_ESC , LAYER_SPACE ,     LAYER_ENT , LAYER_BSPC
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
[_NAV] = LAYOUT_split_3x5_2(
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
[_MOUSE] = LAYOUT_split_3x5_2(
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
[_SYMB] = LAYOUT_split_3x5_2(
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
[_NUMB] = LAYOUT_split_3x5_2(
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
[_FUNC] = LAYOUT_split_3x5_2(
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
[_MEDIA] = LAYOUT_split_3x5_2(
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                         RGB_TOG , RGB_MOD    , RGB_HUI         , RGB_SAI           , RGB_VAI,
  KC_LGUI , KC_LALT , KC_LSFT , KC_LCTL , KC_TRNS ,                         KC_MPRV , KC_MNXT    , KC_KB_VOLUME_UP , KC_KB_VOLUME_DOWN , KC_PSCR,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                         KC_MPLY , KC_KB_MUTE , KC_TRNS         , KC_TRNS           , KC_TRNS,
                                          KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS
),

//    ┌───┬───┬───┬──────┬────────────────┐                            ┌─────┬───┬───┬───┬───┐
//    │ q │ w │ e │  r   │       t        │                            │  y  │ u │ i │ o │ p │
//    ├───┼───┼───┼──────┼────────────────┤                            ├─────┼───┼───┼───┼───┤
//    │ a │ s │ d │  f   │      lalt      │                            │  h  │ j │ k │ l │ ; │
//    ├───┼───┼───┼──────┼────────────────┤                            ├─────┼───┼───┼───┼───┤
//    │ z │ x │ c │ lctl │      lsft      │                            │  n  │ m │ , │ . │ / │
//    └───┴───┴───┴──────┼────────────────┼──────────────────┐   ┌─────┼─────┼───┴───┴───┴───┘
//                       │ TD(TD_ESC_END) │ TD(TD_SPACE_TAB) │   │ ent │     │
//                       └────────────────┴──────────────────┘   └─────┴─────┘
[_GAME] = LAYOUT_split_3x5_2(
  KC_Q , KC_W , KC_E , KC_R    , KC_T           ,                                 KC_Y    , KC_U , KC_I    , KC_O   , KC_P   ,
  KC_A , KC_S , KC_D , KC_F    , KC_LALT        ,                                 KC_H    , KC_J , KC_K    , KC_L   , KC_SCLN,
  KC_Z , KC_X , KC_C , KC_LCTL , KC_LSFT        ,                                 KC_N    , KC_M , KC_COMM , KC_DOT , KC_SLSH,
                                 TD(TD_ESC_END) , TD(TD_SPACE_TAB) ,     KC_ENT , KC_TRNS
)
};
