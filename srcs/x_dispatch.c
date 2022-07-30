/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_dispatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:04:30 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:55:59 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	x_dispatch1(t_print *tab, int size_num, unsigned int num)
{
	if (tab->prc > tab->wdt && tab->prc > size_num)
		tab->zero = 1;
	if (tab->negative == -1 && tab->zero == 1)
		tab->zero = 0;
	if (tab->minus == 1)
		ft_h_prc0_pnt0_minus1(tab, &num, &size_num);
	if (tab->prc >= 0 && tab->prc < size_num)
		tab->prc = size_num;
	if (tab->prc < 0 && tab->minus == 0)
		ft_putnbrpfx(num, tab);
	if (tab->prc >= 0 && tab->minus == 0)
		ft_h_prc0_pnt0_minus0(tab, &size_num);
	else
		ft_process_width(tab, size_num);
	if (tab->minus == 0)
		ft_help_loadx(tab, num, size_num);
}

void	x_dispatch2(t_print *tab, int size_num, unsigned int num)
{
	if (tab->prc == 0 && tab->wdt >= 0 && num == 0)
	{
		tab->zero = 0;
		ft_process_widthx(tab, size_num);
		tab->pnt = (-1);
	}
	if (tab->prc > tab->wdt && tab->prc > size_num && tab->pnt >= 0)
		tab->zero = 1;
	if (tab->negative == -1 && tab->zero == 1 && tab->pnt > 0)
		tab->zero = 0;
	
	if (tab->minus == 1 && tab->pnt >= 0 )
		ft_h_minus1_pnt1(tab, &num, &size_num);
	if (tab->prc >= 0 && tab->prc < size_num && tab->pnt >= 0)
		tab->prc = size_num;
	if (tab->prc >= 0 && tab->minus == 0 && tab->pnt >= 0)
		ft_h_minus0_pnt1(tab, &size_num);
	else
		ft_process_widthx(tab, size_num);
	if (tab->minus == 0 && tab->pnt >= 0)
		ft_help_loadx(tab, num, size_num);
}

void	x_dispatch3(t_print *tab, int size_num, unsigned int num)
{
	if (tab->minus == 1 && tab->zero == 1)
		tab->zero = 0;
	if (tab->wdt == 0 && num != 0 )
	{
		ft_putnbrpfx(num, tab);
		ft_process_widthx(tab, size_num);
	}
	else if (tab->wdt > 0 && tab->wdt > size_num)
	{
		ft_putnbrpfx(num, tab);
		ft_process_widthx(tab, size_num);
	}
	else if (tab->wdt > 0 && tab->wdt <= size_num)
	{
		ft_putnbrpfx(num, tab);
		ft_process_widthx(tab, size_num);
	}
}

void	x_dispatch4(t_print *tab, int size_num, unsigned int num)
{
	if (tab->minus == 1)
	{
		tab->zero = 0;
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

void	x_dispatch5(t_print *tab, int size_num, unsigned int num)
{
	if (tab->minus == 1 && tab->zero == 1)
		tab->zero = 0;
	if (tab->wdt == 0 && num != 0)
		ft_h_pnt1_prcless0(tab, &size_num, &num, 1);
	else if (tab->wdt > 0 && tab->wdt > size_num && tab->minus == 1)
		ft_h_pnt1_prcless0(tab, &size_num, &num, 2);
	else if (tab->wdt > 0 && tab->wdt <= size_num && tab->minus == 1)
		ft_h_pnt1_prcless0(tab, &size_num, &num, 1);
	else if (tab->wdt > 0 && tab->wdt > size_num && tab->minus == 0)
	{
		tab->wdt -= size_num;
		ft_process_widthx(tab, size_num);
		ft_putnbrpfx(num, tab);
	}
	else if (tab->wdt > 0 && tab->wdt <= size_num && tab->minus == 0)
	{
		tab->wdt -= size_num;
		ft_process_widthx(tab, size_num);
		ft_putnbrpfx(num, tab);
	}
}
