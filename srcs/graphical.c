/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:54:18 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/21 16:01:54 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int	__draw(t_tab *tab)
{
	t_mlx	info;
	t_img	img;

	info.tab = tab;
	__init_window(&info, &img, tab);
	printf("BONUS %d\n", BONUS);
	mlx_hook(info.win_ptr, KeyPress, KeyPressMask, __key_press, &info);
	if (BONUS)
		mlx_hook(info.win_ptr, ButtonPress, ButtonPressMask, __zoom, &info);
	mlx_hook(info.win_ptr, DestroyNotify, LeaveWindowMask, __close, &info);
	mlx_loop_hook(info.mlx_ptr, __update_img, &info);
	mlx_loop(info.mlx_ptr);
	mlx_destroy_window(info.mlx_ptr, info.win_ptr);
	mlx_destroy_image(info.mlx_ptr, info.img_ptr);
	mlx_destroy_display(info.mlx_ptr);
	if (info.mlx_ptr)
		free(info.mlx_ptr);
	return (0);
}

int	__close(t_mlx *info)
{
	mlx_loop_end(info->mlx_ptr);
	return (0);
}

int	__key_press(int keycode, t_mlx *info)
{
	if (keycode == XK_Escape)
	{
		__close(info);
		return (0);
	}
	if (BONUS)
		__key_bonus(keycode, info);
	return (0);
}
