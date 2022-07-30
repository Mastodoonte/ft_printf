/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 08:14:58 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:55:50 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	x_first_dispatch(t_print *tab, int size_num, unsigned int num)
{
	if (tab->spe_string == 0)
	{
		if (tab->prc == 0 && tab->pnt == 0)
			x_dispatch1(tab, size_num, num);
		else if (tab->prc >= 0 )
			x_dispatch2(tab, size_num, num);
		else if (tab->prc < 0 && tab->minus == 1 && num != 0)
			x_dispatch3(tab, size_num, num);
		else if (((tab->prc < -1 && num == 0))
			|| (tab->prc == -1 && num == 0 && tab->spe_case == 1))
			x_dispatch4(tab, size_num, num);
		else if (tab->prc < 0)
			x_dispatch5(tab, size_num, num);
		else
			ft_process_widthx(tab, size_num);
	}
	else if (tab->spe_string == -1 && num != 0)
		x_dispatch6(tab, size_num, num);
	else
		ft_process_widthx(tab, size_num);
}

void	ft_load_hexa(t_print *tab)
{
	unsigned int	num;
	int				size_num;

	num = va_arg(tab->args, unsigned int);
	ft_size_calculatorx(num, tab);
	size_num = tab->hexa;
	if (tab->spe_case == 1 && tab->prc < 0)
	{
		tab->prc *= (-1);
		tab->spe_case = 1;
	}
	if (tab->prc == -1 && num == 0 && tab->pnt == 0)
		num *= 0;
	if (tab->spe_case == 1 && tab->prc < 0)
	{
		tab->prc *= (-1);
		tab->spe_case = 1;
	}
	else
		x_first_dispatch(tab, size_num, num);
}
