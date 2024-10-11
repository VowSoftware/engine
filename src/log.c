////////////////////////////////////////////////////////////////////////////////
// Header
////////////////////////////////////////////////////////////////////////////////

// GitHub: https://github.com/VowSoftware/vow-engine/src/log.c

////////////////////////////////////////////////////////////////////////////////
// Dependencies
////////////////////////////////////////////////////////////////////////////////

#include <vowengine/xlog.h>

#include <vowengine/log.h>

#include <stdarg.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Constants
////////////////////////////////////////////////////////////////////////////////

static const char* g_level_strings[] =
{
    "INFO",
    "WARNING",
    "ERROR"
};

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

static VowLogLevel g_level = VOW_LOG_LEVEL_INFO;

////////////////////////////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////////////////////////////

void vow_log_print(VowLogLevel level, const char* format, ...)
{
    if (level < g_level) return;
    const char* level_string = g_level_strings[level];
    printf("%s: ", level_string);
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    printf("\n");
}

void vow_log_level(VowLogLevel level)
{
    g_level = level;
}