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
 * @brief  Webots serial driver
 * @author Andreas Merkle <web@blue-andi.de>
 */

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "WebotsSerialDrv.h"
#include <string.h>

/******************************************************************************
 * Macros
 *****************************************************************************/

/******************************************************************************
 * Types and classes
 *****************************************************************************/

/******************************************************************************
 * Prototypes
 *****************************************************************************/

/******************************************************************************
 * Local Variables
 *****************************************************************************/

/******************************************************************************
 * Public Methods
 *****************************************************************************/

WebotsSerialDrv::WebotsSerialDrv(webots::Emitter* emitter, webots::Receiver* receiver) :
    Stream(),
    m_sender(emitter),
    m_receiver(receiver)
{
    /* Nothing to do. */
}

WebotsSerialDrv::~WebotsSerialDrv()
{
    /* Nothing to do. */
}

void WebotsSerialDrv::setRxChannel(int32_t channelId)
{
    m_receiver.setChannel(channelId);
}

void WebotsSerialDrv::setTxChannel(int32_t channelId)
{
    /* Shall be positive for inter-robot communication. */
    if (0 <= channelId)
    {
        m_sender.setChannel(channelId);
    }
}

void WebotsSerialDrv::print(const char str[])
{
    if (nullptr != str)
    {
        (void)m_sender.send(str, strlen(str));
    }
}

void WebotsSerialDrv::print(uint8_t value)
{
    char    buffer[4U]; /* [0; 255] + string termination */
    int32_t length = snprintf(buffer, sizeof(buffer), "%u", value);

    (void)m_sender.send(buffer, length);
}

void WebotsSerialDrv::print(uint16_t value)
{
    char    buffer[6U]; /* [0; 65535] + string termination */
    int32_t length = snprintf(buffer, sizeof(buffer), "%u", value);

    (void)m_sender.send(buffer, length);
}

void WebotsSerialDrv::print(uint32_t value)
{
    char    buffer[11U]; /* [0; 4294967295] + string termination */
    int32_t length = snprintf(buffer, sizeof(buffer), "%u", value);

    (void)m_sender.send(buffer, length);
}

void WebotsSerialDrv::print(int8_t value)
{
    char    buffer[5U]; /* [-128; 127] + string termination */
    int32_t length = snprintf(buffer, sizeof(buffer), "%d", value);

    (void)m_sender.send(buffer, length);
}

void WebotsSerialDrv::print(int16_t value)
{
    char    buffer[6U]; /* [-32768; 32767] + string termination */
    int32_t length = snprintf(buffer, sizeof(buffer), "%d", value);

    (void)m_sender.send(buffer, length);
}

void WebotsSerialDrv::print(int32_t value)
{
    char    buffer[12U]; /* [-2147483648; 2147483647] + string termination */
    int32_t length = snprintf(buffer, sizeof(buffer), "%d", value);

    (void)m_sender.send(buffer, length);
}

void WebotsSerialDrv::println(const char str[])
{
    if (nullptr != str)
    {
        size_t length = strlen(str);
        char   buffer[length + 1U];

        length = snprintf(buffer, sizeof(buffer), "%s\n", str);

        (void)m_sender.send(buffer, length);
    }
}

void WebotsSerialDrv::println(uint8_t value)
{
    char    buffer[5U]; /* [0; 255] + LF + string termination */
    int32_t length = snprintf(buffer, sizeof(buffer), "%u\n", value);

    (void)m_sender.send(buffer, length);
}

void WebotsSerialDrv::println(uint16_t value)
{
    char    buffer[7U]; /* [0; 65535] + LF + string termination */
    int32_t length = snprintf(buffer, sizeof(buffer), "%u\n", value);

    (void)m_sender.send(buffer, length);
}

void WebotsSerialDrv::println(uint32_t value)
{
    char    buffer[12U]; /* [0; 4294967295] + LF + string termination */
    int32_t length = snprintf(buffer, sizeof(buffer), "%u\n", value);

    (void)m_sender.send(buffer, length);
}

void WebotsSerialDrv::println(int8_t value)
{
    char    buffer[6U]; /* [-128; 127] + LF + string termination */
    int32_t length = snprintf(buffer, sizeof(buffer), "%d\n", value);

    (void)m_sender.send(buffer, length);
}

void WebotsSerialDrv::println(int16_t value)
{
    char    buffer[7U]; /* [-32768; 32767] + LF + string termination */
    int32_t length = snprintf(buffer, sizeof(buffer), "%d\n", value);

    (void)m_sender.send(buffer, length);
}

void WebotsSerialDrv::println(int32_t value)
{
    char    buffer[13U]; /* [-2147483648; 2147483647] + LF + string termination */
    int32_t length = snprintf(buffer, sizeof(buffer), "%d\n", value);

    (void)m_sender.send(buffer, length);
}

size_t WebotsSerialDrv::write(const uint8_t* buffer, size_t length)
{
    return m_sender.send(buffer, length);
}

int WebotsSerialDrv::available() const
{
    return m_receiver.available();
}

size_t WebotsSerialDrv::readBytes(uint8_t* buffer, size_t length)
{
    return m_receiver.receive(buffer, length);
}

/******************************************************************************
 * Private Methods
 *****************************************************************************/

/******************************************************************************
 * Local Functions
 *****************************************************************************/
