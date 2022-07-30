/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_putnbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:00:52 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:52:54 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_h(int nb, t_print *tab)
{
	char	c;

	c = nb + '0';
	tab->tl += write(1, &c, 1);
	tab->wdt -= 1;
	if (tab->prc > 0)
		tab->prc -= 1;
}

void	ft_putnbrpf(int nb, t_print *tab)
{
	if (nb == -2147483648)
	{
		tab->tl += write(1, "2147483648", 10);
		tab->wdt -= 11;
	}
	else
	{
		if (nb < 0)
		{
			tab->tl += write(1, "-", 1);
			nb *= -1;
		}
		if (nb >= 10)
		{
			ft_putnbrpf(nb / 10, tab);
			ft_putnbrpf(nb % 10, tab);
		}
		else
			ft_h(nb, tab);
	}
}

void	ft_putnbrpfu(unsigned int nb, t_print *tab)
{
	char	c;

	if (nb >= 10)
	{
		ft_putnbrpfu(nb / 10, tab);
		ft_putnbrpfu(nb % 10, tab);
	}
	else
	{
		c = nb + '0';
		tab->tl += write(1, &c, 1);
		tab->wdt -= 1;
		if (tab->prc > 0)
			tab->prc -= 1;
	}
}

void	ft_putnbrpfx(unsigned int nb, t_print *tab)
{
	char	*base;

	if (tab->type == 'x')
		base = "0123456789abcdef";
	else if (tab->type == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_putnbrpfx(nb / 16, tab);
		ft_putnbrpfx(nb % 16, tab);
	}
	else
	{
		tab->tl += write(1, &base[nb % 16], 1);
		tab->wdt -= 1;
		if (tab->prc > 0)
			tab->prc -= 1;
	}
}

void	ft_putnbrpfp(unsigned long int nb, t_print *tab)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_putnbrpfp(nb / 16, tab);
		ft_putnbrpfp(nb % 16, tab);
	}
	else
	{
		tab->tl += write(1, &base[nb % 16], 1);
		tab->wdt -= 1;
		if (tab->prc > 0)
			tab->prc -= 1;
	}
}
