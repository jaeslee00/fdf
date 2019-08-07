/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 03:22:12 by hmidoun           #+#    #+#             */
/*   Updated: 2019/08/06 04:47:13 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//#include <math.h>
/*
void draw_line(t_p_list p1, t_p_list p2, void *mlx_ptr, void *win_ptr)
{
	int cumul;
	int xmin;
	int	ymin;
	//int	y_step;

	xmin = fmin(p1.x, p2.x);
	ymin = fmin(p1.y, p2.y);
	if (xmin == p1.x)
	{
		if((ymin = p1.y) < p2.y)
			y_step = 1;
		else
			y_step = -1;
	}
	else
	{
		ymin = p2.y;
		if((ymin = p2.y) < p1.y)
			y_step = 1;
		else
			y_step = -1;
	}
	cumul = abs(p2.x - p1.x) / 2 ;
	for ( xmin++; xmin <= fmax(p1.x, p2.x) ; xmin++ )
	{
		cumul += abs(p2.y - p1.y) ;
		if ( cumul >= abs(p2.x - p1.x) )
		{
			cumul -= abs(p2.x - p1.x) ;
			ymin++;
		}
	mlx_pixel_put(mlx_ptr, win_ptr, xmin, ymin, 100);
	}
}
*/
void	put_error(void)
{
	ft_putendl("error");
	exit(0);
}

#include "stdio.h"
int		main(int argc, char **argv)
{
	int			fd;
	t_p_list	*head;

	head = NULL;
	(void) argv;
	if (argc != 2)
	{
		ft_putendl("usage: ./fdf file");
		//exit(0);
	}
	if ((fd = open("./42.fdf", O_RDONLY)) < 0)
		put_error();
	if(!get_file(&head, fd))
	{/*
			while (head)
			{
				if (head->x == 0)
					printf("\n\n\n\n");
				printf("%d\t%d\t%d\n", head->x,head->y,head->z);
				head = head->next;
			}*/
			//if(head)
			free_list(&head);
			return(0);
	}
	//t_p_list	*tst = head;
	void	*mlx_ptr = NULL;
	void	*win_ptr;

	//void	*img_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, W_SIZE, H_SIZE, "fdf");
//	t_p_list T[11][19];

	init_graphic(mlx_ptr, win_ptr);


	mlx_loop(mlx_ptr);




















/*
while (tst)
{

tst->x *= 20;
		tst->y *= 20;
		tst->z *= 20;

	tst = tst->next;
}

int m  =0;

while (m < 2)
{
tst = head;


while (tst)
{
	zoom(&tst, 2, 2, 2);
	//rotation_x(&tst, 3.14 /6);
	//rotation_x(&tst, 3.14 /6);
	//rotation_x(&tst, 3.14 /6);
	tst = tst->next;
}


tst = head;
	int x=0, y =0;

	while (tst)
	{
		if(x == 19)
		{
			x= 0;
			y++;
		}

		tst->x *= 20;
		tst->y *= 20;
		tst->z *= 20;
		T[y][x].x =  (tst->x - tst->y) * cos(3.14/6) + 500;
		T[y][x].y = - tst->z+ (tst->x + tst->y) * sin(3.14/6) +500;
	T[y][x].z =  tst->z;
		tst = tst->next;
		x++;
	}
	for(y=0;y < 10; y++)
	{
		for(x=0;x < 18; x++)
		{
			//if (y < 18)
				draw_line(T[y][x], T[y][x + 1], mlx_ptr, win_ptr);
			//if (x < 10)
				draw_line(T[y][x],T[y+1][x], mlx_ptr, win_ptr);
			//mlx_pixel_put(mlx_ptr, win_ptr, T[y][x].x , T[y][x].y,  T[y][x].z * 1000000);
			//mlx_pixel_put(mlx_ptr, win_ptr, T[y][x].x, T[y][x].y,  tz * 1500000 + 15000);
		}
		//mlx_pixel_put(mlx_ptr, win_ptr, T[y][x].x, T[y][x].y,  150000);
	}
		mlx_key_hook(mlx_ptr, (void*) 0, 0);
		mlx_loop(mlx_ptr);

m++;
//sleep(2);
//mlx_clear_window(mlx_ptr, win_ptr);
}*/

/*
	T[0][0].x = 100;
	T[0][0].y = 100;

	T[0][1].x = 200;
	T[0][1].y = 200;

	T[0][2].x = 100;
	T[0][2].y = 200;

	T[0][3].x = 200;
	T[0][3].y = 100;

	T[0][4].x = 0;
	T[0][4].y = 0;

	//draw_line(T[0][0],T[0][3], mlx_ptr, win_ptr);
	//draw_line(T[0][0],T[0][1], mlx_ptr, win_ptr);
	//draw_line(T[0][0],T[0][2], mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
	//draw_line(T[0][0],T[0][4], mlx_ptr, win_ptr);

	draw_line(T[0][2],T[0][1], mlx_ptr, win_ptr);
	draw_line(T[0][2],T[0][1], mlx_ptr, win_ptr);
	draw_line(T[0][2],T[0][1], mlx_ptr, win_ptr);
*/

	//draw_line(T[0][0].x,T[0][0].y,T[0][ 1].x,T[0][1].y, mlx_ptr, win_ptr);
	//draw_line(T[0][0].x,T[0][0].y,T[1][ 0].x,T[1][0].y, mlx_ptr, win_ptr);



/*
while (head)
			{
				if (head->x == 0)
					printf("\n\n\n\n");
				printf("%d\t%d\t%d\n", head->x,head->y,head->z);
				head = head->next;
			}


	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;

	int i;
	while (--argc)
	{
		printf("%d\t%d\n",ft_getnbr(argv[argc], &i),i);
	}


	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fdf");
	//mlx_loop(mlx_ptr);
	img_ptr = mlx_new_image(mlx_ptr,500,500);*/
	/*for(int i = 0; i<500;i++)
	{
		//for(int j = 0; j<500;j++)
		//{

		//mlx_pixel_put(mlx_ptr, win_ptr, i, 150, 100);
		//ft_putchar('s');
	//	}

	}*/

		//draw_line(200,200,500,0,mlx_ptr,win_ptr);

	/*	for(int j = 0; j<250;j++)
		{
		draw_line(100,100,400+j ,400-j,mlx_ptr,win_ptr);
		}*/
	//mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr ,250,250);
		//mlx_loop(mlx_ptr);
//	return(0);
}
