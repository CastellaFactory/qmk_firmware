#include "version.h"
#include "debug.h"
#include "action_layer.h"

#define QWERTY 0   // qwerty layer
#define DVORAK 1   // dvorak layer
#define COLEMAK 2  // colemak layer
#define FN 3       // function layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
            /* {{{ Keymap 0: qwerty layer
             *
             * ,--------------------------------------------------.           ,--------------------------------------------------.
             * |  Esc   |   1  |   2  |   3  |   4  |   5  | LFn  |           | LFn  |   6  |   7  |   8  |   9  |   0  |   -    |
             * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
             * | Tab    |   Q  |   W  |   E  |   R  |   T  |  =   |           |  \   |   Y  |   U  |   I  |   O  |   P  |   \    |
             * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
             * | Ctrl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
             * |--------+------+------+------+------+------| Hyper|           | RGui |------+------+------+------+------+--------|
             * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
             * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
             *   |   ~  |  '"  |AltShf| Down |  Up  |                                       | Left | Right|   [  |   ]  | LDvk |
             *   `----------------------------------'                                       `----------------------------------'
             *                                        ,-------------.       ,---------------.
             *                                        | LGui | Alt  |       | Alt  |Ctrl/Esc|
             *                                 ,------|------|------|       |------+--------+------.
             *                                 |      |      | Home |       | PgUp |        |      |
             *                                 |Backsp|Delete|------|       |------| Enter  |Space |
             *                                 |ace   |      | End  |       | PgDn |        |      |
             *                                 `--------------------'       `----------------------'
             */
    // If it accepts an argument (i.e, is a function), it doesn't need KC_.
    // Otherwise, it needs KC_*
    [QWERTY] = KEYMAP(  // layer 2 : qwerty
            // left hand
            KC_ESC,         KC_1,           KC_2,               KC_3,       KC_4,       KC_5,       MO(FN),
            KC_DELT,        KC_Q,           KC_W,               KC_E,       KC_R,       KC_T,       KC_EQL,
            KC_LCTL,        KC_A,           KC_S,               KC_D,       KC_F,       KC_G,
            KC_LSFT,        KC_Z,           KC_X,               KC_C,       KC_V,       KC_B,       ALL_T(KC_NO),
            KC_GRV,         KC_QUOT,        LALT(KC_LSFT),      KC_DOWN,    KC_UP,
                                                                            KC_LGUI,    KC_LALT,
                                                                            KC_HOME,
                                                                            KC_BSPC,    KC_DELT,    KC_END,
            // right hand
            MO(FN),         KC_6,           KC_7,               KC_8,       KC_9,       KC_0,       KC_MINS,
            KC_BSLS,        KC_Y,           KC_U,               KC_I,       KC_O,       KC_P,       KC_BSLS,
                            KC_H,           KC_J,               KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
            KC_RGUI,        KC_N,           KC_M,               KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                                            KC_LEFT,            KC_RGHT,    KC_LBRC,    KC_RBRC,    TO(DVORAK),
            KC_LALT,        CTL_T(KC_ESC),
            KC_PGUP,
            KC_PGDN,        KC_ENT,         KC_SPC
            ), // }}}
    /* {{{ Keymap 1: dvorak layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  Esc   |   1  |   2  |   3  |   4  |   5  | LFn  |           | LFn  |   6  |   7  |   8  |   9  |   0  |   \    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   '  |   ,  |   .  |   P  |   Y  |  =   |           |  \   |   F  |   G  |   C  |   R  |   L  |   /    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Ctrl   |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   -    |
     * |--------+------+------+------+------+------| Hyper|           | RGui |------+------+------+------+------+--------|
     * | LShift |   :  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |   ~  |  '"  |AltShf| Down |  Up  |                                       | Left | Right|   [  |   ]  | LCmk |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,---------------.
     *                                        | LGui | Alt  |       | Alt  |Ctrl/Esc|
     *                                 ,------|------|------|       |------+--------+------.
     *                                 |      |      | Home |       | PgUp |        |      |
     *                                 |Backsp|Delete|------|       |------| Enter  |Space |
     *                                 |ace   |      | End  |       | PgDn |        |      |
     *                                 `--------------------'       `----------------------'
     */
    // If it accepts an argument (i.e, is a function), it doesn't need KC_.
    // Otherwise, it needs KC_*
    [DVORAK] = KEYMAP(  // layer 0 : dvorak
            // left hand
            KC_ESC,         KC_1,           KC_2,               KC_3,       KC_4,       KC_5,       MO(FN),
            KC_TAB,         KC_QUOT,        KC_COMM,            KC_DOT,     KC_P,       KC_Y,       KC_EQL,
            KC_LCTL,        KC_A,           KC_O,               KC_E,       KC_U,       KC_I,
            KC_LSFT,        KC_SCLN,        KC_Q,               KC_J,       KC_K,       KC_X,       ALL_T(KC_NO),
            KC_GRV,         KC_QUOT,        LALT(KC_LSFT),      KC_DOWN,    KC_UP,
                                                                                        KC_LGUI,    KC_LALT,
                                                                                                    KC_HOME,
                                                                            KC_BSPC,    KC_DELT,    KC_END,
            // right hand
            MO(FN),         KC_6,           KC_7,               KC_8,       KC_9,       KC_0,       KC_BSLS,
            KC_BSLS,        KC_F,           KC_G,               KC_C,       KC_R,       KC_L,       KC_SLSH,
                            KC_D,           KC_H,               KC_T,       KC_N,       KC_S,       KC_MINS,
            KC_RGUI,        KC_B,           KC_M,               KC_W,       KC_V,       KC_Z,       KC_RSFT,
                                            KC_LEFT,            KC_RGHT,    KC_LBRC,    KC_RBRC,    TO(COLEMAK),
            KC_LALT,        CTL_T(KC_ESC),
            KC_PGUP,
            KC_PGDN,        KC_ENT,         KC_SPC
            ), // }}}
            /* {{{ Keymap 2: colemak layer
             *
             * ,--------------------------------------------------.           ,--------------------------------------------------.
             * |  Esc   |   1  |   2  |   3  |   4  |   5  | LFn  |           | LFn  |   6  |   7  |   8  |   9  |   0  |   -    |
             * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
             * | Tab    |   Q  |   W  |   F  |   P  |   G  |  =   |           |  \   |   J  |   L  |   U  |   Y  |   ;  |   \    |
             * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
             * | Ctrl   |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |   '    |
             * |--------+------+------+------+------+------| Hyper|           | RGui |------+------+------+------+------+--------|
             * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  | RShift |
             * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
             *   |   ~  |  '"  |AltShf| Down |  Up  |                                       | Left | Right|   [  |   ]  | LQwy |
             *   `----------------------------------'                                       `----------------------------------'
             *                                        ,-------------.       ,---------------.
             *                                        | LGui | Alt  |       | Alt  |Ctrl/Esc|
             *                                 ,------|------|------|       |------+--------+------.
             *                                 |      |      | Home |       | PgUp |        |      |
             *                                 |Backsp|Delete|------|       |------| Enter  |Space |
             *                                 |ace   |      | End  |       | PgDn |        |      |
             *                                 `--------------------'       `----------------------'
             */
    // If it accepts an argument (i.e, is a function), it doesn't need KC_.
    // Otherwise, it needs KC_*
    [COLEMAK] = KEYMAP(  // layer 1 : colemak
            // left hand
            KC_ESC,         KC_1,           KC_2,               KC_3,       KC_4,       KC_5,       MO(FN),
            KC_TAB,         KC_Q,           KC_W,               KC_F,       KC_P,       KC_G,       KC_EQL,
            KC_LCTL,        KC_A,           KC_R,               KC_S,       KC_T,       KC_D,
            KC_LSFT,        KC_Z,           KC_X,               KC_C,       KC_V,       KC_B,       ALL_T(KC_NO),
            KC_GRV,         KC_QUOT,        LALT(KC_LSFT),      KC_DOWN,    KC_UP,
                                                                            KC_LGUI,    KC_LALT,
                                                                                        KC_HOME,
                                                                            KC_BSPC,    KC_DELT,    KC_END,
            // right hand
            MO(FN),         KC_6,           KC_7,               KC_8,       KC_9,       KC_0,       KC_MINS,
            KC_BSLS,        KC_J,           KC_L,               KC_U,       KC_Y,       KC_SCLN,    KC_BSLS,
                            KC_H,           KC_N,               KC_E,       KC_I,       KC_O,       KC_QUOT,
            KC_RGUI,        KC_K,           KC_M,               KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                                            KC_LEFT,            KC_RGHT,    KC_LBRC,    KC_RBRC,    TO(QWERTY),
            KC_LALT,        CTL_T(KC_ESC),
            KC_PGUP,
            KC_PGDN,        KC_ENT,         KC_SPC
            ), // }}}
    /* {{{ Keymap 3: function layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * | RESET  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |  Up  |   7  |   8  |   9  |   *  |   F12  |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------| Prev | Next |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */
    // SYMBOLS
    [FN] = KEYMAP(
            // left hand
            RESET,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
            KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
            KC_TRNS,  KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
            KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
            KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
            KC_TRNS,KC_TRNS,
            KC_TRNS,
            KC_TRNS,KC_TRNS,KC_TRNS,
            // right hand
            KC_TRNS,KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,
            KC_TRNS,KC_UP,  KC_7,   KC_8,   KC_9,   KC_ASTR,KC_F12,
            KC_DOWN,KC_4,   KC_5,   KC_6,   KC_PLUS,KC_TRNS,
            KC_TRNS,KC_AMPR,KC_1,   KC_2,   KC_3,   KC_BSLS,KC_TRNS,
            KC_TRNS,KC_DOT, KC_0,   KC_EQL, KC_TRNS,
            KC_TRNS,KC_TRNS,
            KC_TRNS,
            KC_TRNS,KC_MPRV,KC_MNXT
            ), // }}}
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case QWERTY:
            ergodox_right_led_1_on();
            break;
        case DVORAK:
            ergodox_right_led_2_on();
            break;
        case COLEMAK:
            ergodox_right_led_3_on();
            break;
        case FN:
            ergodox_led_all_on();
            break;
        default:
            // none
            break;
    }

};
