#include "../incs/ft_ssl.h"

/*
 * unsigned char	1 byte	0 to 255
 * signed char	1 byte	-128 to 127
 */

/*
The MD5 algorithm first divides the input in blocks of 512 bits each. 64 Bits are inserted at the end of the last block.
These 64 bits are used to record the length of the original input.
If the last block is less than 512 bits, some extra bits are 'padded' to the end.
Next, each block is divided into 16 words of 32 bits each. These are denoted as M0 ... M15.
*/

/*
 * produit un message de 128bits
 */
char       *ft_md5(char *input)
{
    printf("%f\n", (floor(ft_strlen(input)/512)));
    //int size = sizeof(input)/512;
    ft_printf("output f = %d\n", f_aux(00001100, 00011001, 00001000));
    ft_printf("output g = %d\n", g_aux(00001100, 00011001, 00001000));
    ft_printf("output h = %d\n", h_aux(00001100, 00011001, 00001000));
    ft_printf("output i = %d\n", i_aux(00001100, 00011001, 00001000));
    // char    *msg;
    // int *s;
    // int *k;
    // int *w;

    // msg = malloc(128);
    // ft_bzero(msg, 128);
    // s = s_tab();
    // k = k_tab();
    // w = w_tab();
//    input = ft_strdup("9e107d9d372bb6826bd81d3542a419d6");
    return (input);
}