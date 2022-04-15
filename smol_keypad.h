#ifndef KB_H
#define KB_H

#include "quantum.h"

#define LAYOUT( \
	     K01, K02, K03, K04, \
	     K11, K12, K13, K14, \
	     K21, K22, K23, K24, \
	K30, K31, K32, K33, K34  \
) { \
	{ KC_NO, K01,   K02,   K03,   K04 }, \
	{ KC_NO, K11,   K12,   K13,   K14 }, \
	{ KC_NO, K21,   K22,   K23,   K24 }, \
	{ K30,   K31,   K32,   K33,   K34 }  \
}

#endif