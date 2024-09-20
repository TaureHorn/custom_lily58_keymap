#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _SYSTM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Tab   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |ESC   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   (   |    |    )  |------+------+------+------+------+------|
 * |LCTL  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| LGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_TAB,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TILD,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LPRN,  KC_RPRN,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, KC_LGUI
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F21 |      |  UP  |      | vol- | vol+ |                    |  +=  |  6   |  8   |  9   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | left | down | right| play |      |-------.    ,-------|   -  |  4   |  5   |  6   |      |  "   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      | undo | del  | copy | paste| bksp |-------|    |-------|   0  |  1   |  2   |  3   | pipe |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI | LOWER |/ Enter /       \Enter \  |RAISE |BackSP|  .   |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 *                          
 * F21 = mapped to alt tab by OS
 */
[_LOWER] = LAYOUT(
  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6   ,                  KC_F7   , KC_F8   , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
  KC_F21 , _______, KC_UP  , _______, KC_VOLD , KC_VOLU,                  KC_EQL  , KC_7    , KC_8   , KC_9   , _______, _______,
  _______, KC_LEFT, KC_DOWN, KC_RGHT,KC_MPLY, _______,                    KC_MINS , KC_4    , KC_5   , KC_6   , _______, LSFT(KC_2),
  _______, KC_UNDO, KC_DEL, KC_COPY, KC_PSTE, KC_BSPC, KC_LBRC,  KC_RBRC, KC_0    , KC_1    , KC_2   , KC_3   , KC_PIPE, _______, 
                             _______, _______, _______, KC_ENT, KC_SPC,  _______, _______, KC_DOT 
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  up  |      |      |      |                    |  F15 | F16  | F17  | F18  | F19  | F20  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | left | down | right| home | end  |-------.    ,-------| left | down |  up  | right|      | grave|
 * |------+------+------+------+------+------|   {   |    |    }  |------+------+------+------+------+------|
 * |      | tilde|  *   |  #   |  -   |  _   |-------|    |-------|   _  |   -  |  #   |  *   |  \   |      |    
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RCTL
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  KC_F1   , KC_F2   , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                   KC_F7   , KC_F8   , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
  _______ , _______ , KC_UP  , _______, _______, _______,                   KC_F15  , KC_F16  , KC_F17 , KC_F18 , KC_F19 , KC_F20 ,
  _______ , KC_LEFT , KC_DOWN, KC_RGHT, KC_HOME, KC_END ,                   KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, KC_GRV,
  _______ , KC_TILD , KC_ASTR, KC_NUBS, KC_PMNS, KC_UNDS, KC_LCBR, KC_RCBR, KC_UNDS, KC_PMNS, KC_NUBS, KC_ASTR, KC_BSLS, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    | BOOT |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      | BR - | BR + |                    | OLBR+| OLBR-|      |      |      | PAUS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | caps |      |      |      |      |      |-------.    ,-------|      |      | F23  |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      | F13  |      |-------|    |-------|      | F14  |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RCTL|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 *
 * PAUS = mapped to system lock by OS
 * F13 = discord deafen
 * F14 = discord mute
 * F23 = konsole > new tab
 * OLBR+/- = increase/decrease brightness of oled screen 
 *
 */
  [_SYSTM] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU,                   RGB_VAI, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAUS,
  KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                   XXXXXXX, XXXXXXX, KC_F23 , XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F13 , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F14 , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _SYSTM);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE


#endif // OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master())
        return OLED_ROTATION_270;  // flips the display 90degrees if offhand
    return rotation;
}



bool oled_task_user(void) {

    if (is_keyboard_master()) {
        // set cursor position
        oled_set_cursor(0, 2);

        // write current active layer
        switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write("\n", false);
            break;
        case _LOWER:
            oled_write("CNTRL", false);
            break;
        case _RAISE:
            oled_write("SYMBL", false);
            break;
        case _SYSTM:
            oled_write("SYSTM", false);
            break;
        }

        // read state for caps lock
        led_t led_state = host_keyboard_led_state();
        if (led_state.caps_lock) {
            oled_invert(true);
        } else {
            oled_invert(false); 
        }
        
    }

    return false;
}
