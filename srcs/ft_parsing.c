/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmastor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:35:29 by flmastor          #+#    #+#             */
/*   Updated: 2021/07/05 17:52:32 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_digit_allocation(char c, t_print *tab)
{
	if (tab->star == 1)
		tab->wdt = 0;
	tab->wdt = (tab->wdt * 10) + (c - '0');
}

int	ft_prc_allocation(t_print *tab, const char *format, int from)
{
	int	i;

	i = from + 1;
	tab->pnt = 1;
	if (format[i] == '*')
	{
		tab->prc = va_arg(tab->args, int);
		if (tab->prc == (-1))
		{
			tab->spe_case = 1;
		}
		i++;
	}
	else if (is_format_specification(format[i]))
	{
		tab->prc = -1;
		tab->spe_string = -1;
	}
	else
	{
		tab->prc = 0;
		while (ft_is_digit(format[i]))
			tab->prc = (tab->prc * 10) + (format[i++] - '0');
	}
	return (i);
}

int	ft_parsing_flag(const char *format, int i, t_print *tab)
{
	while (format[i])
	{
		if ((is_flag(format[i]) == 0)
			&& (is_format_specification(format[i]) == 0)
			&& (ft_is_digit(format[i]) == 0))
			break ;
		if (format[i] == '0' && tab->wdt == 0 && tab->minus == 0)
			tab->zero = 1;
		if (format[i] == '.')
			i = ft_prc_allocation(tab, format, i);
		if (format[i] == '-')
			ft_minus_allocation(tab);
		if (format[i] == '*')
			ft__width_star_allocation(tab);
		if (ft_is_digit(format[i]))
			ft_digit_allocation(format[i], tab);
		if (is_format_specification(format[i]))
		{
			tab->type = format[i];
			break ;
		}
		i++;
	}
	return (i);
}

int	ft_parsing(int c, t_print *tab)
{
	if (c == 'c')
		ft_load_char(tab);
	else if (c == 's')
		ft_load_string(tab);
	else if (c == 'p')
		ft_load_pointer(tab);
	else if (c == 'd' || c == 'i')
		ft_load_int(tab);
	else if (c == 'u')
		ft_load_uint(tab);
	else if (c == 'x')
		ft_load_hexa(tab);
	else if (c == 'X')
		ft_load_hexa(tab);
	else if (c == '%')
	{
		tab->type = '%';
		ft_load_percent(tab);
	}
	return (c);
}
