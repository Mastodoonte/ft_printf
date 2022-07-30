/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_interuptor1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:43:25 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:55:10 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_interuptor1_1(t_print *tab)
{
	if (tab->minus == 1)
	{
		tab->wdt -= 6;
		tab->tl += write(1, "(null)", 6);
		ft_process_widths(tab);
	}
	else if (tab->minus == 0)
	{
		tab->wdt -= 6;
		ft_process_widths(tab);
		tab->tl += write(1, "(null)", 6);
	}
}

void	ft_interuptor1_2(t_print *tab, int *interuptor)
{
	if (tab->minus == 1)
	{
		if (tab->prc <= 6)
		{
			tab->wdt -= tab->prc;
			*interuptor = tab->prc;
		}
		else
		{
			tab->wdt -= 6;
			*interuptor = 6;
		}
		if (tab->wdt > *interuptor)
		{
			tab->tl += write(1, "(null)", *interuptor);
			ft_process_widths(tab);
		}
		else
			tab->tl += write(1, "(null)", 6);
	}
}

void	ft_interuptor1_3(t_print *tab)
{
	if (tab->wdt > 6)
	{
		tab->wdt -= 6;
		ft_process_widths(tab);
		tab->tl += write(1, "(null)", 6);
	}
	else
		tab->tl += write(1, "(null)", 6);
}

void	ft_interuptor1_4(t_print *tab, int *interuptor)
{
	if ((tab->minus == 1 && tab->wdt > 6)
		|| (tab->prc >= 0 && tab->spe_case == 1 && tab->minus == 1))
	{
		if (tab->prc <= 6)
			*interuptor = tab->prc;
		else
			*interuptor = 6;
		tab->tl += write(1, "(null)", *interuptor);
		tab->wdt -= *interuptor;
		ft_process_widths(tab);
	}
	else if ((tab->minus == 0 && tab->wdt > 6)
		|| (tab->prc >= 0 && tab->spe_case == 1))
	{
		if (tab->spe_string == -1)
			ft_process_widths(tab);
		if (tab->prc <= 6)
			*interuptor = tab->prc;
		else
			*interuptor = 6;
		tab->wdt -= *interuptor;
		ft_process_widths(tab);
		tab->tl += write(1, "(null)", *interuptor);
	}
}

void	ft_interuptor0_1(t_print *tab, int *size_str, char *output)
{
	if (tab->prc < *size_str)
		tab->wdt -= tab->prc;
	else
	{
		tab->wdt -= *size_str;
		tab->prc = *size_str;
	}
	if (output != NULL)
		ft_putstr(output, tab, tab->prc);
	ft_process_widths(tab);
}
