/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_noprc_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:02:47 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:51:55 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_treat_noprc_nopnt(t_print *tab, int num, int size_num)
{
	int	interuptor;

	interuptor = -1;
	ft_under_noprcnopnt1(tab, &num, &size_num, interuptor);
	interuptor = 1;
	ft_under_noprcnopnt1(tab, &num, &size_num, interuptor);
	if (tab->prc >= 0 && tab->prc < size_num)
		tab->prc = size_num;
	if (tab->prc >= 0 && tab->minus == 0)
		ft_under_noprcnopnt2(tab, &num, &size_num);
	else if (num == 0 && tab->prc == -1 )
	{
		tab->tl += write(1, "0", 1);
		tab->wdt--;
		ft_process_width(tab, size_num);
	}
	else
		ft_process_width(tab, size_num);
	if (tab->minus == 0)
		ft_help_load(tab, num, size_num);
	if (tab->prc < -1 )
		if (tab->wdt > 0)
			ft_process_width(tab, size_num);
}

void	ft_help(t_print *tab, int num, int s_num)
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
		ft_help_load(tab, num, s_num);
}

void	ft_under_noprcnopnt1(t_print *tab, int *num, int *s_num, int i)
{
	if (i == -1)
	{
		if (*num < 0 && tab->prc >= 0 && *num != -2147483648 )
		{
			if (tab->zero == 1 && tab->negative == -1 )
			{
				tab->tl += write(1, "-", 1);
				tab->negative = 0;
			}
			*num = *num * (-1);
			if (tab->prc > 0)
				tab->zero = 1;
			tab->wdt--;
		}
	}
	else if (i == 1)
	{
		if (tab->minus == 1 )
			ft_help(tab, *num, *s_num);
	}
}

void	ft_under_noprcnopnt2(t_print *tab, int *num, int *size_num)
{
	if (tab->prc >= 0 && tab->minus == 0)
	{
		if (tab->wdt < tab->prc)
			tab->wdt = tab->wdt - tab->prc;
		if (tab->negative == -1 && tab->zero == 1 && tab->prc > tab->wdt)
			tab->zero = 0;
		if (tab->negative == -1 && tab->zero == 1 && tab->prc <= *size_num)
		{
			tab->tl += write(1, "-", 1);
			ft_process_specialwidth(tab, *size_num);
			tab->zero = 1;
			tab->negative = 0;
		}
		if (tab->negative == -1 && tab->prc < tab->wdt && tab->prc > *size_num)
		{
			tab->tl += write(1, "-", 1);
			tab->zero = 1;
			tab->negative = 0;
		}
		if (*num == -2147483648)
			tab->wdt--;
		ft_process_specialwidth(tab, *size_num);
	}
}
