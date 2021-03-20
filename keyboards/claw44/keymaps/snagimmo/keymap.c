/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "../../lib/layers.c"
#include "../../lib/invader.c"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_number {
    _QWERTY = 0,
    _RAISE,
    _LOWER,
    _NUMPAD,
};

enum custom_keycodes {
    MY_LCAP = SAFE_RANGE,
    MY_LT2,
    GM_INV
};

#define KC_TO0 TO(_QWERTY)         // qwerty(layer0)
#define KC_TO1 TO(_RAISE)          // raise(layer1)
#define KC_TO2 TO(_LOWER)          // lower(layer2)
#define KC_TO3 TO(_NUMPAD)         // numpad(layer3)
#define KC_LT1 LT(_RAISE, KC_NO)   // raise(layer1)
#define KC_LT2 LT(_LOWER, KC_CAPS) // lower(layer2)
#define EX_FEN C(A(S(KC_INS)))     // execute launcher(fenrir)
#define EX_NYF G(KC_N)             // execute explorer(NyanFi)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT( \
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
        KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        KC_TAB , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                          MY_LT2 , KC_LALT, KC_LCTL, KC_SPC ,     KC_ENT , KC_RCTL, KC_RALT, KC_LT1
    //                 `---------+--------+--------+--------'   `--------+--------+--------+--------'
    ),

    [_RAISE] = LAYOUT( \
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
        KC_GRV , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL , KC_DEL ,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        KC_APP , XXXXXXX, KC_LCBR, KC_LPRN, KC_LBRC, XXXXXXX,     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, EX_FEN , KC_BSLS,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, KC_RCBR, KC_RPRN, KC_RBRC, XXXXXXX,     KC_HOME, KC_PGDN, KC_PGUP, KC_END , XXXXXXX, _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                          MY_LCAP, _______, _______, KC_LGUI,     XXXXXXX, _______, _______, XXXXXXX
    //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
    ),

    [_LOWER] = LAYOUT( \
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        KC_TO0 , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        _______, KC_F11 , KC_F12 , XXXXXXX, KC_INS , XXXXXXX,     EX_NYF , XXXXXXX, _______, _______, _______, _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                          MY_LCAP, _______, _______, _______,     _______, _______, _______, KC_TO3
    //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
    ),

    [_NUMPAD] = LAYOUT( \
    //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------.
        _______, RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_PSLS, KC_P7  , KC_P8  , KC_P9  , KC_EQL , _______,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        KC_TO0 , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_PAST, KC_P4  , KC_P5  , KC_P6  , XXXXXXX, KC_PSCR,
    //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_PMNS, KC_P1  , KC_P2  , KC_P3  , KC_PDOT, _______,
    //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------'
                          MY_LCAP, _______, _______, _______,     _______, _______, KC_PPLS, KC_P0
    //                  `--------+--------+--------+--------'   `--------+--------+--------+--------'
    ),
};

#ifdef OLED_DRIVER_ENABLE

static uint8_t rotation_state = 0;
static uint8_t caps_state = 0;
static uint8_t kana_state = 0;

void write_layer_block(const unsigned char* p, uint16_t read_index, uint16_t write_index) {
    unsigned char raw_byte;
    uint8_t num_row = rotation_state ? (write_index / 5) : (write_index / 21);
    for (int i = 0; i < 6; i++) {
        raw_byte = pgm_read_byte(p + (read_index * 6 + i));
        oled_write_raw_byte(raw_byte, write_index * 6 + i + (num_row * 2)); // skip 2px
    }
}

void write_layer_blocks(const unsigned char* p, uint8_t row, uint8_t col, uint16_t read_index, uint16_t write_index) {
    uint8_t num_col = rotation_state ? 5 : 21;
    for (int i = 0; i < row; i++) {
        read_index  += (i * 32);
        write_index += (i * num_col);
        for (int j = 0; j < col; j++) {
            write_layer_block(p, read_index + j, write_index + j);
        }
    }
}

void render_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            write_layer_blocks(layer_char, 2, 5, 0x01, 0);
            break;
        case _RAISE:
            write_layer_blocks(layer_char, 2, 5, 0x06, 0);
            break;
        case _LOWER:
            write_layer_blocks(layer_char, 2, 5, 0x0b, 0);
            break;
        case _NUMPAD:
            write_layer_blocks(layer_char, 2, 5, 0x10, 0);
            break;
        default:
            write_layer_blocks(layer_char, 2, 5, 0x15, 0);
    }
}

void render_caps_state(uint8_t caps_state) {
    caps_state ? write_layer_blocks(layer_char, 2, 5, 0x41, 20)  // upper
               : write_layer_blocks(layer_char, 2, 5, 0x46, 20); // lower
}

void render_kana_state(uint8_t kana_state) {
    kana_state ? write_layer_blocks(layer_char, 2, 3, 0x5d, 41)  // kana
               : write_layer_blocks(layer_char, 2, 3, 0x5a, 41); // eisu
}

void render_logo(void) {
    // TODO: Call write_layer_blocks()
    static const char PROGMEM logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};
    oled_write_P(logo, false);
}

/* char keylog_str[24]  = {}; */
/* char keylogs_str[50] = {}; */
/* int  keylogs_str_idx = 0; */

/* const char code_to_name[60] = {' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ';', '\'', ' ', ',', '.', '/', ' ', ' ', ' '}; */

/* void set_keylog(uint16_t keycode, keyrecord_t *record) { */
/*     char name = ' '; */
/*     if (keycode < 60) { */
/*         name = code_to_name[keycode]; */
/*     } */
/*  */
/*     #<{(| // update keylog |)}># */
/*     #<{(| snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c", record->event.key.row, record->event.key.col, keycode, name); |)}># */
/*  */
/*     // update keylogs */
/*     if (keylogs_str_idx == sizeof(keylogs_str) - 1) { */
/*         keylogs_str_idx = 0; */
/*         for (int i = 0; i < sizeof(keylogs_str) - 1; i++) { */
/*             keylogs_str[i] = ' '; */
/*         } */
/*     } */
/*  */
/*     keylogs_str[keylogs_str_idx] = name; */
/*     keylogs_str_idx++; */
/* } */

/* const char *read_keylog(void) { return keylog_str; } */
/* const char *read_keylogs(void) { return keylogs_str; } */

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_layer_state();
        render_kana_state(kana_state);
        /* oled_write_ln(read_keylog(), false); */
        /* oled_write_ln(read_keylogs(), false); */
    } else {
        // TODO: Change temporarily rotation_state into false (using XOR operator)
        render_logo();
        // TODO: Restore rotation_state to the 'former' state (using XOR operator)
    }
}

void press_capslock(uint8_t temp_mod){
    clear_mods();
    if (temp_mod & MOD_MASK_SHIFT) {
        tap_code16(S(KC_CAPS));
    } else if (temp_mod & MOD_MASK_CA) {
        tap_code(KC_CAPS);
        kana_state ^= 1; // Toggle IME(kana/eisu) state
    } else {
        tap_code(KC_CAPS);
        kana_state ^= 1; // Toggle IME(kana/eisu) state
    }
    set_mods(temp_mod);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t checker_numpad = 0;
    static uint8_t checker_caps = 0;
    uint8_t temp_mod;
    temp_mod = get_mods();
    switch (keycode) {
        case KC_CAPS:
            if (record->event.pressed) {
                return false; // No change is reflected until you release CapsLock
            } else {
                press_capslock(temp_mod);
            }
            break;
        case MY_LCAP:
            if (record->event.pressed) { tap_code16(S(KC_CAPS)); }
            break;

        // Customized layer-tapping settings
        case MY_LT2:
            if (record->event.pressed) {
                layer_state_set(0b0100);
                return false; // Keep staying at specified layer while holding key
            } else {
                // Check whether Numpad-jumping key is pressed
                if (checker_numpad) {
                    layer_state_set(0b1000); // Switch to the layer3 (_NUMPAD)
                    checker_numpad = 0;
                    return true;
                } else {
                    layer_state_set(0b0000); // Back to the default layer (_QWERTY)
                }

                // Check whether modifier keys(Shift/Alt/Ctrl) is pressed
                if (!checker_caps) { press_capslock(temp_mod); }
                checker_caps = 0; // Even if 1, force it to be 0
            }
            break;
        case KC_TO3:
            if (record->event.pressed) { checker_numpad = 1; }
            break;
        case KC_F1 ... KC_F12: // Function keys
        case KC_1 ... KC_0: // Num 1-0
        case KC_INS:
        case EX_NYF:
            if (record->event.pressed) { checker_caps = 1; }
            break;
        /* default: */
        /*     set_keylog(keycode, record); */
    }
    return true;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180;
    rotation_state = 1;
    return OLED_ROTATION_270;
}

bool led_update_user(led_t led_state) {
    if (caps_state != led_state.caps_lock) {
        caps_state = led_state.caps_lock;
        render_caps_state(caps_state);
    }
    return false;
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state); // _kb() is a hook for _user()
    return res;
}

#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LT1:
        case KC_LT2:
            return 10;
        default:
            return TAPPING_TERM; // 150ms
    }
}
