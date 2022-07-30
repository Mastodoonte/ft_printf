/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_dispatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 19:08:25 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:54:00 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	p_pnt1(t_print *tab, unsigned long int pointer)
{
	tab->wdt -= 2;
	if (pointer != 0 )
	{
		if (tab->minus == 0)
		{
			ft_process_widthp(tab);
			tab->tl += write(1, "0x", 2);
			ft_putnbrpfp(pointer, tab);
		}
		else if (tab->minus == 1)
		{
			tab->tl += write(1, "0x", 2);
			ft_putnbrpfp(pointer, tab);
			ft_process_widthp(tab);
		}
	}
}

void	ft_udr_dsptch(t_print *t, unsigned long int p, unsigned long int s_p)
{
	if ((unsigned long int)t->wdt > s_p + 2 && p != 0)
		p_pnt1(t, p);
	else if (p == 0)
	{
		t->tl += write(1, "0x", 2);
		t->wdt -= 2;
		ft_process_widthp(t);
	}
	else
	{
		t->wdt -= 2;
		ft_display(p, t);
	}
	if (t->wdt > 0)
		ft_process_widthp(t);
}

void	ft_h_dsptch(t_print *t, unsigned long int p, unsigned long int s_p)
{
	if (t->minus == 1 && t->wdt > 2 && t->spe_string == 0)
		ft_display_more_wdt(t, 1);
	else if (t->minus == 0 && t->wdt > 2 && t->spe_string == 0)
		ft_display_more_wdt(t, 2);
	else if (t->minus == 1 && t->prc < 0 && t->spe_string == -1)
		ft_udr_dsptch(t, p, s_p);
	else if (t->minus == 0 && t->prc < 0 && t->spe_string == -1)
		p_pnt1_2(t, s_p, p);
	else
		t->tl += write(1, "0x", 2);
}

void	ft_dispatch_p_1(t_print *t, unsigned long int p, unsigned long int s_p)
{
	if (p == 0)
	{
		t->wdt -= 2;
		if (t->minus == 0)
		{
			ft_process_widthp(t);
			t->tl += write(1, "0x", 2);
		}
		else if (t->minus == 1)
		{
			t->tl += write(1, "0x", 2);
			ft_process_widthp(t);
		}
	}
	else
		ft_h_dsptch(t, p, s_p);
}

void	ft_dispatch_p_2(t_print *tab, unsigned long int size_pointer)
{
	if (tab->minus == 0 && (unsigned long int)tab->wdt >= size_pointer)
	{
		tab->wdt -= 3;
		ft_process_widthp(tab);
		tab->tl += write(1, "0x0", 3);
	}
	else if (tab->minus == 1 && (unsigned long int)tab->wdt >= size_pointer)
	{
		tab->wdt -= 3;
		tab->tl += write(1, "0x0", 3);
		ft_process_widthp(tab);
	}
	else
		tab->tl += write(1, "0x0", 3);
}
