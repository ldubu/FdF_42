/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_a_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:42:54 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/03 16:55:32 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	__draw_a_line(t_point *a, t_point *b, t_img *img)
{
	if (b->y < a->y)
		__swap_ab(a, b);
	if (a->x <= b->x)
	{
		if (b->x - a->x > b->y - a->y)
			__down_x(a, b, img);
		else
			__down_y(a, b, img);
	}
	else
	{
		if (b->x - a->x > b->y - a->y)
			__up_x(a, b, img);
		else
			__up_y(a, b, img);
	}
}

void	__down_x(t_point *a, t_point *b, t_img *img)
{
	int	diff_y;
	int	diff_x;
	int	get_down;

	diff_x = __abs((b->x - a->x) * 2);
	diff_y = __abs((b->y - a->y) * 2);
	get_down = b->x - a->x;
	while (a->x <= b->x)
	{
		__my_mlx_pixel_put(img, a->x, a->y, a->color);
		a->x += 1;
		get_down -= diff_x;
		if (get_down <= 0)
		{
			a->y += 1;
			get_down += diff_y;
		}
	}
}

void	__down_y(t_point *a, t_point *b, t_img *img)
{
	int	diff_y;
	int	diff_x;
	int	get_down;

	diff_x = __abs((b->x - a->x) * 2);
	diff_y = __abs((b->y - a->y) * 2);
	get_down = b->x - a->x;
	while (a->y <= b->y)
	{
		__my_mlx_pixel_put(img, a->x, a->y, a->color);
		a->y += 1;
		get_down -= diff_x;
		if (get_down <= 0)
		{
			a->x += 1;
			get_down += diff_y;
		}
	}
}

void	__up_x(t_point *a, t_point *b, t_img *img)
{
	int	diff_y;
	int	diff_x;
	int	get_down;

	diff_x = __abs((b->x - a->x) * 2);
	diff_y = __abs((b->y - a->y) * 2);
	get_down = b->y - a->y;
	while (b->x <= a->x)
	{
		__my_mlx_pixel_put(img, b->x, b->y, a->color);
		b->x += 1;
		get_down -= diff_y;
		if (get_down <= 0)
		{
			b->y -= 1;
			get_down += diff_x;
		}
	}
}

void	__up_y(t_point *a, t_point *b, t_img *img)
{
	int	diff_y;
	int	diff_x;
	int	get_down;

	diff_x = __abs((b->x - a->x) * 2);
	diff_y = __abs((b->y - a->y) * 2);
	get_down = b->y - a->y;
	while (b->y >= a->y)
	{
		__my_mlx_pixel_put(img, b->x, b->y, a->color);
		b->y -= 1;
		get_down -= diff_x;
		if (get_down <= 0)
		{
			b->x += 1;
			get_down += diff_y;
		}
	}
}
