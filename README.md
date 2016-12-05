# Arduino MIDI LED Light Show

This project will listen to a virtual midi port, and turn the corresponding connected LED.
# Parts / Software required:

- Arduino
- 5 or more LEDs
- Wire
- Virtual MIDI port configurator
- [Serial to midi converter](http://www.spikenzielabs.com/SpikenzieLabs/Serial_MIDI.html)
- [Software to send midi](http://www.manyetas.com/creed/midikeys.html)

## Hardware Setup
### Connect the LEDs to the Arduino as following:

####These are the pins used in the script:
```arduino

pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
```

#### Wiring diagram
The LEDs I used does not require resistors. If yours do, connect a resistor in series before **every** LED.

<img width="500" alt="schematic" src="https://cloud.githubusercontent.com/assets/18582452/20883638/7d4f6e62-bae7-11e6-9603-c4440df44c2f.png">


## Software Setup
Upload [script](https://github.com/tlystad24/arduino-midi-out/blob/master/sketch.ino) to the Arduino.

### Set up a virtual midi connection
On Mac I used "Audio Midi Setup"

Create two virtual MIDI ports: one _from_ software, and one _to_ software.

Open the serial<>midi converter, and select your Arduino's serial port, the midi *INPUT* port and the midi *OUTPUT* port.

Open _MidiKeys_ and configure it to the virtual ports.



