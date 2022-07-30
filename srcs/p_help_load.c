/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_help_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 19:05:14 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:54:14 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_process_widthp(t_print *tab)
{
	while (tab->wdt > 0)
	{
		if (tab->zero > 0)
			tab->tl += write(1, "0", 1);
		else if (tab->zero == 0)
			tab->tl += write(1, " ", 1);
		tab->wdt--;
	}
}

void	ft_display(unsigned long int pointer, t_print *tab)
{
	tab->tl += write(1, "0x", 2);
	ft_putnbrpfp(pointer, tab);
}

void	ft_help_load_pointer(unsigned long int pointer, t_print *tab)
{
	unsigned long int	size_pointer;

	size_pointer = (unsigned long int)tab->hexa;
	if (tab->prc >= 0 && tab->minus == 1 )
	{
		if ((unsigned long int)tab->wdt > size_pointer)
			tab->wdt -= size_pointer;
		tab->tl += write(1, "0x", 2);
		ft_putnbrpfp(pointer, tab);
		ft_process_widthp(tab);
		ft_putnbrpfp(pointer, tab);
	}
	else if (tab->prc >= 0 )
	{
		if ((unsigned long int)tab->wdt > size_pointer)
			tab->wdt -= size_pointer;
		ft_process_widthp(tab);
		tab->tl += write(1, "0x", 2);
		ft_putnbrpfp(pointer, tab);
	}
	else
		ft_display(pointer, tab);
}

void	ft_display_more_wdt( t_print *tab, int a)
{
	if (a == 1)
	{
		tab->wdt -= 2;
		tab->tl += write(1, "0x", 2);
		ft_process_widthp(tab);
	}
	if (a == 2)
	{
		tab->wdt -= 2;
		ft_process_widthp(tab);
		tab->tl += write(1, "0x", 2);
	}
}

void	p_pnt1_2(t_print *tab, unsigned long int s_p, unsigned long int p)
{
	if ((unsigned long int)tab->wdt > s_p + 2)
	{
		tab->wdt -= 2;
		tab->wdt -= s_p;
		ft_process_widthp(tab);
	}
	if (p == 0)
	{
		tab->wdt -= 2;
		ft_process_widthp(tab);
		tab->tl += write(1, "0x", 2);
	}
	else
		ft_display(p, tab);
}
