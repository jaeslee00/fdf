/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 04:13:42 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/14 07:00:15 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_exit(t_fdf_info *fdf)
{
	(void)fdf;
	exit(0);
}

int	ft_error(int type)
{
	if (type == ARGS_ERROR)
	{
		ft_putendl("error in input arguments.");
		ft_putendl("usage: ./fdf [file.fdf]");
	}
	if (type == INVALID_MAP)
		ft_putendl("parsing error.");
	if (type == FILE_ERROR)
		ft_putendl("cannot open the file.");
	if (type == MLX_ERROR)
		ft_putendl("mlx error.");
	if (type == MALLOC_ERROR)
		ft_putendl("MALLOC ERROR.");
	exit(0);
}
