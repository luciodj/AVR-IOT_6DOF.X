/*
    \file   sensors_handling.h

    \brief  Sensors handler header file.

    (c) 2018 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip software and any
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party
    license terms applicable to your use of third party software (including open source software) that
    may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS
    FOR A PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS
    SOFTWARE.
*/

#ifndef SENSORS_HANDLING_H
#define SENSORS_HANDLING_H

#define IMU_OUT_TEMP        0x20    // reg (16-bit) temperature
#define IMU_OUT_XG          0x22    // angular acceleration
#define IMU_OUT_YG          0x24
#define IMU_OUT_ZG          0x26
#define IMU_OUT_XL          0x28    // linear acceleration
#define IMU_OUT_YL          0x2A
#define IMU_OUT_ZL          0x2C

uint16_t SENSORS_getLightValue(void);
int16_t SENSORS_getTempValue (void);
int16_t SENSORS_getIMUValue(uint8_t); // register
void    SENSORS_IMUInit(void);

#endif /* SENSORS_HANDLING_H*/