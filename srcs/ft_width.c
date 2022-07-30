/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:12:29 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:53:33 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_process_specialwidth(t_print *tab, int size_num)
{
	int	count_tl;

	count_tl = 0;
	size_num *= 1;
	while (tab->wdt - tab->prc > 0)
	{
		if (tab->zero > 0)
			count_tl = count_tl + write(1, "0", 1);
		else if (tab->zero == 0)
			count_tl = count_tl + write(1, " ", 1);
		tab->wdt--;
	}
	tab->tl = tab->tl + count_tl;
}

void	ft_process_width(t_print *tab, int size_num)
{
	int	count_tl;

	count_tl = 0;
	size_num *= 1;
	while (tab->wdt > 0)
	{
		if (tab->zero > 0)
		{
			count_tl = count_tl + write(1, "0", 1);
		}
		else if (tab->zero == 0)
		{
			count_tl = count_tl + write(1, " ", 1);
		}
		tab->wdt--;
	}
	tab->tl = tab->tl + count_tl;
}

void	ft_process_widths(t_print *tab)
{
	int	count_tl;

	count_tl = 0;
	while (tab->wdt > 0)
	{
		if (tab->zero > 0)
		{
			count_tl = count_tl + write(1, "0", 1);
		}
		else if (tab->zero == 0)
			count_tl = count_tl + write(1, " ", 1);
		tab->wdt--;
	}
	tab->tl = tab->tl + count_tl;
}

void	ft_process_specialwidthu(t_print *tab, int size_num)
{
	int	count_tl;

	count_tl = 0;
	size_num *= 1;
	while (tab->wdt - tab->prc > 0)
	{
		if (tab->zero > 0)
		{
			count_tl = count_tl + write(1, "0", 1);
		}
		else if (tab->zero == 0)
		{
			count_tl = count_tl + write(1, " ", 1);
		}
		tab->wdt--;
	}
	tab->tl = tab->tl + count_tl;
}

void	ft_process_widthu(t_print *tab, int size_num)
{
	int	count_tl;

	count_tl = 0;
	size_num *= 1;
	while (tab->wdt > 0)
	{
		if (tab->zero > 0)
		{
			count_tl = count_tl + write(1, "0", 1);
		}
		else if (tab->zero == 0)
		{
			count_tl = count_tl + write(1, " ", 1);
		}
		tab->wdt--;
	}
	tab->tl = tab->tl + count_tl;
}
