/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:28:55 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:55:22 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_prc_pntu(t_print *tab, unsigned int num, int size_num)
{
	if (tab->prc == 0 && tab->wdt >= 0 && num == 0)
	{
		tab->zero = 0;
		ft_process_widthu(tab, size_num);
		tab->pnt = (-1);
	}
	if (tab->prc > tab->wdt && tab->prc > size_num && tab->pnt >= 0)
		tab->zero = 1;
	if (tab->negative == -1 && tab->zero == 1 && tab->pnt > 0)
		tab->zero = 0;
	if (tab->minus == 1 && tab->pnt >= 0 )
		ft_under2_noprc_nopntu(tab, &size_num, &num);
	if (tab->prc >= 0 && tab->prc < size_num && tab->pnt >= 0)
		tab->prc = size_num;
	if (tab->prc >= 0 && tab->minus == 0 && tab->pnt >= 0)
		ft_noprc2_pntu(tab, &size_num);
	else
		ft_process_widthu(tab, size_num);
	if (tab->minus == 0 && tab->pnt >= 0)
		ft_help_loadu(tab, num, size_num);
	if (tab->prc < 0)
		if (tab->wdt > 0)
			ft_process_widthu(tab, size_num);
}

void	ft_under_load_1(t_print *tab, unsigned int *num, int *size_num)
{
	if (tab->wdt == 0 && num != 0 )
	{
		ft_putnbrpfu(*num, tab);
		ft_process_widthu(tab, *size_num);
	}
	else if (tab->wdt > 0 && tab->wdt > *size_num
		&& (tab->zero == 0 || tab->zero == 1))
	{
		tab->wdt -= *size_num;
		ft_process_widthu(tab, *size_num);
		if (tab->zero == 1)
			ft_process_widthu(tab, *size_num);
		ft_putnbrpfu(*num, tab);
	}
	else if (tab->wdt > 0 && tab->wdt <= *size_num)
		ft_putnbrpfu(*num, tab);
}

void	ft_under_load_2(t_print *tab, unsigned int *num, int *size_num)
{
	if (tab->minus == 1 && tab->zero == 1)
		tab->zero = 0;
	if (tab->wdt == 0 && *num != 0 )
	{
		ft_putnbrpfu(*num, tab);
		ft_process_widthu(tab, *size_num);
	}
	else if (tab->wdt > 0 && tab->wdt > *size_num)
	{
		ft_putnbrpfu(*num, tab);
		ft_process_widthu(tab, *size_num);
	}
	else if (tab->wdt > 0 && tab->wdt <= *size_num)
	{
		ft_putnbrpfu(*num, tab);
		ft_process_widthu(tab, *size_num);
	}
}

void	ft_under_load_3(t_print *tab, unsigned int *num, int *size_num)
{
	if (tab->minus == 1)
	{
		tab->zero = 0;
		ft_putnbrpfu(*num, tab);
		ft_process_widthu(tab, *size_num);
	}
	else if (tab->minus == 0)
	{
		tab->wdt -= *size_num;
		ft_process_widthu(tab, *size_num);
		ft_putnbrpfu(*num, tab);
	}
}

void	ft_load_uint(t_print *tab)
{
	unsigned int	num;
	int				size_num;

	num = va_arg(tab->args, unsigned int);
	size_num = ft_size_calculatoru(num);
	if (tab->prc == -1 && num == 0 && tab->pnt == 0)
		num *= 0;
	else
	{
		if (tab->prc == 0 && tab->pnt == 0)
			ft_treat_noprc_nopntu(tab, num, size_num);
		else if (tab->prc >= 0 )
			ft_prc_pntu(tab, num, size_num);
		else if (tab->prc < 0 && num != 0 && tab-> minus == 0 )
			ft_under_load_1(tab, &num, &size_num);
		else if (tab->prc < 0 && num != 0 && tab->minus == 1)
			ft_under_load_2(tab, &num, &size_num);
		else if (((tab->prc < -1 && num == 0))
			|| (tab->prc == -1 && num == 0 && tab->spe_case == 1))
			ft_under_load_3(tab, &num, &size_num);
		else
			ft_process_widthu(tab, size_num);
	}
}
