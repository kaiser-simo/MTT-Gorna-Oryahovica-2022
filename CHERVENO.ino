#include "melody.h"

int buzzer = 9;
int green = 13;
int yellow = 12;
int red = 11;
int outled = 10;

void setup() {
  pinMode(green, OUTPUT);

  pinMode(yellow, OUTPUT);

  pinMode(red, OUTPUT);

  pinMode(outled, OUTPUT);
}

void green1(void) {
  int tempogreen = 120;

  int melodygreen[] = {

    NOTE_E4, -4, REST, 8, NOTE_FS4, 8, NOTE_G4, -4, REST, 8, NOTE_DS4, 8,
    NOTE_E4, -8, NOTE_FS4, 8,  NOTE_G4, -8, NOTE_C5, 8, NOTE_B4, -8, NOTE_G4, 8, NOTE_B4, -8, NOTE_E5, 8,
    NOTE_DS5, 1,
    NOTE_D5, 2, REST, 4, REST, 8, NOTE_DS4, 8,
    NOTE_E4, -4, REST, 8, NOTE_FS4, 8, NOTE_G4, -4, REST, 8, NOTE_DS4, 8,
    NOTE_E4, -8, NOTE_FS4, 8,  NOTE_G4, -8, NOTE_C5, 8, NOTE_B4, -8, NOTE_E4, 8, NOTE_G4, -8, NOTE_B4, 8,

    NOTE_AS4, 2, NOTE_A4, -16, NOTE_G4, -16, NOTE_E4, -16, NOTE_D4, -16,
    NOTE_E4, -4, REST, 4,
  };
  int notes = sizeof(melodygreen) / sizeof(melodygreen[0]) / 2;
  int wholenote = (60000 * 4) / tempogreen;

  int divider = 0, noteDuration = 0;
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    divider = melodygreen[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melodygreen[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}

void yellow1(void) {
  int tempoyellow = 85;
  int melodyyellow[] = {
    NOTE_G4, 8, NOTE_C4, 8, NOTE_DS4, 16, NOTE_F4, 16, NOTE_G4, 8, NOTE_C4, 8, NOTE_DS4, 16, NOTE_F4, 16, //1
    NOTE_G4, 8, NOTE_C4, 8, NOTE_DS4, 16, NOTE_F4, 16, NOTE_G4, 8, NOTE_C4, 8, NOTE_DS4, 16, NOTE_F4, 16,
    NOTE_G4, 8, NOTE_C4, 8, NOTE_E4, 16, NOTE_F4, 16, NOTE_G4, 8, NOTE_C4, 8, NOTE_E4, 16, NOTE_F4, 16,
    NOTE_G4, 8, NOTE_C4, 8, NOTE_E4, 16, NOTE_F4, 16, NOTE_G4, 8, NOTE_C4, 8, NOTE_E4, 16, NOTE_F4, 16,
    NOTE_G4, -4, NOTE_C4, -4, //5
  };
  int notes = sizeof(melodyyellow) / sizeof(melodyyellow[0]) / 2;
  int wholenote = (60000 * 4) / tempoyellow;

  int divider = 0, noteDuration = 0;
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    divider = melodyyellow[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melodyyellow[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}

void red1(void) {
  int tempored = 120;
  int melodyred[] = {

    NOTE_A5, 4, NOTE_A4, -8, NOTE_A4, 16, NOTE_A5, 4, NOTE_GS5, -8, NOTE_G5, 16, //7
    NOTE_DS5, 16, NOTE_D5, 16, NOTE_DS5, 8, REST, 8, NOTE_A4, 8, NOTE_DS5, 4, NOTE_D5, -8, NOTE_CS5, 16,

    NOTE_C5, 16, NOTE_B4, 16, NOTE_C5, 16, REST, 8, NOTE_F4, 8, NOTE_GS4, 4, NOTE_F4, -8, NOTE_A4, -16, //9
    NOTE_C5, 4, NOTE_A4, -8, NOTE_C5, 16, NOTE_E5, 2,

    NOTE_A5, 4, NOTE_A4, -8, NOTE_A4, 16, NOTE_A5, 4, NOTE_GS5, -8, NOTE_G5, 16, //7
    NOTE_DS5, 16, NOTE_D5, 16, NOTE_DS5, 8, REST, 8, NOTE_A4, 8, NOTE_DS5, 4, NOTE_D5, -8, NOTE_CS5, 16,

    NOTE_C5, 16, NOTE_B4, 16, NOTE_C5, 16, REST, 8, NOTE_F4, 8, NOTE_GS4, 4, NOTE_F4, -8, NOTE_A4, -16, //9
    NOTE_A4, 4, NOTE_F4, -8, NOTE_C5, 16, NOTE_A4, 2,

  };
  int notes = sizeof(melodyred) / sizeof(melodyred[0]) / 2;
  int wholenote = (60000 * 4) / tempored;

  int divider = 0, noteDuration = 0;
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    divider = melodyred[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melodyred[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}



void loop() {


  digitalWrite(green, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  digitalWrite(outled, LOW);
  green1();
  delay(100);


  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(red, LOW);
  digitalWrite(outled, LOW);
  yellow1();
  delay(100);


  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  digitalWrite(outled, HIGH);
  red1();
  delay(100);
}
