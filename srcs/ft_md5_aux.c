#include "../incs/ft_ssl.h"

/*
In addition MD5 uses four auxiliary functions that each take as input three 32-bit words and produce as output one 32-bit word. They apply the logical operators and, or, not and xor to the input bits.

          F(X,Y,Z) = (X and Y) or (not(X) and Z)
          G(X,Y,Z) = (X and Z) or (Y and not(Z))
          H(X,Y,Z) = X xor Y xor Z
          I(X,Y,Z) = Y xor (X or not(Z))

Operators	Meaning of operators
&	        Bitwise AND
|	        Bitwise OR
^	        Bitwise XOR
~	        Bitwise complement
<<	        Shift left
>>	        Shift right
*/

int     f_aux(int x, int y, int z)
{
    return ((x & y) | ((!x) & z));
}

int     g_aux(int x, int y, int z)
{
    return ((x & z) | (y & (!z)));
}

int     h_aux(int x, int y, int z)
{
    return (x ^ y ^ z);
}

int     i_aux(int x, int y, int z)
{
    return (y ^ (x | (!z)));
}