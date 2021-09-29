#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	s;
	void			*c;

	s = count * size;
	c = malloc(s);
	if (c)
		c = ft_memset(c, 0, s);
	return (c);
}
