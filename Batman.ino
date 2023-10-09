//deleted all unnecessary notes 
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_A5  880
#define NOTE_AS5 932
#define REST      0




int tempo = 151;

// change this to whichever pin you want to use
int buzzer = 13;
int redPin = 5;
int greenPin = 6;
int bluePin = 9;

int melody[] = {
 
    NOTE_DS5,-12, NOTE_DS5,-12, NOTE_D5,-12, NOTE_D5,-12, NOTE_CS5,-12, NOTE_CS5,-12,  NOTE_D5,-12, NOTE_D5,-12,
 NOTE_DS5,-12, NOTE_DS5,-12, NOTE_D5,-12, NOTE_D5,-12, NOTE_CS5,-12, NOTE_CS5,-12,  NOTE_D5,-12, NOTE_D5,-12,
 NOTE_DS5,-12, NOTE_DS5,-12, NOTE_D5,-12, NOTE_D5,-12, NOTE_CS5,-12, NOTE_CS5,-12,  NOTE_D5,-12, NOTE_D5,-12,NOTE_G5,4, NOTE_G5, 2, REST, 3,
 NOTE_GS5,-12, NOTE_GS5,-12,NOTE_G5,-12, NOTE_G5,-12, NOTE_FS5,-12, NOTE_FS5,-12,NOTE_G5,-12, NOTE_G5,-12,
  NOTE_GS5,-12, NOTE_GS5,-12,NOTE_G5,-12, NOTE_G5,-12, NOTE_FS5,-12, NOTE_FS5,-12,NOTE_G5,-12, NOTE_G5,-12,
  NOTE_DS5,-12, NOTE_DS5,-12, NOTE_D5,-12, NOTE_D5,-12, NOTE_CS5,-12, NOTE_CS5,-12,  NOTE_D5,-12, NOTE_D5,-12,NOTE_DS5,4, NOTE_DS5, 2, REST, 3,
NOTE_A5,-12, NOTE_A5,-12,NOTE_GS5,-12, NOTE_GS5,-12, NOTE_G5,-12, NOTE_G5,-12,NOTE_GS5,-12, NOTE_GS5,-12,
  NOTE_G5,-12, NOTE_G5,-12,NOTE_FS5,-12, NOTE_FS5,-12, NOTE_F5,-12, NOTE_F5,-12,NOTE_FS5,-12, NOTE_FS5,-12,
  NOTE_DS5,-12, NOTE_DS5,-12, NOTE_D5,-12, NOTE_D5,-12, NOTE_CS5,-12, NOTE_CS5,-12,  NOTE_D5,-12, NOTE_D5,-12, REST, 3,NOTE_G5,4, NOTE_G5, 2, REST, 3,
 };
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    // Calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // Regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // Dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // Increases the duration in half for dotted notes
    }

    // Play the note
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Set LED color based on the note played
    int notePlayed = melody[thisNote];
    if (notePlayed == NOTE_G5) {
      analogWrite(redPin, 255);   // Red
      analogWrite(greenPin, 171); // Green
      analogWrite(bluePin, 0);    // Blue
    } else if (notePlayed == NOTE_DS5) {
      analogWrite(redPin, 12);
      analogWrite(greenPin, 27); // Green
      analogWrite(bluePin, 240);
    } else if (notePlayed == NOTE_D5) {
      analogWrite(redPin, 104);
      analogWrite(greenPin, 159);
      analogWrite(bluePin, 253); // Blue
    } else if (notePlayed == NOTE_CS5) {
      analogWrite(redPin, 62); // Red
      analogWrite(greenPin, 247);
      analogWrite(bluePin, 253);
    } else if (notePlayed == NOTE_GS5) {
      analogWrite(redPin, 255);   // Red
      analogWrite(greenPin, 0); // Green
      analogWrite(bluePin, 0); // Blue
    } else if (notePlayed == NOTE_FS5) {
      analogWrite(redPin, 255);   // Red
      analogWrite(greenPin, 247); // Green
      analogWrite(bluePin, 0); // Blue
    } else {
      // Default to turning off the LED
      analogWrite(redPin, 0);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 0);
    }

    // Wait for the specified duration before playing the next note.
    delay(noteDuration);

    // Stop the waveform generation before the next note.
    noTone(buzzer);
  }
}

void loop() {
  // No need to repeat the melody.
}
