/*
 ***************************************************************************************************
 * MIRAGE - the open source runtime abstraction for Mindstorm https://github.com/ToCap/Mars
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
 * Includes
 ***************************************************************************************************
*/

#include "CEL_Types.h"


/*
***************************************************************************************************
* Services
***************************************************************************************************
*/


/**
 * @ingroup CEL
 * @brief Evaluates a CEL expression from a string, similar to Python's eval function
 *
 * This function parses and evaluates the CEL expression provided as a string,
 * then writes the string representation of the result into the provided output buffer
 *
 * It behaves similarly to Python's eval by interpreting the expression at runtime
 *
 * @param str The CEL expression to evaluate, represented as a null-terminated string
 * @param output A buffer where the evaluation result as a string will be stored
 * @param size The size of the output buffer in bytes. The function will not write more than this size to avoid buffer overflow
 */
extern void CEL_evaluate(char* str, char* output, int size);


/**
 * @ingroup CEL
 * @brief Parses a expression from a string
 *
 * This function converts a string representing a expression into
 * an internal data structure for later evaluation
 *
 * @param str A string containing the CEL expression to parse
 * @return A pointer to the CEL_expr_t structure representing the parsed expression
 */
extern CEL_expr_t* CEL_parseExpression(char* str);

/**
 * @ingroup CEL
 * @brief Releases the memory allocated for a CEL expression
 *
 * This function should be called to release resources associated
 * with a previously parsed CEL expression
 *
 * @param e Pointer to the CEL expression to free
 */
extern void CEL_freeExpr(CEL_expr_t* e);


/**
 * @ingroup CEL
 * @brief Evaluates a previously parsed CEL expression
 *
 * This function computes and returns the numeric value resulting
 * from the CEL expression pointed to by @p e
 *
 * @param e Pointer to the CEL expression to evaluate
 * @return The result of the evaluation as a double
 */
extern double CEL_evaluateExpression(CEL_expr_t* e);


/*
 * Replaces variables of the form _key_ with their corresponding values in the input string
 *
 * str    : input string
 * output : output string
 * size   : size of the output buffer
 * count  : number of key/value pairs
 * ...    : N pairs of (char* key, double value)
 */
extern void CEL_replaceVariables(const char* str, char* output, int size, int count, ...);