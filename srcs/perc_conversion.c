/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:09:04 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:54:41 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_process_widthper(t_print *tab)
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
		{
			count_tl = count_tl + write(1, " ", 1);
		}
		tab->wdt--;
	}
	tab->tl = tab->tl + count_tl;
}

void	ft_load_percent(t_print *tab)
{
	if (tab->spe_perc == 1)
		tab->zero = 0;
	tab->wdt--;
	if (tab->minus == 1)
	{
		tab->tl += write(1, "%", 1);
	}
	ft_process_widthper(tab);
	if (tab->minus == 0)
	{
		tab->tl += write(1, "%", 1);
	}
}
