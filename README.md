# Count-or-Die
Count-or-Die is a interactive game to be played on the CPX board. 
# Rules
   1. Use the switch to turn the game on and off.  
   2. To reset the game, press both buttons. 
   3. To increase the count, press the right button.
   4. To decrease the count, press the left button. 
   5. Hover your hand over the CPX board to confirm count. 
   6. You will have 30 seconds every round to achieve the correct count.
   7. If the count matches the given count at the beginning of the round, then the round is won.
   8. If the count doesn’t match then the round is lost.
   9. You need to win a total of 3 out of 5 rounds to beat the game.
   10. Now that you understand the game, hover your hand over the device to get started.'
# Inputs
 1. Right Button
     Increases Count.
 2. Left Button
     Decreases Count.
 3. Both Left Button and Right Button
     Resets Game.
 4. Switch
     Turns Game On and Off.
 5. Light Sensor
     If light level is decreased below light threshold then system registers the count as a           final answer.
# Outputs
 1. IEDS
     Displays Green if level is completed
     Displays Red if level is failed
     Displays Blue if thresholds for count are confirmed.
 2. Serial
     Prints:
        Rules when game is turned on.
        Score at the end of each level.
        Winner if level or game is won.
        Maybe next time if level or game is lost.
# Thresholds
 1. Count Threshold
 2. LightSensorThreshold
     Low = 100
