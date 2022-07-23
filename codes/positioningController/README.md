# POSITIONING CONTROLLER
This project consists of the position control of a servo, composed of a motor with reduction, a potentiometer for the position feedback. The set also has an encoder for adjusting the SetPoint and an LCD display to present information related to the system's operation.

The operation follows the guidelines below:
1) The SetPoint is adjusted using the Encoder and represents the desired angle value in degrees. The minimum value to be adjusted is zero and the maximum value must be 180;

2) The Encoder has a button that must be used to confirm or cancel the displayed values. If it is held down for more than 2 seconds, it represents a confirmation, if it is pressed for less time, it means a cancellation of the action. The button will be used to correct the SetPoint value and start position control;

3) The Display shows the following information:
- Current value of the angle, measured using the potentiometer used for the feedback, in the first line;
- Desired value (SetPoint) of the angle, in the first line;
- Adjustment value to be sent to the SetPoint, in the second line;
- User actions confirmation messages, on the second line.

4) When the user confirms the change in the SetPoint, this value is also stored in the Arduino's EEPROM memory so that when the system is activated again, it follows the last adjustment performed in the system;
When the user confirms a new angle value, a message appears on the display informing that the change has been made;
If the user cancels a change, a cancellation message is shown on the display, confirming the change cancellation;

CONNECTION PINS:
- Encoder: 3, 2
- Encoder Button: 4
- LCD: 11, 12, 5, 6, 7, 8 (RS, EN, D4, D5, D6, D7)
- H-Bridge: 9, 10
- Feedback Potentiometer: A0
