/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_prc_under0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:07:24 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:52:08 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_under_prc_pnt1(t_print *tab, int *num)
{
	if (tab->zero == 1 && tab->negative == -1 )
		tab->tl += write(1, "-", 1);
	*num = *num * (-1);
	tab->zero = 1;
	tab->wdt--;
}

void	ft_under_prc_pnt2(t_print *tab, int *num, int *size_num)
{
	if (tab->wdt > 0 && tab->prc == 0 && tab->zero == 1
		&& tab->sign == 0 && tab-> minus == 1
		&& tab->negative == 0 && num == 0)
	{
		tab->prc = -1;
		tab->zero = 0;
		tab->minus = 0;
	}
	else
		ft_help_load(tab, *num, *size_num);
}

void	ft_under_prc_pnt3(t_print *tab, int *size_num)
{
	if (tab->wdt > tab->prc && tab->zero == 1)
	{
		tab->wdt = tab->wdt - tab->prc;
		tab->zero = 0;
		ft_process_width(tab, *size_num);
		tab->zero = 1;
	}
	if (tab->wdt < tab->prc)
		tab->wdt = tab->wdt - tab->prc;
	if (tab->negative == -1 && tab->zero == 1)
		tab->zero = 0;
	ft_process_specialwidth(tab, *size_num);
}

void	ft_process_prc(t_print *tab, int size_num)
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

void	ft_help_load(t_print *tab, int num, int size_num)
{
	if (tab->negative == -1 && tab->prc >= 0 )
	{
		tab->tl += write(1, "-", 1);
	}
	if (tab->prc >= 0 )
	{
		tab->zero = 1;
		ft_process_prc(tab, size_num);
		tab->zero = 0;
		ft_putnbrpf(num, tab);
	}
}
