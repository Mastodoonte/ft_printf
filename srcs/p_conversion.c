/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 08:14:58 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:53:49 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	p_pnt1_else(t_print *tab, unsigned long int size_pointer)
{
	if ((unsigned long int)tab->prc < size_pointer)
		tab->wdt -= tab->prc;
	else
	{
		tab->wdt -= size_pointer;
		tab->prc = size_pointer;
	}
	ft_process_widthp(tab);
}

void	p_pnt0(t_print *tab, unsigned long int s_p, unsigned long int p, int a)
{
	if (a == 1)
	{
		tab->tl += write(1, "0x", 2);
		tab->wdt -= 2;
		ft_putnbrpfp(p, tab);
		ft_process_widthp(tab);
	}
	if (a == 2)
	{
		if ((unsigned long int)tab->prc > s_p)
			tab->wdt -= s_p;
		else if ((unsigned long int)tab->prc < s_p)
			tab->wdt -= s_p;
		ft_process_widthp(tab);
		tab->tl += write(1, "0x", 2);
		ft_putnbrpfp(p, tab);
	}
}

void	ft_dispatch_p_3(t_print *tab, unsigned long int s_p, unsigned long p)
{
	if (tab->prc < 0 && tab->wdt == 0)
		ft_display(p, tab);
	if (tab->prc < 0)
		ft_process_widthp(tab);
	else if (tab->minus == 1 )
		p_pnt1_else(tab, s_p);
	else if (tab->minus == 0 && tab->prc > 0)
		p_pnt1_else(tab, s_p);
	else if (tab->minus == 0 && tab->prc == 0 && tab->wdt > 0 )
	{
		p_pnt1_else(tab, s_p);
		tab->tl += write(1, "0x0", 3);
		ft_putnbrpfp(p, tab);
	}
	else
		ft_putnbrpfp(p, tab);
}

void	ft_dispatch_p_4(t_print *tab, unsigned long int s_p, unsigned long p)
{
	if (tab->minus == 1 )
		p_pnt0(tab, s_p, p, 1);
	else if (tab->minus == 0 && tab->prc > 0)
		p_pnt0(tab, s_p, p, 2);
	else if (tab->minus == 0 && tab->prc == 0 && tab->wdt > 0 )
	{
		tab->wdt -= 2;
		if ((unsigned long int)tab->prc > s_p)
			tab->wdt -= s_p;
		else if ((unsigned long int)tab->prc < s_p)
			tab->wdt -= s_p;
		ft_process_widthp(tab);
		tab->tl += write(1, "0x", 2);
		ft_putnbrpfp(p, tab);
	}
	else
	{
		tab->tl += write(1, "0x", 2);
		ft_putnbrpfp(p, tab);
	}
}

void	ft_load_pointer(t_print *tab)
{
	unsigned long int	pointer;
	unsigned long int	size_pointer;

	pointer = va_arg(tab->args, unsigned long int);
	ft_size_calculatorp(pointer, tab);
	size_pointer = (unsigned long int)tab->hexa;
	if (tab->pnt == 1)
		ft_spe_p5(tab, size_pointer, pointer);
	else
	{
		if (tab->spe_string < 0 && tab-> prc < 0 && tab->spe_case == 0 )
			ft_dispatch_p_1(tab, pointer, size_pointer);
		else if ((pointer == 0 && tab->prc == 0))
			ft_dispatch_p_2(tab, size_pointer);
		else
		{
			if (tab->pnt == 1)
				ft_dispatch_p_3(tab, size_pointer, pointer);
			else if (tab->pnt == 0 )
				ft_dispatch_p_4(tab, size_pointer, pointer);
		}
	}
}
