/* Copyright 2019 Danny Nguyen <danny@keeb.io>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "octapoos.h"

enum custom_keycodes {
  SPOTIFY = SAFE_RANGE,
  CHROME,
  TWITCH,
  YOUTUBE,
  DISCORD,
  STEAM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_MUTE, KC_F13,  KC_MPLY, //
        YOUTUBE, DISCORD, STEAM,   //
        TWITCH,  SPOTIFY, CHROME   //
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_MNXT);
        } else {
            tap_code(KC_MPRV);
        }
    }
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case SPOTIFY:  // Open Spotify
        SEND_STRING(SS_LGUI());
        _delay_ms(100);
        SEND_STRING("spotify");
        _delay_ms(100);
        SEND_STRING(SS_TAP(X_ENTER));
        _delay_ms(100);
        return false;
      case CHROME:  // Open Chrome
        SEND_STRING(SS_LGUI());
        _delay_ms(100);
        SEND_STRING("chrome"SS_TAP(X_ENTER));
        _delay_ms(100);
        return false;
      case TWITCH:
        SEND_STRING(SS_LGUI());
        _delay_ms(100);
        SEND_STRING("chrome"SS_TAP(X_ENTER));
        _delay_ms(200);
        SEND_STRING("twitch.tv"SS_TAP(X_ENTER));
        _delay_ms(100);
        return false;
      case YOUTUBE:
        SEND_STRING(SS_LGUI());
        _delay_ms(100);
        SEND_STRING("chrome"SS_TAP(X_ENTER));
        _delay_ms(200);
        SEND_STRING("youtube.com"SS_TAP(X_ENTER));
        _delay_ms(100);
        return false;
      case DISCORD:
        SEND_STRING(SS_LGUI());
        _delay_ms(100);
        SEND_STRING("discord"SS_TAP(X_ENTER));
        _delay_ms(100);
        return false;
      case STEAM:
        SEND_STRING(SS_LGUI());
        _delay_ms(100);
        SEND_STRING("steam"SS_TAP(X_ENTER));
        _delay_ms(100);
        return false;
    }
  }
  return true;
}
