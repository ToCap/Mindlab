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


/*
 ***************************************************************************************************
 * Includes
 ***************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CEL.h"
#include "CEL_Types.h"


/*
 ***************************************************************************************************
 * Local private functions
 ***************************************************************************************************
*/

CEL_expr_t* parseExpr(char** str);
CEL_expr_t* parseTerm(char** str);
CEL_expr_t* parseFactor(char** str);
void skipWhitespace(char** str);



/*
 ***************************************************************************************************
 * Functions
 ***************************************************************************************************
*/

void skipWhitespace(char** str)
{
    while (**str && isspace((unsigned char)**str)) 
    {
        (*str)++;
    }
}

CEL_expr_t* parseTerm(char** str) 
{
    /* Declaration of local variables */
    CEL_expr_t* e;
    CEL_expr_t* tempExpr;

    /* parse the first factor */
    e = parseFactor(str);

    /*  loop while there are no more factor in current term */
    while (1)
    {
        skipWhitespace(str);
        if (**str != '*' && **str != '/') break;

        /* create new expression for current factor */
        tempExpr = e;
        e = calloc(1, sizeof(CEL_expr_t));
        e->op1 = (void*)tempExpr;
        /* HINTS : current expression becomes a sub-expression of new one */

        switch (**str) 
        {
            case '*': 
            {
                e->oper = Multiplication;
                (*str)++;
                break;
            }
            
            case '/': 
            {
                e->oper = Division;
                (*str)++;
                break;
            }
        }

        /*  parse the next factor */
        e->op2 = parseFactor(str);
    }

    return e;
}

CEL_expr_t* parseFactor(char** str) 
{
    /* Declaration of local variables */
    CEL_expr_t* e;
    char* tempStr;

    /* check if next character is a parenthesis */
    if (**str == '(')
    {
        (*str)++;/* skip over '(' */
        e = parseExpr(str);
        (*str)++; /* skip over ')' */
        return e;
    }

    /*  parse the constant */
    e = calloc(1, sizeof(CEL_expr_t));
    e->oper = Constant;
    e->number = strtod(*str, &tempStr);
    e->op1 = 0;
    e->op2 = 0;

    *str = tempStr;

    return e;
}



CEL_expr_t* parseExpr(char** str) 
{

    /* Declaration of local variables */
    CEL_expr_t* e;
    CEL_expr_t* tempExpr;

    /*  parse the first term */
    e = parseTerm(str);

    /*  loop while there are no more terms in current expression */
    while (1)
    {
        skipWhitespace(str);
        if ((**str != '+') && (**str != '-')) break;
        /* create new expression for current term */
        tempExpr = e;
        e = calloc(1, sizeof(CEL_expr_t));
        e->op1 = tempExpr;
        /* HINTS : current expression becomes a sub-expression of new one */
   
        switch (**str) 
        {
            case '+': 
            {
                e->oper = Addition;
                (*str)++;
                break;
            }
            case '-': 
            {
                e->oper = Subtraction;
                (*str)++;
                break;
            }
        }

        /*  parse the next term */
        e->op2 = parseTerm(str);
    }

    return e;
}


void CEL_evaluate(char* str, char* output, int size)
{
    /* Declaration of local variables */
    char* start = strchr(str, '{');
    char* stop = start;

    int index = 0;
    while (start != NULL)
    {
        /* compute size of string before current start tag and last stop tag */
        int tempSize = start - stop - 1;
        if (tempSize < 0)
        {
            tempSize = 0;
        }

        /* copy string content before current start tag */
        memcpy(output + index, stop + 1, tempSize);
        index += tempSize;

        /* check if a format is specified */
        char frmt[32] = { 0 };
        char* format = strchr(start + 1, ':');

        /* check if linked stop tag exists */
        stop = strchr(start + 1, '}');
        if (stop != NULL)
        {
            /* check if format is valid */
            char* stopExpr = stop;
            if ((format > start) && (format < stop))
            {
                /* extract format information */
                memcpy(frmt, format + 1, stop - format - 1);
                stopExpr = format;/* force stop tag to ignore format for expressionn */
            }

            /* extract expression between start and stop tags */
            char expression[512] = { 0 };
            memcpy(expression, start + 1, (stopExpr) - (start + 1));
            
            /* analyse expression */
            CEL_expr_t* e = CEL_parseExpression(expression);

            /* evaluate expression */
            double result = CEL_evaluateExpression(e);

            /* concatenate expression result to output */
            index += snprintf(output + index, 512, frmt, result);

            /* release resources */
            CEL_freeExpr(e);
            
        }
        else
        {
            //printf("ERROR : ");
        }
        start = strchr(start + 1, '{');
    }

}

CEL_expr_t* CEL_parseExpression(char* str)
{

    return parseExpr(&str);
}


double CEL_evaluateExpression(CEL_expr_t* e) 
{

    switch (e->oper)
    {
        case Constant: 
        {
            return e->number;
        }

        case Addition: 
        {
            return CEL_evaluateExpression(e->op1) + CEL_evaluateExpression(e->op2);
        }

        case Subtraction: 
        {
            return CEL_evaluateExpression(e->op1) - CEL_evaluateExpression(e->op2);
        }

        case Multiplication: 
        {
            return CEL_evaluateExpression(e->op1) * CEL_evaluateExpression(e->op2);
        }

        case Division: 
        {
            return CEL_evaluateExpression(e->op1) / CEL_evaluateExpression(e->op2);
        }

    }

    return 0.0;
    /* HINTS : This line is only for compiler as should be never reached */
}


void CEL_freeExpr(CEL_expr_t* e) 
{

    if (e == NULL) 
    {
        return;
    }

    CEL_freeExpr((CEL_expr_t*)e->op1);
    CEL_freeExpr((CEL_expr_t*)e->op2);

    free(e);

}