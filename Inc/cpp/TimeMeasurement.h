//
// Created by florianfrank on 05.12.21.
//

#ifndef MEMORY_TESTING_FW_TIMEMEASUREMENT_H
#define MEMORY_TESTING_FW_TIMEMEASUREMENT_H

#include <stdint.h>


class TimeMeasurement{
public:
    static uint32_t StartTimer();
    static uint32_t GetTimer();
    static void ResetTimer();
    static uint32_t StopGetTime();

private:
    static uint32_t TransformClockFrequencyToNs(uint32_t value);

};


#endif //MEMORY_TESTING_FW_TIMEMEASUREMENT_H
