/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:28:55 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:51:19 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	ft_prc_pnt(t_print *tab, int num, int size_num)
{
	if (tab->prc == 0 && tab->wdt >= 0 && num == 0)
	{
		tab->zero = 0;
		ft_process_width(tab, size_num);
		tab->pnt = (-1);
	}
	if (tab->prc > tab->wdt && tab->prc > size_num && tab->pnt >= 0)
		tab->zero = 1;
	if (tab->negative == -1 && tab->zero == 1 && tab->pnt > 0)
		tab->zero = 0;
	if (num < 0 && (tab->prc >= 0 || tab->zero == 1) && tab->pnt >= 0)
		ft_under_prc_pnt1(tab, &num);
	if (tab->minus == 1 && tab->pnt >= 0 )
		ft_under_prc_pnt2(tab, &num, &size_num);
	if (tab->prc >= 0 && tab->prc < size_num && tab->pnt >= 0)
		tab->prc = size_num;
	if (tab->prc >= 0 && tab->minus == 0 && tab->pnt >= 0)
		ft_under_prc_pnt3(tab, &size_num);
	else
		ft_process_width(tab, size_num);
	if (tab->minus == 0 && tab->pnt >= 0)
		ft_help_load(tab, num, size_num);
	if (tab->prc < 0)
		if (tab->wdt > 0)
			ft_process_width(tab, size_num);
}

void	ft_last_case(t_print *tab, int num, int size_num)
{
	if (tab->minus == 1)
	{
		tab->zero = 0;
		ft_putnbrpf(num, tab);
		ft_process_width(tab, size_num);
	}
	else if (tab->minus == 0)
	{
		tab->wdt -= size_num;
		ft_process_width(tab, size_num);
		ft_putnbrpf(num, tab);
	}
}

void	ft_load_int(t_print *tab)
{
	int	num;
	int	size_num;

	num = va_arg(tab->args, int);
	if (num < 0)
		tab->negative = -1;
	size_num = ft_size_calculator(num);
	if (tab->prc == -1 && num == 0 && tab->pnt == 0)
		num *= 0;
	else
	{
		if (tab->prc == 0 && tab->pnt == 0)
			ft_treat_noprc_nopnt(tab, num, size_num);
		else if (tab->prc >= 0 )
			ft_prc_pnt(tab, num, size_num);
		else if (tab->prc < 0 && num != 0 && tab-> minus == 0 )
			ft_prcless0(tab, num, size_num);
		else if (tab->prc < 0 && num != 0 && tab->minus == 1)
			ft_under_load_int1prcunder0_minus(tab, &num, &size_num);
		else if (((tab->prc < -1 && num == 0))
			|| (tab->prc == -1 && num == 0 && tab->spe_case == 1))
			ft_last_case(tab, num, size_num);
		else
			ft_process_width(tab, size_num);
	}
}
