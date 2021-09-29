#include "libft.h"

char	*ft_substr(char const *s, unsigned int start,
				size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = (char *) malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}	
		i++;
	}
	str[j] = 0;
	return (str);
}
