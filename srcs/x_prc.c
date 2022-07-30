/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_prc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 08:14:58 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:56:22 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_process_prcx(t_print *tab, int size_num)
{
	int	count_tl;

	count_tl = 0;
	while (tab->prc - size_num > 0)
	{
		if (tab->zero > 0)
		{
			count_tl = count_tl + write(1, "0", 1);
		}
		else if (tab->zero == 0)
		{
			count_tl = count_tl + write(1, " ", 1);
		}
		tab->prc--;
		tab->wdt--;
	}
	tab->tl = tab->tl + count_tl;
}

void	ft_help_loadx(t_print *tab, unsigned int num, int size_num)
{
	if (tab->negative == -1 && tab->prc >= 0 )
	{
		tab->tl += write(1, "-", 1);
	}
	if (tab->prc >= 0 )
	{
		tab->zero = 1;
		ft_process_prcx(tab, size_num);
		tab->zero = 0;
		ft_putnbrpfx(num, tab);
	}
}

void	ft_help_load2x(t_print *tab, unsigned int num, int size_num)
{
	if (tab->negative == -1 && tab->prc >= 0 )
		tab->tl += write(1, "-", 1);
	if (tab->prc >= 0 && num != 0 )
	{
		tab->zero = 1;
		ft_process_prcx(tab, size_num);
		tab->zero = 0;
		ft_putnbrpfx(num, tab);
	}
}

void	ft_h_num_less0(t_print *tab, unsigned int *num)
{
	if (tab->zero == 1 && tab->negative == -1 )
	{
		tab->tl += write(1, "-", 1);
	}
	*num = *num * (-1);
	tab->zero = 1;
	tab->wdt--;
}

void	ft_h_prc0_pnt0_minus1(t_print *tab, unsigned int *num, int *size_num)
{
	if (tab->wdt > 0 && tab->prc == 0 && tab->zero == 1
		&& tab->sign == 0 && tab-> minus == 1
		&& tab->negative == 0 && num == 0)
	{
		tab->prc = -1;
		tab->zero = 0;
		tab->minus = 0;
	}
	else if (tab->wdt > 0 && tab->prc == -1 && tab->minus == 1)
	{
		tab->wdt = tab->wdt - *size_num;
		ft_putnbrpfx(*num, tab);
		if (tab->wdt > 0)
			ft_process_widthx(tab, *size_num);
	}
	else
		ft_help_loadx(tab, *num, *size_num);
}
