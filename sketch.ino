/* Arduino midi to led converter */
union serial_super_data {
   unsigned long int_4_bytes;
   unsigned char read_byte[4];
} super_data;
 
//setup: assign pins to task
void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);    
  Serial.begin(57600); //starting serial at a rate of 57600    
}
 
//loop: wait for serial data, and interpret the message
void loop () {
   if (Serial.available() >= 3)  // wait for three bytes and continue
    {
      for(int i=0;i <=3; i++)
      super_data.read_byte[i]=Serial.read();
      switch (super_data.read_byte[0]) {
        case 144:// starting note on message   
          lightLed(super_data.read_byte[1], HIGH);
          break;
        case 128:// starting note off message     
          lightLed(super_data.read_byte[1], LOW);
          break;
        default:
          break;//do nothing
      }//end switch
    }//end if statement
}//end all
 
 
void lightLed(byte note, int value){
 if(note>=65 && note<=69){ //borders. Since we are using 5 LEDs, the border is within a 5-note range.
   digitalWrite(note-63, value); //This line is converting to pins. If the note is 65 and we remove 63, the result becomes pin 2.
 }
}
