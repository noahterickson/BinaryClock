/*
Inspired by sbbrain from instructables.com
http://www.instructables.com/id/Full-Binary-Clock/step6/The-Code/
*/

#define mux0 9 //arduino pin 9, atmega pin 15
#define mux1 8 //arduino pin 8, atmega pin 14
#define mux2 7 //arduino pin 7, atmega pin 13

#define bit1 10 //arduino pin 10, atmega pin 16
#define bit2 11 //arduino pin 11, atmega pin 17
#define bit4 12 //arduino pin 12, atmega pin 18
#define bit8 13 //arduino pin 13, atmega pin 19
#define hourButton 2 //arduino pin 0, atmega pin 2
#define minButton 3 //arduino pin 1, atmega pin 3

#include <avr/interrupt.h>



void setup() {
  // put your setup code here, to run once:
  // Enable global interrupts
  SREG |= (1 << 7);
  // Interrupt on rising edge for pins 1,0 (pg. 71)
  EICRA |= (1 << ISC11) | (1 << ISC10) | (ISC01) | (ISC00);
  // Enable interrupts on INT0,INT1 (pins 3,4)
  EIMSK |= (1 << INT1) | (1 << INT0);
  pinMode(hourButton, INPUT);
  pinMode(minButton, INPUT);
  pinMode(mux0, OUTPUT);
  pinMode(mux1, OUTPUT);
  pinMode(mux2, OUTPUT);
  pinMode(bit1, OUTPUT);
  pinMode(bit2, OUTPUT);
  pinMode(bit4, OUTPUT);
  pinMode(bit8, OUTPUT);
}

void mux(int muxa2, int muxa1, int muxa0){
  digitalWrite(mux0, muxa0);
  digitalWrite(mux1, muxa1);
  digitalWrite(mux2, muxa2);
  
}

ISR(INT0_vect) {
  hourOne++;
}

ISR(INT1_vect) {
  minOne++;
}

int secOne=1, minOne=3, hourOne=0;
int secTen=1, minTen=2, hourTen=0;
int configTime = 300; //260 seems about right for simulation, 1000 for circuit?


void columns(int columnNum)
{
  byte one;
  byte two;
  byte four;
  byte eight;
  
  switch (columnNum) {
  case 0: //for secOnes
      if (secOne == 1 || secOne == 3 || secOne == 5 || secOne == 7 || secOne == 9) {
        one = HIGH;
      }
      else {
        one = LOW;
      }
      if (secOne == 2 || secOne == 3 || secOne == 6 || secOne == 7) {
        two = HIGH;
      }
      else {
        two = LOW;
      }
      if (secOne == 4 || secOne == 5 || secOne == 6 || secOne == 7) {
        four = HIGH;
      }
      else {
        four = LOW;
      }
      if (secOne == 8 || secOne == 9) {
        eight = HIGH;
      }
      else {
        eight = LOW;
      }
      if (secOne == 0) {
        one = LOW;
        two = LOW;
        four = LOW;
        eight = LOW;
      }
      row(one,two,four,eight);
      break;
  case 1: //for secTens
      if (secTen == 1 || secTen == 3 || secTen == 5 || secTen == 7 || secTen == 9) {
        one = HIGH;
      }
      else {
        one = LOW;
      }
      if (secTen == 2 || secTen == 3 || secTen == 6 || secTen == 7) {
        two = HIGH;
      }
      else {
        two = LOW;
      }
      if (secTen == 4 || secTen == 5 || secTen == 6 || secTen == 7) {
        four = HIGH;
      }
      else {
        four = LOW;
      }
      if (secTen == 8 || secTen == 9) {
        eight = HIGH;
      }
      else {
        eight = LOW;
      }
      if (secTen == 0) {
        one = LOW;
        two = LOW;
        four = LOW;
        eight = LOW;
      }
      row(one,two,four,eight);
      break;
  case 2: //for minOnes
      if (minOne == 1 || minOne == 3 || minOne == 5 || minOne == 7 || minOne == 9) {
        one = HIGH;
      }
      else {
        one = LOW;
      }
      if (minOne == 2 || minOne == 3 || minOne == 6 || minOne == 7) {
        two = HIGH;
      }
      else {
        two = LOW;
      }
      if (minOne == 4 || minOne == 5 || minOne == 6 || minOne == 7) {
        four = HIGH;
      }
      else {
        four = LOW;
      }
      if (minOne == 8 || minOne == 9) {
        eight = HIGH;
      }
      else {
        eight = LOW;
      }
      if (minOne == 0) {
        one = LOW;
        two = LOW;
        four = LOW;
        eight = LOW;
      }
      row(one,two,four,eight);
      break;    
  case 3: //for minTens
      if (minTen == 1 || minTen == 3 || minTen == 5 || minTen == 7 || minTen == 9) {
        one = HIGH;
      }
      else {
        one = LOW;
      }
      if (minTen == 2 || minTen == 3 || minTen == 6 || minTen == 7) {
        two = HIGH;
      }
      else {
        two = LOW;
      }
      if (minTen == 4 || minTen == 5 || minTen == 6 || minTen == 7) {
        four = HIGH;
      }
      else {
        four = LOW;
      }
      if (minTen == 8 || minTen == 9) {
        eight = HIGH;
      }
      else {
        eight = LOW;
      }
      if (minTen == 0) {
        one = LOW;
        two = LOW;
        four = LOW;
        eight = LOW;
      }
      row(one,two,four,eight);
      break;
  case 4: //for hours one
      if (hourOne == 1 || hourOne == 3 || hourOne == 5 || hourOne == 7 || hourOne == 9) {
        one = HIGH;
      }
      else {
        one = LOW;
      }
      if (hourOne == 2 || hourOne == 3 || hourOne == 6 || hourOne == 7) {
        two = HIGH;
      }
      else {
        two = LOW;
      }
      if (hourOne == 4 || hourOne == 5 || hourOne == 6 || hourOne == 7) {
        four = HIGH;
      }
      else {
        four = LOW;
      }
      if (hourOne == 8 || hourOne == 9) {
        eight = HIGH;
      }
      else {
        eight = LOW;
      }
      if (hourOne == 0) {
        one = LOW;
        two = LOW;
        four = LOW;
        eight = LOW;
      }
      row(one,two,four,eight);
      break;
  case 5: //for hourTens
      if (hourTen == 1 || hourTen == 3 || hourTen == 5 || hourTen == 7 || hourTen == 9) {
        one = HIGH;
      }
      else {
        one = LOW;
      }
      if (hourTen == 2 || hourTen == 3 || hourTen == 6 || hourTen == 7) {
        two = HIGH;
      }
      else {
        two = LOW;
      }
      if (hourTen == 4 || hourTen == 5 || hourTen == 6 || hourTen == 7) {
        four = HIGH;
      }
      else {
        four = LOW;
      }
      if (hourTen == 8 || hourTen == 9) {
        eight = HIGH;
      }
      else {
        eight = LOW;
      }
      if (hourTen == 0) {
        one = LOW;
        two = LOW;
        four = LOW;
        eight = LOW;
      }
      row(one,two,four,eight);
      break;            
  }
   
}

void showTime(){
  int temp = 10;
  mux(1,1,1); //turn off
  row(0,0,0,0);
  delayMicroseconds(temp);
  
  mux(0,0,0); // for hours, tens
  columns(5);
  delayMicroseconds(temp);

  mux(1,1,1); //turn off
  row(0,0,0,0);
  delayMicroseconds(temp);
  
  mux(0,0,1); //for hours, ones
  columns(4);
  delayMicroseconds(temp);

  mux(1,1,1); //turn off
  row(0,0,0,0);
  delayMicroseconds(temp);
  
  mux(0,1,0); //for minutes tens
  columns(4);
  delayMicroseconds(temp);

  mux(1,1,1); //turn off
  row(0,0,0,0);
  delayMicroseconds(temp);
  
  mux(0,1,1); //for minutes ones
  columns(2);
  delayMicroseconds(temp);

  mux(1,1,1); //turn off
  row(0,0,0,0);
  delayMicroseconds(temp);
  
  mux(1,0,0); //for seconds tens
  columns(1);
  delayMicroseconds(temp);

  mux(1,1,1); //turn off
  row(0,0,0,0);
  delayMicroseconds(temp);
  
  mux(1,0,1); //for seconds ones
  columns(0);
  delayMicroseconds(temp); 
}

void row(byte one1, byte two2, byte four4, byte eight8){
  digitalWrite(bit1, one1);
  digitalWrite(bit2, two2);
  digitalWrite(bit4, four4);
  digitalWrite(bit8, eight8);
}

int minButtonState = 0;
int hourButtonState = 0;

void loop() {
  //delay(500);
  minButtonState = digitalRead(minButton);
  hourButtonState = digitalRead(hourButton);
  
  static unsigned long lastSecond = 0;
  
  /*if (minButtonState == HIGH && minButtonFlag != 1) {
    minOne++;
    minButtonFlag = 1;
  }
  
  if (hourButtonState == HIGH && hourButtonFlag != 1) {   
    hourOne++;
    hourButtonFlag = 1;
  }
  
  if (millis() - lastSecond >= quarterSec) {
    hourButtonFlag = 0;
    minButtonFlag = 0;
    }*/
    
  else if (minButtonState == LOW && hourButtonState == LOW) {
    if (millis() - lastSecond >= configTime) {
    lastSecond = millis();
    secOne++;
    }
  }
 
  
  if (secOne > 9) {
    secTen++;
    secOne = 0;
  }
  
  if (secTen > 5) {
    minOne++;
    secTen = 0;
  }
  
  if (minOne > 9) {
    minTen++;
    minOne = 0;
  }
  
  if (minTen > 5) {
    hourOne++;
    minTen = 0;
  }
  
  if (hourOne > 9) {
    hourTen++;
    hourOne = 0;
  }
  
  if (hourTen == 2 && hourOne > 4) {
    hourTen = 0;
    hourOne = 0;
    
  }

  showTime();
}

  


