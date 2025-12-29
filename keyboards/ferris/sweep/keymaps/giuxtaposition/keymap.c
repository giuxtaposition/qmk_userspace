#include QMK_KEYBOARD_H

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

enum combos {
    ESC_SPACE_TAB,
    ENT_BSPC_DEL,
    GAME_MODE
};

const uint16_t PROGMEM esc_combo[] = {LAYER_ESC, LAYER_SPACE, COMBO_END};
const uint16_t PROGMEM del_combo[] = {LAYER_ENT, LAYER_BSPC, COMBO_END};
const uint16_t PROGMEM toggle_gamemode[] = {KC_Q, KC_Z, COMBO_END};

combo_t key_combos[] = {
    [ESC_SPACE_TAB] = COMBO(esc_combo, KC_TAB),
    [ENT_BSPC_DEL]  = COMBO(del_combo, KC_DEL),
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

//    ┌──────┬──────┬──────┬──────┬─────┐                   ┌─────────┬─────────┬─────────┬─────────┬─────┐
//    │      │      │      │      │     │                   │         │         │         │         │     │
//    ├──────┼──────┼──────┼──────┼─────┤                   ├─────────┼─────────┼─────────┼─────────┼─────┤
//    │ lgui │ lalt │ lsft │ lctl │     │                   │ MS_LEFT │ MS_DOWN │  MS_UP  │ MS_RGHT │     │
//    ├──────┼──────┼──────┼──────┼─────┤                   ├─────────┼─────────┼─────────┼─────────┼─────┤
//    │      │      │      │      │     │                   │ MS_WHLL │ MS_WHLD │ MS_WHLU │ MS_WHLR │     │
//    └──────┴──────┴──────┴──────┼─────┼─────┐   ┌─────────┼─────────┼─────────┴─────────┴─────────┴─────┘
//                                │     │     │   │ MS_BTN1 │ MS_BTN2 │
//                                └─────┴─────┘   └─────────┴─────────┘
[_MOUSE] = LAYOUT_split_3x5_2(
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                         KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_LGUI , KC_LALT , KC_LSFT , KC_LCTL , KC_TRNS ,                         MS_LEFT , MS_DOWN , MS_UP   , MS_RGHT , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                         MS_WHLL , MS_WHLD , MS_WHLU , MS_WHLR , KC_TRNS,
                                          KC_TRNS , KC_TRNS ,     MS_BTN1 , MS_BTN2
),

//    ┌─────┬───┬───┬───┬─────┐               ┌─────┬──────┬──────┬──────┬──────┐
//    │  `  │ ' │ < │ > │  ;  │               │     │      │      │      │      │
//    ├─────┼───┼───┼───┼─────┤               ├─────┼──────┼──────┼──────┼──────┤
//    │  {  │ } │ ( │ ) │  @  │               │     │ rctl │ rsft │ ralt │ rgui │
//    ├─────┼───┼───┼───┼─────┤               ├─────┼──────┼──────┼──────┼──────┤
//    │     │ ! │ [ │ ] │     │               │     │      │      │      │  \   │
//    └─────┴───┴───┴───┼─────┼─────┐   ┌─────┼─────┼──────┴──────┴──────┴──────┘
//                      │     │     │   │     │     │
//                      └─────┴─────┘   └─────┴─────┘
[_SYMB] = LAYOUT_split_3x5_2(
  KC_GRV  , KC_QUOT , KC_LT   , KC_GT   , KC_SCLN ,                         KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_LCBR , KC_RCBR , KC_LPRN , KC_RPRN , KC_AT   ,                         KC_TRNS , KC_RCTL , KC_RSFT , KC_RALT , KC_RGUI,
  KC_TRNS , KC_EXLM , KC_LBRC , KC_RBRC , KC_TRNS ,                         KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_BSLS,
                                          KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS
),

//    ┌──────┬───┬───┬───┬──────┐               ┌─────┬──────┬──────┬──────┬──────┐
//    │ kp_/ │ 7 │ 8 │ 9 │ kp_+ │               │     │      │      │      │      │
//    ├──────┼───┼───┼───┼──────┤               ├─────┼──────┼──────┼──────┼──────┤
//    │  0   │ 4 │ 5 │ 6 │  -   │               │     │ rctl │ rsft │ ralt │ rgui │
//    ├──────┼───┼───┼───┼──────┤               ├─────┼──────┼──────┼──────┼──────┤
//    │ kp_* │ 1 │ 2 │ 3 │  =   │               │     │      │      │      │      │
//    └──────┴───┴───┴───┼──────┼─────┐   ┌─────┼─────┼──────┴──────┴──────┴──────┘
//                       │      │     │   │     │     │
//                       └──────┴─────┘   └─────┴─────┘
[_NUMB] = LAYOUT_split_3x5_2(
  KC_PSLS , KC_7 , KC_8 , KC_9 , KC_PPLS  ,                         KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_0    , KC_4 , KC_5 , KC_6 , KC_MINUS ,                         KC_TRNS , KC_RCTL , KC_RSFT , KC_RALT , KC_RGUI,
  KC_PAST , KC_1 , KC_2 , KC_3 , KC_EQL   ,                         KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
                                 KC_TRNS  , KC_TRNS ,     KC_TRNS , KC_TRNS
),

//    ┌─────┬────┬────┬────┬─────┐               ┌─────┬──────┬──────┬──────┬──────┐
//    │     │ f7 │ f8 │ f9 │ f10 │               │     │      │      │      │      │
//    ├─────┼────┼────┼────┼─────┤               ├─────┼──────┼──────┼──────┼──────┤
//    │     │ f4 │ f5 │ f6 │ f11 │               │     │ rctl │ rsft │ ralt │ rgui │
//    ├─────┼────┼────┼────┼─────┤               ├─────┼──────┼──────┼──────┼──────┤
//    │     │ f1 │ f2 │ f3 │ f12 │               │     │      │      │      │      │
//    └─────┴────┴────┴────┼─────┼─────┐   ┌─────┼─────┼──────┴──────┴──────┴──────┘
//                         │     │     │   │     │     │
//                         └─────┴─────┘   └─────┴─────┘
[_FUNC] = LAYOUT_split_3x5_2(
  KC_TRNS , KC_F7 , KC_F8 , KC_F9 , KC_F10  ,                         KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_F4 , KC_F5 , KC_F6 , KC_F11  ,                         KC_TRNS , KC_RCTL , KC_RSFT , KC_RALT , KC_RGUI,
  KC_TRNS , KC_F1 , KC_F2 , KC_F3 , KC_F12  ,                         KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
                                    KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS
),

//    ┌──────┬──────┬──────┬──────┬─────┐               ┌──────┬─────────┬──────────────┬────────────────┬──────┐
//    │      │      │      │      │     │               │      │         │              │                │      │
//    ├──────┼──────┼──────┼──────┼─────┤               ├──────┼─────────┼──────────────┼────────────────┼──────┤
//    │ lgui │ lalt │ lsft │ lctl │     │               │ mprv │  mnxt   │ kB_VOLUME_UP │ kB_VOLUME_DOWN │ pscr │
//    ├──────┼──────┼──────┼──────┼─────┤               ├──────┼─────────┼──────────────┼────────────────┼──────┤
//    │      │      │      │      │     │               │ mply │ kB_MUTE │              │                │      │
//    └──────┴──────┴──────┴──────┼─────┼─────┐   ┌─────┼──────┼─────────┴──────────────┴────────────────┴──────┘
//                                │     │     │   │     │      │
//                                └─────┴─────┘   └─────┴──────┘
[_MEDIA] = LAYOUT_split_3x5_2(
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                         KC_TRNS , KC_TRNS    , KC_TRNS         , KC_TRNS           , KC_TRNS,
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
