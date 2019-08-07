/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 03:22:09 by hmidoun           #+#    #+#             */
/*   Updated: 2019/08/06 04:47:44 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include "./libft/libft.h"
# define W_SIZE 9*200
# define H_SIZE 6*200

typedef struct s_p_list	t_p_list;
struct	s_p_list
{
	int			x;
	int			y;
	int			z;
	int			col;
	t_p_list	*next;
};

int			ft_getnbr(char *str, int *nbr);
void		put_error(void);
void		draw_line(t_p_list p1, t_p_list p2, void *mlx_ptr, void *win_ptr);
int			get_file(t_p_list **head, int fd);
void		put_error(void);
void		free_list(t_p_list **head);
int			add_to_p_list(t_p_list **head, int x, int y, int z);
void		draw_line_x1_dx(t_p_list p1, t_p_list p2, void *mlx_ptr, void *win_ptr);
void		draw_line_x2_dx(t_p_list p1, t_p_list p2, void *mlx_ptr, void *win_ptr);
void		draw_line_x1_dy(t_p_list p1, t_p_list p2, void *mlx_ptr, void *win_ptr);
void		draw_line_x2_dx(t_p_list p1, t_p_list p2, void *mlx_ptr, void *win_ptr);


t_p_list	*zoom(t_p_list *lst, int s_x, int s_y, int s_z);
t_p_list	*translation(t_p_list *lst, int tx, int ty, int tz);
t_p_list	*rotation_x(t_p_list *lst, float ang);
t_p_list	*rotation_y(t_p_list *lst, float ang);
t_p_list	*rotation_z(t_p_list *lst, float ang);
void		init_graphic(void *mlx_ptr, void *win_ptr);



#endif
