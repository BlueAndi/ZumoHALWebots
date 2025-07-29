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
 * @brief  Settings realization
 * @author Andreas Merkle <web@blue-andi.de>
 *
 * @addtogroup HALSim
 *
 * @{
 */

#ifndef SETTINGS_H
#define SETTINGS_H

/******************************************************************************
 * Compile Switches
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "ISettings.h"

/******************************************************************************
 * Macros
 *****************************************************************************/

/******************************************************************************
 * Types and Classes
 *****************************************************************************/

/** This class handles settings stored in a JSON file. */
class Settings : public ISettings
{
public:
    /**
     * Constructs the settings adapter.
     */
    Settings() : ISettings(), m_settingsPath{0}, m_maxSpeed(DEFAULT_MAX_SPEED)
    {
        setPath(SETTINGS_FILE_NAME);
    }

    /**
     * Destroys the button A adapter.
     */
    ~Settings()
    {
    }

    /**
     * Get the settings path.
     *
     * @return Settings path.
     */
    const char* getPath() const;

    /**
     * Set the settings path.
     *
     * @param[in] path  Settings path.
     */
    void setPath(const char* path);

    /**
     * Initialize the settings.
     *
     * If the settings are invalid or not compatible to the settings, the
     * default values will be written!
     */
    void init() final;

    /**
     * Get the max. speed.
     *
     * @return Max. speed in steps/s.
     */
    int16_t getMaxSpeed() const final;

    /**
     * Set the max. speed.
     *
     * @param[in] maxSpeed  Max. speed in steps/s.
     */
    void setMaxSpeed(int16_t maxSpeed) final;

private:
    /**
     * Name of the settings file.
     */
    static const char* SETTINGS_FILE_NAME;

    /**
     * Data version is used to detect whether the data in the EEPROM is
     * compatible with the current settings version.
     *
     * Increase the version number by 1 for every change!
     */
    static const uint8_t DATA_VERSION;

    /**
     * Max. speed default values in steps/s.
     */
    static const int16_t DEFAULT_MAX_SPEED = 0;

    /**
     * Max. settings path length.
     */
    static const size_t MAX_PATH_LENGTH = 256U;

    char    m_settingsPath[MAX_PATH_LENGTH]; /**< Path to the settings file. */
    int16_t m_maxSpeed;                      /**< Max. speed in steps/s. */

    /**
     * Load settings from file.
     *
     * @return If successful, it will return true otherwise false.
     */
    bool loadSettings();

    /**
     * Store settings to file.
     */
    void saveSettings();
};

/******************************************************************************
 * Functions
 *****************************************************************************/

#endif /* SETTINGS_H */
/** @} */
