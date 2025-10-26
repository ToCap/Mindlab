
**CEL** stands for **"C Eval-Like"**, inspired by Python's `eval()` function.  This module allows inline evaluation of mathematical expressions within strings at runtime, in C.

# CEL Expression String Format

The `str` parameter passed to `CEL_evaluate` shall follow a specific formatting convention that mixes plain text and inline mathematical expressions as follows :
 - one or more mathematical expression enclosed in curly braces '{}'
 - any alphanumeric characters (except curly braces)

A mathematical expression follows this prototype
{expression:format}
The expression specifier is a mathematical expression supporting almost all C-language operators
|Operator name 	            |Syntax                |
|---------------------------|----------------------|
|Addition 	|a + b 	|
|Subtraction 	|a - b|
|Multiplication 	|a * b|
|Division 	|a / b 	|
|Remainder 	|a % b 	|
|Bitwise NOT 	|~a 	|
|Bitwise AND 	|a & b|
|Bitwise OR 	|a | b |
|Bitwise XOR 	|a ^ b 	|
|Bitwise left shift 	|a << b |
|Bitwise right shift 	|a >> b 	|

Note the operator precedence is respected** like in standard C or Python expressions.  
  For example:  
  - Input: `"Result is {1+2*3}"`  
  - Output: `"Result is 7.000000"`

The format specifier is optionnal, by **default**, the result of an expression is formatted as a **double-precision floating-point number**, using the `"%f"` format with 6 digits after the decimal point.
Default formatting can be overriden by specifying a **custom `printf`-style format string** inside the expression, using a colon (`:`) to separate the expression from the format

