/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 01:12:33 by hmidoun           #+#    #+#             */
/*   Updated: 2019/08/14 06:26:17 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	parse_height_color(char *str, int x_size,
					int y_size, t_info *info)
{
	info->x = x_size;
	info->y = y_size;
	info->z = ft_atoi_skip(&str);
	if (info->z < -100000 || info->z > 100000)
		return (FAIL);
	info->color = atoi_hex(str + 3);
	info->flag_o_color = 1;
	return (SUCCESS);
}

static int	parse_height(char *str, int x_size, int y_size, t_info *info)
{
	info->x = x_size;
	info->y = y_size;
	info->z = ft_atoi(str);
	if (info->z < -100000 || info->z > 100000)
		return (FAIL);
	info->color = 0;
	info->flag_o_color = 0;
	return (SUCCESS);
}

static int	parse_grid(char *str, int x_size, int y_size, t_info *info)
{
	int	ret;
	int color_flag;

	ret = check_input(str, &color_flag);
	if (ret == VALID_HEIGHT_COLOR)
		return (parse_height_color(str, x_size, y_size, info));
	else if (ret == VALID_HEIGHT)
		return (parse_height(str, x_size, y_size, info));
	else
		return (FAIL);
	return (1);
}

static int	process_line(char *line, t_array *grid, int y_size, t_fdf_info *fdf)
{
	int		x_size;
	char	**split;
	t_info	info;

	x_size = 0;
	if (!(split = ft_split(line, " \t")))
		return (FAIL);
	while (split[x_size])
	{
		if (parse_grid(split[x_size], x_size, y_size, &info))
			array_push_back(grid, &info);
		else
		{
			ft_splitdel(split);
			return (FAIL);
		}
		x_size++;
	}
	if (fdf->width_flag == OFF)
	{
		fdf->map_w = x_size;
		fdf->width_flag = ON;
	}
	ft_splitdel(split);
	return (x_size);
}

int			parse_file(t_array *grid, int fd, t_fdf_info *fdf)
{
	char	*line;
	int		y_size;
	int		ret;

	line = NULL;
	y_size = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if ((ret = process_line(line, grid, y_size, fdf)) < 1)
		{
			free(line);
			return (FAIL);
		}
		free(line);
		if (ret != fdf->map_w)
			return (FAIL);
		y_size++;
	}
	fdf->map_h = y_size;
	if (grid->length < 2)
		return (FAIL);
	return (SUCCESS);
}
