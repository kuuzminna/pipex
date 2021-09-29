#include "libft.h"

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			ft_putnbr(147483648);

		}
		else
			ft_putnbr(- nb);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb % 10);
		ft_putnbr(nb / 10);
	}
	else
		ft_putchar(nb + '0');
}