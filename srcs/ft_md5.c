#include "../incs/ft_ssl.h"

static char    **init_tab(int divide, char *input)
{
    int         i;
    char        **new;
    
    i = 0;
    new = malloc(sizeof(char*) * divide);
    while (i < divide)
    {
        new[i] = ft_strnew(512);
        new[i] = ft_strcpy(new[i], input);
        i++;
    }
    return (new);
}

char        **init_m_16(t_md5 *md5, char **m, int i)
{
    int y;

    y = 0;
    while (y < 16)
    {
        m[y] = malloc(32);
        m[y] = ft_strncpy(m[i], md5->tab[i] + ((y + 1) * 16), 16);//c'est moche olala
        ft_putendl(m[y]);
        y++;
    }
    return (m);
}

void        divide_64(t_md5 *md5, char **m16)
{
    int     y;
    
    y = 0;
    (void)m16;
    while (y < 64)
    {
        if (y >= 0 && y <= 15)
        {
            md5->f = f_aux(md5->b, md5->c, md5->d);
            md5->g = y;
        }
        else if (y > 15 && y <= 31)
        {
            md5->f = f_aux(md5->d, md5->b, md5->c);
            md5->g = (5 * y + 1) % 16; 
        }
        else if (y > 31 && y <= 47)
        {
            md5->f = h_aux(md5->b, md5->c, md5->d);
            md5->g = (3 * y + 5) % 16; 
        }
        else if (y > 47 && y <= 63)
        {
            md5->f = i_aux(md5->c, md5->b, md5->d);
            md5->g = (7 * y) % 16;
        }
        md5->d = md5->c;
        md5->c = md5->b;
        //md5->b = (md5->a + md5->f + (k_tab())[y] + m16[g]);// * left_rotate_32 r[i] + b
        md5->a = md5->d;
        y++;
    }
}

void        divide_512(int divide, t_md5 *md5)
{
    int     i;
    char    **m16;

    i = 0;
    m16 = malloc(sizeof(char*) * 17);
    m16[16] = NULL;
    while (i < divide && md5->tab && md5->tab[i])
    {
        //divide tab512 in m16
        m16 = init_m_16(md5, m16, i);
        md5->f = 0;
        md5->g = 0;
        md5->a = a_word(1, 0);
        md5->b = b_word(1, 0);
        md5->c = c_word(1, 0);
        md5->d = d_word(1, 0);
        divide_64(md5, m16);
        values_setter(md5->a, md5->b, md5->c, md5->d);
        i++;
    }
}

char       *ft_md5(char *input)
{
    int     divide;
    t_md5   *md5;

    divide = (int)(ft_strlen(input) / 512) + 1;
    md5 = malloc(sizeof(t_md5));
    md5->tab = init_tab(divide, input);
    divide_512(divide, md5);
    return (input);
}
/*     ft_printf("output f = %d\n", f_aux(00001100, 00011001, 00001000));
    ft_printf("output g = %d\n", g_aux(00001100, 00011001, 00001000));
    ft_printf("output h = %d\n", h_aux(00001100, 00011001, 00001000));
    ft_printf("output i = %d\n", i_aux(00001100, 00011001, 00001000)); */