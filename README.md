# HBD Matrix

This example scrolls `HAPPY BIRTHDAY, YOUR NAME!` repeatedly across a MAX7219
four-in-one display using an Arduino Uno R3. It assumes four 8x8 matrices in a
single horizontal row (32x8 pixels) and the common FC-16 layout.

The Arduino sketch is in [`HappyBirthday/HappyBirthday.ino`](HappyBirthday/HappyBirthday.ino).

## Parts

- Arduino Uno R3 and a USB data cable.
- MAX7219 four-in-one matrix module.
- Jumper wires suitable for your connectors.
- Regulated 5V DC supply rated for 2A for the display.

## Wiring

Disconnect power while wiring. Connect to the display's **DIN/IN** connector,
not its DOUT/OUT connector. Follow pin labels, not connector position.

| Matrix pin | Connection |
| --- | --- |
| VCC | External regulated supply +5V |
| GND | External supply negative/GND **and** Uno GND |
| DIN | Uno D11 |
| CS | Uno D10 |
| CLK | Uno D13 |

Power the Uno through USB. With this arrangement, leave the Uno's 5V pin
unconnected: only the grounds are shared with the external display supply.
Do not connect 9V or 12V to the display. The four matrices are already linked
on the board, so you only wire its input connector.

## Install and upload

1. Install and open [Arduino IDE](https://www.arduino.cc/en/software).
2. Open **Tools > Manage Libraries** and install **MD_Parola** and
   **MD_MAX72XX**, by MajicDesigns. Accept dependency installation if offered.
   `SPI` comes with the Arduino AVR board package.
3. Download this repository with **Code > Download ZIP** and extract it,
   then open `HappyBirthday/HappyBirthday.ino`. Keep the file inside its
   `HappyBirthday` folder.
4. Change `YOUR NAME` in `MESSAGE`, keeping the quotation marks. For example:
   `const char MESSAGE[] = "HAPPY BIRTHDAY, ALEX!   ";`
5. Connect the Uno with its USB data cable. Select **Arduino Uno** and the
   correct port in the IDE. If needed, install **Arduino AVR Boards** in
   Boards Manager.
6. Click **Verify**, then **Upload**. With both the Uno and matrix powered,
   the message should scroll repeatedly.

After upload, the sketch stays on the Uno and starts whenever it is powered.
The IDE does not need to remain open.

## Adjust and troubleshoot

- **Speed:** `SCROLL_SPEED = 100` is slower; `40` is faster.
- **Brightness:** `setIntensity(1)` starts low. The valid range is 0–15;
  0 is dimmest, not off. Higher brightness increases power use.
- **Upside down:** For FC-16 modules, orient the display with DIN on the right
  when looking at the LEDs. PCB lettering may appear upside down.
- **Scrambled or mirrored letters:** Check the PCB layout/model marking.
  Most four-in-one boards are FC-16, but pin labels alone do not identify the
  matrix wiring. Other layouts require the corresponding hardware type.
- **Blank display:** Check display power, shared ground, DIN vs DOUT, the three
  signal wires, selected board/port, and successful upload.
- **Flickering or restarts:** Check supply capacity, connectors, and ground;
  use short power wires and keep brightness low while diagnosing.
- **Missing `MD_Parola.h` or `MD_MAX72xx.h`:** Install both libraries and retry.

## Verification and references

The sketch was checked against the official library APIs and wiring docs.
It compiled successfully for Arduino Uno in Arduino IDE 2.3.10 with
MD_Parola 3.7.7 and MD_MAX72XX 3.5.1: 19,876 bytes of program storage and
123 bytes of global-variable memory.
Upload and physical display behavior remain **unverified**. Change the
`YOUR NAME` placeholder before uploading.

- [MD_Parola API](https://majicdesigns.github.io/MD_Parola/class_m_d___parola.html)
- [FC-16 hardware and orientation](https://majicdesigns.github.io/MD_MAX72XX/page_f_c16.html)
- [Arduino Uno R3](https://docs.arduino.cc/hardware/uno-rev3)
- [Installing Arduino libraries](https://support.arduino.cc/hc/en-us/articles/5145457742236-Install-libraries-in-the-Arduino-IDE)
