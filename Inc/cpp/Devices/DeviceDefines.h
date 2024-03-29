/**
 * @author Florian Frank
 * @copyright University of Passau - Chair of computer engineering
 */
#ifndef MEMORY_TESTING_FW_DEVICEDEFINES_H
#define MEMORY_TESTING_FW_DEVICEDEFINES_H
#include "cpp/MemoryErrorHandling.h"
#include <cstdint>
#include <string>

#if STM32
#include <stm32f4xx_hal_gpio.h>

typedef GPIO_TypeDef* GPIOBank;

#define  IO_BANK_A          ((GPIO_TypeDef *) GPIOA_BASE)
#define  IO_BANK_B          ((GPIO_TypeDef *) GPIOB_BASE)
#define  IO_BANK_C          ((GPIO_TypeDef *) GPIOC_BASE)
#define  IO_BANK_D          ((GPIO_TypeDef *) GPIOD_BASE)
#define  IO_BANK_E          ((GPIO_TypeDef *) GPIOE_BASE)
#define  IO_BANK_F          ((GPIO_TypeDef *) GPIOF_BASE)
#define  IO_BANK_G          ((GPIO_TypeDef *) GPIOG_BASE)
#define  IO_BANK_H          ((GPIO_TypeDef *) GPIOH_BASE)
#define  IO_BANK_I          ((GPIO_TypeDef *) GPIOI_BASE)
#define  IO_BANK_UNDEFINED  ((GPIO_TypeDef *) nullptr)


#define  IO_PIN_0       GPIO_PIN_0
#define  IO_PIN_1       GPIO_PIN_1
#define  IO_PIN_2       GPIO_PIN_2
#define  IO_PIN_3       GPIO_PIN_3
#define  IO_PIN_4       GPIO_PIN_4
#define  IO_PIN_5       GPIO_PIN_5
#define  IO_PIN_6       GPIO_PIN_6
#define  IO_PIN_7       GPIO_PIN_7
#define  IO_PIN_8       GPIO_PIN_8
#define  IO_PIN_9       GPIO_PIN_9
#define  IO_PIN_10      GPIO_PIN_10
#define  IO_PIN_11      GPIO_PIN_11
#define  IO_PIN_12      GPIO_PIN_12
#define  IO_PIN_13      GPIO_PIN_13
#define  IO_PIN_14      GPIO_PIN_14
#define  IO_PIN_15      GPIO_PIN_15
#define  IO_PIN_ALL     GPIO_PIN_ALL
#define  IO_PIN_UNDEFINED   0x00
#else

#define  IO_BANK_UNDEFINED  0

#define  IO_BANK_A          IO_BANK_UNDEFINED
#define  IO_BANK_B          IO_BANK_UNDEFINED
#define  IO_BANK_C          IO_BANK_UNDEFINED
#define  IO_BANK_D          IO_BANK_UNDEFINED
#define  IO_BANK_E          IO_BANK_UNDEFINED
#define  IO_BANK_F          IO_BANK_UNDEFINED
#define  IO_BANK_G          IO_BANK_UNDEFINED
#define  IO_BANK_H          IO_BANK_UNDEFINED
#define  IO_BANK_I          IO_BANK_UNDEFINED


#define  IO_PIN_1       1
#define  IO_PIN_2       2
#define  IO_PIN_3       3
#define  IO_PIN_4       4
#define  IO_PIN_5       5
#define  IO_PIN_6       6
#define  IO_PIN_7       7
#define  IO_PIN_8       8
#define  IO_PIN_9       9
#define  IO_PIN_10      10
#define  IO_PIN_11      11
#define  IO_PIN_12      12
#define  IO_PIN_13      13
#define  IO_PIN_14      14
#define  IO_PIN_15      15
#define  IO_PIN_ALL     16
#define  IO_PIN_UNDEFINED   0x00

typedef int GPIOBank;
#endif // STM32

enum GPIOMode {
    GPIO_INPUT,
    GPIO_OUTPUT

#if STM32
    ,GPIO_OUTPUT_PUSH_PULL,
    GPIO_OUTPUT_OPEN_DRAIN,
    GPIO_ALTERNATE_PUSH_PULL,
    GPIO_ALTERNATE_OPEN_DRAIN
#endif // STM32
};


enum GPIOState {
    GPIO_SET,
    GPIO_RESET
};

class GPIOPin {
    /**
     * @brief This class represents a GPIO pin consisting of a GPIO bank and a Pin.
     */
public:
    GPIOPin(GPIOBank bank, uint32_t pin, std::string description = "Not defined"): m_GPIOBank(bank),
    m_GPIOPin(pin), m_Description(description){ }

    /**
     * @brief Overloaded operator allows the comparison between two different GPIOPins.
     * @param gpioPin gpio pin to compare.
     * @return true if the bank and pin is equal otherwise return false.
     */
    bool operator == (const GPIOPin& gpioPin) const
    {
        return m_GPIOPin == gpioPin.m_GPIOPin && m_GPIOBank == gpioPin.m_GPIOBank;
    }

    GPIOBank GetGPIOBank() const
    {
        return m_GPIOBank;
    }

    uint32_t GetGPIOPin() const
    {
        return m_GPIOPin;
    }

private:
    GPIOBank m_GPIOBank;
    uint32_t m_GPIOPin;
    std::string m_Description;
};
#endif // MEMORY_TESTING_FW_DEVICEDEFINES_H