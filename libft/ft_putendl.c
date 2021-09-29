#include "libft.h"

void    ft_putendl(char *s)
{
    int     i;

    i = 0;
    while(str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
    ft_putchar('\n');
}
