/*
Name: Lisander Lopez - Univeristy Heights High School
Date: 11/20/16
Description:
  This sketch will use a 74HC595 to display a Larson Scanner using LEDs.
  We will use a potentiometer to control the speed of the scanner.
  For more information on the circuit, view the fritzing diagram. 
Notes:
  I researched online about arduinos ability to multi-task. In short, its possible
  with some tricks and some libraries. This sketch goes will with some multithreading.
  The Arduino is basically focused on making the pattern than reading the sensor.
*/
 
const int latchPin = 4; //Pin connected to latch pin of 74HC595
const int clockPin = 5; //Pin connected to clock pin of 74HC595
const int dataPin = 3;  //Pin connected to Serial in of 74HC595

const int potPin = A0;  // Pin the potentiometer is connected to

int waitTime; // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

void setup() 
{
  // Setting pins as output, as we will output data to it
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);

  pinMode(potPin, INPUT); // We are going to read the 'value' of the pot, so it would need to be an input

  Serial.begin(9600);
}

 
void loop() 
{
  
  int potValue = analogRead(A0);  // Reads value of potPin

  potValue = map(potValue, 0, 1024, 10, 1000);  // maps it, to turn it from range of 0-1024 to 10-1000. Which will be used as milliseconds
  waitTime = potValue;  // Set the value we mapped as the wait time
  
  clockShiftRegister(B00000000);  // Clocking the first stage of the pattern to the second register
  clockShiftRegister(B10000000);  // Clocking the first stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B11000000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B01100000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00110000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00011000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00001100);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00000110);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00000011);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B10000000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00000001);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern
  
  clockShiftRegister(B11000000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B01100000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00110000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00011000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00001100);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00000110);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00000011);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00000001);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  // At this stage the patter is half way done the LEDs went 'across' now we need to 'bring them back'

  clockShiftRegister(B00000011);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00000110);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00001100);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00011000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00110000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B01100000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B11000000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

    clockShiftRegister(B10000000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00000001);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00000011);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00000110);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00001100);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00011000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B00110000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern
 
  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B01100000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern

  clockShiftRegister(B00000000);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(B11000000);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(waitTime);  // Wait X amount (in ms) until displaying next stage of pattern
}
 
void clockShiftRegister(byte data)
{
  digitalWrite(latchPin, LOW); // Lets make sure the latch pin is set to low, so that the shift regsiter doesn't display anything yet
  shiftOut(dataPin, clockPin, LSBFIRST, data);  // Shift out the data given in the parameter (the bit) to the register
}

void displayShiftRegister(){
  // The 74HC595 displays whats in the register on a Rising edge of the latch pin, We will produce this by bringing the pin low, then High.
  // I bring it back low to make sure nothing gets clocked while I input my data.
  digitalWrite(latchPin, LOW);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
}
