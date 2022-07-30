/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_special_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 23:57:58 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:54:22 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_spe_p1(t_print *tab, unsigned long int s_p, unsigned long int p)
{
	int			rest;

	rest = 0;
	tab->zero = 1;
	rest = tab->wdt - (tab->prc + 2);
	if (rest > 0)
		tab->prc = rest;
	tab->tl += write(1, "0x", 2);
	tab->wdt -= s_p;
	tab->wdt -= 2;
	if (rest > 0)
		tab->wdt -= rest;
	ft_process_widthp(tab);
	ft_putnbrpfp(p, tab);
	if (rest > 0)
	{
		tab->wdt = rest;
		tab->zero = 0;
	}
	ft_process_widthp(tab);
}

void	ft_spe_p2(t_print *tab, unsigned long int s_p, unsigned long int p)
{
	if (tab->spe_string == -1 && tab->pnt == 1)
		ft_putnbrpfp(p, tab);
	else if (tab->spe_string == 1)
	{
		if (tab->wdt > 0)
			tab->wdt -= (s_p + 2);
		ft_process_widthp(tab);
		tab->tl += write(1, "0x", 2);
		ft_putnbrpfp(p, tab);
	}
	else
		ft_h_spe1_p2(tab, s_p, p);
}

void	ft_spe_p3(t_print *tab, unsigned long int s_p, unsigned long int p)
{
	if (tab->prc >= tab->wdt)
	{
		tab->zero = 1;
		tab->wdt = tab->prc + 2;
		tab->prc = 0;
	}
	if (tab->wdt > tab->prc)
	{
		tab->zero = 1;
		if (tab->minus == 1)
		{
			tab->wdt -= 2;
			tab->tl += write(1, "0x", 2);
			tab->wdt -= s_p;
			ft_process_widthp(tab);
			ft_putnbrpfp(p, tab);
		}
		else if (tab->minus == 0)
		{
			tab->wdt -= s_p + 2;
			tab->tl += write(1, "0x", 2);
			ft_process_widthp(tab);
			ft_putnbrpfp(p, tab);
		}
	}
}

void	ft_spe_p4(t_print *tab)
{
	if (tab->spe_string == -1)
	{
		ft_help_spe_p4(tab, 1);
	}
	else
	{
		if (tab->wdt == 0 && tab->spe_string == 1)
			ft_help_spe1_p4(tab, 1);
		else if (tab->wdt == 0 && tab->prc > 0
			&& tab->spe_string == 0 && tab->minus == 0)
			ft_help_spe_p4(tab, 2);
		else
			ft_help_spe1_p4(tab, 1);
	}
}

void	ft_spe_p5(t_print *tab, unsigned long int s_p, unsigned long int p)
{
	if (tab->prc < 0)
	{
		tab->prc *= (-1);
		tab->spe_string = 1;
	}
	if (p != 0)
	{
		if (tab->wdt > tab->prc)
		{
			if ((unsigned long int)tab->prc < s_p)
				tab->prc = s_p;
			if (tab->minus == 1)
				ft_spe_p1(tab, s_p, p);
			else if (tab->minus == 0)
				ft_spe_p2(tab, s_p, p);
		}
		else
			ft_spe_p3(tab, s_p, p);
	}
	else if (p == 0)
		ft_spe_p4(tab);
}
