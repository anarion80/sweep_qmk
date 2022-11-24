
#include QMK_KEYBOARD_H
#include "quantum.h"

enum tap_dance_codes {
  DANCE_E,  // Polska litera ę
  DANCE_O,  // Polska litera ó
  DANCE_A,  // Polska litera ą
  DANCE_S,  // Polska litera ś
  DANCE_L,  // Polska litera ł
  DANCE_Z,  // Polska litera ż
  DANCE_X,  // Polska litera ź
  DANCE_C,  // Polska litera ć
  DANCE_N,  // Polska litera ń
  DANCE_1,  // KC_DOT(.)    KC_EXLM(!)     KC_DOT/KC_DOT   KC_DOT
  DANCE_3,  // KC_SLASH(/)  (S(KC_MINS))(_)    KC_SLASH/KC_SLASH   KC_SLASH
  DANCE_15, // KC_SPACE     KC_UNDS(_)   KC_SPACE/KC_SPACE    KC_SPACE
  DANCE_31, // Win+Shift+S for screen shots
  DANCE_32, // KC_QUOTE(')     (LGUI(KC_QUOTE))    KC_GRAVE(`)    KC_GRAVE(`)
  DANCE_33, // (LALT(KC_3))     (LALT(LSFT(KC_2)))  (LALT(KC_3))/(LALT(KC_3))   (LALT(KC_3))
  DANCE_54, // KC_ESCAPE    (LALT(LGUI(KC_ESCAPE)))     KC_ESCAPE/KC_ESCAPE     KC_ESCAPE <- not used
  DANCE_55, // KC_Q     KC_H <- not used
  DANCE_56, // KC_TAB   (LGUI(KC_TAB))
  DANCE_57, // KC_DELETE    (LCTL(KC_K))
  DANCE_58, // KC_GRAVE     (LGUI(KC_GRAVE)) <- not used
  DANCE_59, // KC_SPACE     (LGUI(KC_O))
  DANCE_60, // KC_LEFT      (LALT(KC_LEFT))
  DANCE_63, // KC_RIGHT     (LGUI(KC_RIGHT))
  BKSL_HME, // KC_BSLS      KC_HOME
  PIPE_END, // KC_PIPE      KC_END
  CTRL_HOME, // KC_LBRC      CTRL+HOME
  CTRL_END, // KC_RBRC      CTRL+HOME
  MID_CLICK, // KC_MS_BTN1         KC_MS_BTN3
  SCREEN_CLIP, // KC_QUOTE          Win+Shift+S for screen shots
  RESET_MCU, // KC_NUM          RESET
  PRNT_SCRN, // KC_SCRL     KC_PSCR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
  // Base Layer - Letter Keys
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
      KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,    						                KC_Y,   KC_U,   KC_I,   KC_O,  KC_P,
  //------------------------------------------------------------------------------       ----------------------------------------------------------------------------
      KC_A,    KC_S,    MT(MOD_LALT,KC_D),    MT(MOD_LGUI,KC_F),    KC_G,  	        KC_H,   MT(MOD_RGUI,KC_J),   MT(MOD_RALT,KC_K),  KC_L,  KC_SEMICOLON,
  //------------------------------------------------------------------------------       ----------------------------------------------------------------------------
      KC_Z,   KC_X,  KC_C,   KC_V,  KC_B,     							        KC_N,   KC_M,   KC_COMMA,   KC_DOT,   KC_SLASH,
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
		    					MT(MOD_MEH,KC_SPACE),   OSM(MOD_LSFT),                              OSM(MOD_RCTL), TO(1)
  //---------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
  ),

  [1] = LAYOUT(
  // Navigation Layer
  //--------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
    KC_ESCAPE,  KC_MS_WH_LEFT,  KC_MS_UP,   KC_MS_WH_RIGHT,  KC_PGUP,                       LCTL(LSFT(KC_TAB)), LALT(KC_LEFT),  KC_UP,   LALT(KC_RIGHT),  KC_BSPC,
  //--------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
    TD(DANCE_56),   KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,    MT(MOD_LGUI,KC_DEL),            RCTL(KC_TAB),   KC_LEFT,   KC_DOWN, KC_RIGHT,   KC_ENTER,
  //--------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
    OSM(MOD_LCTL),   KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_MS_BTN2, KC_PGDN,                   TD(MID_CLICK),     TD(CTRL_HOME),   KC_INS,   TD(CTRL_END),   TO(3),
  //--------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
                                TO(0),  OSM(MOD_LSFT),                                      KC_LALT,    TO(2)
  ),

  [2] = LAYOUT(
  // Symbols Layer
  //------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
    KC_ESCAPE,  KC_GRAVE,   TD(SCREEN_CLIP),   KC_DQUO,     LSFT(KC_EQL),                       KC_MINS,    KC_7,   KC_8,   KC_9,   KC_BSPC,
  //------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
    KC_TAB,     TD(BKSL_HME),   LSFT(KC_LBRC),  LSFT(KC_RBRC),  TD(PIPE_END),                   KC_EQL, KC_4,   KC_5,   KC_6,   KC_ENTER,
  //------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
    KC_TILD,    KC_LBRC,    KC_LPRN,    KC_RPRN,   KC_RBRC,                                     KC_0,   KC_1,   KC_2,   KC_3,   KC_DELETE,
  //------------------------------------------------------------------------------------       ----------------------------------------------------------------------------------
		    					TO(0),  OSM(MOD_LSFT),                                          KC_LALT,    OSM(MOD_RCTL)
  ),

  [3] = LAYOUT(
  // Audio/Function Keys layer
  //--------------------------------------------------------------------------------------------------      -----------------------------------------------------
    KC_ESCAPE,  KC_MEDIA_PLAY_PAUSE,    KC_MEDIA_PREV_TRACK,    KC_MEDIA_NEXT_TRACK,    TD(PRNT_SCRN),      KC_F9,  KC_F10,  KC_F11,    KC_F12,  KC_BSPC,
  //--------------------------------------------------------------------------------------------------      -----------------------------------------------------
    KC_TAB,     KC_MUTE,    KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,    KC_PAUS,                                KC_F5,  KC_F6,   KC_F7,     KC_F8,   KC_ENTER,
  //---------------------------------------------------------------------------------------------------     -----------------------------------------------------
    KC_CAPS,    KC_KP_ASTERISK, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP,   /*TD(RESET_MCU)*/ QK_BOOT,                      KC_F1,  KC_F2,   KC_F3,     KC_F4,   KC_DELETE,
  //---------------------------------------------------------------------------------------------------     -----------------------------------------------------
	                            TO(0),  OSM(MOD_LSFT),                                                      KC_LALT,    OSM(MOD_RCTL)
  )
};





extern bool g_suspend_state;
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
uint16_t last_keycode = KC_NO;
uint8_t last_modifier = 0;

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state = {
    .is_press_action = true,
    .step = 0
};

void on_dance_e(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_e_dance_step(qk_tap_dance_state_t *state);
void dance_e_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_e_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_e(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_E);
		tap_code16(KC_E);
		tap_code16(KC_E);
	}
	if(state->count > 3) {
		tap_code16(KC_E);
	}
}

uint8_t dance_e_dance_step(qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	return MORE_TAPS;
}
void dance_e_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state.step = dance_e_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_E); break;
		case SINGLE_HOLD: register_code16(LSFT(KC_E)); break;
		case DOUBLE_TAP: register_code16(RALT(KC_E)); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_E); register_code16(KC_E);
	}
}

void dance_e_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_E); break;
		case SINGLE_HOLD: unregister_code16(LSFT(KC_E)); break;
		case DOUBLE_TAP: unregister_code16(RALT(KC_E)); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_E); break;
	}
	dance_state.step = 0;
}

void on_dance_o(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_o_dance_step(qk_tap_dance_state_t *state);
void dance_o_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_o_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_o(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_O);
		tap_code16(KC_O);
		tap_code16(KC_O);
	}
	if(state->count > 3) {
		tap_code16(KC_O);
	}
}

uint8_t dance_o_dance_step(qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	return MORE_TAPS;
}
void dance_o_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state.step = dance_o_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_O); break;
		case SINGLE_HOLD: register_code16(LSFT(KC_O)); break;
		case DOUBLE_TAP: register_code16(RALT(KC_O)); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_O); register_code16(KC_O);
	}
}

void dance_o_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_O); break;
		case SINGLE_HOLD: unregister_code16(LSFT(KC_O)); break;
		case DOUBLE_TAP: unregister_code16(RALT(KC_O)); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_O); break;
	}
	dance_state.step = 0;
}

void on_dance_a(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_a_dance_step(qk_tap_dance_state_t *state);
void dance_a_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_a_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_a(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_A);
		tap_code16(KC_A);
		tap_code16(KC_A);
	}
	if(state->count > 3) {
		tap_code16(KC_A);
	}
}

uint8_t dance_a_dance_step(qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	return MORE_TAPS;
}
void dance_a_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state.step = dance_a_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_A); break;
		case SINGLE_HOLD: register_code16(LSFT(KC_A)); break;
		case DOUBLE_TAP: register_code16(RALT(KC_A)); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_A); register_code16(KC_A);
	}
}

void dance_a_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_A); break;
		case SINGLE_HOLD: unregister_code16(LSFT(KC_A)); break;
		case DOUBLE_TAP: unregister_code16(RALT(KC_A)); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_A); break;
	}
	dance_state.step = 0;
}

void on_dance_s(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_s_dance_step(qk_tap_dance_state_t *state);
void dance_s_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_s_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_s(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_S);
		tap_code16(KC_S);
		tap_code16(KC_S);
	}
	if(state->count > 3) {
		tap_code16(KC_S);
	}
}

uint8_t dance_s_dance_step(qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	return MORE_TAPS;
}
void dance_s_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state.step = dance_s_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_S); break;
		case SINGLE_HOLD: register_code16(LSFT(KC_S)); break;
		case DOUBLE_TAP: register_code16(RALT(KC_S)); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_S); register_code16(KC_S);
	}
}

void dance_s_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_S); break;
		case SINGLE_HOLD: unregister_code16(LSFT(KC_S)); break;
		case DOUBLE_TAP: unregister_code16(RALT(KC_S)); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_S); break;
	}
	dance_state.step = 0;
}

void on_dance_l(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_l_dance_step(qk_tap_dance_state_t *state);
void dance_l_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_l_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_l(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_L);
		tap_code16(KC_L);
		tap_code16(KC_L);
	}
	if(state->count > 3) {
		tap_code16(KC_L);
	}
}

uint8_t dance_l_dance_step(qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	return MORE_TAPS;
}
void dance_l_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state.step = dance_l_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_L); break;
		case SINGLE_HOLD: register_code16(LSFT(KC_L)); break;
		case DOUBLE_TAP: register_code16(RALT(KC_L)); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_L); register_code16(KC_L);
	}
}

void dance_l_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_L); break;
		case SINGLE_HOLD: unregister_code16(LSFT(KC_L)); break;
		case DOUBLE_TAP: unregister_code16(RALT(KC_L)); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_L); break;
	}
	dance_state.step = 0;
}

void on_dance_z(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_z_dance_step(qk_tap_dance_state_t *state);
void dance_z_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_z_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_z(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_Z);
		tap_code16(KC_Z);
		tap_code16(KC_Z);
	}
	if(state->count > 3) {
		tap_code16(KC_Z);
	}
}

uint8_t dance_z_dance_step(qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	return MORE_TAPS;
}
void dance_z_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state.step = dance_z_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_Z); break;
		case SINGLE_HOLD: register_code16(LSFT(KC_Z)); break;
		case DOUBLE_TAP: register_code16(RALT(KC_Z)); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_Z); register_code16(KC_Z);
	}
}

void dance_z_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_Z); break;
		case SINGLE_HOLD: unregister_code16(LSFT(KC_Z)); break;
		case DOUBLE_TAP: unregister_code16(RALT(KC_Z)); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_Z); break;
	}
	dance_state.step = 0;
}

void on_dance_x(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_x_dance_step(qk_tap_dance_state_t *state);
void dance_x_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_x_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_x(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_X);
		tap_code16(KC_X);
		tap_code16(KC_X);
	}
	if(state->count > 3) {
		tap_code16(KC_X);
	}
}

uint8_t dance_x_dance_step(qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	return MORE_TAPS;
}
void dance_x_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state.step = dance_x_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_X); break;
		case SINGLE_HOLD: register_code16(LSFT(KC_X)); break;
		case DOUBLE_TAP: register_code16(RALT(KC_X)); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_X); register_code16(KC_X);
	}
}

void dance_x_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_X); break;
		case SINGLE_HOLD: unregister_code16(LSFT(KC_X)); break;
		case DOUBLE_TAP: unregister_code16(RALT(KC_X)); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_X); break;
	}
	dance_state.step = 0;
}

void on_dance_c(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_c_dance_step(qk_tap_dance_state_t *state);
void dance_c_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_c_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_c(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_C);
		tap_code16(KC_C);
		tap_code16(KC_C);
	}
	if(state->count > 3) {
		tap_code16(KC_C);
	}
}

uint8_t dance_c_dance_step(qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	return MORE_TAPS;
}
void dance_c_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state.step = dance_c_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_C); break;
		case SINGLE_HOLD: register_code16(LSFT(KC_C)); break;
		case DOUBLE_TAP: register_code16(RALT(KC_C)); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_C); register_code16(KC_C);
	}
}

void dance_c_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_C); break;
		case SINGLE_HOLD: unregister_code16(LSFT(KC_C)); break;
		case DOUBLE_TAP: unregister_code16(RALT(KC_C)); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_C); break;
	}
	dance_state.step = 0;
}

void on_dance_n(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_n_dance_step(qk_tap_dance_state_t *state);
void dance_n_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_n_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_n(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_N);
		tap_code16(KC_N);
		tap_code16(KC_N);
	}
	if(state->count > 3) {
		tap_code16(KC_N);
	}
}

uint8_t dance_n_dance_step(qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	return MORE_TAPS;
}
void dance_n_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state.step = dance_n_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_N); break;
		case SINGLE_HOLD: register_code16(LSFT(KC_N)); break;
		case DOUBLE_TAP: register_code16(RALT(KC_N)); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_N); register_code16(KC_N);
	}
}

void dance_n_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_N); break;
		case SINGLE_HOLD: unregister_code16(LSFT(KC_N)); break;
		case DOUBLE_TAP: unregister_code16(RALT(KC_N)); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_N); break;
	}
	dance_state.step = 0;
}

void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_1_dance_step(qk_tap_dance_state_t *state);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_DOT);
		tap_code16(KC_DOT);
		tap_code16(KC_DOT);
	}
	if(state->count > 3) {
		tap_code16(KC_DOT);
	}
}

uint8_t dance_1_dance_step(qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	return MORE_TAPS;
}
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state.step = dance_1_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_DOT); break;
		case SINGLE_HOLD: register_code16(KC_EXLM); break;
		case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
	}
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_DOT); break;
		case SINGLE_HOLD: unregister_code16(KC_EXLM); break;
		case DOUBLE_TAP: unregister_code16(KC_DOT); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
	}
	dance_state.step = 0;
}

void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_3_dance_step(qk_tap_dance_state_t *state);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_SLASH);
		tap_code16(KC_SLASH);
		tap_code16(KC_SLASH);
	}
	if(state->count > 3) {
		tap_code16(KC_SLASH);
	}
}

uint8_t dance_3_dance_step(qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	return MORE_TAPS;
}
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state.step = dance_3_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_SLASH); break;
		case SINGLE_HOLD: register_code16(S(KC_MINS)); break;
		case DOUBLE_TAP: register_code16(KC_SLASH); register_code16(KC_SLASH); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_SLASH); register_code16(KC_SLASH);
	}
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_SLASH); break;
		case SINGLE_HOLD: unregister_code16(S(KC_MINS)); break;
		case DOUBLE_TAP: unregister_code16(KC_SLASH); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_SLASH); break;
	}
	dance_state.step = 0;
}

void on_dance_15(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_15_dance_step(qk_tap_dance_state_t *state);
void dance_15_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_15_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_15(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
    }
    if(state->count > 3) {
        tap_code16(KC_SPACE);
    }
}

uint8_t dance_15_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_15_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_15_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_SPACE); break;
        case SINGLE_HOLD: register_code16(KC_UNDS); break;
        case DOUBLE_TAP: register_code16(KC_SPACE); register_code16(KC_SPACE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SPACE); register_code16(KC_SPACE);
    }
}

void dance_15_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_SPACE); break;
        case SINGLE_HOLD: unregister_code16(KC_UNDS); break;
        case DOUBLE_TAP: unregister_code16(KC_SPACE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SPACE); break;
    }
    dance_state.step = 0;
}
void on_dance_31(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_31_dance_step(qk_tap_dance_state_t *state);
void dance_31_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_31_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_31(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_2));
        tap_code16(LSFT(KC_2));
        tap_code16(LSFT(KC_2));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_2));
    }
}

uint8_t dance_31_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_31_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_31_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(LSFT(KC_2)); break;
        case SINGLE_HOLD: register_code16(LGUI(LSFT(KC_S))); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_2)); register_code16(LSFT(KC_2)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_2)); register_code16(LSFT(KC_2));
    }
}

void dance_31_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_2)); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(KC_S))); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_2)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_2)); break;
    }
    dance_state.step = 0;
}
void on_dance_32(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_32_dance_step(qk_tap_dance_state_t *state);
void dance_32_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_32_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_32(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
        tap_code16(KC_QUOTE);
    }
    if(state->count > 3) {
        tap_code16(KC_QUOTE);
    }
}

uint8_t dance_32_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_32_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_32_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_QUOTE); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_QUOTE)); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_QUOTE); register_code16(KC_QUOTE);
    }
}

void dance_32_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_QUOTE); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_QUOTE)); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_QUOTE); break;
    }
    dance_state.step = 0;
}
void on_dance_33(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_33_dance_step(qk_tap_dance_state_t *state);
void dance_33_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_33_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_33(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(KC_3));
        tap_code16(LALT(KC_3));
        tap_code16(LALT(KC_3));
    }
    if(state->count > 3) {
        tap_code16(LALT(KC_3));
    }
}

uint8_t dance_33_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_33_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_33_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(LALT(KC_3)); break;
        case SINGLE_HOLD: register_code16(LALT(LSFT(KC_2))); break;
        case DOUBLE_TAP: register_code16(LALT(KC_3)); register_code16(LALT(KC_3)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_3)); register_code16(LALT(KC_3));
    }
}

void dance_33_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(LALT(KC_3)); break;
        case SINGLE_HOLD: unregister_code16(LALT(LSFT(KC_2))); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_3)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_3)); break;
    }
    dance_state.step = 0;
}
void on_dance_54(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_54_dance_step(qk_tap_dance_state_t *state);
void dance_54_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_54_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_54(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

uint8_t dance_54_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_54_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_54_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: register_code16(LALT(LGUI(KC_ESCAPE))); break;
        case DOUBLE_TAP: register_code16(KC_ESCAPE); register_code16(KC_ESCAPE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_54_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: unregister_code16(LALT(LGUI(KC_ESCAPE))); break;
        case DOUBLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state.step = 0;
}
void on_dance_55(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_55_dance_step(qk_tap_dance_state_t *state);
void dance_55_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_55_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_55(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_Q);
        tap_code16(KC_Q);
        tap_code16(KC_Q);
    }
    if(state->count > 3) {
        tap_code16(KC_Q);
    }
}

uint8_t dance_55_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_55_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_55_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_Q); break;
        case SINGLE_HOLD: register_code16(KC_H); break;
        case DOUBLE_TAP: register_code16(KC_Q); register_code16(KC_Q); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_Q); register_code16(KC_Q);
    }
}

void dance_55_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_Q); break;
        case SINGLE_HOLD: unregister_code16(KC_H); break;
        case DOUBLE_TAP: unregister_code16(KC_Q); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_Q); break;
    }
    dance_state.step = 0;
}
void on_dance_56(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_56_dance_step(qk_tap_dance_state_t *state);
void dance_56_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_56_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_56(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

uint8_t dance_56_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_56_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_56_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_TAB)); break;
        case DOUBLE_TAP: register_code16(KC_TAB); register_code16(KC_TAB); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void dance_56_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_TAB)); break;
        case DOUBLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state.step = 0;
}
void on_dance_57(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_57_dance_step(qk_tap_dance_state_t *state);
void dance_57_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_57_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_57(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DELETE);
        tap_code16(KC_DELETE);
        tap_code16(KC_DELETE);
    }
    if(state->count > 3) {
        tap_code16(KC_DELETE);
    }
}

uint8_t dance_57_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_57_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_57_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_DELETE); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_K)); break;
        case DOUBLE_TAP: register_code16(KC_DELETE); register_code16(KC_DELETE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DELETE); register_code16(KC_DELETE);
    }
}

void dance_57_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_DELETE); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_K)); break;
        case DOUBLE_TAP: unregister_code16(KC_DELETE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DELETE); break;
    }
    dance_state.step = 0;
}
void on_dance_58(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_58_dance_step(qk_tap_dance_state_t *state);
void dance_58_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_58_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_58(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_GRAVE);
        tap_code16(KC_GRAVE);
        tap_code16(KC_GRAVE);
    }
    if(state->count > 3) {
        tap_code16(KC_GRAVE);
    }
}

uint8_t dance_58_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_58_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_58_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_GRAVE); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_GRAVE)); break;
        case DOUBLE_TAP: register_code16(KC_GRAVE); register_code16(KC_GRAVE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_GRAVE); register_code16(KC_GRAVE);
    }
}

void dance_58_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_GRAVE); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_GRAVE)); break;
        case DOUBLE_TAP: unregister_code16(KC_GRAVE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_GRAVE); break;
    }
    dance_state.step = 0;
}
void on_dance_59(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_59_dance_step(qk_tap_dance_state_t *state);
void dance_59_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_59_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_59(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
    }
    if(state->count > 3) {
        tap_code16(KC_SPACE);
    }
}

uint8_t dance_59_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_59_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_59_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_SPACE); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_O)); break;
        case DOUBLE_TAP: register_code16(KC_SPACE); register_code16(KC_SPACE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SPACE); register_code16(KC_SPACE);
    }
}

void dance_59_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_SPACE); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_O)); break;
        case DOUBLE_TAP: unregister_code16(KC_SPACE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SPACE); break;
    }
    dance_state.step = 0;
}
void on_dance_60(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_60_dance_step(qk_tap_dance_state_t *state);
void dance_60_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_60_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_60(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
    }
    if(state->count > 3) {
        tap_code16(KC_LEFT);
    }
}

uint8_t dance_60_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_60_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_60_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_LEFT); break;
        case SINGLE_HOLD: register_code16(LALT(KC_LEFT)); break;
        case DOUBLE_TAP: register_code16(KC_LEFT); register_code16(KC_LEFT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT); register_code16(KC_LEFT);
    }
}

void dance_60_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_LEFT)); break;
        case DOUBLE_TAP: unregister_code16(KC_LEFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT); break;
    }
    dance_state.step = 0;
}
void on_dance_63(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_63_dance_step(qk_tap_dance_state_t *state);
void dance_63_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_63_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_63(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RIGHT);
        tap_code16(KC_RIGHT);
        tap_code16(KC_RIGHT);
    }
    if(state->count > 3) {
        tap_code16(KC_RIGHT);
    }
}

uint8_t dance_63_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_63_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_63_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_RIGHT); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_RIGHT)); break;
        case DOUBLE_TAP: register_code16(KC_RIGHT); register_code16(KC_RIGHT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RIGHT); register_code16(KC_RIGHT);
    }
}

void dance_63_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_RIGHT); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_RIGHT)); break;
        case DOUBLE_TAP: unregister_code16(KC_RIGHT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RIGHT); break;
    }
    dance_state.step = 0;
}

void on_bksl_hme(qk_tap_dance_state_t *state, void *user_data);
uint8_t bksl_hme_dance_step(qk_tap_dance_state_t *state);
void bksl_hme_finished(qk_tap_dance_state_t *state, void *user_data);
void bksl_hme_reset(qk_tap_dance_state_t *state, void *user_data);

void on_bksl_hme(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_BSLS);
        tap_code16(KC_BSLS);
        tap_code16(KC_BSLS);
    }
    if(state->count > 3) {
        tap_code16(KC_BSLS);
    }
}

uint8_t bksl_hme_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void bksl_hme_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = bksl_hme_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_BSLS); break;
        case SINGLE_HOLD: register_code16(KC_HOME); break;
        case DOUBLE_TAP: register_code16(KC_BSLS); register_code16(KC_BSLS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_BSLS); register_code16(KC_BSLS);
    }
}

void bksl_hme_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_BSLS); break;
        case SINGLE_HOLD: unregister_code16(KC_HOME); break;
        case DOUBLE_TAP: unregister_code16(KC_BSLS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_BSLS); break;
    }
    dance_state.step = 0;
}

void on_pipe_end(qk_tap_dance_state_t *state, void *user_data);
uint8_t pipe_end_dance_step(qk_tap_dance_state_t *state);
void pipe_end_finished(qk_tap_dance_state_t *state, void *user_data);
void pipe_end_reset(qk_tap_dance_state_t *state, void *user_data);

void on_pipe_end(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PIPE);
        tap_code16(KC_PIPE);
        tap_code16(KC_PIPE);
    }
    if(state->count > 3) {
        tap_code16(KC_PIPE);
    }
}

uint8_t pipe_end_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void pipe_end_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = pipe_end_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_PIPE); break;
        case SINGLE_HOLD: register_code16(KC_END); break;
        case DOUBLE_TAP: register_code16(KC_PIPE); register_code16(KC_PIPE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PIPE); register_code16(KC_PIPE);
    }
}

void pipe_end_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_PIPE); break;
        case SINGLE_HOLD: unregister_code16(KC_END); break;
        case DOUBLE_TAP: unregister_code16(KC_PIPE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PIPE); break;
    }
    dance_state.step = 0;
}

void on_ctrl_home(qk_tap_dance_state_t *state, void *user_data);
uint8_t ctrl_home_dance_step(qk_tap_dance_state_t *state);
void ctrl_home_finished(qk_tap_dance_state_t *state, void *user_data);
void ctrl_home_reset(qk_tap_dance_state_t *state, void *user_data);

void on_ctrl_home(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_HOME);
        tap_code16(KC_HOME);
        tap_code16(KC_HOME);
    }
    if(state->count > 3) {
        tap_code16(KC_HOME);
    }
}

uint8_t ctrl_home_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void ctrl_home_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = bksl_hme_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_HOME); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_HOME)); break;
        case DOUBLE_TAP: register_code16(KC_HOME); register_code16(KC_LBRC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_HOME); register_code16(KC_LBRC);
    }
}

void ctrl_home_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_HOME); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_HOME)); break;
        case DOUBLE_TAP: unregister_code16(KC_HOME); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_HOME); break;
    }
    dance_state.step = 0;
}

void on_ctrl_end(qk_tap_dance_state_t *state, void *user_data);
uint8_t ctrl_end_dance_step(qk_tap_dance_state_t *state);
void ctrl_end_finished(qk_tap_dance_state_t *state, void *user_data);
void ctrl_end_reset(qk_tap_dance_state_t *state, void *user_data);

void on_ctrl_end(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_END);
        tap_code16(KC_END);
        tap_code16(KC_END);
    }
    if(state->count > 3) {
        tap_code16(KC_END);
    }
}

uint8_t ctrl_end_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void ctrl_end_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = bksl_hme_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_END); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_END)); break;
        case DOUBLE_TAP: register_code16(KC_END); register_code16(KC_END); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_END); register_code16(KC_END);
    }
}

void ctrl_end_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_END); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_END)); break;
        case DOUBLE_TAP: unregister_code16(KC_END); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_END); break;
    }
    dance_state.step = 0;
}

void on_mid_click(qk_tap_dance_state_t *state, void *user_data);
uint8_t mid_click_dance_step(qk_tap_dance_state_t *state);
void mid_click_finished(qk_tap_dance_state_t *state, void *user_data);
void mid_click_reset(qk_tap_dance_state_t *state, void *user_data);

void on_mid_click(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MS_BTN1);
        tap_code16(KC_MS_BTN1);
        tap_code16(KC_MS_BTN1);
    }
    if(state->count > 3) {
        tap_code16(KC_MS_BTN1);
    }
}

uint8_t mid_click_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void mid_click_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = bksl_hme_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_MS_BTN1); break;
        case SINGLE_HOLD: register_code16(KC_MS_BTN3); break;
        case DOUBLE_TAP: register_code16(KC_MS_BTN1); register_code16(KC_MS_BTN1); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MS_BTN1); register_code16(KC_MS_BTN1);
    }
}

void mid_click_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_MS_BTN1); break;
        case SINGLE_HOLD: unregister_code16(KC_MS_BTN3); break;
        case DOUBLE_TAP: unregister_code16(KC_MS_BTN1); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MS_BTN1); break;
    }
    dance_state.step = 0;
}

void on_screen_clip(qk_tap_dance_state_t *state, void *user_data);
uint8_t screen_clip_dance_step(qk_tap_dance_state_t *state);
void screen_clip_finished(qk_tap_dance_state_t *state, void *user_data);
void screen_clip_reset(qk_tap_dance_state_t *state, void *user_data);

void on_screen_clip(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_2));
        tap_code16(LSFT(KC_2));
        tap_code16(LSFT(KC_2));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_2));
    }
}

uint8_t screen_clip_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void screen_clip_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_31_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_QUOT); break;
        case SINGLE_HOLD: register_code16(LGUI(LSFT(KC_S))); break;
        case DOUBLE_TAP: register_code16(KC_QUOT); register_code16(KC_QUOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_QUOT); register_code16(KC_QUOT);
    }
}

void screen_clip_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_QUOT); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(KC_S))); break;
        case DOUBLE_TAP: unregister_code16(KC_QUOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_QUOT); break;
    }
    dance_state.step = 0;
}

void on_reset(qk_tap_dance_state_t *state, void *user_data);
uint8_t reset_dance_step(qk_tap_dance_state_t *state);
void reset_finished(qk_tap_dance_state_t *state, void *user_data);
void reset_reset(qk_tap_dance_state_t *state, void *user_data);

void on_reset(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_NUM));
        tap_code16(LSFT(KC_NUM));
        tap_code16(LSFT(KC_NUM));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_NUM));
    }
}

uint8_t reset_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void reset_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_31_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_NUM); break;
        case SINGLE_HOLD: register_code16(QK_BOOT); break;
        case DOUBLE_TAP: register_code16(KC_NUM); register_code16(KC_NUM); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_NUM); register_code16(KC_NUM);
    }
}

void reset_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_NUM); break;
        case SINGLE_HOLD: unregister_code16(QK_BOOT); break;
        case DOUBLE_TAP: unregister_code16(KC_NUM); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_NUM); break;
    }
    dance_state.step = 0;
}

void on_print_screen(qk_tap_dance_state_t *state, void *user_data);
uint8_t print_screen_dance_step(qk_tap_dance_state_t *state);
void print_screen_finished(qk_tap_dance_state_t *state, void *user_data);
void print_screen_reset(qk_tap_dance_state_t *state, void *user_data);

void on_print_screen(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_SCRL));
        tap_code16(LSFT(KC_SCRL));
        tap_code16(LSFT(KC_SCRL));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_SCRL));
    }
}

uint8_t print_screen_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void print_screen_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_31_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_SCRL); break;
        case SINGLE_HOLD: register_code16(KC_PSCR); break;
        case DOUBLE_TAP: register_code16(KC_SCRL); register_code16(KC_SCRL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SCRL); register_code16(KC_SCRL);
    }
}

void print_screen_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_SCRL); break;
        case SINGLE_HOLD: unregister_code16(KC_PSCR); break;
        case DOUBLE_TAP: unregister_code16(KC_SCRL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SCRL); break;
    }
    dance_state.step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_E] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_e, dance_e_finished, dance_e_reset),
        [DANCE_O] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_o, dance_o_finished, dance_o_reset),
        [DANCE_A] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_a, dance_a_finished, dance_a_reset),
        [DANCE_S] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_s, dance_s_finished, dance_s_reset),
        [DANCE_L] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_l, dance_l_finished, dance_l_reset),
        [DANCE_Z] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_z, dance_z_finished, dance_z_reset),
        [DANCE_X] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_x, dance_x_finished, dance_x_reset),
        [DANCE_C] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_c, dance_c_finished, dance_c_reset),
        [DANCE_N] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_n, dance_n_finished, dance_n_reset),
        [DANCE_15] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_15, dance_15_finished, dance_15_reset),
        [DANCE_31] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_31, dance_31_finished, dance_31_reset),
        [DANCE_32] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_32, dance_32_finished, dance_32_reset),
        [DANCE_33] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_33, dance_33_finished, dance_33_reset),
        [DANCE_54] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_54, dance_54_finished, dance_54_reset),
        [DANCE_55] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_55, dance_55_finished, dance_55_reset),
        [DANCE_56] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_56, dance_56_finished, dance_56_reset),
        [DANCE_57] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_57, dance_57_finished, dance_57_reset),
        [DANCE_58] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_58, dance_58_finished, dance_58_reset),
        [DANCE_59] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_59, dance_59_finished, dance_59_reset),
        [DANCE_60] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_60, dance_60_finished, dance_60_reset),
        [DANCE_63] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_63, dance_63_finished, dance_63_reset),
        [BKSL_HME] = ACTION_TAP_DANCE_FN_ADVANCED(on_bksl_hme, bksl_hme_finished, bksl_hme_reset),
        [PIPE_END] = ACTION_TAP_DANCE_FN_ADVANCED(on_pipe_end, pipe_end_finished, pipe_end_reset),
        [CTRL_HOME] = ACTION_TAP_DANCE_FN_ADVANCED(on_ctrl_home, ctrl_home_finished, ctrl_home_reset),
        [CTRL_END] = ACTION_TAP_DANCE_FN_ADVANCED(on_ctrl_end, ctrl_end_finished, ctrl_end_reset),
        [MID_CLICK] = ACTION_TAP_DANCE_FN_ADVANCED(on_mid_click, mid_click_finished, mid_click_reset),
        [SCREEN_CLIP] = ACTION_TAP_DANCE_FN_ADVANCED(on_screen_clip, screen_clip_finished, screen_clip_reset),
        [RESET_MCU] = ACTION_TAP_DANCE_FN_ADVANCED(on_reset, reset_finished, reset_reset),
        [PRNT_SCRN] = ACTION_TAP_DANCE_FN_ADVANCED(on_print_screen, print_screen_finished, print_screen_reset),
};
