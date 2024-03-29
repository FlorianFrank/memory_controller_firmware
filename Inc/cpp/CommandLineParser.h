/**
 * @author Florian Frank
 * @copyright University of Passau - Chair of computer engineering
 */
#ifndef MEMORY_TESTING_FW_COMMANDLINEPARSER_H
#define MEMORY_TESTING_FW_COMMANDLINEPARSER_H


#include "cpp/MemoryControllers/MemoryController.h"
#include "CommandDefines.h"
#include <cstdint>

#if STM32
extern "C" {
#include <stm32f4xx_hal_uart.h>
}
#endif // STM32

class CommandLineParser
{
public:

    explicit CommandLineParser (MemoryController *memoryController, InterfaceWrapper *commmunicationInterface);

    void showHelp(uint8_t *inBuff, uint32_t *buffLen);

    MEM_ERROR executeCommand(uint8_t *inBuff, uint32_t *inBuffLen, uint8_t *outBuff, uint32_t *outBufflen, Command cmdIdx);



private:
    CommandLineParser()= default;
    Command m_commandMode = NOPE;
    uint32_t m_arguments[3];
    uint8_t m_WriteMode = 0xFF;
    uint16_t len;
    uint16_t old_len;
    char Rx_Buffer[100];


    static const char* command_help[];
    static const char * command[];

    MemoryController *m_MemoryController;

    char m_SendBuffer[STRING_BUFFER_SIZE];

    InterfaceWrapper *m_InterfaceWrapper;

};


#endif //MEMORY_TESTING_FW_COMMANDLINEPARSER_H
