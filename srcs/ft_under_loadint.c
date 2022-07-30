/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_under_loadint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:15:25 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:53:03 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_under_load_int1prcunder0(t_print *tab, int *num, int *size_num)
{
	if (*num == -2147483648)
		tab->tl += write(1, "-", 1);
	ft_putnbrpf(*num, tab);
	ft_process_width(tab, *size_num);
}

void	ft_under_load_int2prcunder0(t_print *tab, int *num, int *size_num)
{
	tab->wdt -= *size_num;
	if (*num < 0)
		tab->wdt--;
	ft_process_width(tab, *size_num);
	if (*num < 0)
	{
		tab->tl += write(1, "-", 1);
		tab->wdt--;
		*num *= (-1);
	}
	ft_putnbrpf(*num, tab);
}

void	ft_under_load_int3prcunder0(t_print *tab, int *num, int *size_num)
{
	tab->wdt -= *size_num;
	if (*num < 0)
		tab->wdt--;
	if (*num < 0)
	{
		tab->tl += write(1, "-", 1);
		*num *= (-1);
	}
	ft_process_width(tab, *size_num);
	if (*num == -2147483648)
		tab->tl += write(1, "-", 1);
	ft_putnbrpf(*num, tab);
}

void	ft_under_load_int1prcunder0_minus(t_print *tab, int *n, int *s_n)
{
	if (tab->minus == 1 && tab->zero == 1)
		tab->zero = 0;
	if (tab->wdt == 0 && *n != 0 )
	{
		if (*n == -2147483648)
			tab->tl += write(1, "-", 1);
		ft_putnbrpf(*n, tab);
		ft_process_width(tab, *s_n);
	}
	else if (tab->wdt > 0 && tab->wdt > *s_n)
	{
		if (*n == -2147483648)
			tab->tl += write(1, "-", 1);
		if (*n < 0 && *n != -2147483648)
			tab->wdt--;
		ft_putnbrpf(*n, tab);
		ft_process_width(tab, *s_n);
	}
	else if (tab->wdt > 0 && tab->wdt <= *s_n)
	{
		if (*n == -2147483648)
			tab->tl += write(1, "-", 1);
		ft_putnbrpf(*n, tab);
		ft_process_width(tab, *s_n);
	}
}

void	ft_prcless0(t_print *tab, int num, int size_num)
{
	if (tab->wdt == 0 && num != 0 )
		ft_under_load_int1prcunder0(tab, &num, &size_num);
	else if (tab->wdt > 0 && tab->wdt > size_num && tab->zero == 0)
		ft_under_load_int2prcunder0(tab, &num, &size_num);
	else if (tab->wdt > 0 && tab->wdt > size_num && tab->zero == 1)
		ft_under_load_int3prcunder0(tab, &num, &size_num);
	else if (tab->wdt > 0 && tab->wdt <= size_num)
	{
		if (num == -2147483648)
			tab->tl += write(1, "-", 1);
		ft_putnbrpf(num, tab);
	}
}
