/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_help.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 08:14:58 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:56:06 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_h_prc0_pnt0_minus0(t_print *tab, int *size_num)
{
	if (tab->wdt < tab->prc)
		tab->wdt = tab->wdt - tab->prc;
	if (tab->negative == -1 && tab->zero == 1 && tab->prc > tab->wdt)
		tab->zero = 0;
	if (tab->negative == -1 && tab->zero == 1 && tab->prc <= *size_num)
	{
		tab->tl += write(1, "-", 1);
		ft_process_specialwidthx(tab, *size_num);
		tab->zero = 1;
		tab->negative = 0;
	}
	if (tab->negative == -1 && tab->prc < tab->wdt && tab->prc > *size_num)
	{
		tab->tl += write(1, "-", 1);
		tab->zero = 1;
		tab->negative = 0;
	}
	ft_process_specialwidthx(tab, *size_num);
}

void	ft_h_minus1_pnt1(t_print *tab, unsigned int *num, int *size_num)
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
		ft_help_loadx(tab, *num, *size_num);
}

void	ft_h_minus0_pnt1(t_print *tab, int *size_num)
{
	if (tab->wdt > tab->prc && tab->zero == 1)
	{
		tab->wdt = tab->wdt - tab->prc;
		if (tab->spe_case == 0)
			tab->zero = 0;
		ft_process_widthx(tab, *size_num);
		tab->zero = 1;
	}
	if (tab->wdt < tab->prc)
		tab->wdt = tab->wdt - tab->prc;
	if (tab->negative == -1 && tab->zero == 1)
		tab->zero = 0;
	ft_process_specialwidthx(tab, *size_num);
}

void	ft_h_pnt1_prcless0(t_print *tab, int *s_n, unsigned int *n, int a)
{
	if (a == 1)
	{
		ft_putnbrpfx(*n, tab);
		ft_process_widthx(tab, *s_n);
	}
	if (a == 2)
	{
		ft_putnbrpfx(*n, tab);
		ft_process_widthx(tab, *s_n);
	}
}

void	x_dispatch6(t_print *tab, int size_num, unsigned int num)
{
	if (tab->spe_string == -1)
		tab->zero = 0;
	if (tab->minus == 1)
	{
		ft_putnbrpfx(num, tab);
		ft_process_widthx(tab, size_num);
	}
	else if (tab->minus == 0)
	{
		tab->wdt -= size_num;
		ft_process_widthx(tab, size_num);
		ft_putnbrpfx(num, tab);
	}
}
