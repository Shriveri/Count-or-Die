# ButtonMasher2000
   1. ButtonMasher2000 is a interactive game to be played on the CPX board that centers on reliving stress.
# Rules
   1. Use the switch to turn the game on and off.  
   2. To reset the game, press both buttons when the game is off. 
   3. To increase the count, press the right button.
   4. To decrease the count, press the left button. 
   5. Hover your flashlight or a light source over the cpx board to confirm answer. 
   6. If the count matches the given count at the beginning of the round, then the round is won.
   8. If the count doesn’t match then the count is reset.
   9. Now that you understand the game, confirm a count of 0. 
# Inputs
 1. Right Button
     - Increases Count.
 2. Left Button
     - Decreases Count.
 3. Both Left Button and Right Button
     - Resets Game.
 4. Switch
     - Turns Game On and Off.
 5. Light Sensor
     - If light level is decreased below light threshold then system registers the count as final answer.
# Outputs
1. IEDS
    - Displays Green if the count is correct when confirmed.
    - Displays Red if the count is incorrect when confirmed.
    - Displays Blue if the game undergos a reset.
2. Serial
     - Prints:
        - Introductory Paragraph explaning rules and how to play.
        - Score at the end of each level.
        - Threshold of the following level.
# Thresholds
 1. Count Threshold
     - Level 0 = 0
     - Level 1 = 10
     - Level 2 = 20
     - Level 3 = -40
     - Level 4 = 30
     - Level 5 = 100
 3. LightSensorThreshold
     FlashlightThreshold is 700
