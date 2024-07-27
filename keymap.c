#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Tab   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |ESC   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCTL  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RCTL|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_TAB,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, KC_RCTL
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  (3) |      |  UP  |      |      | vol+ |                    |  +=  |  7   |  8   |  9   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | caps | left | down | right| play | vol- |-------.    ,-------|   -  |  4   |   5  |  6   |      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      | undo | del  | copy | paste| bksp |-------|    |-------|   0  |  1   |   2  |  3   | pipe |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RCTL |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6   ,                  KC_F7   , KC_F8   , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
  MO(_ADJUST), _______, KC_UP  , _______, _______, KC_VOLU ,              KC_EQL  , KC_7    , KC_8   , KC_9   , _______, _______,
  KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT,KC_MPLY, KC_VOLD ,                   KC_MINS , KC_4    , KC_5   , KC_6   , _______, _______,
  _______, KC_UNDO, KC_DEL, KC_COPY, KC_PSTE, KC_BSPC, _______,  _______, KC_0    , KC_1    , KC_2   , KC_3   , KC_PIPE, _______, 
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  up  |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | caps | left | down | right| home | end  |-------.    ,-------| left | down |  up  | right|      | grave|
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      | tilde|  *   |  #   |  -   |  _   |-------|    |-------|   _  |   -  |  #   |  *   |  \   |      |    
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RCTL
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  KC_F1   , KC_F2   , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                   KC_F7   , KC_F8   , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
  _______ , _______ , KC_UP  , _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  KC_CAPS , KC_LEFT , KC_DOWN, KC_RGHT, KC_HOME, KC_END ,                   KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, KC_GRV,
  _______ , KC_TILD , KC_ASTR, KC_NUBS, KC_PMNS, KC_UNDS, _______, _______, KC_UNDS, KC_PMNS, KC_NUBS, KC_ASTR, KC_BSLS, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
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
        oled_set_cursor(0, 1);

        oled_write("LILY\n  58\n\n\n\n\n", false);
        // write current active layer
        switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write("FIRST\n\n\n\n\n", false);
            break;
        case _LOWER:
            oled_write("CNTRL\n\n\n\n\n", false);
            break;
        case _RAISE:
            oled_write("SYMBL\n\n\n\n\n", false);
            break;
        case _ADJUST:
            oled_write("FALSE\n\n\n\n\n", false);
            break;
        }

        // read state for caps lock
        led_t led_state = host_keyboard_led_state();
        oled_write_P(led_state.caps_lock ? PSTR("CAPS\nLOCK") : PSTR("    \n    "), false);
        
    } else {
        static const char image [] PROGMEM = { 
            // 'skull', 128x32px
            0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x40, 0x00, 0x80, 0xc0, 
            0x00, 0x80, 0x80, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x80, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0xe0, 0xc0, 0x40, 0x00, 0xe0, 0xc0, 0x40, 0x00, 0x60, 0xc0, 0xe0, 0x00, 0x00, 0x40, 0x40, 0x00, 
            0xe0, 0x20, 0xe0, 0x00, 0xa0, 0xe0, 0x60, 0x00, 0x60, 0xa0, 0xa0, 0x00, 0x60, 0xa0, 0xe0, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x80, 0x10, 0x10, 0x30, 0x20, 0x20, 0x00, 0x20, 
            0x20, 0x00, 0xc0, 0xc0, 0x80, 0x88, 0x80, 0x80, 0x90, 0x80, 0xe0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x20, 
            0x00, 0x10, 0x10, 0x10, 0x10, 0x90, 0x50, 0x58, 0x58, 0x53, 0x51, 0x51, 0x51, 0xd1, 0xd1, 0xc1, 
            0x30, 0x40, 0x00, 0x31, 0x40, 0x01, 0x70, 0x30, 0x00, 0x50, 0x01, 0x00, 0x50, 0x00, 0x11, 0x61, 
            0x00, 0x00, 0x01, 0x20, 0x00, 0x31, 0x30, 0x00, 0x61, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x09, 0x79, 0x00, 0x78, 0x49, 0x79, 0x00, 0x00, 0x48, 0x79, 0x00, 0x30, 0x48, 0x48, 0x30, 0x00, 
            0x61, 0x79, 0x01, 0x00, 0x69, 0x49, 0x39, 0x00, 0x78, 0x51, 0x79, 0x00, 0x70, 0x51, 0x79, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0xfc, 0xfe, 0xfe, 0xff, 0x7f, 0x19, 0x18, 
            0x08, 0xc8, 0xc8, 0x80, 0x01, 0x9f, 0x3f, 0x1f, 0x7f, 0xe1, 0x81, 0x01, 0x9f, 0xdf, 0xde, 0x9c, 
            0x1c, 0x1c, 0x1c, 0x5c, 0x1a, 0x9b, 0x19, 0x09, 0x89, 0x99, 0x49, 0x0d, 0x05, 0x12, 0x09, 0x00, 
            0x04, 0x44, 0x04, 0x8c, 0x15, 0x05, 0x0c, 0xd4, 0x24, 0x24, 0x24, 0x24, 0xe4, 0xe4, 0xe5, 0x25, 
            0x00, 0x18, 0x00, 0x00, 0x80, 0x04, 0x14, 0x80, 0x00, 0x0c, 0x80, 0x00, 0x00, 0x8c, 0x00, 0x00, 
            0x10, 0x00, 0x00, 0x8c, 0x0c, 0x00, 0x0c, 0x08, 0x00, 0x90, 0x00, 0x00, 0x00, 0x00, 0x22, 0x62, 
            0x62, 0x62, 0x62, 0x62, 0x62, 0x62, 0x62, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0x60, 
            0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0xd2, 0xd2, 0xd2, 0xd2, 0xd2, 0xd2, 0xd2, 0xd2, 0xd2, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3f, 0xff, 0xff, 0xff, 0xfa, 0xfc, 0xfe, 0xfc, 
            0xf8, 0xe0, 0x81, 0x00, 0x00, 0x06, 0x0f, 0xfe, 0xfe, 0xef, 0x47, 0x07, 0x07, 0x07, 0x1f, 0x0f, 
            0x48, 0x48, 0x48, 0xc8, 0xc0, 0xe0, 0xe1, 0xe0, 0xa0, 0x20, 0x20, 0xe0, 0xe8, 0xc8, 0xc8, 0x08, 
            0x68, 0x38, 0x1c, 0x4c, 0x24, 0x24, 0x24, 0x24, 0x24, 0x23, 0x21, 0x20, 0x20, 0x20, 0x20, 0x08, 
            0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x03, 0x02, 0x00, 0x00, 0x02, 0x00, 0x00, 0x02, 0x00, 0x00, 
            0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x03, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 
            0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 
            0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe7, 0xff, 0x7f, 0x7f, 0x3f, 0x37, 0x3f, 
            0x3f, 0x3f, 0x1f, 0x00, 0x00, 0x10, 0x10, 0x1b, 0x0f, 0x01, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 
            0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0d, 0x15, 0x35, 0xd5, 0x95, 0x95, 0x95, 0x95, 0x95, 0x84
        };
        
        oled_write_raw_P(image, sizeof(image));
    }

    return false;
}
