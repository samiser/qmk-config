#include QMK_KEYBOARD_H

// Compose-key macros: require the OS compose key to be set to Menu,
// e.g. XKB option `compose:menu`
enum custom_keycodes {
    KB_PND = SAFE_RANGE,
    KB_EUR,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KB_PND:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_APP) "l-");
            }
            return false;
        case KB_EUR:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_APP) "=e");
            }
            return false;
    }
    return true;
}

// Layers match the ZMK config: 0 colemak, 1 left, 2 right, 3 function,
// 4 numpad, 5 adjust (media/RGB here; BT/backlight on the wireless board)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_2(
        KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,      KC_J,    KC_L,         KC_U,         KC_Y,         KC_NO,
        LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,      KC_M,    RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O),
        KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,      KC_K,    KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,
                                    MO(1),        KC_SPC,                           KC_ENT,       MO(2)
    ),
    [1] = LAYOUT_split_3x5_2(
        KC_ESC, KC_UNDS, KC_LCBR, KC_RCBR, KC_GRV,     KC_PLUS, KC_7, KC_8, KC_9, KC_NO,
        KC_TAB, KC_LT,   KC_LPRN, KC_RPRN, KC_GT,      KC_MINS, KC_4, KC_5, KC_6, KC_EQL,
        MO(3),  KC_PIPE, KC_LBRC, KC_RBRC, KC_TILD,    KC_0,    KC_1, KC_2, KC_3, KC_BSLS,
                         MO(1),   KC_NO,                        KC_NO, MO(5)
    ),
    [2] = LAYOUT_split_3x5_2(
        KC_NO,   KC_AT,   KC_QUES,       KC_EXLM, KB_EUR,           KC_PGUP, KC_CIRC, KC_QUOT, KC_DQUO, KC_HOME,
        KC_BSPC, KC_PERC, KC_HASH,       KC_DLR,  KB_PND,           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_COLN,
        KC_DEL,  CW_TOGG, C(S(KC_C)),    KC_NO,   C(S(KC_V)),       KC_PGDN, KC_AMPR, KC_ASTR, KC_SCLN, KC_END,
                          MO(5),         KC_NO,                              KC_NO,   MO(2)
    ),
    [3] = LAYOUT_split_3x5_2(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_F12, KC_F7, KC_F8, KC_F9, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_F11, KC_F4, KC_F5, KC_F6, KC_NO,
        KC_NO, KC_NO, MO(4), KC_NO, KC_NO,    KC_F10, KC_F1, KC_F2, KC_F3, KC_NO,
                      KC_NO, KC_NO,                   KC_NO, KC_NO
    ),
    [4] = LAYOUT_split_3x5_2(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_PPLS, KC_P7, KC_P8, KC_P9, KC_NUM,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_PMNS, KC_P4, KC_P5, KC_P6, KC_PEQL,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_P0,   KC_P1, KC_P2, KC_P3, KC_PDOT,
                      KC_NO, KC_NO,                    KC_NO, KC_NO
    ),
    [5] = LAYOUT_split_3x5_2(
        KC_NO,   KC_NO, KC_MPLY, KC_VOLD, KC_VOLU,    KC_NO, RM_VALU, RM_SPDD, RM_SPDU, KC_NO,
        KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,      KC_NO, RM_VALD, RM_PREV, RM_NEXT, KC_NO,
        QK_BOOT, KC_NO, KC_NO,   KC_NO,   KC_NO,      KC_NO, RM_TOGG, RM_HUED, RM_HUEU, KC_NO,
                        KC_NO,   KC_NO,                      KC_NO,   KC_NO
    ),
};
