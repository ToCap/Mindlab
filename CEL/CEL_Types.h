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
* Constants
***************************************************************************************************
*/


typedef enum CEL_operation {
    Text,
    Constant,
    Addition,
    Subtraction,
    Multiplication,
    Division
} CEL_operation_e;


typedef struct CEL_expr 
{
    CEL_operation_e   oper;
    double      number;
    void* op1;
    void* op2;
} CEL_expr_t;
