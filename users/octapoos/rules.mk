SRC += octapoos.c \
       process_record.c

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
  SRC += tap_dance.c
endif

ifeq ($(strip $(AUDIO_ENABLE)), yes)
  SRC += muse.c
endif
