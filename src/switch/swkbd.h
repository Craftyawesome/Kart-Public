#ifndef _SWITCH_SWKBD
#define _SWITCH_SWKBD

#include <switch/applets/swkbd.h>

// Borrowed from https://github.com/joel16/NX-Shell/ (/source/keyboard.c)

char *swkbdResult;

// Empty strings are invalid.
SwkbdTextCheckResult Switch_Keyboard_ValidateText(char *string, size_t size);
void Switch_Keyboard_GetText(const char *guide_text, const char *initial_text);

#endif