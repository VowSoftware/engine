#ifndef VOW_GUARD_FRAMEWORK
#define VOW_GUARD_FRAMEWORK

#include <vowframework/file.h>
#include <vowframework/handle.h>
#include <vowframework/log.h>
#include <vowframework/memory.h>
#include <vowframework/timer.h>
#include <vowframework/tuple.h>
#include <vowframework/window.h>

////////////////////////////////////////////////////////////////////////////////
// Initializes framework systems and resources.
//
// This function should be called before all other framework function.
////////////////////////////////////////////////////////////////////////////////
void vow_framework_initialize(void);

////////////////////////////////////////////////////////////////////////////////
// Finalizes framework systems and resources.
//
// This function should be called after all other framework functions.
////////////////////////////////////////////////////////////////////////////////
void vow_framework_finalize(void);

////////////////////////////////////////////////////////////////////////////////
// Updates framework systems.
//
// This function should be called first in the user's main game loop.
////////////////////////////////////////////////////////////////////////////////
void vow_framework_update(void);

#endif