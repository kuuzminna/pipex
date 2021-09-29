#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*c;

	if (!(dst) && !(src))
		return (NULL);
	d = (unsigned char *) dst;
	c = (unsigned char *) src;
	if (c < d)
		while (len--)
			d[len] = c[len];
	else
		while (len--)
			*d++ = *c++;
	return (dst);
}
