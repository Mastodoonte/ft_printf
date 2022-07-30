/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_interuptor0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 13:44:24 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:55:03 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_interuptor0_2(t_print *tab, int *size_str, char *output)
{
	if (tab->prc < *size_str)
		tab->wdt -= tab->prc;
	else
	{
		tab->wdt -= *size_str;
		tab->prc = *size_str;
	}
	ft_process_widths(tab);
	if (output != NULL)
		ft_putstr(output, tab, tab->prc);
}

void	ft_interuptor0_3(t_print *tab, int *size_str, char *output)
{
	if (tab->prc < *size_str)
		tab->wdt -= tab->prc;
	else
	{
		tab->wdt -= *size_str;
		tab->prc = *size_str;
	}
	ft_process_widths(tab);
	ft_putstr(output, tab, tab->prc);
}

void	ft_interuptor0_4(t_print *tab, int *size_str, char *output)
{
	if (tab->minus == 1 )
	{
		tab->wdt -= *size_str;
		ft_putstr(output, tab, *size_str);
		ft_process_widths(tab);
	}
	else if (tab->minus == 0 && tab->prc > 0)
	{
		tab->wdt -= *size_str;
		ft_process_widths(tab);
		ft_putstr(output, tab, *size_str);
	}
	else if (tab->minus == 0 && tab->prc == 0 && tab->wdt > 0 )
	{
		tab->wdt -= *size_str;
		tab->prc = *size_str;
		ft_process_widths(tab);
		ft_putstr(output, tab, *size_str);
	}
	else
		ft_putstr(output, tab, *size_str);
}

void	ft_interuptor0_5(t_print *tab, int *size_str, char *output)
{
	if (tab->minus == 1 )
	{	
		tab->wdt -= *size_str;
		ft_putstr(output, tab, *size_str);
		ft_process_widths(tab);
	}
	else if (tab->minus == 0 )
	{
		tab->wdt -= *size_str;
		ft_process_widths(tab);
		ft_putstr(output, tab, *size_str);
	}
	else if (tab->minus == 0 && tab->prc == 0 && tab->wdt > 0 )
		ft_help_interuptor0_5(tab, size_str, output);
	else
		ft_putstr(output, tab, *size_str);
}

void	ft_interuptor0_6(t_print *tab, int *size_str, char *output)
{
	if (tab->minus == 1)
	{
		if (tab->wdt < *size_str)
			ft_putstr(output, tab, *size_str);
		else
		{
			ft_putstr(output, tab, *size_str);
			tab->wdt -= *size_str;
			ft_process_widths(tab);
		}
	}
	else if (tab->minus == 0)
	{
		if (tab->wdt < *size_str)
			ft_putstr(output, tab, *size_str);
		else
		{
			tab->wdt -= *size_str;
			ft_process_widths(tab);
			ft_putstr(output, tab, *size_str);
		}
	}
}
