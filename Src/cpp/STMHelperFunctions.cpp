/**
 * @author Florian Frank
 * @copyright University of Passau - Chair of computer engineering
 */
#include "cpp/STMHelperFunctions.h"

#if STM32
#include "stm32f4xx_hal_def.h"
#endif // STM32

/*static*/ MEM_ERROR STMHelperFunctions::Delay(uint32_t milliseconds)
{
#if STM32 // TODO
   //Initially clear flag
    (void) SysTick->CTRL;
    while (milliseconds != 0) {
        //COUNTFLAG returns 1 if timer counted to 0 since the last flag read
        milliseconds -= (SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) >> SysTick_CTRL_COUNTFLAG_Pos;
    }
#endif // STM32
    return MemoryErrorHandling::MEM_NO_ERROR;
}
