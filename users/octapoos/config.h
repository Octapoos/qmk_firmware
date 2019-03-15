#pragma once

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_ANIMATIONS
  #ifndef RGBLIGHT_SLEEP
    #define RGBLIGHT_SLEEP
  #endif // RGBLIGHT_SLEEP
#endif // RGBLIGHT_ENABLE

#define FORCE_NKRO

#ifndef TAPPING_TOGGLE
#define TAPPING_TOGGLE  1
#endif
