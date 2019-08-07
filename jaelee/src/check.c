/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 01:12:33 by hmidoun           #+#    #+#             */
/*   Updated: 2019/08/06 06:42:24 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		atoi_hex(char *str)
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
				nbr |= str[i] - 'A';
			else
				nbr |= str[i] - 'a';
		}
		i++;
	}
	return (nbr);
}

static int		parse_height_color(char *str, int x_size, int y_size, t_info *info)
{
	info->x = x_size;
	info->y = y_size;
	info->z = ft_atoi_skip(&str);
	info->color = atoi_hex(str + 3);
	return (SUCCESS);
}

static int		parse_height(char *str, int x_size, int y_size, t_info *info)
{
	info->x = x_size;
	info->y = y_size;
	info->z = ft_atoi(str);
	info->color = -1;
	return (SUCCESS);
}

static int		parse_grid(char *str, int x_size, int y_size, t_info *info)
{
	int	ret;
	int color_flag;

	ret = check_input(str, &color_flag);
	if (ret == VALID_HEIGHT_COLOR)
		return (parse_height_color(str, x_size, y_size, info));
	else if (ret == VALID_HEIGHT)
		return (parse_height(str, x_size,y_size, info));
	else
		return (FAIL);
	return(1);
}

int		process_line(char *line, t_array *grid, int y_size)
{
	int		x_size;
	char	**split;
	t_info	info;

	x_size = 0;
	split = ft_split(line, " \t");
	while(split[x_size])
	{
		if (parse_grid(split[x_size], x_size, y_size, &info))
			array_push_back(grid, &info);
		else
		{
			ft_splitdel(split);
			return (0);
		}
		x_size++;
	}
	ft_splitdel(split);
	return (1);
}

int		parse_file(t_array *grid, int fd)
{
	char	*line;
	int		y_size;

	line = NULL;
	y_size = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!process_line(line, grid, y_size))
		{
			free(line);
			return (0);
		}
		free(line);
		y_size++;
	}
	return(1);
}

