/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:54:18 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/03 17:03:34 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
//;

int	__draw(t_tab *tab, int **coordonees, int size)
{
	t_mlx	info;
	t_img	img;
	t_point	a;
	t_point b;

	__init_window(&info, &img);
	//creer une fonction qui prend coordo, size et tab? et qui modifie l'image
	//initier a, b et appeler draw dans cette fonction
	__draw_a_line(&a, &b, &img);
	mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.img_ptr, 0, 0);
	mlx_loop(info.mlx_ptr);
	return (0);
}

int	__init_window(t_mlx *info, t_img *img)
{
	info->angle = 0.523599;
	info->scale = 20;
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
