//
// Created by florianfrank on 07.12.21.
//

#ifndef STM_MEASUREMENT_FIRMWARE_USBWRAPPER_H
#define STM_MEASUREMENT_FIRMWARE_USBWRAPPER_H

#include <usbd_cdc.h>


class USBWrapper
{
    void receiveUSB(uint8_t *dstBuffer, uint32_t bufferSize);


    void showHelpUSB();

    void executeCommandUSB();

    void USBCDCRXCallback(uint8_t *Buf, uint32_t Len);
};


#endif //STM_MEASUREMENT_FIRMWARE_USBWRAPPER_H
