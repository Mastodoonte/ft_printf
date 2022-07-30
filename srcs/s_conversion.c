/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:56:21 by florianma         #+#    #+#             */
/*   Updated: 2021/07/05 17:54:51 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	dispatch1(t_print *tab, int *interuptor)
{
	if (tab->spe_string == -1)
		ft_process_widths(tab);
	if (tab->spe_case == 1 && tab->prc < 0
		&& tab->pnt == 1 && tab->spe_string == 0
		&& tab->spe_case == 1)
		ft_interuptor1_1(tab);
	else if (tab->prc == 0 && tab->spe_case == 1
		&& tab->spe_string == 0 && tab->pnt == 0)
		ft_interuptor1_1(tab);
	else if (tab->spe_case == 0)
	{
		if (tab->minus == 1)
			ft_interuptor1_2(tab, interuptor);
		else if (tab->minus == 0)
			ft_interuptor1_3(tab);
	}
	else if (tab->spe_string == 0)
		ft_interuptor1_4(tab, interuptor);
}

void	dispatch_under_2(t_print *tab, char *output, int size_str )
{
	if (tab->spe_string == 0 && tab->prc < 0 && tab->spe_case == 1)
		ft_interuptor0_6(tab, &size_str, output);
	else if (tab->prc < 0 && tab->pnt == 1 && tab->spe_string == -1)
		ft_process_widths(tab);
	else
	{
		if (tab->minus == 1)
			ft_interuptor0_1(tab, &size_str, output);
		else if (tab->minus == 0 && tab->prc > 0)
			ft_interuptor0_2(tab, &size_str, output);
		else if (tab->minus == 0 && tab->prc == 0 && tab->wdt > 0)
			ft_interuptor0_3(tab, &size_str, output);
		else
			ft_putstr(output, tab, size_str);
	}
}

void	dispatch2(t_print *tab, char *output, int null )
{
	int	size_str;

	size_str = ft_strlen(output);
	if (tab->wdt == 0 && tab->pnt == 1 && tab->prc == 0
		&& tab->spe_string == 0 && tab->spe_case == 0)
		;
	else if (tab->pnt == 1 && null == 0 && tab->prc > -2 && tab->spe_case == 0)
	{
		if (tab->prc == -1)
			ft_process_widths(tab);
		else if (tab->minus == 1)
			ft_interuptor0_1(tab, &size_str, output);
		else if (tab->minus == 0 && tab->prc > 0)
			ft_interuptor0_2(tab, &size_str, output);
		else if (tab->minus == 0 && tab->prc == 0 && tab->wdt > 0)
			ft_interuptor0_3(tab, &size_str, output);
		else
			ft_putstr(output, tab, size_str);
	}
	else if (tab->pnt == 0 && null == 0 && tab->prc > -2 && tab->spe_case == 0)
		ft_interuptor0_4(tab, &size_str, output);
	else if (tab->prc < -1 && tab->spe_case == 0)
		ft_interuptor0_5(tab, &size_str, output);
	else if (tab->spe_case == 1)
		dispatch_under_2(tab, output, size_str);
}

void	ft_load_string(t_print *tab)
{
	char	*output;
	int		interuptor;
	int		null;

	interuptor = 0;
	null = 0;
	output = va_arg(tab->args, char *);
	if (output == NULL)
	{
		output = "(null)";
		if (tab->pnt == 1 && tab->prc < 0 && tab->wdt == 0)
			null++;
		tab->spe_case = 1;
		interuptor = 1;
	}
	if (interuptor == 1)
	{
		dispatch1(tab, &interuptor);
	}
	else
		dispatch2(tab, output, null);
}

void	ft_help_interuptor0_5(t_print *tab, int *size_str, char *output)
{
	if (tab->prc < *size_str)
		tab->wdt -= tab->prc;
	else
	{
		tab->wdt -= *size_str;
		tab->prc = *size_str;
	}
	ft_process_widths(tab);
	ft_putstr(output, tab, tab->prc);
}
