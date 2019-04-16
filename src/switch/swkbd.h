#ifndef _SWITCH_SWKBD
#define _SWITCH_SWKBD

#include <switch/applets/swkbd.h>

SwkbdInline switch_kbdinline;
SwkbdAppearArg switch_appearArg;
Result switch_kdbresult;
SwkbdState switch_kbdstate;

void Switch_Keyboard_Init();
void Switch_Keyboard_Update();
void Switch_Keyboard_Open();
void Switch_Keyboard_Close();

#endif