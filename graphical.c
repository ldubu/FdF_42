/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:54:18 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/25 15:54:37 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int	__open_window()
{
	void	*mlx_ptr;
	void	*win_ptr;
	float	angle = 0.8;
	t_img	img;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
	{
		printf("erreur initialisation\n");
		return (1);
	}
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "Titre");
	if (win_ptr == NULL)
	{
		printf("erreur fenetre\n");
		return (1);
	}
	img.ptr = mlx_new_image(mlx_ptr, 1920, 1080);
	if (img.ptr == NULL)
	{
		printf("erreur image\n");
		return (1);
	}
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.endian);
	t_segment	seg;
	seg.xa = (0-0) * cosf(angle);
	seg.xb = (1 - 0) * cosf(angle);
	seg.ya = (0 + 0) * sinf(angle) - 0;
	seg.yb = (1 + 0) * sinf(angle) - 0;
	seg.color = 0x00FFFFFF;
	__draw_a_line(&seg, &img);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.ptr, 0, 0);
	mlx_loop(mlx_ptr);
}

void	__my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int *) dst = color;
}

void	__swap_ab(t_segment *seg)
{
	int	temp;

	temp = seg->xa;
	seg->xa = seg->xb;
	seg->xb = temp;
	temp = seg->ya;
	seg->ya = seg->yb;
	seg->yb = temp;
}

int	__abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

//printf("xa = %d, xb = %d, ya = %d, yb = %d, get = %d, dif_y = %d, dif_x = %d\n", seg->xa, seg->xb, seg->ya, seg->yb, get_down, diff_y, diff_x);
