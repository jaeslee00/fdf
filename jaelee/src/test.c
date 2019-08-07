/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 04:38:56 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/07 08:54:41 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>


int		main(int argc, char **argv)
{
	int			fd;
	t_array		grid;
	t_info		*to_draw;




	void	*mlx_ptr = NULL;
	void	*win_ptr;

	//void	*img_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 9*250, 6*250, "fdf");



	(void) argv;
	if (argc != 2)
	{
		ft_putendl("usage: ./fdf [file.fdf]");
		//exit(0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	array_init(&grid, sizeof(t_info));
	if(!parse_file(&grid, fd))
	{
		return(0);
	}

	int		minz = ((t_info*)grid.ptr)[0].z;
	int		maxz = ((t_info*)grid.ptr)[0].z;
	int		x_line;

//////////////////////////////////////////////
	t_info	t1;
	t_info	t2;

	t1.z = 0;
	t2.z = 15;

	t1.color = 65280;
	t2.color = 16187906;

/////////////////////////////////////////////
	to_draw = (t_info *)malloc(sizeof(t_info) * grid.length);


	for (size_t i=0; i < grid.length; i++)
	{
		if (((t_info*)grid.ptr)[i].y == 1 && ((t_info*)grid.ptr)[i].x == 0)
			x_line = i;
		/*
		if (((t_info*)grid.ptr)[i].z > maxz)
			maxz = ((t_info*)grid.ptr)[i].z;
		if (((t_info*)grid.ptr)[i].z < minz)
			minz = ((t_info*)grid.ptr)[i].z;*/
		if (((t_info*)grid.ptr)[i].color == -1)
			((t_info*)grid.ptr)[i].color = get_color(((t_info*)grid.ptr)[i].z, t1, t2, -1);
		to_draw[i] = zoom(((t_info*)grid.ptr)[i], 2, 2, 2); // scale it in the begining to avoid some problems with int coord ***********
		//to_draw[i] = rotation_z(((t_info*)grid.ptr)[i], 3.14/2);//*******************************************************
		//to_draw[i] = rotation_z(to_draw[i], M_PI - 0.2);
		//printf("%d\n", to_draw[i].color);
	}
	draw(to_draw, x_line, (int)  grid.length, mlx_ptr, win_ptr);
/*
	for (size_t i=0; i < grid.length; i++)
	{
		to_draw2[i].x =  (to_draw[i].x - to_draw[i].y) * cos(M_PI / 6.0f) + 800;
		to_draw2[i].y = -to_draw[i].z + (to_draw[i].x + to_draw[i].y) * sin(M_PI / 6.0f) +400;

	}

	for(size_t y = 0; y < grid.length / x_line; y++)
	{
		for (int i = 0; i < x_line; i++)
		{
			if (i < x_line - 1)
				draw_line(to_draw2[i + y * x_line], to_draw2[i + 1 + y * x_line], mlx_ptr, win_ptr);
			if (y < grid.length / x_line - 1)
				draw_line(to_draw2[i + y * x_line], to_draw2[i + (y+1) * x_line], mlx_ptr, win_ptr);
		}
	}*/
	mlx_loop(mlx_ptr);
	printf("%d \t %d \t %d \t %lu\n", maxz, minz, x_line, grid.length / x_line);
	return (1);
}

//2,0x820505
