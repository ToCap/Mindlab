

#include <stdio.h>

#include "CEL.h"

void main(void)
{
	char   str[100] = "{1+2*3:%.2af} abc {1+1}";

	char output[100] = { 0 };

	CEL_expr_t* e = 0;
	
	CEL_evaluate(str, output, 100);

	//e = CEL_parseExpression(str);

	//printf("ddddd %f", CEL_evaluateExpression(e));
}