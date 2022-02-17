/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:14:43 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/17 16:36:18 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
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
	draw_a_line(5, 5, 200, 100, &img);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.ptr, 0, 0);
	mlx_loop(mlx_ptr);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int *) dst = color;
}

void	draw_a_line(t_segment *seg, t_img *img)
{
	int	diff_y;
	int diff_x;
	int	get_down;
	
	get_down = xb - xa;
	diff_x = (xb - xa) * 2;
	diff_y = (yb - ya) * 2;
	while (xa <= xb)
	{
		my_mlx_pixel_put(img, xa, ya, 0x00FF0000);
		xa += 1;
		get_down -= diff_y;
		if (get_down <= 0)
		{
			ya += 1;
			get_down += diff_x;
		}
	}
}
