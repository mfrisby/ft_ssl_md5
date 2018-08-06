#ifndef FT_SSL_H
# define FT_SSL_H

# include <unistd.h>
# include "../libft/includes/libft.h"

typedef struct      s_md5
{
    int             f;
    int             g;
    //words
    int             a;
    int             b;
    int             c;
    int             d;
    //input divide
    char            **tab;
}                   t_md5;

typedef struct      s_env
{
    char            **cmds;
    char            **args;
    char            **opts;
}                   t_env;

int     parse_entry(t_env *e,int ac, char **av);
char    *ft_md5(char *input);
int     *w_tab();
int     *r_tab();
int     *k_tab();
int     *s_tab();
int     f_aux(int x, int y, int z);
int     g_aux(int x, int y, int z);
int     h_aux(int x, int y, int z);
int     i_aux(int x, int y, int z);
void     values_setter(int a, int b, int c, int d);
int     a_word();
int     b_word();
int     c_word();
int     d_word();
int left_rotate_32(int n, unsigned int d);
int right_rotate_32(int n, unsigned int d);

#endif