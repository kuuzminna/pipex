#include "libft.h"

int	ft_numLen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		minus;
	char	*str;
	int		i;

	minus = 0;
	if (n < 0)
	{
		minus++;
		n *= -1;
	}
	str = (char *) malloc(sizeof(str) * (ft_numLen(n) + minus + 1));
	if (minus)
	{
		str[0] = '-';
	}
	i = ft_numLen(n) + minus - 1;
	while (i >= (0 + minus))
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	str[ft_numLen(n) + minus] = '\0';
	return (str);
}
