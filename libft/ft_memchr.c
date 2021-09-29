#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	sym;

	str = (unsigned char *) s;
	sym = (unsigned char) c;
	while (*str && n)
	{
		if (*str == sym)
			return (str);
		str++;
		n--;
	}
	if (n > 0 && sym == '\0')
		return (str);
	return (NULL);
}
