#pragma once
#ifndef KEYCODES_H
#define KEYCODES_H

static constexpr int KEY_ESCAPE     = 27;

/* Use real ncurses keycodes if we're using ncurses, otherwise make them up */
#ifndef TILES

#define NCURSES_NOMACROS
#if (defined __CYGWIN__)
#include "ncurses/curses.h"
#else
#include <curses.h>
#endif /* (defined __CYGWIN__) */

#else /* TILES */

/* Select ncurses key definitions for special keys found on a typical keyboard.
 * Names match ncurses, values are arbitrary (starting at 256; above ASCII).
 */
enum keycode {
    KEY_BREAK = 256,  /* Break key */
    KEY_DOWN,         /* Down arrow key */
    KEY_UP,           /* Up arrow key */
    KEY_LEFT,         /* Left arrow key */
    KEY_RIGHT,        /* Right arrow key */
    KEY_HOME,         /* Home key */
    KEY_BACKSPACE,    /* Backspace */
    KEY_DC,           /* Delete Character */
    KEY_NPAGE,        /* page down */
    KEY_PPAGE,        /* page up */
    KEY_ENTER,        /* Enter */
    KEY_BTAB,         /* Back tab key (shift + tab) */
    KEY_END,          /* End key */
    CATAKEY_MAX,
};

inline constexpr int KEY_F( const int n ) /* 0 <= n <= 63 */
{
    return CATAKEY_MAX + n;    /* F1, F2, etc*/
}
#endif /* TILES */

#endif
