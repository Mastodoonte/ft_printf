/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_special_case1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmastor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:27:08 by flmastor          #+#    #+#             */
/*   Updated: 2021/07/05 17:54:34 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_help_spe1_p4(t_print *tab, int a)
{
	if (a == 1)
	{
		if (tab->wdt == 0 && tab->prc > 0
			&& tab->spe_string == 0 && tab->minus == 0)
			ft_help_spe_p4(tab, 2);
		else
		{
			if (tab->wdt > 0 && tab->spe_string == 1 && tab->pnt == 1)
				ft_help_spe_p4(tab, 1);
			else if (tab->wdt == 0 && tab->pnt == 1 && tab->prc == 1)
			{
				tab->tl += write(1, "0x", 2);
				if (tab->spe_case == 1)
					tab->tl += write(1, "0", 1);
			}
			else if (tab->wdt == 0 && tab->pnt == 1 && tab->prc == 0)
				tab->tl += write(1, "0x", 2);
			else
			{
				tab->wdt = tab->prc;
				tab->tl += write(1, "0x0", 3);
				tab->zero = 1;
			}
		}
	}
}

void	ft_help_spe_p4(t_print *tab, int a)
{
	if (a == 1)
	{
		if (tab->minus == 1)
		{
			tab->tl += write(1, "0x", 2);
			tab->wdt -= 2;
			ft_process_widthp(tab);
		}
		else if (tab->minus == 0)
		{
			tab->wdt -= 2;
			ft_process_widthp(tab);
			tab->tl += write(1, "0x", 2);
		}
	}
	if (a == 2)
	{
		tab->tl += write(1, "0x", 2);
		tab->wdt = tab->prc;
		tab->zero = 1;
		ft_process_widthp(tab);
	}
}

void	ft_h_spe1_p2(t_print *tab, unsigned long int s_p, unsigned long int p )
{
	int	rest;

	rest = 0;
	tab->zero = 0;
	rest = tab->wdt - (tab->prc + 2 );
	if (rest > 0)
		tab->wdt = rest;
	ft_process_widthp(tab);
	tab->tl += write(1, "0x", 2);
	tab->zero = 1;
	tab->wdt = tab->prc - s_p;
	tab->wdt -= s_p;
	ft_process_widthp(tab);
	ft_putnbrpfp(p, tab);
}
