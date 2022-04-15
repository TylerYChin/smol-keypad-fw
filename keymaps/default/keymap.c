#include "kb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_P7, KC_P8, KC_P9, KC_SLSH, 
		KC_P4, KC_P5, KC_P6, KC_PAST, 
		KC_P1, KC_P2, KC_P3, KC_MINS, 
		TO(1), KC_P0, KC_PDOT, KC_ENT, KC_PPLS),

	KEYMAP(
		KC_P7, KC_P8, KC_P9, KC_ENT, 
		KC_P4, KC_P5, KC_P6, KC_PAST, 
		KC_P1, KC_P2, KC_P3, KC_PMNS, 
		TO(2), KC_P0, KC_LPRN, KC_RPRN, KC_PPLS),

	KEYMAP(
		KC_DOT, KC_COMM, KC_LPRN, KC_RPRN, 
		KC_COLN, KC_SCLN, KC_LCBR, KC_RCBR, 
		KC_QUOT, KC_DQUO, KC_LBRC, KC_RBRC, 
		TO(3), KC_EQL, KC_EXLM, KC_LABK, KC_RABK),

	KEYMAP(
		KC_F1, KC_F2, KC_F3, KC_F4, 
		KC_F5, KC_F6, KC_F7, KC_F8, 
		KC_F9, KC_F10, KC_F11, KC_F12, 
		TO(4), KC_F13, KC_F14, KC_F15, KC_F16),

	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		TO(0), KC_TRNS, KC_TRNS, RESET, M(0))
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	keyevent_t event = record->event;

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

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}