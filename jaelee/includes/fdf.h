/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 03:22:09 by hmidoun           #+#    #+#             */
/*   Updated: 2019/08/09 07:49:28 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "array.h"
#include <stdio.h>/////////////////////

typedef struct	s_info
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_info;

typedef struct	s_fdf_info
{
	int 	x_max;
	int 	y_max;
	int		height_max;
	float 	x_rot;
	float	y_rot;
	float	z_rot;
}				t_fdf_info;

int		ft_atoi_skip(char **str);
void	put_error(void);

int		parse_file(t_array *grid, int fd);
int		check_input(char *str, int *color_flag);
void	put_error(void);

//void	free_list(t_info **head);
//int		add_to_p_list(t_info **head, int x, int y, int z);

void	draw_line(t_info p1, t_info p2, void *mlx_ptr, void *win_ptr);
void	draw_line_x1_dx(t_info p1, t_info p2, void *mlx_ptr, void *win_ptr);
void	draw_line_x2_dx(t_info p1, t_info p2, void *mlx_ptr, void *win_ptr);
void	draw_line_x1_dy(t_info p1, t_info p2, void *mlx_ptr, void *win_ptr);
void	draw_line_x2_dx(t_info p1, t_info p2, void *mlx_ptr, void *win_ptr);


t_info	zoom(t_info lst, int s_x, int s_y, int s_z);
t_info	translation(t_info lst, int tx, int ty, int tz);
t_info	rotation_x(t_info lst, float ang);
t_info	rotation_y(t_info lst, float ang);
t_info	rotation_z(t_info lst, float ang);

//t_info	rotation(t_info lst, float x_ang, float y_ang, float z_ang);


void	draw(t_info *to_draw, int T[3], int sizes, void *mlw_ptr, void *win_ptr);
void	iso(t_info **to_draw, int size, int T[3]);



double	percent(int start, int end, int current);
int		get_light(int start, int end, double percentage);
int		get_color(int current, t_info start, t_info end, int i);

void	set_color(t_array grid, int *x_line);


void	instruction(void *mlx_ptr, void *win_ptr);

int		init_zoom(t_array grid, int T[3]);

#define COMMA ','
#define ON 1
#define OFF 0
#define VALID_HEIGHT_COLOR 2
#define VALID_COLOR 1
#define VALID_HEIGHT 1
#define SUCCESS 1
#define FAIL 0
#define	X_SCREEN 9 * 200
#define	Y_SCREEN 6 * 200
#define	X_INSTRUCTION 300
#endif


