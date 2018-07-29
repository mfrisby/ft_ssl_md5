#ifndef FT_SSL_H
# define FT_SSL_H

# include <unistd.h>
# include "../libft/includes/libft.h"

typedef struct      s_env
{
    char            **cmds;
    char            **args;
    char            **opts;
}                   t_env;

int     parse_entry(t_env *e,int ac, char **av);
char    *ft_md5(char *input);
int     *w_tab();
int     *k_tab();
int     *s_tab();
int     f_aux(int x, int y, int z);
int     g_aux(int x, int y, int z);
int     h_aux(int x, int y, int z);
int     i_aux(int x, int y, int z);
int     a_word();
int     b_word();
int     c_word();
int     d_word();

#endif