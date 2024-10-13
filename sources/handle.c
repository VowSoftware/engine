////////////////////////////////////////////////////////////////////////////////
// Dependencies
////////////////////////////////////////////////////////////////////////////////

#include <vowengine/private/handle.h>
#include <vowengine/private/log.h>

#include <vowengine/handle.h>
#include <vowengine/log.h>

#include <assert.h>

////////////////////////////////////////////////////////////////////////////////
// Constants
////////////////////////////////////////////////////////////////////////////////

#define TYPE_BIT_COUNT 8
#define TYPE_BIT_MASK 0x00000000000000ff

#define INDEX_BIT_COUNT 32
#define INDEX_BIT_MASK 0x000000ffffffff00

////////////////////////////////////////////////////////////////////////////////
// Functions <vowengine/private/handle.h>
////////////////////////////////////////////////////////////////////////////////

VowHandle vow_handle_create(VowHandleIndex index, VowHandleType type)
{
    assert(VOW_HANDLE_MIN_INDEX <= index && index <= VOW_HANDLE_MAX_INDEX);
    switch (type)
    {
        case VOW_HANDLE_TYPE_TIMER:
            if (index > VOW_TIMER_CAPACITY)
            {
                vow_log_print(VOW_LOG_LEVEL_WARNING, "Failed to create handle. Reached timer capacity.");
                return VOW_HANDLE_INVALID;
            }
    }
    const VowHandle handle = index << TYPE_BIT_COUNT | type;
    return handle;
}

int vow_handle_resolve(VowHandle handle, VowHandleType type)
{
    const VowHandleType actual_type = handle & TYPE_BIT_MASK;
    assert(actual_type == type);
    const VowHandleIndex index = handle >> TYPE_BIT_COUNT;
    return index;
}