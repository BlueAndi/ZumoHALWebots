/* MIT License
 *
 * Copyright (c) 2023 - 2025 Andreas Merkle <web@blue-andi.de>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*******************************************************************************
    DESCRIPTION
*******************************************************************************/
/**
 * @brief  Power interface realization
 * @author Norbert Schulz <github@schulznorbert.de>
 *
 * @addtogroup HALTarget
 *
 * @{
 */

#ifndef POWER_H
#define POWER_H

/******************************************************************************
 * Compile Switches
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "IPower.h"

/******************************************************************************
 * Macros
 *****************************************************************************/

/******************************************************************************
 * Types and Classes
 *****************************************************************************/

/** This class provides access to the Zumo power APIs */
class Power : public IPower
{
public:
    /**
     * Constructs the power interface provider.
     */
    Power()
    {
    }

    /**
     * Destroys the power interface provider.
     */
    ~Power()
    {
    }

    /**
     * Indicate if the robot is powered over USB.
     * 
     *  @return true if power is detected on the USB connector, false otherwise.
     */
    bool isUsbPowered();

    /**
     * Read battery power in millivolts.
     * 
     *  @return Actual battery voltage value in millivolts.
     */
    uint16_t getBatteryVoltage();
};

/******************************************************************************
 * Functions
 *****************************************************************************/

#endif /* POWER_H */
/** @} */
