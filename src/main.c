/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 04:38:56 by jaelee            #+#    #+#             */
/*   Updated: 2019/08/14 07:10:38 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

int			key_press(int keycode, void *param)
{
	t_fdf_info	*fdf;

	fdf = (t_fdf_info*)param;
	if (keycode == MAIN_PAD_W || keycode == MAIN_PAD_A ||
		keycode == MAIN_PAD_S || keycode == MAIN_PAD_D ||
		keycode == MAIN_PAD_Q || keycode == MAIN_PAD_E)
		press_rotation(keycode, fdf);
	else if (keycode == PAD_9 || keycode == PAD_6)
		press_offset_color(keycode, fdf);
	else if (keycode == ARROW_UP || keycode == ARROW_DOWN ||
		keycode == ARROW_LEFT || keycode == ARROW_RIGHT)
		press_move(keycode, fdf);
	else if (keycode == NUMBER_PAD_PLUS || keycode == NUMBER_PAD_MINUS)
		press_zoom(keycode, fdf);
	else if (keycode == MAIN_PAD_I || keycode == MAIN_PAD_P)
		perspective(keycode, fdf);
	else if (keycode == MAIN_PAD_SPACE)
		reset_transformation(fdf);
	else if (keycode == MAIN_PAD_ESC)
		exit(0);
	draw(fdf);
	return (0);
}

static void	initialize_mlx(t_fdf_info *fdf)
{
	int			bpp;
	int			s_l;
	int			endian;

	if (!(fdf->mlx_ptr = mlx_init()))
		ft_error(MLX_ERROR);
	if (!(fdf->win_ptr = mlx_new_window(fdf->mlx_ptr,
		X_SCREEN, Y_SCREEN, "fdf")))
		ft_error(MLX_ERROR);
	if (!(fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, X_IMG, Y_IMG)))
		ft_error(MLX_ERROR);
	if (!(fdf->img_string = mlx_get_data_addr(fdf->img_ptr,
		&bpp, &s_l, &endian)))
		ft_error(MLX_ERROR);
	if (!(fdf->copy = (t_info*)malloc(sizeof(t_info) * fdf->grid.length)))
		ft_error(MALLOC_ERROR);
	instruction(fdf);
	fdf->color_offset = -1.3;
	set_color(fdf->grid, fdf, 1);
	fdf->init_zoom = init_zoom(fdf);
	fdf->zoom = fdf->init_zoom;
}

static void	initialize_fdf(t_fdf_info *fdf)
{
	ft_bzero(fdf, sizeof(*fdf));
	array_init(&fdf->grid, sizeof(t_info));
	fdf->perspective = ISO;
}

int			main(int argc, char **argv)
{
	int			fd;
	t_fdf_info	fdf;

	initialize_fdf(&fdf);
	if (argc != 2)
		ft_error(ARGS_ERROR);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error(FILE_ERROR);
	if (!parse_file(&fdf.grid, fd, &fdf))
	{
		close(fd);
		ft_error(INVALID_MAP);
	}
	if (close(fd < 0))
		ft_error(CLOSE_FILE_ERROR);
	initialize_mlx(&fdf);
	draw(&fdf);
	mlx_hook(fdf.win_ptr, KEY_PRESS, 0, key_press, &fdf);
	mlx_hook(fdf.win_ptr, 17, 0, ft_exit, &fdf);
	mlx_loop(fdf.mlx_ptr);
	exit(0);
}
