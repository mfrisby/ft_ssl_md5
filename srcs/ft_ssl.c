#include "../incs/ft_ssl.h"

void     test_md5()
{
    char *ret;

    ret = ft_md5("The quick brown fox jumps over the lazy dog");
    if ((ft_strcmp(ret, "9e107d9d372bb6826bd81d3542a419d6")) != 0)
        ft_putendl("test failed 1");
    else
        ft_putendl("test succeed 1");

    ret = ft_md5("The quick brown fox jumps over the lazy dog.");
    if ((ft_strcmp(ret, "e4d909c290d0fb1ca068ffaddf22cbd0")) != 0)
        ft_putendl("test failed 2");
    else
        ft_putendl("test succeed 2");

     ret = ft_md5("The quick brown fox jumps over the lazy dog.00000000000000000000000The quick brown fox jumps over the lazy dog.00000000000000000000000The quick brown fox jumps over the lazy dog.00000000000000000000000The quick brown fox jumps over the lazy dog.00000000000000000000000The quick brown fox jumps over the lazy dog.00000000000000000000000The quick brown fox jumps over the lazy dog.00000000000000000000000The quick brown fox jumps over the lazy dog.00000000000000000000000The quick brown fox jumps over the lazy dog.00000000000000000000000The quick brown fox jumps over the lazy dog.00000000000000000000000The quick brown fox jumps over the lazy dog.00000000000000000000000The quick brown fox jumps over the lazy dog.00000000000000000000000The quick brown fox jumps over the lazy dog.00000000000000000000000The quick brown fox jumps over the lazy dog.00000000000000000000000The quick brown fox jumps over the lazy dog.00000000000000000000000");
    if ((ft_strcmp(ret, "e4d909c290d0fb1ca068ffaddf22cbd0")) != 0)
        ft_putendl("test failed 2");
    else
        ft_putendl("test succeed 2"); 
}

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
    test_md5();
    return (0);
}