/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:40:32 by florianma         #+#    #+#             */
/*   Updated: 2021/07/06 10:04:39 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print	*ft_initialise_tab(t_print *tab)
{
	tab->type = 0;
	tab->star = 0;
	tab->wdt = 0;
	tab->prc = -1;
	tab->zero = 0;
	tab->pnt = 0;
	tab->sign = 0;
	tab->tl = 0;
	tab->minus = 0;
	tab->perc = 0;
	tab->negative = 0;
	tab->hexa = 0;
	tab->spe_case = 0;
	tab->spe_string = 0;
	tab->spe_perc = 0;
	return (tab);
}

t_print	*ft_initialise1_tab(t_print *tab)
{
	tab->type = 0;
	tab->star = 0;
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->sign = 0;
	tab->minus = 0;
	tab->perc = 0;
	tab->negative = 0;
	tab->hexa = 0;
	tab->spe_case = 0;
	tab->spe_string = 0;
	tab->spe_perc = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	t_print	*tab;

	if (!format)
		return (-1);
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (0);
	ft_initialise_tab(tab);
	va_start(tab->args, format);
	ret = ft_underpf(format, tab);
	va_end(tab->args);
	ret = ret + tab->tl;
	free(tab);
	return (ret);
}

int	ft_underpf(const char *format, t_print *tab)
{
	int			i;
	int			char_count;

	i = -1;
	char_count = 0;
	while (format[++i])
	{
		tab = ft_initialise1_tab(tab);
		if (format[i] == '%' && format[i + 1])
		{
			i = ft_parsing_flag(format, i + 1, tab);
			if (is_format_specification(format[i]) == 1)
				ft_parsing(format[i], tab);
			else if (tab->wdt-- > 0)
				ft_process_width(tab, 0);
			else if (format[i])
				char_count = char_count + write(1, &format[i], 1);
		}
		else if (format[i] != '%')
		{
			char_count += write(1, &format[i], 1);
		}
	}
	return (char_count);
}
