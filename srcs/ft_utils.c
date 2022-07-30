/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmastor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:08:34 by flmastor          #+#    #+#             */
/*   Updated: 2021/07/05 17:53:14 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_maxll(unsigned long long res, int signe)
{
	if (res > 9223372036854775807 && signe == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					signe;
	unsigned long long	res;

	i = -1;
	signe = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		++i;
	}
	if (res > 9223372036854775807)
		return (ft_maxll(res, signe));
	return (res * signe);
}

int	ft_size_calculator(int nbr)
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

void	ft_putstr(char *str, t_print *tab, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		tab->tl += write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
