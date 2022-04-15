#include "smol_keypad.h"

enum layer_names {
	_BASE,
	_MOD,
	_PRGM,
	_FCT,
	_TEST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT(
		KC_P7, KC_P8, KC_P9, KC_SLSH, 
		KC_P4, KC_P5, KC_P6, KC_PAST, 
		KC_P1, KC_P2, KC_P3, KC_MINS, 
		TO(1), KC_P0, KC_PDOT, KC_ENT, KC_PPLS),

	LAYOUT(
		KC_P7, KC_P8, KC_P9, KC_ENT, 
		KC_P4, KC_P5, KC_P6, KC_PAST, 
		KC_P1, KC_P2, KC_P3, KC_PMNS, 
		TO(2), KC_P0, KC_LPRN, KC_RPRN, KC_PPLS),

	LAYOUT(
		KC_DOT, KC_COMM, KC_LPRN, KC_RPRN, 
		KC_COLN, KC_SCLN, KC_LCBR, KC_RCBR, 
		KC_QUOT, KC_DQUO, KC_LBRC, KC_RBRC, 
		TO(3), KC_EQL, KC_EXLM, KC_LABK, KC_RABK),

	LAYOUT(
		KC_F1, KC_F2, KC_F3, KC_F4, 
		KC_F5, KC_F6, KC_F7, KC_F8, 
		KC_F9, KC_F10, KC_F11, KC_F12, 
		TO(4), KC_F13, KC_F14, KC_F15, KC_F16),

	LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		TO(0), KC_TRNS, KC_TRNS, RESET, M(0))
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	//keyevent_t event = record->event;

	switch (id) {
		case 0:
			if (record->event.pressed) {
				return MACRO( T(M), T(O), T(D), END );
			}
			break;
		case 5:
			if (record->event.pressed) {
				return MACRO( T(M), T(O), T(D), END );
			}
			break;
	}
	return MACRO_NONE;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
  /* With an if statement we can check which encoder was turned. */
  if (index == 0) { /* First encoder */
    /* And with another if statement we can check the direction. */
	if (clockwise) {
	  tap_code(KC_VOLU);
	} else {
	  tap_code(KC_VOLD);
	}
  }
  return false;
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
	oled_write_P(PSTR("Layer: "), false);
	
	switch (get_higher_layer(layer_state)) {
		case _BASE:
			oled_write_P(PSTR("Default\n"), false);
			break;
		case _MOD:
			oled_write_P(PSTR("Modulo\n"), false);
			break;
		case _PRGM:
			oled_write_P(PSTR("Program\n"), false);
			break;
		case _FCT:
			oled_write_P(PSTR("Function\n"), false);
			break;
		case _TEST:
			oled_write_P(PSTR("Test\n"), false);
			break;
		default:
			oled_write_P(PSTR("What\n"), false);
	}
	return false;
}
#endif