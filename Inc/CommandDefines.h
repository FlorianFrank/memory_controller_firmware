/**
 * @author Florian Frank
 * @copyright University of Passau - Chair of computer engineering
 */
#ifndef STM_MEASUREMENT_FIRMWARE_COMMANDDEFINES_H
#define STM_MEASUREMENT_FIRMWARE_COMMANDDEFINES_H

typedef enum {
    SHOW_HELP = 0x0,
    FILL_WITH_ZEROS = 0x1,
    FILL_WITH_ONES = 0x2,
    WRITE_ASCENDING = 0x3,
    WRITE_ALTERNATE_ZERO_ONE = 0x4,
    WRITE_ALTERNATE_ONE_ZERO = 0x5,
    WRITE_ADDRESS = 0x6,
    WRITE_ADDRESS_RANGE = 0x7,
    GET_PERFORMANCE_MEASURES = 0x8,
    GET_ADDRESS = 0x9,
    READ = 0xA,
    WRITE = 0xB,
    CHECK_ADDRESS = 0xC,
    CHECK_ADDRESS_RANGE = 0xD,
    GET_VALUES = 0xE,
    NOPE = 0xFF
} Command; // List of possible commands

#endif //STM_MEASUREMENT_FIRMWARE_COMMANDDEFINES_H
