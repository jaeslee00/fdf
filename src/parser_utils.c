/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 03:45:15 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/14 05:30:32 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_color(const char *str)
{
	int	i;
	int	len;

	len = (int)ft_strlen(str);
	if (len < 3 || len > 8)
		return (FAIL);
	if (str[0] != '0' && str[1] != 'x')
		return (FAIL);
	i = 2;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !((str[i] >= 'A' && str[i] <= 'F')
			|| (str[i] >= 'a' && str[i] <= 'f')))
			return (FAIL);
		i++;
	}
	return (VALID_COLOR);
}

static int	check_height(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (!str[1])
			return (FAIL);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FAIL);
		i++;
	}
	return (VALID_HEIGHT);
}

static int	nbr_of_comma(char *str)
{
	int	index;
	int	cnt;

	index = 0;
	cnt = 0;
	while (str[index])
	{
		if (str[index] == COMMA)
			cnt++;
		index++;
	}
	if (cnt == 1)
		return (SUCCESS);
	return (FAIL);
}

int			check_input(char *str, int *color_flag)
{
	char	**split;
	int		cnt;

	if (ft_strchr(str, COMMA) && nbr_of_comma(str))
	{
		if (!(split = ft_strsplit(str, COMMA)))
			return (FAIL);
		cnt = 0;
		while (split[cnt])
			cnt++;
		if (cnt != 2 || !check_height(split[0]) || !check_color(split[1]))
		{
			ft_splitdel(split);
			return (FAIL);
		}
		else
		{
			*color_flag = ON;
			ft_splitdel(split);
			return (VALID_HEIGHT_COLOR);
		}
	}
	else
		return (check_height(str));
}
