# Intrusion Alarm 
This project was built on TinkerCad platform (.brd shows the schematic)
consists of a monitoring system with 2 alarm zones (pins 7 and 8).

Once the alarm system is powered up, it will monitor two digital inputs to identify if any zones have been invaded.
If a zone is invaded, the alarm will sound intermittently to indicate that there has been an invasion (with a 2 second trigger followed by 2 second silence) for 3 minutes and off for 30 seconds. The alarm will sound again in the same way until it is deactivated via the input used to activate or deactivate the alarm (pin 12). The alarm output (pin 13) will flash an LED at a frequency of 1Hz when the alarm is on and remain lit when the alarm is off.
