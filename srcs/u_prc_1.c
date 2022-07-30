/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_prc_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:50:55 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:55:38 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_process_prcu(t_print *tab, int size_num)
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

void	ft_help_loadu(t_print *tab, unsigned int num, int size_num)
{
	if (tab->negative == -1 && tab->prc >= 0 )
	{
		tab->tl += write(1, "-", 1);
	}
	if (tab->prc >= 0 )
	{
		tab->zero = 1;
		ft_process_prcu(tab, size_num);
		tab->zero = 0;
		ft_putnbrpfu(num, tab);
	}
}

void	ft_under1_noprc_nopntu(t_print *tab, unsigned int *num, int a)
{
	if (a == 0)
	{
		if (tab->zero == 1 && tab->negative == -1 )
		{
			tab->tl += write(1, "-", 1);
			tab->negative = 0;
		}
		*num = *num * (-1);
		tab->wdt--;
	}
	if (a == 1)
	{
		if (tab->zero == 1 && tab->negative == -1 )
		{
			tab->tl += write(1, "-", 1);
			tab->negative = 0;
		}
		*num = *num * (-1);
		tab->zero = 1;
		tab->wdt--;
	}
}

void	ft_under2_noprc_nopntu(t_print *tab, int *s_n, unsigned int *n)
{
	if (tab->wdt > 0 && tab->prc == 0 && tab->zero == 1
		&& tab->sign == 0 && tab-> minus == 1
		&& tab->negative == 0 && n == 0)
	{
		tab->prc = -1;
		tab->zero = 0;
		tab->minus = 0;
	}
	else
		ft_help_loadu(tab, *n, *s_n);
}

void	ft_under3_noprc_nopntu(t_print *tab, int *size_num)
{
	if (tab->wdt < tab->prc)
		tab->wdt = tab->wdt - tab->prc;
	if (tab->negative == -1 && tab->zero == 1 && tab->prc > tab->wdt)
		tab->zero = 0;
	if (tab->negative == -1 && tab->zero == 1 && tab->prc <= *size_num)
	{
		tab->tl += write(1, "-", 1);
		ft_process_specialwidthu(tab, *size_num);
		tab->zero = 1;
		tab->negative = 0;
	}
	if (tab->negative == -1 && tab->prc < tab->wdt && tab->prc > *size_num)
	{
		tab->tl += write(1, "-", 1);
		tab->zero = 1;
		tab->negative = 0;
	}
	ft_process_specialwidthu(tab, *size_num);
}
