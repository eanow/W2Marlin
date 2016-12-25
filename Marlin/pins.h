#ifndef PINS_H
#define PINS_H

#include "boards.h"

#if !MB(5DPRINT)
#define X_MS1_PIN -1
#define X_MS2_PIN -1
#define Y_MS1_PIN -1
#define Y_MS2_PIN -1
#define Z_MS1_PIN -1
#define Z_MS2_PIN -1
#define E0_MS1_PIN -1
#define E0_MS2_PIN -1
#define E1_MS1_PIN -1
#define E1_MS2_PIN -1
#define DIGIPOTSS_PIN -1
#endif



/****************************************************************************************
*
*
****************************************************************************************/

#if MB(99)
#define KNOWN_BOARD 1

#define X_STEP_PIN          2
#define X_DIR_PIN           3
#define X_ENABLE_PIN        -1
#define X_STOP_PIN          16

#define Y_STEP_PIN          5
#define Y_DIR_PIN           6
#define Y_ENABLE_PIN       -1
#define Y_STOP_PIN          67

#define Z_STEP_PIN          62
#define Z_DIR_PIN           63
#define Z_ENABLE_PIN       -1
#define Z_STOP_PIN          59

#define E0_STEP_PIN         65
#define E0_DIR_PIN          66
#define E0_ENABLE_PIN      -1

#define SDPOWER            -1
#define SDSS               53
#define LED_PIN            -1
#define FAN_PIN            -1
#define PS_ON_PIN           9
#define KILL_PIN           -1

#define HEATER_0_PIN        13
#define HEATER_1_PIN       -1
#define HEATER_2_PIN       -1
#define TEMP_0_PIN          6   // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!!
#define TEMP_1_PIN         -1   // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!!
#define TEMP_2_PIN         -1   // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!!
#define HEATER_BED_PIN      4
#define TEMP_BED_PIN       10

#endif // 99



/****************************************************************************************
* Arduino Mega pin assignment
*
****************************************************************************************/
#if IS_RAMPS || MB(3DRAG) || MB(AZTEEG_X3) || MB(AZTEEG_X3_PRO)
#define KNOWN_BOARD 1

//////////////////FIX THIS//////////////
#ifndef __AVR_ATmega1280__
 #ifndef __AVR_ATmega2560__
 #error Oops!  Make sure you have 'Arduino Mega' selected from the 'Tools -> Boards' menu.
 #endif
#endif


// uncomment one of the following lines for RAMPS v1.3 or v1.0, comment both for v1.2 or 1.1
// #define RAMPS_V_1_3
// #define RAMPS_V_1_0


#if (IS_RAMPS && !MB(RAMPS_OLD)) || MB(3DRAG) || MB(AZTEEG_X3) || MB(AZTEEG_X3_PRO)

  #define LARGE_FLASH true

  #if MB(3DRAG)
    #define X_STEP_PIN         54
    #define X_DIR_PIN          55
    #define X_ENABLE_PIN       38
    #define X_MIN_PIN           3
    #define X_MAX_PIN           -1   //2 //Max endstops default to disabled "-1", set to commented value to enable.

    #define Y_STEP_PIN         60
    #define Y_DIR_PIN          61
    #define Y_ENABLE_PIN       56
    #define Y_MIN_PIN          14
    #define Y_MAX_PIN          -1   //15

    #define Z_STEP_PIN         46
    #define Z_DIR_PIN          48
    #define Z_ENABLE_PIN       63
    #define Z_MIN_PIN          18
    #define Z_MAX_PIN          -1

    #define Y2_STEP_PIN        36
    #define Y2_DIR_PIN         34
    #define Y2_ENABLE_PIN      30

    #define Z2_STEP_PIN        36
    #define Z2_DIR_PIN         34
    #define Z2_ENABLE_PIN      30

    #define E0_STEP_PIN        26
    #define E0_DIR_PIN         28
    #define E0_ENABLE_PIN      24

    #define E1_STEP_PIN        36
    #define E1_DIR_PIN         34
    #define E1_ENABLE_PIN      30

    #define SDPOWER            -1
    #define SDSS               25//53
    #define LED_PIN            13

    #define BEEPER             33

  #else

    #define X_STEP_PIN         54
    #define X_DIR_PIN          55
    #define X_ENABLE_PIN       38
    #define X_MIN_PIN           3
    #define X_MAX_PIN           2

    #define Y_STEP_PIN         60
    #define Y_DIR_PIN          61
    #define Y_ENABLE_PIN       56
    #define Y_MIN_PIN          14
    #define Y_MAX_PIN          15

    #define Z_STEP_PIN         46
    #define Z_DIR_PIN          48
    #define Z_ENABLE_PIN       62
    #define Z_MIN_PIN          18
    #define Z_MAX_PIN          19

    #define Y2_STEP_PIN        36
    #define Y2_DIR_PIN         34
    #define Y2_ENABLE_PIN      30

    #define Z2_STEP_PIN        36
    #define Z2_DIR_PIN         34
    #define Z2_ENABLE_PIN      30

    #define E0_STEP_PIN        26
    #define E0_DIR_PIN         28
    #define E0_ENABLE_PIN      24

    #define E1_STEP_PIN        36
    #define E1_DIR_PIN         34
    #define E1_ENABLE_PIN      30

#if MB(RAMPS_13_EEB)  //FMM added for Filament Extruder
#ifdef FILAMENT_SENSOR
    //define analog pin for the filament width sensor input
    //Use the RAMPS 1.4 Analog input 5 on the AUX2 connector
      #define FILWIDTH_PIN        5
#endif
#endif


    #if MB(AZTEEG_X3_PRO)
      #define E2_STEP_PIN        23
      #define E2_DIR_PIN         25
      #define E2_ENABLE_PIN      40

      #define E3_STEP_PIN        27
      #define E3_DIR_PIN         29
      #define E3_ENABLE_PIN      41

      #define E4_STEP_PIN        43
      #define E4_DIR_PIN         37
      #define E4_ENABLE_PIN      42
    #endif

    #define SDPOWER            -1
    #define SDSS               53
    #define LED_PIN            13
  #endif

  #if MB(RAMPS_13_EFB) || MB(RAMPS_13_EFF) || MB(AZTEEG_X3) || MB(AZTEEG_X3_PRO)
    #define FAN_PIN            9 // (Sprinter config)
  #else
    #define FAN_PIN            4 // IO pin. Buffer needed
  #endif

  #if MB(3DRAG) || MB(RAMPS_13_EEF)
    #define FAN_PIN            8
  #endif

  #if MB(RAMPS_13_EFF)
    #define CONTROLLERFAN_PIN  -1 //Pin used for the fan to cool controller
  #endif

  #define PS_ON_PIN          12

  #if defined(REPRAP_DISCOUNT_SMART_CONTROLLER) || defined(G3D_PANEL)
    #define KILL_PIN           41
  #else
    #define KILL_PIN           -1
  #endif

  #if MB(RAMPS_13_EFF)
    #define HEATER_0_PIN       8
  #else
    #define HEATER_0_PIN       10   // EXTRUDER 1
  #endif

  #if MB(RAMPS_13_EFB) || MB(AZTEEG_X3)
    #define HEATER_1_PIN       -1
  #else
    #define HEATER_1_PIN       9    // EXTRUDER 2 (FAN On Sprinter)
  #endif


  #if MB(3DRAG)
    #define HEATER_0_PIN       10
    #define HEATER_1_PIN       12
    #define HEATER_2_PIN       6
  #elif MB(AZTEEG_X3_PRO)
    #define HEATER_2_PIN       16
    #define HEATER_3_PIN       17
    #define HEATER_4_PIN       4
    #define HEATER_5_PIN       5
    #define HEATER_6_PIN       6
    #define HEATER_7_PIN       11
  #else
    #define HEATER_2_PIN       -1
  #endif

  #define TEMP_0_PIN         13   // ANALOG NUMBERING
  #define TEMP_1_PIN         15   // ANALOG NUMBERING
  #if MB(AZTEEG_X3_PRO)
    #define TEMP_2_PIN         12   // ANALOG NUMBERING
    #define TEMP_3_PIN         11   // ANALOG NUMBERING
    #define TEMP_4_PIN         10   // ANALOG NUMBERING
    #define TC1                4    // ANALOG NUMBERING Thermo couple on Azteeg X3Pro
    #define TC2                5    // ANALOG NUMBERING Thermo couple on Azteeg X3Pro
  #else
    #define TEMP_2_PIN         -1   // ANALOG NUMBERING
  #endif

  #if MB(RAMPS_13_EFF) || MB(RAMPS_13_EEF)
    #define HEATER_BED_PIN     -1    // NO BED
  #else
    #if MB(3DRAG)
      #define HEATER_BED_PIN     9    // BED
    #else
      #define HEATER_BED_PIN     8    // BED
    #endif
  #endif

  #define TEMP_BED_PIN       14   // ANALOG NUMBERING

  #ifdef NUM_SERVOS
    #define SERVO0_PIN         11

    #if NUM_SERVOS > 1
      #define SERVO1_PIN         6
    #endif

    #if NUM_SERVOS > 2
      #define SERVO2_PIN         5
    #endif

    #if NUM_SERVOS > 3
      #define SERVO3_PIN         4
    #endif
  #endif

  #if MB(AZTEEG_X3_PRO)
    #define BEEPER 33
  #endif

  #ifdef TEMP_STAT_LEDS
    #if MB(AZTEEG_X3)
      #define STAT_LED_RED       6
      #define STAT_LED_BLUE     11
    #endif
  #endif

  #ifdef ULTRA_LCD

    #ifdef NEWPANEL
      #define LCD_PINS_RS 16
      #define LCD_PINS_ENABLE 17
      #define LCD_PINS_D4 23
      #define LCD_PINS_D5 25
      #define LCD_PINS_D6 27
      #define LCD_PINS_D7 29

      #ifdef REPRAP_DISCOUNT_SMART_CONTROLLER
        #define BEEPER 37

        #define BTN_EN1 33
        #define BTN_EN2 31
        #define BTN_ENC 35

        #define SDCARDDETECT 49
      #elif defined(LCD_I2C_PANELOLU2)
        #define BTN_EN1 47  //reverse if the encoder turns the wrong way.
        #define BTN_EN2 43
        #define BTN_ENC 32
        
        #define LCD_SDSS 53
        #define SDCARDDETECT -1
        #define KILL_PIN 41
      #elif defined(LCD_I2C_VIKI)
        #define BTN_EN1 22  //reverse if the encoder turns the wrong way.
        #define BTN_EN2 7
        #define BTN_ENC -1
        #define LCD_SDSS 53
        #define SDCARDDETECT 49
      #else
        //arduino pin which triggers an piezzo beeper
        #define BEEPER 33  // Beeper on AUX-4

        //buttons are directly attached using AUX-2
        #ifdef REPRAPWORLD_KEYPAD
          #define BTN_EN1 64 // encoder
          #define BTN_EN2 59 // encoder
          #define BTN_ENC 63 // enter button
          #define SHIFT_OUT 40 // shift register
          #define SHIFT_CLK 44 // shift register
          #define SHIFT_LD 42 // shift register
        #else
          #define BTN_EN1 37
          #define BTN_EN2 35
          #define BTN_ENC 31  //the click
        #endif

        #ifdef G3D_PANEL
          #define SDCARDDETECT 49
        #else
          #define SDCARDDETECT -1  // Ramps does not use this port
        #endif

      #endif

      #if MB(3DRAG)
        #define BEEPER -1

        #define LCD_PINS_RS 27
        #define LCD_PINS_ENABLE 29
        #define LCD_PINS_D4 37
        #define LCD_PINS_D5 35
        #define LCD_PINS_D6 33
        #define LCD_PINS_D7 31

       //buttons
       #define BTN_EN1 16
       #define BTN_EN2 17
       #define BTN_ENC 23 //the click

    #endif
    #else //old style panel with shift register
      //arduino pin witch triggers an piezzo beeper
      #define BEEPER 33   //No Beeper added

      //buttons are attached to a shift register
  // Not wired this yet
      //#define SHIFT_CLK 38
      //#define SHIFT_LD 42
      //#define SHIFT_OUT 40
      //#define SHIFT_EN 17

      #define LCD_PINS_RS 16
      #define LCD_PINS_ENABLE 17
      #define LCD_PINS_D4 23
      #define LCD_PINS_D5 25
      #define LCD_PINS_D6 27
      #define LCD_PINS_D7 29
    #endif
  #endif //ULTRA_LCD

#else // RAMPS_V_1_1 or RAMPS_V_1_2 as default (BOARD_RAMPS_OLD)

#define X_STEP_PIN         26
#define X_DIR_PIN          28
#define X_ENABLE_PIN       24
#define X_MIN_PIN           3
#define X_MAX_PIN          -1    //2

#define Y_STEP_PIN         38
#define Y_DIR_PIN          40
#define Y_ENABLE_PIN       36
#define Y_MIN_PIN          16
#define Y_MAX_PIN          -1    //17

#define Z_STEP_PIN         44
#define Z_DIR_PIN          46
#define Z_ENABLE_PIN       42
#define Z_MIN_PIN          18
#define Z_MAX_PIN          -1    //19

#define E0_STEP_PIN         32
#define E0_DIR_PIN          34
#define E0_ENABLE_PIN       30

#define SDPOWER            48
#define SDSS               53
#define LED_PIN            13
#define PS_ON_PIN          -1
#define KILL_PIN           -1

#ifdef RAMPS_V_1_0 // RAMPS_V_1_0
  #define HEATER_0_PIN     12    // RAMPS 1.0
  #define HEATER_BED_PIN   -1    // RAMPS 1.0
  #define FAN_PIN          11    // RAMPS 1.0
#else // RAMPS_V_1_1 or RAMPS_V_1_2
  #define HEATER_0_PIN     10    // RAMPS 1.1
  #define HEATER_BED_PIN    8    // RAMPS 1.1
  #define FAN_PIN           9    // RAMPS 1.1
#endif
#define HEATER_1_PIN        -1
#define HEATER_2_PIN        -1
#define TEMP_0_PIN          2    // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!!
#define TEMP_1_PIN          -1
#define TEMP_2_PIN          -1
#define TEMP_BED_PIN        1    // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!!

#endif // RAMPS_13_EFB || RAMPS_13_EEB || RAMPS_13_EFF || 3DRAG

// SPI for Max6675 Thermocouple

#ifndef SDSUPPORT
// these pins are defined in the SD library if building with SD support
  #define SCK_PIN          52
  #define MISO_PIN         50
  #define MOSI_PIN         51
  #define MAX6675_SS       66// Do not use pin 53 if there is even the remote possibility of using Dsplay/SD card
#else
  #define MAX6675_SS       66// Do not use pin 49 as this is tied to the switch inside the SD card socket to detect if there is an SD card present
#endif

#endif // RAMPS_OLD || RAMPS_13_EFB || RAMPS_13_EEB || RAMPS_13_EFF || 3DRAG


/****************************************************************************************
* Sanguinololu pin assignment
*
****************************************************************************************/
#if MB(STB_11)
#define STB
#endif
#if MB(MELZI) || MB(MELZI_1284)
#define MELZI
#endif
#if MB(AZTEEG_X1)
#define AZTEEG_X1
#endif
#if MB(SANGUINOLOLU_12) || MB(MELZI) || MB(STB_11) || MB(AZTEEG_X1) || MB(MELZI_1284)
#undef MOTHERBOARD
#define MOTHERBOARD BOARD_SANGUINOLOLU_11
#define SANGUINOLOLU_V_1_2

#if defined(__AVR_ATmega1284P__)
  #define LARGE_FLASH true
#endif
#endif

#if MB(SANGUINOLOLU_11)
#define KNOWN_BOARD 1
#ifndef __AVR_ATmega644P__
#ifndef __AVR_ATmega1284P__
#error Oops!  Make sure you have 'Sanguino' selected from the 'Tools -> Boards' menu.
#endif
#endif

#define X_STEP_PIN         15
#define X_DIR_PIN          21
#define X_STOP_PIN         18

#define Y_STEP_PIN         22
#define Y_DIR_PIN          23
#define Y_STOP_PIN         19

#define Z_STEP_PIN         3
#define Z_DIR_PIN          2
#define Z_STOP_PIN         20

#define E0_STEP_PIN         1
#define E0_DIR_PIN          0

#define LED_PIN            -1

#define FAN_PIN            -1
 #if FAN_PIN == 12 || FAN_PIN ==13
  #define FAN_SOFT_PWM
#endif

#ifdef MELZI
 #define LED_PIN            27 /* On some broken versions of the Sanguino libraries the pin definitions are wrong, which then needs LED_PIN as pin 28. But you better upgrade your Sanguino libraries! See #368. */
 #define FAN_PIN            4 // Works for Panelolu2 too
#endif

#ifdef STB
 #define FAN_PIN            4
  //  Uncomment this if you have the first generation (V1.10) of STBs board
 #define LCD_PIN_BL         17 // LCD backlight LED
#endif

#ifdef AZTEEG_X1
 #define FAN_PIN            4
#endif

#ifdef NUM_SERVOS
  #define SERVO0_PIN          -1

  #if NUM_SERVOS > 1
    #define SERVO1_PIN        -1
  #endif

  #if NUM_SERVOS > 2
    #define SERVO2_PIN        -1
  #endif

  #if NUM_SERVOS > 3
    #define SERVO3_PIN        -1
  #endif
#endif

#define PS_ON_PIN          -1
#define KILL_PIN           -1

#define HEATER_0_PIN       13 // (extruder)
#define HEATER_1_PIN       -1
#define HEATER_2_PIN       -1

#ifdef SANGUINOLOLU_V_1_2

 #define HEATER_BED_PIN     12 // (bed)
 #define X_ENABLE_PIN       14
 #define Y_ENABLE_PIN       14
 #define Z_ENABLE_PIN       26
 #define E0_ENABLE_PIN      14

 #ifdef LCD_I2C_PANELOLU2
   #define FAN_PIN          4 // Uses Transistor1 (PWM) on Panelolu2's Sanguino Adapter Board to drive the fan
 #endif

#else

#define HEATER_BED_PIN      14  // (bed)
#define X_ENABLE_PIN       -1
#define Y_ENABLE_PIN       -1
#define Z_ENABLE_PIN       -1
#define E0_ENABLE_PIN      -1

#endif

#define TEMP_0_PIN          7   // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!! (pin 33 extruder)
#define TEMP_1_PIN         -1
#define TEMP_2_PIN         -1
#define TEMP_BED_PIN        6   // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!! (pin 34 bed)
#define SDPOWER            -1
#define SDSS               31

/* On some broken versions of the Sanguino libraries the pin definitions are wrong, which then needs SDSS as pin 24. But you better upgrade your Sanguino libraries! See #368. */
//#define SDSS               24

 #ifdef ULTRA_LCD
   #ifdef NEWPANEL
     //we have no buzzer installed
     #define BEEPER -1
     //LCD Pins
     //rcf- removed dogm
     //The encoder and click button
     #define BTN_EN1 11
     #define BTN_EN2 10
     #ifdef LCD_I2C_PANELOLU2
       #ifdef MELZI
         #define BTN_ENC 29 //the click switch
         #define LCD_SDSS 30 //to use the SD card reader on the Panelolu2 rather than the melzi board
       #else
         #define BTN_ENC 30 //the click switch
       #endif
     #else
       #define BTN_ENC 16  //the click switch
     #endif //Panelolu2
     //not connected to a pin
     #define SDCARDDETECT -1

   #endif //Newpanel
 #endif //Ultipanel

 #ifdef MAKRPANEL
     #define BEEPER 29
     // Pins for DOGM SPI LCD Support
     #define DOGLCD_A0  30
     #define DOGLCD_CS  17
     #define LCD_PIN_BL 28  // backlight LED on PA3
     // GLCD features
     #define LCD_CONTRAST 1
     // Uncomment screen orientation
     #define LCD_SCREEN_ROT_0
       // #define LCD_SCREEN_ROT_90
       // #define LCD_SCREEN_ROT_180
       // #define LCD_SCREEN_ROT_270
     //The encoder and click button
     #define BTN_EN1 11
     #define BTN_EN2 10
     #define BTN_ENC 16  //the click switch
     //not connected to a pin
     #define SDCARDDETECT -1
 #endif //Makrpanel

#endif // SANGUINOLOLU_11


/****************************************************************************************
* Teensylu 0.7 / Printrboard pin assignments (AT90USB1286)
* Requires the Teensyduino software with Teensy++ 2.0 selected in Arduino IDE!
  http://www.pjrc.com/teensy/teensyduino.html
* See http://reprap.org/wiki/Printrboard for more info
****************************************************************************************/
#if MB(TEENSYLU) || MB(PRINTRBOARD)
#define KNOWN_BOARD 1
#define AT90USB 1286  // Disable MarlinSerial etc.

#ifndef __AVR_AT90USB1286__
#error Oops!  Make sure you have 'Teensy++ 2.0' selected from the 'Tools -> Boards' menu.
#endif

#ifdef AT90USBxx_TEENSYPP_ASSIGNMENTS  // use Teensyduino Teensy++2.0 pin assignments instead of Marlin traditional.
#error These Teensylu/Printrboard assignments depend on traditional Marlin assignments, not AT90USBxx_TEENSYPP_ASSIGNMENTS in fastio.h
#endif

#define LARGE_FLASH        true

#define X_STEP_PIN          0
#define X_DIR_PIN           1
#define X_ENABLE_PIN       39

#define Y_STEP_PIN          2
#define Y_DIR_PIN           3
#define Y_ENABLE_PIN       38

#define Z_STEP_PIN          4
#define Z_DIR_PIN           5
#define Z_ENABLE_PIN       23

#define E0_STEP_PIN         6
#define E0_DIR_PIN          7
#define E0_ENABLE_PIN      19

#define HEATER_0_PIN       21  // Extruder
#define HEATER_1_PIN       -1
#define HEATER_2_PIN       -1
#define HEATER_BED_PIN     20  // Bed
#define FAN_PIN            22  // Fan
// You may need to change FAN_PIN to 16 because Marlin isn't using fastio.h
// for the fan and Teensyduino uses a different pin mapping.

#if MB(TEENSYLU)  // Teensylu
  #define X_STOP_PIN         13
  #define Y_STOP_PIN         14
  #define Z_STOP_PIN         15
  #define TEMP_0_PIN          7  // Extruder / Analog pin numbering
  #define TEMP_BED_PIN        6  // Bed / Analog pin numbering
#else  // Printrboard
  #define X_STOP_PIN         35
  #define Y_STOP_PIN          8
  #define Z_STOP_PIN         36
  #define TEMP_0_PIN          1  // Extruder / Analog pin numbering
  #define TEMP_BED_PIN        0  // Bed / Analog pin numbering
  #ifdef FILAMENT_SENSOR
   #define FILWIDTH_PIN        2
  #endif //FILAMENT_SENSOR
#endif

#define TEMP_1_PIN         -1
#define TEMP_2_PIN         -1

#define SDPOWER            -1
#define SDSS                8
#define LED_PIN            -1
#define PS_ON_PIN          -1
#define KILL_PIN           -1
#define ALARM_PIN          -1

#ifndef SDSUPPORT
// these pins are defined in the SD library if building with SD support
  #define SCK_PIN           9
  #define MISO_PIN         11
  #define MOSI_PIN         10
#endif

#endif // TEENSYLU || PRINTRBOARD


#if MB(OMCA_A) //Alpha OMCA board
#define KNOWN_BOARD 1

#ifndef __AVR_ATmega644__
#error Oops!  Make sure you have 'SanguinoA' selected from the 'Tools -> Boards' menu.
#endif

#define X_STEP_PIN         21
#define X_DIR_PIN          20
#define X_ENABLE_PIN       24
#define X_STOP_PIN         0

#define Y_STEP_PIN         23
#define Y_DIR_PIN          22
#define Y_ENABLE_PIN       24
#define Y_STOP_PIN         1

#define Z_STEP_PIN         26
#define Z_DIR_PIN          25
#define Z_ENABLE_PIN       24
#define Z_STOP_PIN         2

#define E0_STEP_PIN         28
#define E0_DIR_PIN          27
#define E0_ENABLE_PIN       24

#define E1_STEP_PIN         -1 // 19
#define E1_DIR_PIN          -1 // 18
#define E1_ENABLE_PIN       24

#define E2_STEP_PIN         -1 // 17
#define E2_DIR_PIN          -1 // 16
#define E2_ENABLE_PIN       24

#define SDPOWER            -1
#define SDSS               11
#define SDCARDDETECT       -1 // 10 optional also used as mode pin
#define LED_PIN            -1
#define FAN_PIN            3
#define PS_ON_PIN          -1
#define KILL_PIN           -1

#define HEATER_0_PIN       4
#define HEATER_1_PIN       -1 // 12
#define HEATER_2_PIN       -1 // 13
#define TEMP_0_PIN          0 //D27   // MUST USE ANALOG INPUT NUMBERING NOT DIGITAL OUTPUT NUMBERING!!!!!!!!!
#define TEMP_1_PIN         -1 // 1
#define TEMP_2_PIN         -1 // 2
#define HEATER_BED_PIN     -1 // 14/15
#define TEMP_BED_PIN       -1 // 1,2 or I2C
/*  Unused (1) (2) (3) 4 5 6 7 8 9 10 11 12 13 (14) (15) (16) 17 (18) (19) (20) (21) (22) (23) 24 (25) (26) (27) 28 (29) (30) (31)  */

#endif // OMCA_A

#if MB(OMCA)  // Final OMCA board -- REF http://sanguino.cc/hardware
#define KNOWN_BOARD 1

#if !defined(__AVR_ATmega644P__) && !defined(__AVR_ATmega644__)
#error Oops!  Make sure you have 'Sanguino' selected from the 'Tools -> Boards' menu. (Final OMCA board)
#endif

#define X_STEP_PIN         26
#define X_DIR_PIN          25
#define X_ENABLE_PIN       10
#define X_STOP_PIN         0

#define Y_STEP_PIN         28
#define Y_DIR_PIN          27
#define Y_ENABLE_PIN       10
#define Y_STOP_PIN         1

#define Z_STEP_PIN         23
#define Z_DIR_PIN          22
#define Z_ENABLE_PIN       10
#define Z_STOP_PIN         2

#define E0_STEP_PIN         24
#define E0_DIR_PIN          21
#define E0_ENABLE_PIN       10

/* future proofing */
#define __FS  20
#define __FD  19
#define __GS  18
#define __GD  13

#define UNUSED_PWM           14 /* PWM on LEFT connector */

#define E1_STEP_PIN         -1 // 21
#define E1_DIR_PIN          -1 // 20
#define E1_ENABLE_PIN       -1 // 19

#define E2_STEP_PIN         -1 // 21
#define E2_DIR_PIN          -1 // 20
#define E2_ENABLE_PIN       -1 // 18

#define SDPOWER            -1
#define SDSS               11
#define SDCARDDETECT       -1 // 10 optional also used as mode pin
#define LED_PIN            -1
#define FAN_PIN            14 /* PWM on MIDDLE connector */
#define PS_ON_PIN          -1
#define KILL_PIN           -1

#define HEATER_0_PIN        3 /*DONE PWM on RIGHT connector */
#define HEATER_1_PIN       -1
#define HEATER_2_PIN       -1
#define HEATER_1_PIN       -1
#define HEATER_2_PIN       -1
#define TEMP_0_PIN          0 // ANALOG INPUT NUMBERING
#define TEMP_1_PIN          1 // ANALOG
#define TEMP_2_PIN         -1 // 2
#define HEATER_BED_PIN      4
#define TEMP_BED_PIN        2 // 1,2 or I2C

#define I2C_SCL       16
#define I2C_SDA       17

#endif // OMCA



/*************************************
 * PICA Arduino shield configuration mjrice
 ************************************* */
#if MB(PICA) || MB(PICA_REVC)
 #define KNOWN_BOARD 1
 #define LARGE_FLASH true

 #define X_DIR_PIN         54
 #define X_STEP_PIN        55
 #define Y_DIR_PIN         56
 #define Y_STEP_PIN        57
 #define Z_DIR_PIN         58
 #define Z_STEP_PIN        59
 #define X_ENABLE_PIN      60     
 #define Y_ENABLE_PIN      61
 #define Z_ENABLE_PIN      62
//rcf- disabling max endstops
 #define X_MIN_PIN         14
 //#define X_MAX_PIN         15

 #define Y_MIN_PIN          16
 //#define Y_MAX_PIN          17

 #define Z_MIN_PIN          23
 //#define Z_MAX_PIN          22

 #define E0_STEP_PIN         67 
 #define E0_DIR_PIN          24
 #define E0_ENABLE_PIN       26

 #define SDPOWER            -1
 #define LED_PIN            -1 
 #define PS_ON_PIN          -1
 #define KILL_PIN           -1

 #define SSR_PIN            6
 #define HEATER_BED_PIN     8 // heat bed
 
#if MB(PICA_REVC)
 #define HEATER_0_PIN       10 // extruder 
 #define HEATER_1_PIN       2 // second extruder
 #define FAN_PIN            9
 #define FAN_2_PIN          7
#else
 #define HEATER_0_PIN       9 // extruder 
 #define HEATER_1_PIN       10 // second extruder
 #define FAN_PIN            11
 #define FAN_2_PIN          12
#endif

 #define TEMP_0_PIN         9   // ANALOG NUMBERING
 #define TEMP_1_PIN         10
 #define TEMP_BED_PIN       10
 #define TEMP_2_PIN         11
 #define TEMP_3_PIN         12

 // LCD interface pins
 #define LCD_PINS_RS 33
 #define LCD_PINS_ENABLE 30
 #define LCD_PINS_D4 35
 #define LCD_PINS_D5 32
 #define LCD_PINS_D6 37
 #define LCD_PINS_D7 36

 #define BTN_EN1 47
 #define BTN_EN2 48
 #define BTN_ENC 31  //the click 

 #define BLEN_C 2
 #define BLEN_B 1
 #define BLEN_A 0

 #define SDCARDDETECT 49
 #define BEEPER       29
 #define SDSS         53
 
 //encoder rotation values
 #define encrot0 0
 #define encrot1 2
 #define encrot2 3
 #define encrot3 1
 
#endif // PICA

// -----------------------------------------------------------------------------
// YOU MUST USE SOFTWARE PWM FOR FANS IF THEY ARE ON PINS 11, 12, or 13
// This is because the Mega uses timer1 to support hardware pwm on those pins,
// and Marlin is using timer1 for stepper motor interrupts.
#if FAN_PIN == 11 || FAN_PIN == 12 || FAN_PIN ==13
  #define FAN_SOFT_PWM
#endif
// -----------------------------------------------------------------------------

#ifndef KNOWN_BOARD
#error Unknown MOTHERBOARD value in configuration.h
#endif

//List of pins which to ignore when asked to change by gcode, 0 and 1 are RX and TX, do not mess with those!
#define _E0_PINS E0_STEP_PIN, E0_DIR_PIN, E0_ENABLE_PIN, HEATER_0_PIN,
#if EXTRUDERS > 1
  #define _E1_PINS E1_STEP_PIN, E1_DIR_PIN, E1_ENABLE_PIN, HEATER_1_PIN,
#else
  #define _E1_PINS
#endif
#if EXTRUDERS > 2
  #define _E2_PINS E2_STEP_PIN, E2_DIR_PIN, E2_ENABLE_PIN, HEATER_2_PIN,
#else
  #define _E2_PINS
#endif

#ifdef X_STOP_PIN
  #if X_HOME_DIR < 0
    #define X_MIN_PIN X_STOP_PIN
    #define X_MAX_PIN -1
  #else
    #define X_MIN_PIN -1
    #define X_MAX_PIN X_STOP_PIN
  #endif
#endif

#ifdef Y_STOP_PIN
  #if Y_HOME_DIR < 0
    #define Y_MIN_PIN Y_STOP_PIN
    #define Y_MAX_PIN -1
  #else
    #define Y_MIN_PIN -1
    #define Y_MAX_PIN Y_STOP_PIN
  #endif
#endif

#ifdef Z_STOP_PIN
  #if Z_HOME_DIR < 0
    #define Z_MIN_PIN Z_STOP_PIN
    #define Z_MAX_PIN -1
  #else
    #define Z_MIN_PIN -1
    #define Z_MAX_PIN Z_STOP_PIN
  #endif
#endif

#ifdef DISABLE_MAX_ENDSTOPS
#define X_MAX_PIN          -1
#define Y_MAX_PIN          -1
#define Z_MAX_PIN          -1
#endif

#ifdef DISABLE_MIN_ENDSTOPS
#define X_MIN_PIN          -1
#define Y_MIN_PIN          -1
#define Z_MIN_PIN          -1
#endif

#define SENSITIVE_PINS {0, 1, X_STEP_PIN, X_DIR_PIN, X_ENABLE_PIN, X_MIN_PIN, X_MAX_PIN, Y_STEP_PIN, Y_DIR_PIN, \
                        Y_ENABLE_PIN, Y_MIN_PIN, Y_MAX_PIN, Z_STEP_PIN, Z_DIR_PIN, Z_ENABLE_PIN, Z_MIN_PIN, Z_MAX_PIN, PS_ON_PIN, \
                        HEATER_BED_PIN, FAN_PIN, _E0_PINS _E1_PINS _E2_PINS             \
                        analogInputToDigitalPin(TEMP_0_PIN), analogInputToDigitalPin(TEMP_1_PIN), analogInputToDigitalPin(TEMP_2_PIN), analogInputToDigitalPin(TEMP_BED_PIN) }

#endif //__PINS_H

