/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:20:34 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/25 13:48:30 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	__init_window(t_mlx *info, t_img *img, t_tab *tab)
{
	info->win_x = 2000;
	info->win_y = 1000;
	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr, info->win_x, info->win_y, \
	"FdF");
	info->img_ptr = mlx_new_image(info->mlx_ptr, info->win_x, info->win_y);
	img->img_addr = mlx_get_data_addr(info->img_ptr, &img->bpp, \
	&img->size_line, &img->endian);
	info->img = img;
	__init_data(info, tab);
	return (0);
}

void	__init_data(t_mlx *info, t_tab *tab)
{
		info->scale = (tab->z_max - tab->z_min);
	info->z_scale = 4;
	info->projection = 1;
	info->angle = 0.523599;
	info->alpha = 0.0;
	info->beta = 0.0;
	info->omega = 0.0;
	info->redo = 0;
	info->shift_x = info->win_x / 2.15;
	info->shift_y = info->z_scale * tab->z_max;
	__auto_scale(info, tab);
}

void	__init_image(t_mlx *info)
{
	info->img_ptr = mlx_new_image(info->mlx_ptr, 2000, 1000);
	info->img->img_addr = mlx_get_data_addr(info->img_ptr, &info->img->bpp, \
	&info->img->size_line, &info->img->endian);
}
