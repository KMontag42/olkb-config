#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _BASE 0
#define _MOVE 1
#define _SYMB 2
#define _MOUSE 3
#define _FUNC 4
#define ENDASH LALT(KC_MINS)
#define POUND LALT(KC_3)
#define H(X) LALT(LCTL(X))

enum planck_keycodes {
  MOVE = SAFE_RANGE,
  SYMB,
  FUNC
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Bksp |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Func | Ctrl |  Alt |  Cmd | Symb | Enter| Space| Move |  Cmd |  Alt | Ctrl | Func |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS},
  {KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {FUNC,    KC_LCTL, KC_LALT, KC_LGUI, SYMB,    KC_ENT,  KC_SPC,  MOVE,    KC_RGUI, KC_RALT, KC_RCTL, FUNC   }
},

/* MOVE
 * ,-----------------------------------------------------------------------------------.
 * | H(3) | H(F1)| H(F2)| H(F3)| H(F4)| H(F5)| H(8) | Home |  Up  |  End | H(7) |  Esc |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | H(4) | H(F6)| H(F7)| H(F8)| H(F9)|H(F10)| H(9) | Left | Down | Right| Caps |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |H(F11)|H(F12)| H(0) | H(1) | H(2) | H(A) | Pg Dn| Pg Up| H(5) | H(6) |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOVE] = {
  {H(KC_3), H(KC_F1),H(KC_F2),H(KC_F3),H(KC_F4),H(KC_F5),H(KC_8), KC_HOME, KC_UP,   KC_END,  H(KC_7), KC_ESC },
  {H(KC_4), H(KC_F6),H(KC_F7),H(KC_F8),H(KC_F9),H(KC_F10),H(KC_9),KC_LEFT, KC_DOWN, KC_RGHT, KC_CAPS, KC_DEL },
  {_______, H(KC_F11),H(KC_F12),H(KC_0),H(KC_1),H(KC_2), H(KC_A), KC_PGDN, KC_PGUP, H(KC_5), H(KC_6), _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* SYMB
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   –  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Del |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   £  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ~  |   `  |   +  |   =  |   |  |   \  |   [  |   ]  |   {  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMB] = {
  {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    ENDASH },
  {KC_DEL,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, POUND  },
  {_______, KC_TILD, KC_GRV,  KC_PLUS, KC_EQL,  KC_PIPE, KC_BSLS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* MOUSE
 * ,-----------------------------------------------------------------------------------.
 * |      |      | ACC-2| ACC-1| ACC-0|      |      | SW-L |  M-U | SW-R |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | MB-3 | MB-2 | MB-1 |      |      |  M-L |  M-D |  M-R |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | SW-D | SW-U |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = {
  {XXXXXXX, XXXXXXX, KC_ACL2, KC_ACL1, KC_ACL0, XXXXXXX, XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, KC_BTN3, KC_BTN2, KC_BTN1, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, KC_WH_U, XXXXXXX, XXXXXXX, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* FUNC
 * ,-----------------------------------------------------------------------------------.
 * | Reset|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Vol+ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F11 |  F12 |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 | Vol- |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F21 |  F22 |  F23 |  F24 |      |      | Power|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Prev | Mute | Play | Next |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNC] = {
  {RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_VOLU},
  {XXXXXXX, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_VOLD},
  {_______, KC_F21,  KC_F22,  KC_F23,  KC_F24,  XXXXXXX, XXXXXXX, KC_POWER,XXXXXXX, XXXXXXX, XXXXXXX, _______},
  {_______, _______, _______, _______, KC_MPRV, KC_MUTE, KC_MPLY, KC_MNXT, _______, _______, _______, _______}
}

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MOVE:
      if (record->event.pressed) {
        layer_on(_MOVE);
        update_tri_layer(_MOVE, _SYMB, _MOUSE);
      } else {
        layer_off(_MOVE);
        update_tri_layer(_MOVE, _SYMB, _MOUSE);
      }
      return false;
      break;
    case SYMB:
      if (record->event.pressed) {
        layer_on(_SYMB);
        update_tri_layer(_MOVE, _SYMB, _MOUSE);
      } else {
        layer_off(_SYMB);
        update_tri_layer(_MOVE, _SYMB, _MOUSE);
      }
      return false;
      break;
    case FUNC:
      if (record->event.pressed) {
        layer_on(_FUNC);
      } else {
        layer_off(_FUNC);
      }
      return false;
      break;
  }
  return true;
}
