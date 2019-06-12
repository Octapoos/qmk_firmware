#include "octapoos.h"

uint16_t copy_paste_timer;

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

#ifdef AUDIO_ENABLE
float csgo_song[][2] = SONG(CHROMATIC_SOUND);
#endif

// Defines actions tor my global custom keycodes. Defined in octapoos.h file
// Then runs the _keymap's record handler if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KC_QWERTY:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_QWERTY);
    }
    break;

  case KC_COLEMAK:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_COLEMAK);
    }
    break;
  case KC_DVORAK:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_DVORAK);
    }
    break;
  case KC_WORKMAN:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_WORKMAN);
    }
    break;
  case KC_CSGO:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_CSGO);
      #ifdef AUDIO_ENABLE
      PLAY_SONG(csgo_song);
      #endif
    }
    break;

  case VRSN: // Prints firmware version
    if (record->event.pressed) {
      send_string_with_delay_P(PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE), MACRO_TIMER);
    }
    break;

  case KC_CCCV:                                    // One key copy/paste
    if (record->event.pressed) {
      copy_paste_timer = timer_read();
    }
    else {
      if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {   // Hold, copy
        register_code(KC_LCTL);
        tap_code(KC_C);
        unregister_code(KC_LCTL);
      }
      else {                                // Tap, paste
        register_code(KC_LCTL);
        tap_code(KC_V);
        unregister_code(KC_LCTL);
      }
    }
    break;
#ifdef MACROPAD
  case SPOTIFY:  // Open Spotify
    if (record->event.pressed) {
      send_launch_macro("spotify", record);
    }
    return false;
  case CHROME:  // Open Chrome
    if (record->event.pressed) {
      send_launch_macro("chrome", record);
    }
    return false;
  case TWITCH:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI());
      _delay_ms(100);
      SEND_STRING("chrome"SS_TAP(X_ENTER));
      _delay_ms(200);
      SEND_STRING("twitch.tv"SS_TAP(X_ENTER));
      _delay_ms(100);
    }
    return false;
  case YOUTUBE:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI());
      _delay_ms(100);
      SEND_STRING("chrome"SS_TAP(X_ENTER));
      _delay_ms(200);
      SEND_STRING("youtube.com"SS_TAP(X_ENTER));
      _delay_ms(100);
    }
    return false;
  case DISCORD:
    if (record->event.pressed) {
      send_launch_macro("discord", record);
    }
    return false;
  case STEAM:
    if (record->event.pressed) {
      send_launch_macro("steam", record);
    }
    return false;
  case LEAGUE:
    if (record->event.pressed) {
      send_launch_macro("league", record);
    }
    return false;
/*#ifdef UNICODE_ENABLE
  case UC_FLIP: // (ノಠ痊ಠ)ノ彡┻━┻
    if (record->event.pressed) {
      send_unicode_hex_string("0028 30CE 0CA0 75CA 0CA0 0029 30CE 5F61 253B 2501 253B");
    }
    break;
  case UC_TABL: // ┬─┬ノ( º _ ºノ)
    if (record->event.pressed) {
      send_unicode_hex_string("252C 2500 252C 30CE 0028 0020 00BA 0020 005F 0020 00BA 30CE 0029");
    }
    break;
  case UC_SHRG: // ¯\_(ツ)_/¯
    if (record->event.pressed) {
      send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
    }
    break;
  case UC_DISA: // ಠ_ಠ
    if (record->event.pressed) {
      send_unicode_hex_string("0CA0 005F 0CA0");
    }
    break;
#endif*/
#endif
  }
  return process_record_keymap(keycode, record);
}
