/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_a_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:42:54 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/25 13:56:41 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	__draw_a_line(t_segment *seg, t_img *img)
{
	if (seg->yb < seg->ya)
		__swap_ab(seg);
	if (seg->xa <= seg->xb)
	{
		if (seg->xb - seg->xa > seg->yb - seg->ya)
			__down_x(seg, img);
		else
			__down_y(seg, img);
	}
	else
	{
		if (seg->xb - seg->xa > seg->yb - seg->ya)
			__up_x(seg, img);
		else
			__up_y(seg, img);
	}
}

void	__down_x(t_segment *seg, t_img *img)
{
	int	diff_y;
	int	diff_x;
	int	get_down;

	diff_x = __abs((seg->xb - seg->xa) * 2);
	diff_y = __abs((seg->yb - seg->ya) * 2);
	get_down = seg->xb - seg->xa;
	while (seg->xa <= seg->xb)
	{
		__my_mlx_pixel_put(img, seg->xa, seg->ya, seg->color);
		seg->xa += 1;
		get_down -= diff_x;
		if (get_down <= 0)
		{
			seg->ya += 1;
			get_down += diff_y;
		}
	}
}

void	__down_y(t_segment *seg, t_img *img)
{
	int	diff_y;
	int	diff_x;
	int	get_down;

	diff_x = __abs((seg->xb - seg->xa) * 2);
	diff_y = __abs((seg->yb - seg->ya) * 2);
	get_down = seg->xb - seg->xa;
	while (seg->ya <= seg->yb)
	{
		__my_mlx_pixel_put(img, seg->xa, seg->ya, seg->color);
		seg->ya += 1;
		get_down -= diff_x;
		if (get_down <= 0)
		{
			seg->xa += 1;
			get_down += diff_y;
		}
	}
}

void	__up_x(t_segment *seg, t_img *img)
{
	int	diff_y;
	int	diff_x;
	int	get_down;

	diff_x = __abs((seg->xb - seg->xa) * 2);
	diff_y = __abs((seg->yb - seg->ya) * 2);
	get_down = seg->yb - seg->ya;
	while (seg->xb <= seg->xa)
	{
		__my_mlx_pixel_put(img, seg->xb, seg->yb, seg->color);
		seg->xb += 1;
		get_down -= diff_y;
		if (get_down <= 0)
		{
			seg->yb -= 1;
			get_down += diff_x;
		}
	}
}

void	__up_y(t_segment *seg, t_img *img)
{
	int	diff_y;
	int	diff_x;
	int	get_down;

	diff_x = __abs((seg->xb - seg->xa) * 2);
	diff_y = __abs((seg->yb - seg->ya) * 2);
	get_down = seg->yb - seg->ya;
	while (seg->yb >= seg->ya)
	{
		__my_mlx_pixel_put(img, seg->xb, seg->yb, seg->color);
		seg->yb -= 1;
		get_down -= diff_x;
		if (get_down <= 0)
		{
			seg->xb += 1;
			get_down += diff_y;
		}
	}
}
