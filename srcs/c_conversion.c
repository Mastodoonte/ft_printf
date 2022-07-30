/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 08:57:58 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:51:45 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_process_widthc(t_print *tab)
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
			count_tl = count_tl + write(1, " ", 1);
		tab->wdt--;
	}
	tab->tl = tab->tl + count_tl;
}

void	ft_load_char(t_print *tab)
{
	char	output;

	output = va_arg(tab->args, int);
	if (tab->wdt > 0 && tab->minus == 0)
	{
		tab->wdt--;
		ft_process_widthc(tab);
		tab->tl += write(1, &output, 1);
	}
	else if (tab->wdt > 0 && tab->minus == 1)
	{
		tab->wdt--;
		tab->tl += write(1, &output, 1);
		ft_process_widthc(tab);
	}
	else
		tab->tl += write(1, &output, 1);
}
