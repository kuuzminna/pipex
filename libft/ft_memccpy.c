/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrapefr <ggrapefr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:39:39 by ggrapefr          #+#    #+#             */
/*   Updated: 2021/09/29 18:39:41 by ggrapefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
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
