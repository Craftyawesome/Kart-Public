// Borrowed from https://github.com/joel16/NX-Shell/ (/source/keyboard.c)

#include "../p_local.h"
#include "../s_sound.h"

#include "swkbd.h"
#include <switch/applets/swkbd.h>
#include <switch/services/hid.h>

// Empty strings are invalid.
SwkbdTextCheckResult Switch_Keyboard_ValidateText(char *string, size_t size) {
	if (strcmp(string, "") == 0) {
		strncpy(string, "The name cannot be empty.", size); 
		return SwkbdTextCheckResult_Bad;
	}

	return SwkbdTextCheckResult_OK;
}

void Switch_Keyboard_GetText(const char *guide_text, const char *initial_text) {
	// Check if this enter press is coming from an actual keyboard
	if (hidKeyboardHeld(KBD_ENTER)) {
		swkbdResult = strdup(initial_text);
		return;
	}

	// Can't bring up the software keyboard when you can't pause the game
	if (!P_CanAutoPause()) {
		S_StartSound(NULL, sfx_s26d); // Error sound
		swkbdResult = "";
		return;
	}

	Result ret = 0;
	SwkbdConfig swkbd;
	static char input_string[256];

	if (R_FAILED(ret = swkbdCreate(&swkbd, 0))) {
		swkbdClose(&swkbd);
		swkbdResult = "";
	}

	swkbdConfigMakePresetDefault(&swkbd);

	if (strlen(guide_text) != 0)
		swkbdConfigSetGuideText(&swkbd, guide_text);

	if (strlen(initial_text) != 0)
		swkbdConfigSetInitialText(&swkbd, initial_text);

	swkbdConfigSetTextCheckCallback(&swkbd, Switch_Keyboard_ValidateText);

	if (R_FAILED(ret = swkbdShow(&swkbd, input_string, sizeof(input_string)))) {
		swkbdClose(&swkbd);
		swkbdResult = "";
	}

	swkbdClose(&swkbd);
	swkbdResult = input_string;
}