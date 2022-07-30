/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmastor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 11:36:06 by flmastor          #+#    #+#             */
/*   Updated: 2021/07/05 17:52:18 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	is_flag(char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*')
		return (1);
	return (0);
}

int	is_format_specification(char c)
{
	int		i;
	char	*specifications;

	specifications = "udicsupxX%";
	i = 0;
	while (specifications[i])
	{
		if (c == specifications[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_minus_allocation(t_print *tab)
{
	tab->minus = 1;
	tab->zero = 0;
}

void	ft__width_star_allocation(t_print *tab)
{
	tab->star = 1;
	tab->wdt = (int)va_arg(tab->args, int);
	if (tab->wdt < 0)
	{
		tab->minus = 1;
		tab->wdt *= -1;
		tab->spe_perc = 1;
	}
}
