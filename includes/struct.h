/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:02:36 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/08 14:04:22 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data_img
{
	char	*img_addr;
	int		bpp;
	int		size_line;
	int		endian;
}			t_img;

typedef struct s_data_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	t_img	*img;
	int		scale;
	int		z_scale;
	int		win_x;
	int		win_y;
	int		shift_x;
	int		shift_y;
	float	angle;
}			t_mlx;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_point;

typedef struct s_data_tab //peut etre inutile
{
	int	**coordonnees;
	int	x_max;
	int	y_max;
	int z_max;
	int z_min;
}		t_tab;

#endif