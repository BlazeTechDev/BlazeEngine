#pragma once

#define BLZ_KEY_UNKNOWN            -1

/* Printable keys */
#define BLZ_KEY_SPACE              32
#define BLZ_KEY_APOSTROPHE         39  /* ' */
#define BLZ_KEY_COMMA              44  /* , */
#define BLZ_KEY_MINUS              45  /* - */
#define BLZ_KEY_PERIOD             46  /* . */
#define BLZ_KEY_SLASH              47  /* / */
#define BLZ_KEY_0                  48
#define BLZ_KEY_1                  49
#define BLZ_KEY_2                  50
#define BLZ_KEY_3                  51
#define BLZ_KEY_4                  52
#define BLZ_KEY_5                  53
#define BLZ_KEY_6                  54
#define BLZ_KEY_7                  55
#define BLZ_KEY_8                  56
#define BLZ_KEY_9                  57
#define BLZ_KEY_SEMICOLON          59  /* ; */
#define BLZ_KEY_EQUAL              61  /* = */
#define BLZ_KEY_A                  65
#define BLZ_KEY_B                  66
#define BLZ_KEY_C                  67
#define BLZ_KEY_D                  68
#define BLZ_KEY_E                  69
#define BLZ_KEY_F                  70
#define BLZ_KEY_G                  71
#define BLZ_KEY_H                  72
#define BLZ_KEY_I                  73
#define BLZ_KEY_J                  74
#define BLZ_KEY_K                  75
#define BLZ_KEY_L                  76
#define BLZ_KEY_M                  77
#define BLZ_KEY_N                  78
#define BLZ_KEY_O                  79
#define BLZ_KEY_P                  80
#define BLZ_KEY_Q                  81
#define BLZ_KEY_R                  82
#define BLZ_KEY_S                  83
#define BLZ_KEY_T                  84
#define BLZ_KEY_U                  85
#define BLZ_KEY_V                  86
#define BLZ_KEY_W                  87
#define BLZ_KEY_X                  88
#define BLZ_KEY_Y                  89
#define BLZ_KEY_Z                  90
#define BLZ_KEY_LEFT_BRACKET       91  /* [ */
#define BLZ_KEY_BACKSLASH          92  /* \ */
#define BLZ_KEY_RIGHT_BRACKET      93  /* ] */
#define BLZ_KEY_GRAVE_ACCENT       96  /* ` */
#define BLZ_KEY_WORLD_1            161 /* non-US #1 */
#define BLZ_KEY_WORLD_2            162 /* non-US #2 */

#define BLZ_KEY_ESCAPE             256
#define BLZ_KEY_ENTER              257
#define BLZ_KEY_TAB                258
#define BLZ_KEY_BACKSPACE          259
#define BLZ_KEY_INSERT             260
#define BLZ_KEY_DELETE             261
#define BLZ_KEY_RIGHT              262
#define BLZ_KEY_LEFT               263
#define BLZ_KEY_DOWN               264
#define BLZ_KEY_UP                 265
#define BLZ_KEY_PAGE_UP            266
#define BLZ_KEY_PAGE_DOWN          267
#define BLZ_KEY_HOME               268
#define BLZ_KEY_END                269
#define BLZ_KEY_CAPS_LOCK          280
#define BLZ_KEY_SCROLL_LOCK        281
#define BLZ_KEY_NUM_LOCK           282
#define BLZ_KEY_PRINT_SCREEN       283
#define BLZ_KEY_PAUSE              284
#define BLZ_KEY_F1                 290
#define BLZ_KEY_F2                 291
#define BLZ_KEY_F3                 292
#define BLZ_KEY_F4                 293
#define BLZ_KEY_F5                 294
#define BLZ_KEY_F6                 295
#define BLZ_KEY_F7                 296
#define BLZ_KEY_F8                 297
#define BLZ_KEY_F9                 298
#define BLZ_KEY_F10                299
#define BLZ_KEY_F11                300
#define BLZ_KEY_F12                301
#define BLZ_KEY_F13                302
#define BLZ_KEY_F14                303
#define BLZ_KEY_F15                304
#define BLZ_KEY_F16                305
#define BLZ_KEY_F17                306
#define BLZ_KEY_F18                307
#define BLZ_KEY_F19                308
#define BLZ_KEY_F20                309
#define BLZ_KEY_F21                310
#define BLZ_KEY_F22                311
#define BLZ_KEY_F23                312
#define BLZ_KEY_F24                313
#define BLZ_KEY_F25                314
#define BLZ_KEY_KP_0               320
#define BLZ_KEY_KP_1               321
#define BLZ_KEY_KP_2               322
#define BLZ_KEY_KP_3               323
#define BLZ_KEY_KP_4               324
#define BLZ_KEY_KP_5               325
#define BLZ_KEY_KP_6               326
#define BLZ_KEY_KP_7               327
#define BLZ_KEY_KP_8               328
#define BLZ_KEY_KP_9               329
#define BLZ_KEY_KP_DECIMAL         330
#define BLZ_KEY_KP_DIVIDE          331
#define BLZ_KEY_KP_MULTIPLY        332
#define BLZ_KEY_KP_SUBTRACT        333
#define BLZ_KEY_KP_ADD             334
#define BLZ_KEY_KP_ENTER           335
#define BLZ_KEY_KP_EQUAL           336
#define BLZ_KEY_LEFT_SHIFT         340
#define BLZ_KEY_LEFT_CONTROL       341
#define BLZ_KEY_LEFT_ALT           342
#define BLZ_KEY_LEFT_SUPER         343
#define BLZ_KEY_RIGHT_SHIFT        344
#define BLZ_KEY_RIGHT_CONTROL      345
#define BLZ_KEY_RIGHT_ALT          346
#define BLZ_KEY_RIGHT_SUPER        347
#define BLZ_KEY_MENU               348

#define BLZ_KEY_LAST               BLZ_KEY_MENU

#define BLZ_MOD_SHIFT           0x0001

#define BLZ_MOD_CONTROL         0x0002
#define BLZ_MOD_ALT             0x0004
#define BLZ_MOD_SUPER           0x0008
#define BLZ_MOD_CAPS_LOCK       0x0010
#define BLZ_MOD_NUM_LOCK        0x0020

#define BLZ_MOUSE_BUTTON_1         0
#define BLZ_MOUSE_BUTTON_2         1
#define BLZ_MOUSE_BUTTON_3         2
#define BLZ_MOUSE_BUTTON_4         3
#define BLZ_MOUSE_BUTTON_5         4
#define BLZ_MOUSE_BUTTON_6         5
#define BLZ_MOUSE_BUTTON_7         6
#define BLZ_MOUSE_BUTTON_8         7
#define BLZ_MOUSE_BUTTON_LAST      BLZ_MOUSE_BUTTON_8
#define BLZ_MOUSE_BUTTON_LEFT      BLZ_MOUSE_BUTTON_1
#define BLZ_MOUSE_BUTTON_RIGHT     BLZ_MOUSE_BUTTON_2
#define BLZ_MOUSE_BUTTON_MIDDLE    BLZ_MOUSE_BUTTON_3

#define BLZ_JOYSTICK_1             0
#define BLZ_JOYSTICK_2             1
#define BLZ_JOYSTICK_3             2
#define BLZ_JOYSTICK_4             3
#define BLZ_JOYSTICK_5             4
#define BLZ_JOYSTICK_6             5
#define BLZ_JOYSTICK_7             6
#define BLZ_JOYSTICK_8             7
#define BLZ_JOYSTICK_9             8
#define BLZ_JOYSTICK_10            9
#define BLZ_JOYSTICK_11            10
#define BLZ_JOYSTICK_12            11
#define BLZ_JOYSTICK_13            12
#define BLZ_JOYSTICK_14            13
#define BLZ_JOYSTICK_15            14
#define BLZ_JOYSTICK_16            15
#define BLZ_JOYSTICK_LAST          BLZ_JOYSTICK_16

#define BLZ_GAMEPAD_BUTTON_A               0
#define BLZ_GAMEPAD_BUTTON_B               1
#define BLZ_GAMEPAD_BUTTON_X               2
#define BLZ_GAMEPAD_BUTTON_Y               3
#define BLZ_GAMEPAD_BUTTON_LEFT_BUMPER     4
#define BLZ_GAMEPAD_BUTTON_RIGHT_BUMPER    5
#define BLZ_GAMEPAD_BUTTON_BACK            6
#define BLZ_GAMEPAD_BUTTON_START           7
#define BLZ_GAMEPAD_BUTTON_GUIDE           8
#define BLZ_GAMEPAD_BUTTON_LEFT_THUMB      9
#define BLZ_GAMEPAD_BUTTON_RIGHT_THUMB     10
#define BLZ_GAMEPAD_BUTTON_DPAD_UP         11
#define BLZ_GAMEPAD_BUTTON_DPAD_RIGHT      12
#define BLZ_GAMEPAD_BUTTON_DPAD_DOWN       13
#define BLZ_GAMEPAD_BUTTON_DPAD_LEFT       14
#define BLZ_GAMEPAD_BUTTON_LAST            BLZ_GAMEPAD_BUTTON_DPAD_LEFT

#define BLZ_GAMEPAD_BUTTON_CROSS       BLZ_GAMEPAD_BUTTON_A
#define BLZ_GAMEPAD_BUTTON_CIRCLE      BLZ_GAMEPAD_BUTTON_B
#define BLZ_GAMEPAD_BUTTON_SQUARE      BLZ_GAMEPAD_BUTTON_X
#define BLZ_GAMEPAD_BUTTON_TRIANGLE    BLZ_GAMEPAD_BUTTON_Y

#define BLZ_GAMEPAD_AXIS_LEFT_X        0
#define BLZ_GAMEPAD_AXIS_LEFT_Y        1
#define BLZ_GAMEPAD_AXIS_RIGHT_X       2
#define BLZ_GAMEPAD_AXIS_RIGHT_Y       3
#define BLZ_GAMEPAD_AXIS_LEFT_TRIGGER  4
#define BLZ_GAMEPAD_AXIS_RIGHT_TRIGGER 5
#define BLZ_GAMEPAD_AXIS_LAST          BLZ_GAMEPAD_AXIS_RIGHT_TRIGGER