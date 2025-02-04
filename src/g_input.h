// SONIC ROBO BLAST 2
//-----------------------------------------------------------------------------
// Copyright (C) 1998-2000 by DooM Legacy Team.
// Copyright (C) 1999-2018 by Sonic Team Junior.
//
// This program is free software distributed under the
// terms of the GNU General Public License, version 2.
// See the 'LICENSE' file for more details.
//-----------------------------------------------------------------------------
/// \file  g_input.h
/// \brief handle mouse/keyboard/joystick inputs,
///        maps inputs to game controls (forward, spin, jump...)

#ifndef __G_INPUT__
#define __G_INPUT__

#include "d_event.h"
#include "keys.h"
#include "command.h"

// number of total 'button' inputs, include keyboard keys, plus virtual
// keys (mousebuttons and joybuttons becomes keys)
#define NUMKEYS 256


#ifdef _arch_dreamcast
#define MOUSEBUTTONS 5
#define JOYBUTTONS   8 //  8 buttons
#define JOYHATS      2  // 2 hats
#define JOYAXISSET   3  // 3 Sets of 2 axises
#elif defined (_XBOX)
#define MOUSEBUTTONS 5
#define JOYBUTTONS   12 // 12 buttons
#define JOYHATS      1  // 1 hat
#define JOYAXISSET   2  // 2 Sets of 2 axises
#elif defined (_PSP)
#define MOUSEBUTTONS 3
#define JOYBUTTONS   14 // 10 buttons
#define JOYHATS      1  // 1 hat
#define JOYAXISSET   1  // 1 Set of 2 axises
#elif defined (_WII)
#define MOUSEBUTTONS 3
#define JOYBUTTONS   20 // 20 buttons
#define JOYHATS      1  // 1 hat
#define JOYAXISSET   5  // 5 Sets of 2 axises
#elif defined (__SWITCH__)
#define MOUSEBUTTONS 3
#define JOYBUTTONS   11 // 11 buttons
#define JOYHATS      1  // 1 hat
#define JOYAXISSET   3
#else
#define MOUSEBUTTONS 8
#define JOYBUTTONS   32 // 32 buttons
#define JOYHATS      4  // 4 hats
#define JOYAXISSET   4  // 4 Sets of 2 axises
#endif

//
// mouse and joystick buttons are handled as 'virtual' keys
//
typedef enum
{
	KEY_MOUSE1 = NUMKEYS,
	KEY_JOY1 = KEY_MOUSE1 + MOUSEBUTTONS,
	KEY_HAT1 = KEY_JOY1 + JOYBUTTONS,

	KEY_DBLMOUSE1 =KEY_HAT1 + JOYHATS*4, // double clicks
	KEY_DBLJOY1 = KEY_DBLMOUSE1 + MOUSEBUTTONS,
	KEY_DBLHAT1 = KEY_DBLJOY1 + JOYBUTTONS,

	KEY_2MOUSE1 = KEY_DBLHAT1 + JOYHATS*4,
	KEY_2JOY1 = KEY_2MOUSE1 + MOUSEBUTTONS,
	KEY_2HAT1 = KEY_2JOY1 + JOYBUTTONS,

	KEY_DBL2MOUSE1 = KEY_2HAT1 + JOYHATS*4,
	KEY_DBL2JOY1 = KEY_DBL2MOUSE1 + MOUSEBUTTONS,
	KEY_DBL2HAT1 = KEY_DBL2JOY1 + JOYBUTTONS,

	KEY_3JOY1 = KEY_DBL2HAT1 + JOYHATS*4,
	KEY_3HAT1 = KEY_3JOY1 + JOYBUTTONS,

	KEY_DBL3JOY1 = KEY_3HAT1 + JOYHATS*4,
	KEY_DBL3HAT1 = KEY_DBL3JOY1 + JOYBUTTONS,

	KEY_4JOY1 = KEY_DBL3HAT1 + JOYHATS*4,
	KEY_4HAT1 = KEY_4JOY1 + JOYBUTTONS,

	KEY_DBL4JOY1 = KEY_4HAT1 + JOYHATS*4,
	KEY_DBL4HAT1 = KEY_DBL4JOY1 + JOYBUTTONS,

	KEY_MOUSEWHEELUP = KEY_DBL4HAT1 + JOYHATS*4,
	KEY_MOUSEWHEELDOWN = KEY_MOUSEWHEELUP + 1,
	KEY_2MOUSEWHEELUP = KEY_MOUSEWHEELDOWN + 1,
	KEY_2MOUSEWHEELDOWN = KEY_2MOUSEWHEELUP + 1,

	NUMINPUTS = KEY_2MOUSEWHEELDOWN + 1,
} key_input_e;

typedef enum
{
	gc_null = 0, // a key/button mapped to gc_null has no effect
	gc_aimforward,
	gc_aimbackward,
	gc_turnleft,
	gc_turnright,
	gc_accelerate,
	gc_drift,
	gc_brake,
	gc_fire,
	gc_lookback,
	gc_camreset,
	gc_camtoggle,
	gc_spectate,
	gc_lookup,
	gc_lookdown,
	gc_centerview,
	gc_talkkey,
	gc_teamkey,
	gc_scores,
	gc_console,
	gc_pause,
	gc_systemmenu,
	gc_screenshot,
	gc_recordgif,
	gc_viewpoint,
	gc_custom1, // Lua scriptable
	gc_custom2, // Lua scriptable
	gc_custom3, // Lua scriptable
	num_gamecontrols
} gamecontrols_e;

// mouse values are used once
extern consvar_t cv_mousesens, cv_mouseysens;
extern consvar_t cv_mousesens2, cv_mouseysens2;
extern consvar_t cv_controlperkey;

extern INT32 mousex, mousey;
extern INT32 mlooky; //mousey with mlookSensitivity
extern INT32 mouse2x, mouse2y, mlook2y;

extern INT32 joyxmove[JOYAXISSET], joyymove[JOYAXISSET], joy2xmove[JOYAXISSET], joy2ymove[JOYAXISSET],
	joy3xmove[JOYAXISSET], joy3ymove[JOYAXISSET], joy4xmove[JOYAXISSET], joy4ymove[JOYAXISSET];

// current state of the keys: true if pushed
extern UINT8 gamekeydown[NUMINPUTS];

// two key codes (or virtual key) per game control
extern INT32 gamecontrol[num_gamecontrols][2];
extern INT32 gamecontrolbis[num_gamecontrols][2]; // secondary splitscreen player
extern INT32 gamecontrol3[num_gamecontrols][2];
extern INT32 gamecontrol4[num_gamecontrols][2];
#define PLAYER1INPUTDOWN(gc) (gamekeydown[gamecontrol[gc][0]] || gamekeydown[gamecontrol[gc][1]])
#define PLAYER2INPUTDOWN(gc) (gamekeydown[gamecontrolbis[gc][0]] || gamekeydown[gamecontrolbis[gc][1]])
#define PLAYER3INPUTDOWN(gc) (gamekeydown[gamecontrol3[gc][0]] || gamekeydown[gamecontrol3[gc][1]])
#define PLAYER4INPUTDOWN(gc) (gamekeydown[gamecontrol4[gc][0]] || gamekeydown[gamecontrol4[gc][1]])

// peace to my little coder fingers!
// check a gamecontrol being active or not

// remaps the input event to a game control.
void G_MapEventsToControls(event_t *ev);

// returns the name of a key
const char *G_KeynumToString(INT32 keynum);
INT32 G_KeyStringtoNum(const char *keystr);

// detach any keys associated to the given game control
void G_ClearControlKeys(INT32 (*setupcontrols)[2], INT32 control);
void G_ClearAllControlKeys(void);
void Command_Setcontrol_f(void);
void Command_Setcontrol2_f(void);
void Command_Setcontrol3_f(void);
void Command_Setcontrol4_f(void);
void G_Controldefault(UINT8 player);
void G_SaveKeySetting(FILE *f);
INT32 G_CheckDoubleUsage(INT32 keynum, boolean modify);

#endif
