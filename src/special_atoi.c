/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 05:29:44 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/14 05:30:06 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			atoi_hex(char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		nbr = nbr << 4;
		if (ft_isdigit(str[i]))
			nbr |= str[i] - '0';
		else
		{
			if (str[i] >= 'A' && str[i] <= 'F')
				nbr |= str[i] - 'A' + 10;
			else
				nbr |= str[i] - 'a' + 10;
		}
		i++;
	}
	return (nbr);
}

int			ft_atoi_skip(char **str)
{
	int		i;
	int		neg;
	int		number;

	number = 0;
	neg = 1;
	i = 0;
	while (**str == 32 || (**str >= 9 && **str <= 13))
		((*str)++);
	if (**str == '-')
	{
		neg = -1;
		((*str)++);
	}
	else if (**str == '+')
		((*str)++);
	while (**str >= '0' && **str <= '9')
	{
		number = number * 10 + **str - '0';
		((*str)++);
	}
	return (number * neg);
}
