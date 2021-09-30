/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrapefr <ggrapefr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:39:45 by ggrapefr          #+#    #+#             */
/*   Updated: 2021/09/29 18:39:47 by ggrapefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	sym;

	str = (unsigned char *) s;
	sym = (unsigned char) c;
	while (n)
	{
		if (*str == sym)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
