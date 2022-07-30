/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:46:48 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:53:24 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_size_calculatoru(unsigned int nbr)
{
	int	compteur;

	if (nbr == 0)
		return (1);
	compteur = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		compteur++;
	}
	return (compteur);
}

void	ft_size_calculatorx(unsigned int nbr, t_print *tab)
{
	if (nbr >= 16)
	{
		ft_size_calculatorx(nbr / 16, tab);
		ft_size_calculatorx(nbr % 16, tab);
	}
	else
		tab->hexa += 1;
}

void	ft_process_specialwidthx(t_print *tab, int size_num)
{
	int	count_tl;

	count_tl = 0;
	size_num *= 1;
	while (tab->wdt - tab->prc > 0)
	{
		if (tab->zero > 0)
		{
			count_tl = count_tl + write(1, "0", 1);
		}
		else if (tab->zero == 0)
		{
			count_tl = count_tl + write(1, " ", 1);
		}
		tab->wdt--;
	}
	tab->tl = tab->tl + count_tl;
}

void	ft_process_widthx(t_print *tab, int size_num)
{
	int	count_tl;

	count_tl = 0;
	size_num *= 1;
	while (tab->wdt > 0)
	{
		if (tab->zero > 0)
		{
			count_tl = count_tl + write(1, "0", 1);
		}
		else if (tab->zero == 0)
		{
			count_tl = count_tl + write(1, " ", 1);
		}
		tab->wdt--;
	}
	tab->tl = tab->tl + count_tl;
}

void	ft_size_calculatorp(unsigned long int nbr, t_print *tab)
{
	if (nbr >= 16)
	{
		ft_size_calculatorp(nbr / 16, tab);
		ft_size_calculatorp(nbr % 16, tab);
	}
	else
		tab->hexa += 1;
}
