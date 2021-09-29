#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] == c)
			j = i;
		i++;
	}
	if (s[j] == c)
		return ((char *)&s[j]);
	return (NULL);
}
