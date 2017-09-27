/*
Name: Lisander Lopez - Univeristy Heights High School
Date: 11/20/16
Description:
  This sketch will use a 74HC595 to display a Larson Scanner using LEDs.
  We will use a potentiometer to control the speed of the scanner.
  For more information on the circuit, view the fritzing diagram. 
Notes:
  I was looking at my previous code to see how to improve it.
  I figured out that if I made a function which checks the pots value,
  and called it everytime I needed it, it would make the scanner more smoother.
  This acheived the "multi-tasking" trick I was looking for.

  Plus, I made an array of bytes called pattern to help me send the bytes to the shift
  register without being bombarded with 0's and 1's
*/
 
const int latchPin = 4; //Pin connected to latch pin of 74HC595
const int clockPin = 5; //Pin connected to clock pin of 74HC595
const int dataPin = 3;  //Pin connected to Serial in of 74HC595

const int potPin = A0;  // Pin the potentiometer is connected to

// The following is an array of bytes. Instead of writing out the bytes
// everytime when calling the shift out function. We can create an array
// that containes the bytes for out pattern, and call them as needed.
byte pattern[] = 
{
  B00000000,
  B10000000,
  B11000000,
  B01100000,
  B00110000,
  B00011000,
  B00001100,
  B00000110,
  B00000011,
  B00000001
};

void setup() 
{
  // Setting pins as output, as we will output data to it
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);

  pinMode(potPin, INPUT); // We are going to read the 'value' of the pot, so it would need to be an input

}
 
void loop() 
{
  
  clockShiftRegister(pattern[0]);  // Clocking the first stage of the pattern to the second register
  clockShiftRegister(pattern[1]);  // Clocking the first stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[2]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[3]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[4]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[5]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[6]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[7]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[8]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[1]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[9]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.
  
  clockShiftRegister(pattern[2]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[3]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[4]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[5]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[6]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[7]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[8]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[9]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  // At this stage the patter is half way done the LEDs went 'across' now we need to 'bring them back'

  clockShiftRegister(pattern[8]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[7]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[6]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[5]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[4]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[3]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[2]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[1]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[9]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[8]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[7]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[6]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[5]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[4]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.
 
  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.

  clockShiftRegister(pattern[0]);  // Clocking the next stage of the pattern to the second register
  clockShiftRegister(pattern[2]);  // Clocking the next stage of the pattern to the first register
  displayShiftRegister(); // Displaying the data on the register to the LEDs
  delay(readPot());  // Time to delay in between pattern changes (how fast the pattern displays), We will retreive this value from the pot. The speed will depend on the user.
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

int readPot(){
  return map(analogRead(potPin), 0, 1024, 10, 1000);  // Reads value of potPin and then maps it, to turn it from range of 0-1024 to 10-1000. Which will be used as milliseconds
}

