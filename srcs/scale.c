/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:47:51 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/25 14:25:32 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	__auto_scale(t_mlx *info, t_tab *tab)
{
	t_point	t;
	int		i;
	float	test;
	float	test_z;

	i = 2;
	test = (tab->z_max - tab->z_min);
	test_z = 4;
	__isometric(&t, info, tab);
	if (t.x > info->win_x || t.y > info->win_y)
	{
		while (t.x > info->win_x || t.y > info->win_y)
		{
			info->scale = test / i;
			info->z_scale = test_z / i;
			info->shift_y = info->z_scale * tab->z_max;
			__isometric(&t, info, tab);
			i++;
		}
	}
	else
		__too_small(&t, test, info);
}

void	__too_small(t_point *t, float test, t_mlx *info)
{
	int		i;

	i = 2;
	while (t->x < info->win_x && t->y < info->win_y)
	{
		info->scale = test + i;
		info->z_scale = (info->scale / (info->tab->z_max \
		- info->tab->z_min)) * 4;
		info->shift_y = info->z_scale * info->tab->z_max;
		__isometric(t, info, info->tab);
		i++;
	}
	i -= 4;
	info->scale = test + i;
	info->z_scale = (info->scale / (info->tab->z_max \
	- info->tab->z_min)) * 4;
}

void	__isometric(t_point *t, t_mlx *info, t_tab *tab)
{
	t->x = (((tab->x_max * info->scale) - (tab->y_max * info->scale)) \
		* cos(info->angle)) + info->shift_x;
	t->y = ((((tab->x_max * info->scale) + (tab->y_max * info->scale)) \
		* sin(info->angle)) - tab->coordonnees[tab->y_max - 2][tab->x_max - 3] \
		* info->z_scale) + info->shift_y;
}
