#include "bpitches.h"

#define melodyPin 9

int music = 1;

// Jingle Bells

int jb_melody[] = {
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
};

int jb_tempo[] = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};

// We wish you a merry Christmas

int wish_melody[] = {
  NOTE_B3,
  NOTE_F4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4,
  NOTE_D4, NOTE_D4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_D4, NOTE_B3, NOTE_B3,
  NOTE_D4, NOTE_G4, NOTE_E4,
  NOTE_F4
};

int wish_tempo[] = {
  4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 8, 8,
  4, 4, 4,
  2
};

// Santa Claus is coming to town

int santa_melody[] = {
  NOTE_G4,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_C5,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4,
  NOTE_E4, NOTE_G4, NOTE_C4, NOTE_E4,
  NOTE_D4, NOTE_F4, NOTE_B3,
  NOTE_C4
};

int santa_tempo[] = {
  8,
  8, 8, 4, 4, 4,
  8, 8, 4, 4, 4,
  8, 8, 4, 4, 4,
  8, 8, 4, 2,
  4, 4, 4, 4,
  4, 2, 4,
  1
};

void play(int song) {
  // iterate over the notes of the melody:
  if (song == 3) {
    Serial.println(" 'We wish you a Merry Christmas'");
    int size = sizeof(wish_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / wish_tempo[thisNote];

      tone(melodyPin, wish_melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      tone(melodyPin, 0, noteDuration);

    }
  } else if (song == 2) {
    Serial.println(" 'Santa Claus is coming to town'");
    int size = sizeof(santa_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 900 / santa_tempo[thisNote];

      tone(melodyPin, santa_melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      tone(melodyPin, 0, noteDuration);

    }
  } else {

    Serial.println(" 'Jingle Bells'");
    int size = sizeof(jb_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / jb_tempo[thisNote];

      tone(melodyPin, jb_melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      tone(melodyPin, 0, noteDuration);

    }
  }
}

void(* reset) (void) = 0; //declare reset function @ address 0

void setup() {
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(11, INPUT);
  pinMode(10, INPUT);
  pinMode(8, INPUT);
  pinMode(7, INPUT);

  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);

  digitalWrite(6, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);

  while (digitalRead(13) == LOW) {

  }
  tone(melodyPin, NOTE_A3, 200);
  delay(100);
  tone(melodyPin, NOTE_B3, 200);
  delay(100);
  tone(melodyPin, NOTE_C4, 200);
  delay(100);
  tone(melodyPin, NOTE_D4, 200);
  delay(100);
  digitalWrite(6, LOW);
  delay(100);
  digitalWrite(3, LOW);
  delay(100);
  digitalWrite(4, LOW);
  delay(100);
  digitalWrite(5, LOW);
  delay(100);
  digitalWrite(6, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(8) == HIGH) {

    digitalWrite(6, LOW);
    delay(100);
    digitalWrite(3, LOW);
    delay(100);
    digitalWrite(4, LOW);
    delay(100);
    digitalWrite(5, LOW);
    delay(100);
    if (music == 1) {
      music = 0;
      play(3);
    }
  }

  if (digitalRead(10) == HIGH) {
    tone(melodyPin, NOTE_D2, 200);
    delay(200);
    tone(melodyPin, NOTE_D1, 200);
    reset();

  }
  if (digitalRead(11) == HIGH) {
    tone(melodyPin, NOTE_C5, 800);
    delay(200);
    tone(melodyPin, NOTE_D4, 800);
    digitalWrite(6, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }
  if (digitalRead(12) == HIGH) {
    tone(melodyPin, NOTE_D4, 200);
    delay(200);
    tone(melodyPin, NOTE_C5, 200);
    digitalWrite(6, LOW);
    delay(100);
    digitalWrite(3, LOW);
    delay(100);
    digitalWrite(4, LOW);
    delay(100);
    digitalWrite(5, LOW);
    delay(100);
  }
  if (digitalRead(13) == HIGH) {
    play(1);
  }




}
