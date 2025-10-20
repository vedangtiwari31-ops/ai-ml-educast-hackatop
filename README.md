# ai-ml-Arduino-Solar-Tracker-hackatop
# Arduino Solar Tracker

This project uses 4 LDR sensors and 2 servo motors to automatically track the brightest light source.

## Components
- Arduino Uno: The brain of the project, responsible for processing data and controlling the motors.
- 4 Light Dependent Resistors (LDRs): Detect light intensity from different directions.
- 4 Resistors (10k ohm): Form a voltage divider circuit with the LDRs.
- 2 SG90 Servo Motors: One controls the horizontal axis (azimuth), and the other controls the vertical axis (elevation).
- Solar Panel: Demonstrates how the tracker aligns the panel with sunlight.
- Breadboard and Jumper Wires: For making temporary connections.

## Working Principle
The arduino based sun tracking solar panel project works on the principle of comparing light intensities to determine the sun’s position. Here’s how it operates:

1. Light Detection:

   1. Four LDRs are placed in a cross pattern around the solar panel, dividing it into four quadrants: top-left, top-right, bottom-left, and bottom-right.
   2. Each LDR senses the intensity of sunlight in its respective quadrant and sends the analog data to the Arduino.
2. Data Processing:

  1. The Arduino reads the LDR values and calculates the differences between opposing quadrants:
       1. Horizontal difference = (Top-Left + Bottom-Left) - (Top-Right + Bottom-Right)
       2. Vertical difference = (Top-Left + Top-Right) - (Bottom-Left + Bottom-Right)
   2. These differences indicate the direction in which the solar panel needs to move to align with the sun.
3. Servo Adjustment:

    1. Based on the calculated differences, the Arduino adjusts the angles of the horizontal and vertical servos.
    2. The servos move incrementally until the light intensity is balanced across all LDRs, indicating that the panel is aligned with the sun.
       
4. Dynamic Tracking:

    1. As the sun moves throughout the day, the system continuously adjusts the panel’s position to ensure it remains perpendicular to the sun’s rays.

5. The LDRs detect light intensity, and the servos adjust position accordingly.
# ai-ml-educast-hackatop
