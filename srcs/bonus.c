/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:25:11 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/25 14:21:23 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	__rotate(t_point *point, t_mlx *info)
{
	int	y;
	int	z;
	int	x;

	x = point->x;
	y = point->y;
	z = point->z;
	point->y = y * cos(info->beta) - z * sin(info->beta);
	z = point->z;
	point->x = x * cos(info->alpha) - z * sin(info->alpha);
	x = point->x;
	y = point->y;
	point->x = x * cos(info->omega) - y * sin(info->omega);
	point->y = y * cos(info->omega) + x * sin(info->omega);
}

int	__zoom(int button, int x, int y, t_mlx *info)
{
	(void) x;
	(void) y;
	if (button == 4)
	{
		info->scale += 1;
		info->z_scale = (info->scale / (info->tab->z_max \
		- info->tab->z_min)) * 4;
		info->redo = 0;
	}
	if (button == 5 && info->scale > 1)
	{
		info->scale -= 1;
		info->z_scale = (info->scale / (info->tab->z_max \
		- info->tab->z_min)) * 4;
		info->redo = 0;
	}
	return (0);
}

int	__key_bonus(int keycode, t_mlx *info)
{
	if (keycode == XK_Up)
		info->shift_y -= 30;
	else if (keycode == XK_Down)
		info->shift_y += 30;
	else if (keycode == XK_Right)
		info->shift_x += 30;
	else if (keycode == XK_Left)
		info->shift_x -= 30;
	else if (keycode == XK_w)
		info->beta += 0.05;
	else if (keycode == XK_s)
		info->beta -= 0.05;
	else if (keycode == XK_d)
		info->alpha += 0.05;
	else if (keycode == XK_a)
		info->alpha -= 0.05;
	else
	{
		__key_bonus2(keycode, info);
		return (0);
	}	
	info->redo = 0;
	return (0);
}

int	__key_bonus2(int keycode, t_mlx *info)
{
	if (keycode == XK_e)
		info->omega += 0.05;
	else if (keycode == XK_q)
		info->omega -= 0.05;
	else if (keycode == XK_p)
	{
		info->projection = 0;
		info->angle = 0.785398;
	}
	else if (keycode == XK_i)
	{
		info->projection = 1;
		info->angle = 0.523599;
	}
	else if (keycode == XK_z)
		info->z_scale += 1;
	else if (keycode == XK_x)
		info->z_scale -= 1;
	else if (keycode == XK_o)
		__init_data(info, info->tab);
	else
		return (0);
	info->redo = 0;
	return (0);
}
