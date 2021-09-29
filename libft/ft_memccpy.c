#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
	int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *) dst;
	str2 = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		str1[i] = str2[i];
		if ((unsigned char)c == str1[i])
			return (&str1[i + 1]);
		i++;
	}
	return (NULL);
}
