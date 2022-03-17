/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_a_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:42:54 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/17 15:45:25 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
////printf("xa = %d, ya = %d, xb = %d, yb = %d\n", a->x, a->y, b->x, b->y);

void	__draw_a_line(t_point *a, t_point *b, t_mlx *img)
{
	if (b->y < a->y)
		__swap_ab(a, b);
	//printf("xa = %d, ya = %d, xb = %d, yb = %d\n", a->x, a->y, b->x, b->y);
	//printf("xa = %d, ya = %d, xb = %d, yb = %d\n", a->x, a->y, b->x, b->y);
	//printf("za = %d, zb = %d\n", a->z, b->z);
	b->color = __color(b->z, img->tab);
	a->color = __color(a->z, img->tab);
	//printf("a = %x, b = %x\n", a->color, b->color);
	if (a->x <= b->x)
	{
		if (__abs(b->x - a->x) > __abs(b->y - a->y))
			__down_x(a, b, img);
		else
			__down_y(a, b, img);
	}
	else
	{
		if (__abs(b->x - a->x) > __abs(b->y - a->y))
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
	int distance;
	int i;

	i = 0;
	//printf("1\n");
	distance = 0;
	if (b->z != a->z)
		distance = sqrt((double)(b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y)) / abs(b->z - a->z);
	diff_x = __abs((b->x - a->x) * 2);
	diff_y = __abs((b->y - a->y) * 2);
	get_down = b->x - a->x;
	while (a->x <= b->x)
	{
		__my_mlx_pixel_put(img, a->x, a->y, a->color);
		a->x += 1;
		i++;
		//printf("distance = %d, i = %d\n", distance, i);
		if (distance != 0 && i % distance == 0)
		{
			a->z ++;
			if (a->z > b->z)
				a->z = b->z;
			a->color = __color(a->z, img->tab);
		}
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
	int distance;
	int i;

	i = 0;
	//printf("2\n");
	distance = 0;
	if (b->z != a->z)
		distance = sqrt((b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y)) / abs(b->z - a->z);
	diff_x = __abs((b->x - a->x) * 2);
	diff_y = __abs((b->y - a->y) * 2);
	get_down = b->x - a->x;
	while (a->y <= b->y)
	{
		__my_mlx_pixel_put(img, a->x, a->y, a->color);
		a->y += 1;
		i++;
		//printf("distance = %d, i = %d\n", distance, i);
		if (distance != 0 && i % distance == 0)
		{
			a->z--;
			if (a->z < b->z)
				a->z = b->z;
			a->color = __color(a->z, img->tab);
		}
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
	int distance;
	int i;

	i = 0;
	//printf("3\n");
	distance = 0;
	if (b->z != a->z)
		distance = sqrt((double)(b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y)) / abs(b->z - a->z);
	diff_x = __abs((b->x - a->x) * 2);
	diff_y = __abs((b->y - a->y) * 2);
	get_down = b->y - a->y;
	while (b->x <= a->x)
	{
		__my_mlx_pixel_put(img, b->x, b->y, a->color);
		b->x += 1;
		if (distance != 0 && i % distance == 0)
		{
			a->z++;
			if (a->z > b->z)
				a->z = b->z;
			a->color = __color(a->z, img->tab);
		}
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
	int distance;
	int i;

	i = 0;
	//printf("4\n");
	distance = 0;
	if (b->z != a->z)
		distance = sqrt((double)(a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y)) / abs(b->z - a->z);
	diff_x = __abs((b->x - a->x) * 2);
	diff_y = __abs((b->y - a->y) * 2);
	get_down = b->y - a->y;
	a->color = b->color;
	while (b->y >= a->y)
	{
		__my_mlx_pixel_put(img, b->x, b->y, a->color);
		b->y -= 1;
		i++;
		if (distance != 0 && i % distance == 0)
		{
			//printf("distance = %d, i = %d, a = %d, b = %d\n", distance, i, a->z, b->z);
			b->z++;
			if (b->z > a->z)
				b->z = a->z;
			a->color = __color(b->z, img->tab);
		}
		get_down -= diff_x;
		if (get_down <= 0)
		{
			b->x += 1;
			get_down += diff_y;
		}
	}
}
