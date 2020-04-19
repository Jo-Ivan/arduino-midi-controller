#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

int buttonState[] = {0, 0, 0, 0, 0};

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);
  Serial.begin(115200);

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);

}

void loop() {
  int sensorVal[] = {
    !digitalRead(2),
    !digitalRead(3),
    !digitalRead(4),
    !digitalRead(5),
    !digitalRead(6),
  };

  for (int i = 0; i < 5; i++) {
    if (sensorVal[i] != buttonState[i]) {
      buttonState[i] = sensorVal [i];

      if (buttonState[i]) {
        MIDI.sendNoteOn(42 + i, 127, 1);
      } else {
        MIDI.sendNoteOff(42 + i, 127, 1);
      }

    }
  }
}