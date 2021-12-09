/**
 * @author Florian Frank
 * @copyright University of Passau - Chair of computer engineering
 */
#ifndef MEMORY_TESTING_FW_MEMORYCONTROLLER_H
#define MEMORY_TESTING_FW_MEMORYCONTROLLER_H

#include "cpp/MemoryErrorHandling.h"
#include "TimeMeasurement.h"
#include "io_pin_defines.h"
#include "InterfaceWrappers.h"

/* see fmc.c
 * FMC_NORSRAM_BANK1 = 0x60000000
 * FMC_NORSRAM_BANK2 = 0x64000000
 * FMC_NORSRAM_BANK3 = 0x68000000
 * FMC_NORSRAM_BANK4 = 0x6C000000
 * We use Bank 1, Block 2, thus FMC_NE2 and 0x64000000
 * */

#define COMMAND_COUNT		15

// Define IO to empty when not using STM32
#ifndef __IO
#define __IO volatile
#endif // !__IO

class SPIWrapper;

#define MEMORY_BUFFER_SIZE	40960						// 5x8192 buffer size for the sram buffer

using MEM_ERROR = MemoryErrorHandling::MEM_ERROR;

class MemoryController
{
public:

    typedef enum {
        FAILED = 0,
        PASSED = !FAILED
    } TestStatus;

    explicit MemoryController(InterfaceWrappers *interfaceWrapper);

    // Basic Read and write functions which must be implemented by the deriving classes
    virtual MEM_ERROR Write8BitWord(uint32_t adr, uint8_t value) = 0;
    virtual MEM_ERROR Read8BitWord(uint32_t adr, uint8_t *ret) = 0;
    virtual MEM_ERROR Write16BitWord(uint32_t adr, uint16_t value) = 0;
    virtual MEM_ERROR Read16BitWord(uint32_t adr, uint16_t *value) = 0;


    MEM_ERROR WriteSingleValue(uint32_t address, uint8_t value);
    MEM_ERROR WriteSingleValue(uint32_t address, uint16_t value);

    MEM_ERROR FillMemoryArea(uint32_t startAddress, uint32_t endAddress, uint8_t value);
    MEM_ERROR FillMemoryArea(uint32_t startAddress, uint32_t endAddress, uint16_t value);
    MEM_ERROR FillMemoryArea(uint32_t startAddress, uint32_t endAddress, uint8_t(*dataFunction)(uint32_t address));
    MEM_ERROR FillMemoryArea(uint32_t startAddress, uint32_t endAddress, uint16_t(*dataFunction)(uint32_t address));

    MEM_ERROR VerifyMemoryArea(uint32_t startAddress, uint32_t endAddress, uint16_t expectedValue);
    MEM_ERROR VerifyMemoryArea(uint32_t startAddress, uint32_t endAddress, uint8_t expectedValue);
    MEM_ERROR VerifyMemoryArea(uint32_t startAddress, uint32_t endAddress, uint8_t(*dataFunction)(uint32_t address));
    MEM_ERROR VerifyMemoryArea(uint32_t startAddress, uint32_t endAddress, uint16_t(*dataFunction)(uint32_t address));


    MEM_ERROR FillWithZeros();
    MEM_ERROR FillWithZerosAndVerifyRead();
    MEM_ERROR FillWithOnes();
    MEM_ERROR FillMemoryWithAscendingValues();
    MEM_ERROR FillMemoryWithAscendingValuesAndVerifyRead(uint8_t *buffer, uint32_t *buffLen, const uint32_t *arguments);
    MEM_ERROR FillMemoryWithAlternatingZeroAndOne();
    MEM_ERROR FillMemoryWithAlternatingOneAndZero();


    // TODO refactor
    MEM_ERROR GetProbabilityOfFlippedOnesAndZeros(uint8_t *buffer, uint32_t *buffLen);

protected:
    static bool IsInvalidAddress(uint32_t address);

    // helper functions
    void InitCounter();

    void InitArguments();

    uint8_t write_mode;
    uint16_t len;
    char STRING_BUFFER[STRING_BUFFER_SIZE];
    TimeMeasurement m_timeMeasurement;

    uint32_t m_MMIOStartAddress;
    InterfaceWrappers *m_InterfaceWrapper;

    // commands
    uint16_t start_value = 0x0; // start value for ascending writing
    uint32_t start_adr = 0x0;	// start address for writeSRAMRange
    uint32_t end_adr = 0x0;		// end address for writeSRAMRange

    // global string buffer
    char SRAM_BUFFER[MEMORY_BUFFER_SIZE]{};
    char *srambp{};

    // probability counter
// 1 MB RAM => 1 million 1's and 0's possible => uint32_t
    uint32_t total_one;
    uint32_t total_zero;
    uint32_t flipped_one;
    uint32_t flipped_zero;

};

#endif /* __MEMORY_CONTROL_H */
