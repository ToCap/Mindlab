/*
 ***************************************************************************************************
 * MindLab - the open source programming language for Mindstorm https://github.com/ToCap/Mindlab
 *
 * Copyright (C) 2022  GC-MS Software (ThomTheCat)
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.
 *
 *  Software distributed under the License is distributed on an "AS IS"
 *  basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
 *  License for the specific language governing rights and limitations
 *  under the License.
 ***************************************************************************************************
*/


#pragma once

/*
***************************************************************************************************
* Constants
***************************************************************************************************
*/


/**
* @brief Define size of pointer given in bytes on 32-bit CPU
*/
#define STD_CPU_TYPE_32    4u

/**
* @brief Define size of pointer given in bytes on 64-bit CPU
*/
#define STD_CPU_TYPE_64    8u


/**
* @brief Define position of most and least significant byte depending on platform
*/
#define STD_MSB_FIRST       0u          /* Big Endian bit ordering     */
#define STD_LSB_FIRST       1u          /* Little Endian bit ordering  */



/**
* @brief Define size of pointer given in bytes on 64-bit CPU
*/
#define STD_HIGH_BYTE_FIRST   0u          /* Big Endian byte ordering    */
#define STD_LOW_BYTE_FIRST    1u          /* Little Endian byte ordering */




/**
* @brief Defines FALSE boolean value if it doesn't exist.
*/
#define STD_FALSE 0
#ifndef FALSE
#define FALSE   STD_FALSE
#endif

/**
* @brief Defines TRUE boolean value if it doesn't exist.
*/
#define STD_TRUE 1
#ifndef TRUE
#define TRUE    STD_TRUE
#endif


/**
* @brief Defines maximum value of an unsigned 8-bit integer
*/
#define STD_UINT8_MAX 0xFF


/**
* @brief Defines minimum value of an unsigned 8-bit integer
*/
#define STD_UINT8_MIN 0


/**
* @brief Defines maximum value of an unsigned 16-bit integer
*/
#define STD_UINT16_MAX 0xFFFF


/**
* @brief Defines minimum value of an unsigned 16-bit integer
*/
#define STD_UINT16_MIN 0


/**
* @brief Defines maximum value of an unsigned 32-bit integer
*/
#define STD_UINT32_MAX 0xFFFFFFFF


/**
* @brief Defines minimum value of an unsigned 32-bit integer
*/
#define STD_UINT32_MIN 0


/**
* @brief Defines maximum value of a signed 32-bit integer
*/
#define STD_SINT8_MAX 127


/**
* @brief Defines minimum value of a signed 32-bit integer
*/
#define STD_SINT8_MIN -127


/**
* @brief Defines maximum value of a signed 16-bit integer
*/
#define STD_SINT16_MAX 32767


/**
* @brief Defines minimum value of a signed 16-bit integer
*/
#define STD_SINT16_MIN -32768


/**
* @brief Defines maximum value of a signed 32-bit integer
*/
#define STD_SINT32_MAX 2147483647

/**
* @brief Defines minimum value of a signed 32-bit integer
*/
#define STD_SINT32_MIN -2147483648


