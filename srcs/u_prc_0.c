/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_prc_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:53:25 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:55:30 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_treat_noprc_nopntu(t_print *tab, unsigned int num, int size_num)
{
	if (tab->minus == 1)
		ft_under2_noprc_nopntu(tab, &size_num, &num);
	if (tab->prc >= 0 && tab->prc < size_num)
		tab->prc = size_num;
	if (tab->prc >= 0 && tab->minus == 0)
		ft_under3_noprc_nopntu(tab, &size_num);
	else if (num == 0 && tab->prc == -1 )
	{
		tab->tl += write(1, "0", 1);
		tab->wdt--;
		ft_process_widthu(tab, size_num);
	}
	else
		ft_process_widthu(tab, size_num);
	if (tab->minus == 0)
		ft_help_loadu(tab, num, size_num);
	if (tab->prc < -1 )
		if (tab->wdt > 0)
			ft_process_widthu(tab, size_num);
}

void	ft_noprc1_pntu(t_print *tab, unsigned int *num, int a)
{
	if (a == 0)
	{
		if (tab->zero == 1 && tab->negative == -1 )
			tab->tl += write(1, "-", 1);
		*num = *num * (-1);
		tab->zero = 1;
		tab->wdt--;
	}
}

void	ft_noprc2_pntu(t_print *tab, int *size_num)
{
	if (tab->wdt > tab->prc && tab->zero == 1)
	{
		tab->wdt = tab->wdt - tab->prc;
		tab->zero = 0;
		ft_process_widthu(tab, *size_num);
		tab->zero = 1;
	}
	if (tab->wdt < tab->prc)
		tab->wdt = tab->wdt - tab->prc;
	if (tab->negative == -1 && tab->zero == 1)
		tab->zero = 0;
	ft_process_specialwidthu(tab, *size_num);
}
