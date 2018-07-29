#include "../incs/ft_ssl.h"

int     main(int ac, char **av)
{
    t_env *e;

    if (ac < 3)
    {
        ft_putendl("usage: ft_ssl command [command opts] [command args]");
        return (-1);
    }
    e = malloc(sizeof(t_env));
    if ((parse_entry(e, ac, av)) == -1)
        return (-1);
    ft_md5();
    return (0);
}