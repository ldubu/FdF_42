/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:06:50 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/21 15:14:52 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	__color_down_x(t_point *a, t_point *b, int i, t_mlx *img)
{
	if (a->distance != 0 && i % a->distance == 0)
	{
		a->z ++;
		if (a->z > b->z)
			a->z = b->z;
		a->color = __color(a->z, img->tab);
	}
}

void	__color_down_y(t_point *a, t_point *b, int i, t_mlx *img)
{
	if (a->distance != 0 && i % a->distance == 0)
	{
		a->z --;
		if (a->z < b->z)
			a->z = b->z;
		a->color = __color(a->z, img->tab);
	}
}

void	__color_up_x(t_point *a, t_point *b, int i, t_mlx *img)
{
	if (a->distance != 0 && i % a->distance == 0)
	{
		a->z++;
		if (a->z > b->z)
			a->z = b->z;
		a->color = __color(a->z, img->tab);
	}
}

void	__color_up_y(t_point *a, t_point *b, int i, t_mlx *img)
{
	if (a->distance != 0 && i % a->distance == 0)
	{
		b->z++;
		if (b->z > a->z)
			b->z = a->z;
		a->color = __color(b->z, img->tab);
	}
}

int	__color(int z, t_tab *tab)
{
	float	z_diff;
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;

	z_diff = tab->z_max - tab->z_min;
	z_diff = fabs((z_diff - (z_diff - z)) / z_diff);
	red = 255 * z_diff;
	green = 102 - 102 * z_diff;
	blue = 255 - z_diff * 153;
	return (red << 16 | green << 8 | blue);
}
