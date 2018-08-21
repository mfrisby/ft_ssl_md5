#include "../incs/ft_ssl.h"

int   print_errors_cmds(char *s)
{
    ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", s);
    ft_printf("Standard commands:\n\nMessage Digest commands:\n");
    ft_printf("md5\nsha256\n\nCipher commands:\n");
    return (-1);
}

/*
* i dont know if i'll need multiple cmd after
*/
int    get_command(t_env *e, char *s)
{
    if ((ft_strcmp(s, "md5")) != 0 && (ft_strcmp(s, "sha256") != 0))
        return (-1);
    e->cmds = malloc(sizeof(char*) * 2);
    e->cmds[0] = ft_strdup(s);
    e->cmds[1] = NULL;
    return (0);
}

void    get_argument(t_env *e, char *s)
{
    if (e->args == NULL)
        e->args = malloc(sizeof(char*) * 2);
    e->args = malloc(sizeof(char*) * 2);
    e->args[0] = ft_strdup(s);
    e->args[1] = NULL;
}

//md5 -s string
void    get_options(t_env *e, char *s)
{
    if (e->opts == NULL)
        e->opts = malloc(sizeof(char*) * 2);
    e->opts[0] = ft_strdup(s);
    e->opts[1] = NULL;
}

int     parse_entry(t_env *e, int ac, char **av)
{
    int i;

    i = 2;
    if ((get_command(e, av[1])) == -1)
        return (print_errors_cmds(av[1]));
    while (i < ac && av[i])
    {
        if (av[i][0] == '-')
            get_options(e, av[i]);
        else
            get_argument(e, av[i]);
        i++;
    }
    return (0);
}