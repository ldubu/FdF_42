/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_a_line_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:15:40 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/23 14:55:27 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Modifie l'image avant de la projeter */

void	__my_mlx_pixel_put(t_mlx *info, int x, int y, int color)
{
	char	*dst;

	if (x < info->win_x && y < info->win_y && x > -1 && y > -1)
	{
		dst = info->img->img_addr + (y * info->img->size_line + x \
		* (info->img->bpp / 8));
		*(unsigned int *) dst = color;
	}
}

/* Dans le cas, ou b > a, on echange les deux points */

void	__swap_ab(t_point *a, t_point *b)
{
	int	temp;

	temp = a->x;
	a->x = b->x;
	b->x = temp;
	temp = a->y;
	a->y = b->y;
	b->y = temp;
	temp = a->z;
	a->z = b->z;
	b->z = temp;
	temp = b->color;
	b->color = a->color;
	a->color = temp;
}
