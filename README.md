# Escape room challange

This project is an escape room built using a Nucleo F303RE. It has 4 mini-games that the user has to complete within 10 minutes to win the challenge.
## Hardware Requirements
- Nucleo F303RE
- Potentiometer
- Buzzer
- LED & KEY or Whadda WPM461 module
- LCD screen
- Resistors
- Breadboard and connecting wires

## Software Requirements
- [Arduino IDE](https://www.arduino.cc/en/software)
- Required libraries:
    - **TM1638plus** by Gavin Lyons 2.0.0 (Install from Arduino Library Manager)

## Pin mapping table

| **PIN**      | **CONNECTION(S)**                        |
|--------------|------------------------------------------|
| **3V3**      | Whadda (VCC), potentiometer, I2C backpack (VA, OE) |
| **5V**       | I2C backpack (VB)                        |
| **D4**       | TM_STROBE                                |
| **D6**       | TM_CLOCK                                 |
| **D7**       | TM_DIO                                   |
| **D8**       | Buzzer                                   |
| **A0**       | WIPER_PIN (potentiometer)                |
| **GND**      | All the grounds via breadboard            |
| **SCL/D14**  | A2 on the backpack                       |
| **SCL/D15**  | A1 on the backpack                       |


## Installation Instructions
1. Download and install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Clone this repository or download the ZIP file.
3. Open the `escapeRoom.ino` file in the Arduino IDE.
4. Ensure you have the correct board and port selected in **Tools > Board** and **Tools > Port**.
5. Click the **Upload** button to upload the code to your Arduino Uno.

## How to Use
- Once uploaded, the escape room will start.
# Escape Room Mini Games

To win the escape room, you have to win **4 mini-games** in **10 minutes**. The games are:

## 1. Catch the Square

In the first game, you will need to catch the racing square on the LCD display using the Nucleo’s user button. The goal is to press the button while the square is in front of the arrow (placed on the second row of the LCD).

- To proceed to the next mini-game, you must catch the square **3 times**.
- After you catch the square, the arrow will change its position, and the square will move **faster**!

---
## 2. Decoding Secret Numbers

In the second game, you'll use the Whadda to display a decimal number. You must enter that number in **binary**, using the 8 buttons on the Whadda.

- Each time you press a button, the corresponding LED will light up, helping you track your binary input.
- **Lit LEDs represent ones**, and unlit LEDs represent zeros.
- You'll have to decode **3 numbers**, with each round becoming more difficult.

**Note**: The binary number must be aligned to the right. For example, if the number is 1, only the **rightmost LED** should be lit.

---
## 3. Minimalistic Piano

The buzzer will play a short song (***Melc, melc, codobelc*** – a Romanian song). Your goal is to replicate the song using the buttons on the Whadda board:
![img.png](img.png)
- **S1** plays the **G note** (Sol).
- **S4** plays the **E note** (Mi).
- To hear the song again, press **S8**.
- To reset your try and start again, press **S7**.

**Note**: Due to a mistake on the Whadda board, **S4** is the **third button** from left to right.

Timing is also crucial, so make sure the duration of the notes is similar to the original song.

| Notes | Button |
|-------|--------|
| Sol (G) | S1 |
| Mi (E) | S4 |

---

## 4. Test Your Ear

In this game, the buzzer will play a random note for one second. Your task is to use the **potentiometer** to match that note:

- Sliding the potentiometer to the **left** plays **low notes**, and sliding to the **right** plays **high notes**.
- You must match the correct note for **one second**.
- Complete this **3 times**, with each round increasing the range of possible notes.

After you match the correct note, the buzzer will pause for **3 seconds** before playing the next note.

---

## Project Status
- Final version


## License

This project is not licensed. All rights reserved.
