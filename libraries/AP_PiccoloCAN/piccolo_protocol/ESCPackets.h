// ESCPackets.h was generated by ProtoGen version 3.2.a

/*
 * This file is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Oliver Walters
 */

#ifndef _ESCPACKETS_H
#define _ESCPACKETS_H

// Language target is C, C++ compilers: don't mangle us
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \file
 */

#include <stdbool.h>
#include "ESCVelocityProtocol.h"
#include "ESCDefines.h"

/*!
 * General ESC configuration parameters
 */
typedef struct
{
    bool    swInhibit;            //!< 1 = ESC is inhibited (disabled) on startup
    bool    piccoloCommands;      //!< 1 = ESC will respond to PICCOLO autopilot commands
    bool    broadcastCommands;    //!< 1 = ESC will accept broadcast command messages
    uint8_t commandInputPriority; //!< Command input source priority, refer to enumeration ESCCommandPriorities
    uint8_t motorTempSensor;      //!< External motor temperature sensor configuration
    uint8_t keepalive;            //!< ESC keepalive timeout - If this is non-zero, the ESC will automatically revert to *STANDBY* mode if it does not receive a valid command for the alloted period
    uint8_t motorBeepMode;       
    uint8_t motorBeepVolume;      //!< Motor beep volume
}ESC_Config_t;

//! Create the ESC_Config packet
void encodeESC_ConfigPacketStructure(void* pkt, const ESC_Config_t* user);

//! Decode the ESC_Config packet
int decodeESC_ConfigPacketStructure(const void* pkt, ESC_Config_t* user);

//! Create the ESC_Config packet from parameters
void encodeESC_ConfigPacket(void* pkt, bool swInhibit, bool piccoloCommands, bool broadcastCommands, uint8_t commandInputPriority, uint8_t motorTempSensor, uint8_t keepalive, uint8_t motorBeepMode, uint8_t motorBeepVolume);

//! Decode the ESC_Config packet to parameters
int decodeESC_ConfigPacket(const void* pkt, bool* swInhibit, bool* piccoloCommands, bool* broadcastCommands, uint8_t* commandInputPriority, uint8_t* motorTempSensor, uint8_t* keepalive, uint8_t* motorBeepMode, uint8_t* motorBeepVolume);

//! Encode a ESC_Config_t into a byte array
void encodeESC_Config_t(uint8_t* data, int* bytecount, const ESC_Config_t* user);

//! Decode a ESC_Config_t from a byte array
int decodeESC_Config_t(const uint8_t* data, int* bytecount, ESC_Config_t* user);

//! return the packet ID for the ESC_Config packet
#define getESC_ConfigPacketID() (PKT_ESC_CONFIG)

//! return the minimum encoded length for the ESC_Config packet
#define getESC_ConfigMinDataLength() (8)

//! return the maximum encoded length for the ESC_Config packet
#define getESC_ConfigMaxDataLength() (8)

/*!
 * Telemetry settings (storage class)
 */
typedef struct
{
    uint8_t                period;  //!< Telemetry period code (maps indirectly to a telemetry period value)
    uint8_t                silence; //!< Telemetry silence period (delay after RESET before telemetry data is sent)
    ESC_TelemetryPackets_t packets; //!< Bitfield describing which telemetry packets are enabled
}ESC_TelemetryConfig_t;

//! Create the ESC_TelemetryConfig packet
void encodeESC_TelemetryConfigPacketStructure(void* pkt, const ESC_TelemetryConfig_t* user);

//! Decode the ESC_TelemetryConfig packet
int decodeESC_TelemetryConfigPacketStructure(const void* pkt, ESC_TelemetryConfig_t* user);

//! Create the ESC_TelemetryConfig packet from parameters
void encodeESC_TelemetryConfigPacket(void* pkt, uint8_t period, uint8_t silence, const ESC_TelemetryPackets_t* packets);

//! Decode the ESC_TelemetryConfig packet to parameters
int decodeESC_TelemetryConfigPacket(const void* pkt, uint8_t* period, uint8_t* silence, ESC_TelemetryPackets_t* packets);

//! Encode a ESC_TelemetryConfig_t into a byte array
void encodeESC_TelemetryConfig_t(uint8_t* data, int* bytecount, const ESC_TelemetryConfig_t* user);

//! Decode a ESC_TelemetryConfig_t from a byte array
int decodeESC_TelemetryConfig_t(const uint8_t* data, int* bytecount, ESC_TelemetryConfig_t* user);

//! return the packet ID for the ESC_TelemetryConfig packet
#define getESC_TelemetryConfigPacketID() (PKT_ESC_TELEMETRY_SETTINGS)

//! return the minimum encoded length for the ESC_TelemetryConfig packet
#define getESC_TelemetryConfigMinDataLength() (3)

//! return the maximum encoded length for the ESC_TelemetryConfig packet
#define getESC_TelemetryConfigMaxDataLength() (3)

/*!
 * Send this packet to command ESCs which have CAN ID values in the range {1,4}
 * (inclusive). This packet must be sent as a broadcast packet (address = 0xFF)
 * such that all ESCs can receive it. Similiar commands are available for
 * commanding ESCs with ID values up to 64, using different ESC_SETPOINT_x
 * packet ID values.
 */
typedef struct
{
    uint16_t pwmValueA; //!< The PWM (pulse width) command for ESC with CAN ID 1
    uint16_t pwmValueB; //!< The PWM (pulse width) command for ESC with CAN ID 2
    uint16_t pwmValueC; //!< The PWM (pulse width) command for ESC with CAN ID 3
    uint16_t pwmValueD; //!< The PWM (pulse width) command for ESC with CAN ID 4
}ESC_CommandMultipleESCs_t;

//! Create the ESC_CommandMultipleESCs packet from parameters
void encodeESC_CommandMultipleESCsPacket(void* pkt, uint16_t pwmValueA, uint16_t pwmValueB, uint16_t pwmValueC, uint16_t pwmValueD, uint32_t id);

//! Decode the ESC_CommandMultipleESCs packet to parameters
int decodeESC_CommandMultipleESCsPacket(const void* pkt, uint16_t* pwmValueA, uint16_t* pwmValueB, uint16_t* pwmValueC, uint16_t* pwmValueD);

//! return the minimum encoded length for the ESC_CommandMultipleESCs packet
#define getESC_CommandMultipleESCsMinDataLength() (8)

//! return the maximum encoded length for the ESC_CommandMultipleESCs packet
#define getESC_CommandMultipleESCsMaxDataLength() (8)

//! Create the ESC_Disable packet from parameters
void encodeESC_DisablePacket(void* pkt);

//! Decode the ESC_Disable packet to parameters
int decodeESC_DisablePacket(const void* pkt);

//! return the packet ID for the ESC_Disable packet
#define getESC_DisablePacketID() (PKT_ESC_DISABLE)

//! return the minimum encoded length for the ESC_Disable packet
#define getESC_DisableMinDataLength() (2)

//! return the maximum encoded length for the ESC_Disable packet
#define getESC_DisableMaxDataLength() (2)

//! Create the ESC_Enable packet from parameters
void encodeESC_EnablePacket(void* pkt);

//! Decode the ESC_Enable packet to parameters
int decodeESC_EnablePacket(const void* pkt);

//! return the packet ID for the ESC_Enable packet
#define getESC_EnablePacketID() (PKT_ESC_STANDBY)

//! return the minimum encoded length for the ESC_Enable packet
#define getESC_EnableMinDataLength() (2)

//! return the maximum encoded length for the ESC_Enable packet
#define getESC_EnableMaxDataLength() (2)

/*!
 * Send a PWM (pulse width) command to an individual ESC. The pulse width value
 * in specified in microseconds for compatibility with standard ESC interface.
 * Use the broadcast ID (0xFF) to send this command to all ESCs on the CAN bus.
 */
typedef struct
{
    uint16_t pwmCommand; //!< PWM command
}ESC_PWMCommand_t;

//! Create the ESC_PWMCommand packet from parameters
void encodeESC_PWMCommandPacket(void* pkt, uint16_t pwmCommand);

//! Decode the ESC_PWMCommand packet to parameters
int decodeESC_PWMCommandPacket(const void* pkt, uint16_t* pwmCommand);

//! return the packet ID for the ESC_PWMCommand packet
#define getESC_PWMCommandPacketID() (PKT_ESC_PWM_CMD)

//! return the minimum encoded length for the ESC_PWMCommand packet
#define getESC_PWMCommandMinDataLength() (2)

//! return the maximum encoded length for the ESC_PWMCommand packet
#define getESC_PWMCommandMaxDataLength() (2)

/*!
 * Send an RPM (speed) command to an individual ESC. Use the broadcast ID
 * (0xFF) to send this command to all ESCs on the CAN bus
 */
typedef struct
{
    uint16_t rpmCommand; //!< RPM Command
}ESC_RPMCommand_t;

//! Create the ESC_RPMCommand packet from parameters
void encodeESC_RPMCommandPacket(void* pkt, uint16_t rpmCommand);

//! Decode the ESC_RPMCommand packet to parameters
int decodeESC_RPMCommandPacket(const void* pkt, uint16_t* rpmCommand);

//! return the packet ID for the ESC_RPMCommand packet
#define getESC_RPMCommandPacketID() (PKT_ESC_RPM_CMD)

//! return the minimum encoded length for the ESC_RPMCommand packet
#define getESC_RPMCommandMinDataLength() (2)

//! return the maximum encoded length for the ESC_RPMCommand packet
#define getESC_RPMCommandMaxDataLength() (2)

/*!
 * The ESC_STATUS_A packet contains high-priority ESC status information. This
 * packet is transmitted by the ESC at regular (user-configurable) intervals.
 * It can also be requested (polled) from the ESC by sending a zero-length
 * packet of the same type.
 */
typedef struct
{
    uint8_t          mode;    //!< ESC operating mode. The lower four bits indicate the operational mode of the ESC, in accordance with the ESCOperatingModes enumeration. The upper three bits are used for debugging and should be ignored for general use.
    ESC_StatusBits_t status;  //!< ESC status bits
    uint16_t         command; //!< ESC operational command - value depends on 'mode' available in this packet. If the ESC is disabled, data reads 0x0000. If the ESC is in open-loop PWM mode, this value is the PWM command in units of 1us, in the range 1000us to 2000us. If the ESC is in closed-loop RPM mode, this value is the RPM command in units of 1RPM
    uint16_t         rpm;     //!< Motor speed
}ESC_StatusA_t;

//! Create the ESC_StatusA packet from parameters
void encodeESC_StatusAPacket(void* pkt, uint8_t mode, const ESC_StatusBits_t* status, uint16_t command, uint16_t rpm);

//! Decode the ESC_StatusA packet to parameters
int decodeESC_StatusAPacket(const void* pkt, uint8_t* mode, ESC_StatusBits_t* status, uint16_t* command, uint16_t* rpm);

//! return the packet ID for the ESC_StatusA packet
#define getESC_StatusAPacketID() (PKT_ESC_STATUS_A)

//! return the minimum encoded length for the ESC_StatusA packet
#define getESC_StatusAMinDataLength() (8)

//! return the maximum encoded length for the ESC_StatusA packet
#define getESC_StatusAMaxDataLength() (8)

/*!
 * The ESC_STATUS_B packet contains ESC operational information. This packet is
 * transmitted by the ESC at regular (user-configurable) intervals. It can also
 * be requested (polled) from the ESC by sending a zero-length packet of the
 * same type.
 */
typedef struct
{
    uint16_t voltage;          //!< ESC Rail Voltage
    int16_t  current;          //!< ESC Current. Current IN to the ESC is positive. Current OUT of the ESC is negative
    uint16_t dutyCycle;        //!< ESC Motor Duty Cycle
    int8_t   escTemperature;   //!< ESC Logic Board Temperature
    uint8_t  motorTemperature; //!< ESC Motor Temperature
}ESC_StatusB_t;

//! Create the ESC_StatusB packet from parameters
void encodeESC_StatusBPacket(void* pkt, uint16_t voltage, int16_t current, uint16_t dutyCycle, int8_t escTemperature, uint8_t motorTemperature);

//! Decode the ESC_StatusB packet to parameters
int decodeESC_StatusBPacket(const void* pkt, uint16_t* voltage, int16_t* current, uint16_t* dutyCycle, int8_t* escTemperature, uint8_t* motorTemperature);

//! return the packet ID for the ESC_StatusB packet
#define getESC_StatusBPacketID() (PKT_ESC_STATUS_B)

//! return the minimum encoded length for the ESC_StatusB packet
#define getESC_StatusBMinDataLength() (8)

//! return the maximum encoded length for the ESC_StatusB packet
#define getESC_StatusBMaxDataLength() (8)

/*!
 * ESC Status C telemetry packet transmitted by the ESC at regular intervals
 * (reserved for future use)
 */
typedef struct
{
    float    fetTemperature; //!< ESC Phase Board Temperature
    uint16_t pwmFrequency;   //!< Current motor PWM frequency (10 Hz per bit)
    uint16_t timingAdvance;  //!< Current timing advance (0.1 degree per bit)
}ESC_StatusC_t;

//! Create the ESC_StatusC packet from parameters
void encodeESC_StatusCPacket(void* pkt, float fetTemperature, uint16_t pwmFrequency, uint16_t timingAdvance);

//! Decode the ESC_StatusC packet to parameters
int decodeESC_StatusCPacket(const void* pkt, float* fetTemperature, uint16_t* pwmFrequency, uint16_t* timingAdvance);

//! return the packet ID for the ESC_StatusC packet
#define getESC_StatusCPacketID() (PKT_ESC_STATUS_C)

//! return the minimum encoded length for the ESC_StatusC packet
#define getESC_StatusCMinDataLength() (7)

//! return the maximum encoded length for the ESC_StatusC packet
#define getESC_StatusCMaxDataLength() (7)

/*!
 * This packet contains raw accelerometer data from the ESC. It can be
 * requested (polled) from the ESC by sending a zero-length packet of the same
 * type. It can also be transmitted by the ESC at high-frequency using the
 * high-frequency streaming functionality of the ESC
 */
typedef struct
{
    int16_t xAcc;       //!< X axis acceleration value
    int16_t yAcc;       //!< Y axis acceleration value
    int16_t zAcc;       //!< Z axis acceleration value
    uint8_t fullscale;  //!< Accelerometer full-scale range
    uint8_t resolution; //!< Accelerometer measurement resolution, in 'bits'.
}ESC_Accelerometer_t;

//! Create the ESC_Accelerometer packet from parameters
void encodeESC_AccelerometerPacket(void* pkt, int16_t xAcc, int16_t yAcc, int16_t zAcc, uint8_t fullscale, uint8_t resolution);

//! Decode the ESC_Accelerometer packet to parameters
int decodeESC_AccelerometerPacket(const void* pkt, int16_t* xAcc, int16_t* yAcc, int16_t* zAcc, uint8_t* fullscale, uint8_t* resolution);

//! return the packet ID for the ESC_Accelerometer packet
#define getESC_AccelerometerPacketID() (PKT_ESC_ACCELEROMETER)

//! return the minimum encoded length for the ESC_Accelerometer packet
#define getESC_AccelerometerMinDataLength() (8)

//! return the maximum encoded length for the ESC_Accelerometer packet
#define getESC_AccelerometerMaxDataLength() (8)

/*!
 * Warning and error status information
 */
typedef struct
{
    ESC_WarningBits_t warnings;
    ESC_ErrorBits_t   errors;  
}ESC_WarningErrorStatus_t;

//! Create the ESC_WarningErrorStatus packet
void encodeESC_WarningErrorStatusPacketStructure(void* pkt, const ESC_WarningErrorStatus_t* user);

//! Decode the ESC_WarningErrorStatus packet
int decodeESC_WarningErrorStatusPacketStructure(const void* pkt, ESC_WarningErrorStatus_t* user);

//! Create the ESC_WarningErrorStatus packet from parameters
void encodeESC_WarningErrorStatusPacket(void* pkt, const ESC_WarningBits_t* warnings, const ESC_ErrorBits_t* errors);

//! Decode the ESC_WarningErrorStatus packet to parameters
int decodeESC_WarningErrorStatusPacket(const void* pkt, ESC_WarningBits_t* warnings, ESC_ErrorBits_t* errors);

//! return the packet ID for the ESC_WarningErrorStatus packet
#define getESC_WarningErrorStatusPacketID() (PKT_ESC_WARNINGS_ERRORS)

//! return the minimum encoded length for the ESC_WarningErrorStatus packet
#define getESC_WarningErrorStatusMinDataLength() (4)

//! return the maximum encoded length for the ESC_WarningErrorStatus packet
#define getESC_WarningErrorStatusMaxDataLength() (4)

/*!
 * Motor status flags
 */
typedef struct
{
    uint16_t standbyCause;     //!< Cause of most recent standby event
    uint16_t disableCause;     //!< Cause of most recent disable event
    uint16_t offCause;         //!< Cause of most recent motor-stop event
    uint16_t failedStartCause; //!< Cause of most recent failed-start
}ESC_MotorStatusFlags_t;

//! Create the ESC_MotorStatusFlags packet
void encodeESC_MotorStatusFlagsPacketStructure(void* pkt, const ESC_MotorStatusFlags_t* user);

//! Decode the ESC_MotorStatusFlags packet
int decodeESC_MotorStatusFlagsPacketStructure(const void* pkt, ESC_MotorStatusFlags_t* user);

//! Create the ESC_MotorStatusFlags packet from parameters
void encodeESC_MotorStatusFlagsPacket(void* pkt, uint16_t standbyCause, uint16_t disableCause, uint16_t offCause, uint16_t failedStartCause);

//! Decode the ESC_MotorStatusFlags packet to parameters
int decodeESC_MotorStatusFlagsPacket(const void* pkt, uint16_t* standbyCause, uint16_t* disableCause, uint16_t* offCause, uint16_t* failedStartCause);

//! return the packet ID for the ESC_MotorStatusFlags packet
#define getESC_MotorStatusFlagsPacketID() (PKT_ESC_MOTOR_FLAGS)

//! return the minimum encoded length for the ESC_MotorStatusFlags packet
#define getESC_MotorStatusFlagsMinDataLength() (8)

//! return the maximum encoded length for the ESC_MotorStatusFlags packet
#define getESC_MotorStatusFlagsMaxDataLength() (8)

/*!
 * This packet contains the serial number for the ESC. Additionally there are
 * two extra values (each 16-bit) which can be programmed by the user for any
 * purpose.
 */
typedef struct
{
    uint8_t  HardwareRevision; //!< ESC hardware revision (OTP - not configurable by user)
    uint8_t  Model;            //!< ESC model (OTP - not configurable by user)
    uint16_t SerialNumber;     //!< ESC Serial Number (OTP - not configurable by user)
    uint16_t UserIDA;          //!< User ID Value A - user can set this value to any value
    uint16_t UserIDB;          //!< User ID Value B - user can set this value to any value
}ESC_Address_t;

//! Create the ESC_Address packet
void encodeESC_AddressPacketStructure(void* pkt, const ESC_Address_t* user);

//! Decode the ESC_Address packet
int decodeESC_AddressPacketStructure(const void* pkt, ESC_Address_t* user);

//! Create the ESC_Address packet from parameters
void encodeESC_AddressPacket(void* pkt, uint8_t HardwareRevision, uint8_t Model, uint16_t SerialNumber, uint16_t UserIDA, uint16_t UserIDB);

//! Decode the ESC_Address packet to parameters
int decodeESC_AddressPacket(const void* pkt, uint8_t* HardwareRevision, uint8_t* Model, uint16_t* SerialNumber, uint16_t* UserIDA, uint16_t* UserIDB);

//! return the packet ID for the ESC_Address packet
#define getESC_AddressPacketID() (PKT_ESC_SERIAL_NUMBER)

//! return the minimum encoded length for the ESC_Address packet
#define getESC_AddressMinDataLength() (8)

//! return the maximum encoded length for the ESC_Address packet
#define getESC_AddressMaxDataLength() (8)

/*!
 * This packet contains a zero-terminated string (max-length 8) used to
 * identify the particular ESC.
 */
typedef struct
{
    uint8_t ESCTitle[8]; //!< Description of this ESC
}ESC_Title_t;

//! Create the ESC_Title packet from parameters
void encodeESC_TitlePacket(void* pkt, const uint8_t ESCTitle[8]);

//! Decode the ESC_Title packet to parameters
int decodeESC_TitlePacket(const void* pkt, uint8_t ESCTitle[8]);

//! return the packet ID for the ESC_Title packet
#define getESC_TitlePacketID() (PKT_ESC_TITLE)

//! return the minimum encoded length for the ESC_Title packet
#define getESC_TitleMinDataLength() (8)

//! return the maximum encoded length for the ESC_Title packet
#define getESC_TitleMaxDataLength() (8)

/*!
 * This packet contains the firmware version of the ESC
 */
typedef struct
{
    uint8_t  versionMajor;     //!< Major firmware version number
    uint8_t  versionMinor;     //!< Minor firmware version numner
    uint8_t  versionDay;       //!< Firmware release date, day-of-month
    uint8_t  versionMonth;     //!< Firmware release data, month-of-year
    uint16_t versionYear;      //!< Firmware release date, year
    uint16_t firmwareChecksum; //!< Firmware checksum
}ESC_Firmware_t;

//! Create the ESC_Firmware packet
void encodeESC_FirmwarePacketStructure(void* pkt, const ESC_Firmware_t* user);

//! Decode the ESC_Firmware packet
int decodeESC_FirmwarePacketStructure(const void* pkt, ESC_Firmware_t* user);

//! Create the ESC_Firmware packet from parameters
void encodeESC_FirmwarePacket(void* pkt, uint8_t versionMajor, uint8_t versionMinor, uint8_t versionDay, uint8_t versionMonth, uint16_t versionYear, uint16_t firmwareChecksum);

//! Decode the ESC_Firmware packet to parameters
int decodeESC_FirmwarePacket(const void* pkt, uint8_t* versionMajor, uint8_t* versionMinor, uint8_t* versionDay, uint8_t* versionMonth, uint16_t* versionYear, uint16_t* firmwareChecksum);

//! return the packet ID for the ESC_Firmware packet
#define getESC_FirmwarePacketID() (PKT_ESC_FIRMWARE)

//! return the minimum encoded length for the ESC_Firmware packet
#define getESC_FirmwareMinDataLength() (8)

//! return the maximum encoded length for the ESC_Firmware packet
#define getESC_FirmwareMaxDataLength() (8)

/*!
 * This packet contains system runtime information
 */
typedef struct
{
    uint32_t millisecondsSinceReset; //!< Number of milliseconds since the ESC last experienced a reset/power-on event
    uint16_t powerCycles;            //!< Number of power cycle events that the ESC has experienced
    uint8_t  resetCode;              //!< Processor RESET code for debug purposes
    uint8_t  cpuOccupancy;           //!< Processor usage
}ESC_SystemInfo_t;

//! Create the ESC_SystemInfo packet
void encodeESC_SystemInfoPacketStructure(void* pkt, const ESC_SystemInfo_t* user);

//! Decode the ESC_SystemInfo packet
int decodeESC_SystemInfoPacketStructure(const void* pkt, ESC_SystemInfo_t* user);

//! Create the ESC_SystemInfo packet from parameters
void encodeESC_SystemInfoPacket(void* pkt, uint32_t millisecondsSinceReset, uint16_t powerCycles, uint8_t resetCode, uint8_t cpuOccupancy);

//! Decode the ESC_SystemInfo packet to parameters
int decodeESC_SystemInfoPacket(const void* pkt, uint32_t* millisecondsSinceReset, uint16_t* powerCycles, uint8_t* resetCode, uint8_t* cpuOccupancy);

//! return the packet ID for the ESC_SystemInfo packet
#define getESC_SystemInfoPacketID() (PKT_ESC_SYSTEM_INFO)

//! return the minimum encoded length for the ESC_SystemInfo packet
#define getESC_SystemInfoMinDataLength() (8)

//! return the maximum encoded length for the ESC_SystemInfo packet
#define getESC_SystemInfoMaxDataLength() (8)

/*!
 * This packet contains the telemetry packet configuration
 */
typedef struct
{
    ESC_TelemetryConfig_t settings;      //!< Telemetry settings
    char                  apiVersion[5]; //!< The API version of the ESC. Field is encoded constant.
}ESC_TelemetrySettings_t;

//! Create the ESC_TelemetrySettings packet from parameters
void encodeESC_TelemetrySettingsPacket(void* pkt, const ESC_TelemetryConfig_t* settings);

//! Decode the ESC_TelemetrySettings packet to parameters
int decodeESC_TelemetrySettingsPacket(const void* pkt, ESC_TelemetryConfig_t* settings, char apiVersion[5]);

//! return the packet ID for the ESC_TelemetrySettings packet
#define getESC_TelemetrySettingsPacketID() (PKT_ESC_TELEMETRY_SETTINGS)

//! return the minimum encoded length for the ESC_TelemetrySettings packet
#define getESC_TelemetrySettingsMinDataLength() (4)

//! return the maximum encoded length for the ESC_TelemetrySettings packet
#define getESC_TelemetrySettingsMaxDataLength() (8)

/*!
 * This packet contains information on the non-volatile ESC settings
 */
typedef struct
{
    bool     settingsLocked;    //!< Set if the ESC settings are locked
    uint8_t  version;           //!< Version of EEPROM data
    uint16_t size;              //!< Size of settings data
    uint16_t checksum;          //!< Settings checksum
    uint16_t validatedChecksum; //!< Validated settings checksum
}ESC_EEPROMSettings_t;

//! Create the ESC_EEPROMSettings packet
void encodeESC_EEPROMSettingsPacketStructure(void* pkt, const ESC_EEPROMSettings_t* user);

//! Decode the ESC_EEPROMSettings packet
int decodeESC_EEPROMSettingsPacketStructure(const void* pkt, ESC_EEPROMSettings_t* user);

//! Create the ESC_EEPROMSettings packet from parameters
void encodeESC_EEPROMSettingsPacket(void* pkt, bool settingsLocked, uint8_t version, uint16_t size, uint16_t checksum, uint16_t validatedChecksum);

//! Decode the ESC_EEPROMSettings packet to parameters
int decodeESC_EEPROMSettingsPacket(const void* pkt, bool* settingsLocked, uint8_t* version, uint16_t* size, uint16_t* checksum, uint16_t* validatedChecksum);

//! return the packet ID for the ESC_EEPROMSettings packet
#define getESC_EEPROMSettingsPacketID() (PKT_ESC_EEPROM)

//! return the minimum encoded length for the ESC_EEPROMSettings packet
#define getESC_EEPROMSettingsMinDataLength() (5)

//! return the maximum encoded length for the ESC_EEPROMSettings packet
#define getESC_EEPROMSettingsMaxDataLength() (7)

/*!
 * ESC telltales
 */
typedef struct
{
    uint8_t  maxTemperature;      //!< Maximum recorded internal temperature
    uint8_t  maxFetTemperature;   //!< Maximum recorded MOSFET temperature
    uint8_t  maxMotorTemperature; //!< Maximum recorded motor temperature
    uint8_t  maxRippleVoltage;    //!< Maximum recorded battery voltage
    float    maxBatteryCurrent;   //!< Maximum recorded battery current
    float    maxRegenCurrent;     //!< Maximum recorded regen current
    uint16_t totalStarts;         //!< Number of successful motor start events
    uint16_t failedStarts;        //!< Number of failed motor start events
    uint32_t escRunTime;          //!< ESC run time
    uint32_t motorRunTime;        //!< Motor run time
    uint32_t desyncEvents;        //!< Number of recorded motor desync events
}ESC_TelltaleValues_t;

//! Create the ESC_TelltaleValues packet
void encodeESC_TelltaleValuesPacketStructure(void* pkt, const ESC_TelltaleValues_t* user);

//! Decode the ESC_TelltaleValues packet
int decodeESC_TelltaleValuesPacketStructure(const void* pkt, ESC_TelltaleValues_t* user);

//! Create the ESC_TelltaleValues packet from parameters
void encodeESC_TelltaleValuesPacket(void* pkt, uint8_t maxTemperature, uint8_t maxFetTemperature, uint8_t maxMotorTemperature, uint8_t maxRippleVoltage, float maxBatteryCurrent, float maxRegenCurrent, uint16_t totalStarts, uint16_t failedStarts, uint32_t escRunTime, uint32_t motorRunTime, uint32_t desyncEvents);

//! Decode the ESC_TelltaleValues packet to parameters
int decodeESC_TelltaleValuesPacket(const void* pkt, uint8_t* maxTemperature, uint8_t* maxFetTemperature, uint8_t* maxMotorTemperature, uint8_t* maxRippleVoltage, float* maxBatteryCurrent, float* maxRegenCurrent, uint16_t* totalStarts, uint16_t* failedStarts, uint32_t* escRunTime, uint32_t* motorRunTime, uint32_t* desyncEvents);

//! return the packet ID for the ESC_TelltaleValues packet
#define getESC_TelltaleValuesPacketID() (PKT_ESC_TELLTALES)

//! return the minimum encoded length for the ESC_TelltaleValues packet
#define getESC_TelltaleValuesMinDataLength() (3)

//! return the maximum encoded length for the ESC_TelltaleValues packet
#define getESC_TelltaleValuesMaxDataLength() (24)

/*!
 * Git commit hash for the ESC firmware
 */
typedef struct
{
    char hash[8]; //!< git commit hash
}ESC_GitHash_t;

//! Create the ESC_GitHash packet from parameters
void encodeESC_GitHashPacket(void* pkt, const char hash[8]);

//! Decode the ESC_GitHash packet to parameters
int decodeESC_GitHashPacket(const void* pkt, char hash[8]);

//! return the packet ID for the ESC_GitHash packet
#define getESC_GitHashPacketID() (PKT_ESC_GIT_HASH)

//! return the minimum encoded length for the ESC_GitHash packet
#define getESC_GitHashMinDataLength() (1)

//! return the maximum encoded length for the ESC_GitHash packet
#define getESC_GitHashMaxDataLength() (8)

/*!
 * PWM input calibration
 */
typedef struct
{
    uint8_t  protocol;     //!< Protocol version (reserved for future use). Field is encoded constant.
    int8_t   pwmOffset;    //!< PWM offset compensation value
    uint16_t inputMin;     //!< PWM value corresponding with 0% throttle
    uint16_t inputMax;     //!< PWM value corresponding with 1000% throttle
    uint16_t armThreshold; //!< PWM arming threshold
}ESC_PWMInputCalibration_t;

//! Create the ESC_PWMInputCalibration packet
void encodeESC_PWMInputCalibrationPacketStructure(void* pkt, const ESC_PWMInputCalibration_t* user);

//! Decode the ESC_PWMInputCalibration packet
int decodeESC_PWMInputCalibrationPacketStructure(const void* pkt, ESC_PWMInputCalibration_t* user);

//! Create the ESC_PWMInputCalibration packet from parameters
void encodeESC_PWMInputCalibrationPacket(void* pkt, int8_t pwmOffset, uint16_t inputMin, uint16_t inputMax, uint16_t armThreshold);

//! Decode the ESC_PWMInputCalibration packet to parameters
int decodeESC_PWMInputCalibrationPacket(const void* pkt, uint8_t* protocol, int8_t* pwmOffset, uint16_t* inputMin, uint16_t* inputMax, uint16_t* armThreshold);

//! return the packet ID for the ESC_PWMInputCalibration packet
#define getESC_PWMInputCalibrationPacketID() (PKT_ESC_PWM_INPUT_CALIBRATION)

//! return the minimum encoded length for the ESC_PWMInputCalibration packet
#define getESC_PWMInputCalibrationMinDataLength() (8)

//! return the maximum encoded length for the ESC_PWMInputCalibration packet
#define getESC_PWMInputCalibrationMaxDataLength() (8)

#ifdef __cplusplus
}
#endif
#endif // _ESCPACKETS_H
