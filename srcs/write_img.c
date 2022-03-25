/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:37:48 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/25 14:24:11 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* S'il faut reecrire la fenetre, cette fonction s'en occupe*/

int	__update_img(t_mlx *info)
{
	t_point	a;
	t_point	b;
	void	*img_ptr;

	if (info->redo == 1)
		return (0);
	img_ptr = info->img_ptr;
	__init_image(info);
	a.color = 0x00066FF;
	__write_img(info, &a, &b);
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	mlx_destroy_image(info->mlx_ptr, img_ptr);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img_ptr, 0, 0);
	info->redo = 1;
	return (0);
}

/* Transforme les coordonnes x, y, z en x, y selon la projection
	isometrique puis les envoie a la fonction draw_line*/

void	__write_img(t_mlx *info, t_point *a, t_point *b)
{
	t_pair	coor;

	coor.y = 0;
	while (coor.y < info->tab->y_max)
	{
		coor.x = 0;
		a->z = info->tab->coordonnees[coor.y][coor.x];
		__calculate_xy(a, coor.x, coor.y, info);
		if (a->x > info->win_x || a->y > info->win_y)
		{
			coor.y = info->tab->y_max;
			coor.x = info->tab->x_max;
		}
		while (coor.x < info->tab->x_max)
		{
			a->z = info->tab->coordonnees[coor.y][coor.x];
			__calculate_xy(a, coor.x, coor.y, info);
			if (a->x > info->win_x || a->y > info->win_y)
				coor.x = info->tab->x_max;
			else
				__write_img2(info, a, b, &coor);
			coor.x++;
		}
		coor.y++;
	}
}

void	__write_img2(t_mlx *info, t_point *a, t_point *b, t_pair *coor)
{
	if (coor->y < info->tab->y_max - 1)
	{
		a->z = info->tab->coordonnees[coor->y][coor->x];
		b->z = info->tab->coordonnees[coor->y + 1][coor->x];
		__calculate_xy(a, coor->x, coor->y, info);
		__calculate_xy(b, coor->x, coor->y + 1, info);
		a->z = info->tab->coordonnees[coor->y][coor->x];
		b->z = info->tab->coordonnees[coor->y + 1][coor->x];
		__draw_a_line(a, b, info);
	}
	if (coor->x < info->tab->x_max - 1)
	{
		a->z = info->tab->coordonnees[coor->y][coor->x];
		__calculate_xy(a, coor->x, coor->y, info);
		b->z = info->tab->coordonnees[coor->y][coor->x + 1];
		__calculate_xy(b, coor->x + 1, coor->y, info);
		a->z = info->tab->coordonnees[coor->y][coor->x];
		b->z = info->tab->coordonnees[coor->y][coor->x + 1];
		__draw_a_line(a, b, info);
	}
}

void	__calculate_xy(t_point *point, int x, int y, t_mlx *info)
{
	int	temp;

	point->x = x * info->scale;
	point->y = y * info->scale;
	point->z *= info->z_scale;
	__rotate(point, info);
	if (info->projection)
	{
		temp = point->x;
		point->x = (((point->x) - (point->y)) * cos(info->angle)) \
		+ info->shift_x;
		point->y = ((((temp) + (point->y)) \
		* sin(info->angle)) - point->z) + info->shift_y;
	}
	else if (BONUS)
	{
		point->x = (point->x - point->z * cos(info->angle)) \
		+ info->shift_x;
		point->y = (point->y - point->z * sin(info->angle)) \
		+ info->shift_y;
	}
}
