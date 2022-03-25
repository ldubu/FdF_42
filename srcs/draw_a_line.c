/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_a_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:42:54 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/23 14:58:15 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 	Tracer de ligne entre deux point en utilisant l'implementation de  Bresenham
	Il y a 8 disposition possible mais elle peuven etre reduite a 4 en swappant
	a et b.
*/

void	__draw_a_line(t_point *a, t_point *b, t_mlx *img)
{
	if (b->y < a->y)
		__swap_ab(a, b);
	b->color = __color(b->z, img->tab);
	a->color = __color(a->z, img->tab);
	a->distance = 0;
	if (b->z != a->z)
		a->distance = sqrt((double)(b->x - a->x) * (b->x - a->x) \
		+ (b->y - a->y) * (b->y - a->y)) / abs(b->z - a->z);
	if (a->x <= b->x)
	{
		if (abs(b->x - a->x) > abs(b->y - a->y))
			__down_x(a, b, img);
		else
			__down_y(a, b, img);
	}
	else
	{
		if (abs(b->x - a->x) > abs(b->y - a->y))
			__up_x(a, b, img);
		else
			__up_y(a, b, img);
	}
}

void	__down_x(t_point *a, t_point *b, t_mlx *img)
{
	int	diff_y;
	int	diff_x;
	int	get_down;
	int	i;

	i = 0;
	diff_x = abs((b->x - a->x) * 2);
	diff_y = abs((b->y - a->y) * 2);
	get_down = b->x - a->x;
	while (a->x <= b->x)
	{
		__my_mlx_pixel_put(img, a->x, a->y, a->color);
		a->x += 1;
		i++;
		__color_down_x(a, b, i, img);
		get_down -= diff_y;
		if (get_down <= 0)
		{
			a->y += 1;
			get_down += diff_x;
		}
	}
}

void	__down_y(t_point *a, t_point *b, t_mlx *img)
{
	int	diff_y;
	int	diff_x;
	int	get_down;
	int	i;

	i = 0;
	diff_x = abs((b->x - a->x) * 2);
	diff_y = abs((b->y - a->y) * 2);
	get_down = b->x - a->x;
	while (a->y <= b->y)
	{
		__my_mlx_pixel_put(img, a->x, a->y, a->color);
		a->y += 1;
		i++;
		__color_down_y(a, b, i, img);
		get_down -= diff_x;
		if (get_down <= 0)
		{
			a->x += 1;
			get_down += diff_y;
		}
	}
}

void	__up_x(t_point *a, t_point *b, t_mlx *img)
{
	int	diff_y;
	int	diff_x;
	int	get_down;
	int	i;

	i = 0;
	diff_x = abs((b->x - a->x) * 2);
	diff_y = abs((b->y - a->y) * 2);
	get_down = b->y - a->y;
	while (b->x <= a->x)
	{
		__my_mlx_pixel_put(img, b->x, b->y, a->color);
		b->x += 1;
		__color_up_x(a, b, i, img);
		get_down -= diff_y;
		if (get_down <= 0)
		{
			b->y -= 1;
			get_down += diff_x;
		}
	}
}

void	__up_y(t_point *a, t_point *b, t_mlx *img)
{
	int	diff_y;
	int	diff_x;
	int	get_down;
	int	i;

	i = 0;
	diff_x = abs((b->x - a->x) * 2);
	diff_y = abs((b->y - a->y) * 2);
	get_down = b->y - a->y;
	a->color = b->color;
	while (b->y >= a->y)
	{
		__my_mlx_pixel_put(img, b->x, b->y, a->color);
		b->y -= 1;
		i++;
		__color_up_y(a, b, i, img);
		get_down -= diff_x;
		if (get_down <= 0)
		{
			b->x += 1;
			get_down += diff_y;
		}
	}
}
