/*
 * Copyright (C) 2021 iOTA
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/**
 * @file ota.h
 * @brief OTA
 */
#ifndef _OTA_H
#define _OTA_H

/*-------------------------- OTA enumerated types --------------------------*/

/**
 * @ingroup ota_enum_types
 * @brief The OTA API return status.
 * OTA client errors returned by the OTA API's
 */
typedef enum otaErr
{
  otaErrUnknown = -1,
  otaErrNone = 0,
  OtaErrUninitialized,
  otaErrInvalidArgument,

  NumberOfOtaErrors                   /* @brief Add the values above. DO NOT ADD ANY NEW VALUES AFTER THIS*/
} otaErr_t;


/**
 * @ingroup ota_enum_types
 * @brief OTA client states.
 *
 * The current state of the OTA Client.
 *
 * @note Current library supports only single context of OTA client.
 */
typedef enum otaState
{
  otaStateUninitialized = -1,
  otaStateInitDone = 0,
  otaStateReady,
  otaStateJsonProcess,
  otaStateBinaryProcess,
  otaStateSubsystemProcess,
  otaStateSuspend,
  otaStateStop,
  otaStateError,

  NumberOfOtaStates                     /* @brief Add the values above. DO NOT ADD ANY NEW VALUES AFTER THIS*/
} otaState_t;


/**
 * @ingroup ota_enum_types
 * @brief OTA json document parser error codes.
 */
typedef enum otaJsonParseErr
{
    otaJsonParseErrUnknown = -1,        /* @brief The error code has not yet been set by a logic path. */
    otaJsonParseErrNone = 0,            /* @brief Signifies no error has occurred. */
    otaJsonParseErrNoFile,              /* @brief No Json file is present. */
    otaJsonParseErrZeroFileSize,        /* @brief Json document specified a zero sized file. This is not allowed. */
    otaJsonParseErrCorruptedFile,       /* @brief Json downloaded is corrupted. */
    otaJsonParseErrUnknownFormatFound,  /* @brief Json is not in known format. May be MIM is trying to get into system */

    NumberofotaJsonParseErr             /* @brief Add the values above. DO NOT ADD ANY NEW VALUES AFTER THIS*/
} otaJsonParseErr_t;


typedef struct ota
{

} ota_t;

#endif //_OTA_H

