#include "pitches.h" 
#define BUZZER_PIN 9 

int melody[] = {
  NOTE_B4, REST,
  NOTE_FS4, NOTE_FS4, NOTE_B4, NOTE_FS4, NOTE_E4, REST, NOTE_B3,

  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_B3, NOTE_B3, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_B3, NOTE_B3,
  NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_AS3, NOTE_AS3, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_AS3, NOTE_B3,
  NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_B3, NOTE_B3, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_B3, NOTE_B3,
  NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_AS3, NOTE_AS3, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_AS3,

  NOTE_B4, NOTE_A4, NOTE_G4, NOTE_D4, NOTE_FS4, NOTE_E4, NOTE_B4,
  NOTE_B4, NOTE_A4, NOTE_G4, NOTE_D4, NOTE_FS4, NOTE_AS4,

  REST, NOTE_E4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_B3,
  NOTE_D4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_B4,
  REST, NOTE_E4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_B3,
  NOTE_D4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_B4, REST, NOTE_B3, NOTE_B3, NOTE_B3,
  NOTE_D4, NOTE_CS4, NOTE_B3, NOTE_FS3, NOTE_E3, NOTE_FS3, NOTE_FS4, NOTE_B4, NOTE_FS4, NOTE_E4,
  
  REST
};

int durations[] = {
  4, 2,
  4, 8, 4, 8, 4, 2, 8,

  4, 4, 8, 8, 2, 8, 4, 4, 8, 8, 2, 8,
  4, 4, 8, 8, 2, 8, 4, 4, 8, 8, 2, 8,
  4, 4, 8, 8, 2, 8, 4, 4, 8, 8, 2, 8,
  4, 4, 8, 8, 2, 8, 4, 4, 8, 8, 2,

  2, 2, 2, 4, 1, 1, 8,
  2, 2, 2, 4, 1, 1,

  2, 2, 8, 8, 8, 2,
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 2,
  2, 2, 8, 8, 8, 2,
  8, 8, 8, 8, 8, 8, 2, 2, 8, 8, 8,
  2, 2, 2, 8, 4, 4, 8, 4, 8, 2,

  1
};


void setup() {
  // put your setup code here, to run once:
pinMode(BUZZER_PIN, OUTPUT); 
}

void loop() {
  
   int size = sizeof(durations) / sizeof(int);   //calculates number of eleemnts in durations array

for (int note = 0; note < size; note++) {    // gets notes from 0 to less than 'size' in increments of 1


//to calculate the note duration, take one second divided by the note type. 
	   //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc. 
	   int duration = 1000 / durations[note]; 


tone(BUZZER_PIN, melody[note], duration); 
	   
	 
//
// The tone() function is an Arduino-built-in function that generates a square wave of a specified frequency on a pin. Here:

// BUZZER_PIN is the pin number (9).
// melody[note] gives the frequency (in Hz) of the current note.
// duration tells the function how long to play the note in milliseconds.
// When called, tone() immediately starts producing the note sound on the buzzer pin.


//to distinguish the notes, set a minimum time between them. 
  //the note's duration + 30% seems to work well: 
  int pauseBetweenNotes = duration * 1.30; 

delay(pauseBetweenNotes); 
//This tells the Arduino to wait (do nothing) for pauseBetweenNotes milliseconds.

//stop the tone playing: 
	   noTone(BUZZER_PIN); 

// Calling noTone() after the delay() ensures that the pin is not producing any sound before moving on to the next note in the sequence.

// Why it’s needed:
// This ensures a clean break between notes and prevents any lingering tone if something unexpected happens.
}
}
