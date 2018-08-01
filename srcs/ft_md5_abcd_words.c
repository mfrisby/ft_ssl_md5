#include "../incs/ft_ssl.h"

int     a_word(int get, int value)
{
    static int a = 0x67452301;

    if (get == 1)
        return (a);
    else
        a += value;
    return (a);
}

int     b_word(int get, int value)
{
    static int b = 0xefcdab89;

    if (get == 1)
        return (b);
    else
        b += value;
    return (b);
}

int     c_word(int get, int value)
{
    static int c = 0x98badcfe;

    if (get == 1)
        return (c);
    else
        c += value;
    return (c);
}

int     d_word(int get, int value)
{
    static int d = 0x10325476;
    
    if (get == 1)
        return (d);
    else
        d += value;
    return (d);
}

void     values_setter(int a, int b, int c, int d)
{
        a_word(0, a);
        b_word(0, b);
        c_word(0, c);
        d_word(0, d);
}