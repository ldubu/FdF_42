/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:54:18 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/08 15:00:04 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
//;

int	__draw(t_tab *tab)
{
	t_mlx	info;
	t_img	img;

	__init_window(&info, &img);
	/*t_point a;
	t_point b;
	t_point c;
	t_point d;
	t_point e;
	t_point f;
	t_point g;
	t_point h;

	a.x = 500;
	a.y = 250;
	b.x = 550;
	b.y = 200;
	c.x = 650;
	c.y = 200;
	d.x = 700;
	d.y = 250;
	e.x = 700;
	e.y = 350;
	f.x = 650;
	f.y = 400;
	g.x = 550;
	g.y = 400;
	h.x = 500;
	h.y = 350;

	b.color = 0x000FF00;
	g.color = 0x00000FF;
	h.color = 0x0FFFF00;

	__draw_a_line(&a, &e, &img);
	//__draw_a_line(&e, &a, &img);
	__draw_a_line(&b, &f, &img);
	//__draw_a_line(&f, &b, &img);
	//__draw_a_line(&c, &g, &img);
	__draw_a_line(&g, &c, &img);
	//__draw_a_line(&d, &h, &img);
	__draw_a_line(&h, &d, &img);
	
	tab->x_max = 0;
	__my_mlx_pixel_put(&img, 600, 300, 0x0FF0000);
	__my_mlx_pixel_put(&img, 650, 200, 0x0FF0000);
	__my_mlx_pixel_put(&img, 550, 400, 0x0FF0000);*/
	__write_img(tab, &img, &info);
	mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.img_ptr, 0, 0);
	mlx_loop(info.mlx_ptr);
	return (0);
}

void	__write_img(t_tab *tab, t_img *img, t_mlx *info)
{
	int		y;
	int		x;
	t_point	a;
	t_point	b;

	y = 0;
	while (y < tab->y_max)
	{
		x = 0;
		while (x < tab->x_max)
		{
			a.z = tab->coordonnees[y][x];
			__calculate_xy(&a, x, y, info);
			if (x < tab->x_max - 1)
			{
				b.z = tab->coordonnees[y][x + 1];
				__calculate_xy(&b, x + 1, y, info);
				__draw_a_line(&a, &b, img);
			}
			if (y < tab->y_max - 1)
			{
				b.z = tab->coordonnees[y + 1][x];
				__calculate_xy(&a, x, y, info);
				__calculate_xy(&b, x, y + 1, info);
				__draw_a_line(&a, &b, img);
			}
			x++;
		}
		y++;
	}
}

void	__calculate_xy(t_point *point, int x, int y, t_mlx *info)
{
	point->color = 0x0FFFFFF;
	point->x = (((x * info->scale) - (y * info->scale)) * cos(info->angle)) \
	+ info->shift_x;
	point->y = ((((x * info->scale) + (y * info->scale)) \
	* sin(info->angle)) - point->z * info->z_scale) + info->shift_y;
}

int	__init_window(t_mlx *info, t_img *img)
{
	info->angle = 0.523599;
	info->scale = 30;
	info->z_scale = 1;
	info->win_x = 2000;
	info->win_y = 1000;
	info->shift_x = info->win_x / 3;
	info->shift_y = info->win_y / 3;
	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr, 2000, 1000, "Titre");
	info->img_ptr = mlx_new_image(info->mlx_ptr, 2000, 1000);
	img->img_addr = mlx_get_data_addr(info->img_ptr, &img->bpp, \
	&img->size_line, &img->endian);
	return (0);
}

void	__my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int *) dst = color;
}

void	__swap_ab(t_point *a, t_point *b)
{
	int	temp;

	temp = a->x;
	a->x = b->x;
	b->x = temp;
	temp = a->y;
	a->y = b->y;
	b->y = temp;
}

int	__abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

//printf("xa = %d, xb = %d, ya = %d, yb = %d, get = %d, dif_y = %d, dif_x = %d\n", seg->xa, seg->xb, seg->ya, seg->yb, get_down, diff_y, diff_x);
