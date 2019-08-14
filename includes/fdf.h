/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 03:22:09 by hmidoun           #+#    #+#             */
/*   Updated: 2019/08/14 07:11:34 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "array.h"

# define COMMA				','
# define ON					1
# define OFF				0
# define VALID_HEIGHT_COLOR	2
# define VALID_COLOR		1
# define VALID_HEIGHT		1
# define SUCCESS			1
# define FAIL				0
# define RAD_30				0.52359877559
# define X_SCREEN			(9 * 200)
# define Y_SCREEN			(6 * 200)
# define X_INSTR			300
# define Y_IMG				Y_SCREEN
# define X_IMG				(X_SCREEN - X_INSTR)
# define SIZE_IMG			4 * ((Y_IMG) * X_IMG)
# define KEY_PRESS			2
# define KEY_RELEASE		3
# define ISO				1
# define PARALLEL			0
# define BLACK 				0x000000
# define WHITE 				0xFFFFFF
# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define NUMBER_PAD_PLUS	69
# define NUMBER_PAD_MINUS	78
# define MAIN_PAD_I			34
# define MAIN_PAD_P			35
# define MAIN_PAD_W			13
# define MAIN_PAD_S			1
# define MAIN_PAD_A			0
# define MAIN_PAD_D			2
# define MAIN_PAD_Q			12
# define MAIN_PAD_E			14
# define MAIN_PAD_SPACE		49
# define MAIN_PAD_ESC		53
# define PAD_9				92
# define PAD_6				88
# define ARGS_ERROR			1
# define INVALID_MAP		2
# define FILE_ERROR			3
# define MLX_ERROR			4
# define MALLOC_ERROR		5
# define CLOSE_FILE_ERROR	6

typedef struct	s_coord
{
	int x;
	int y;
}				t_coord;

typedef struct	s_info
{
	int		x;
	int		y;
	int		z;
	int		color;
	int		flag_o_color;
}				t_info;

typedef struct	s_fdf_info
{
	int		height_max;
	int		width_flag;
	int		iso_center[2];
	int		para_center[2];
	int		map_w;
	int		map_h;
	int		init_zoom;
	int		z_max;
	int		z_min;

	double	x_rot;
	double	y_rot;
	double	z_rot;
	int		x_offset;
	int		y_offset;
	double	color_offset;
	int		zoom;
	int		perspective;
	t_array	grid;
	t_info	*copy;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_string;
}				t_fdf_info;

void			put_error(void);

int				parse_file(t_array *grid, int fd, t_fdf_info *fdf);
int				check_input(char *str, int *color_flag);
int				atoi_hex(char *str);
int				ft_atoi_skip(char **str);

void			draw(t_fdf_info *fdf);
void			draw_line(t_info p1, t_info p2, t_fdf_info *fdf);
void			draw_line_x(t_info p1, t_info p2, t_fdf_info *fdf);
void			draw_line_y(t_info p1, t_info p2, t_fdf_info *fdf);
void			pixel_in_img(char *image_string, int x, int y, int color);
void			reset_img(char *image_string);

t_info			zoom(t_info lst, int s_x, int s_y, int s_z);
t_info			translation(t_info lst, int tx, int ty, int tz);
t_info			rotation_x(t_info lst, double ang);
t_info			rotation_y(t_info lst, double ang);
t_info			rotation_z(t_info lst, double ang);
void			isometric(t_info *draw, t_fdf_info *fdf);

double			percent(int start, int end, int current);
int				get_color(int current, t_info start, t_info end,
					double color_offset);
void			set_color(t_array grid, t_fdf_info *fdf, int flag);
void			instruction(t_fdf_info *fdf);

int				init_zoom(t_fdf_info *fdf);

int				key_press(int keycode, void *param);
void			perspective(int key, t_fdf_info *fdf);
void			reset_transformation(t_fdf_info *fdf);
void			press_rotation(int key, t_fdf_info *fdf);
void			press_move(int key, t_fdf_info *fdf);
void			press_zoom(int key, t_fdf_info *fdf);
void			press_offset_color(int key, t_fdf_info *fdf);

int				ft_exit(t_fdf_info *fdf);
int				ft_error(int type);

#endif
