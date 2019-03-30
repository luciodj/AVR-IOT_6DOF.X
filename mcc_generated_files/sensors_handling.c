/*
    \file   sensors_handling.c

    \brief  Sensors handling handler source file.

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

#include <stdint.h>
#include "sensors_handling.h"
#include "include/adc0.h"
#include "drivers/i2c_simple_master.h"
#include "include/pin_manager.h"

#define MCP9809_ADDR				0x18
#define MCP9808_REG_TA				0x05
#define LIGHT_SENSOR_ADC_CHANNEL	5

uint16_t SENSORS_getLightValue(void)
{
    return ADC_0_get_conversion(LIGHT_SENSOR_ADC_CHANNEL);
}

int16_t SENSORS_getTempValue (void)
{
    int32_t temperature;

    temperature = i2c_read2ByteRegister(MCP9809_ADDR, MCP9808_REG_TA);

    temperature = temperature << 19;
    temperature = temperature >> 19;

    temperature *= 100;
    temperature /= 16;

    return temperature;
}

// 6DOF IMU Click(tm) constants
#define IMU_ADDRESS         (0x6B)

int16_t SENSORS_getIMUValue(uint8_t reg)
{
    return i2c_read2ByteRegister(IMU_ADDRESS,  reg)>>7;
}

void SENSORS_IMUInit(void)
{
    IMU_CS_set_level(true);

    uint16_t signature = i2c_read1ByteRegister( IMU_ADDRESS, IMU_WHO_AM_I);
    printf("IMU signature = %d\n", signature);

    i2c_write1ByteRegister(IMU_ADDRESS, IMU_ACC_CFG, 0x10);    // 13Hz 2g, 400Hz
    i2c_write1ByteRegister(IMU_ADDRESS, IMU_GYR_CFG, 0x24);    // 26Hz 500dps
    i2c_write1ByteRegister(IMU_ADDRESS, IMU_CTR_C,   0x06);    // MSB first
}