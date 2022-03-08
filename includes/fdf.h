/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:07:22 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/08 09:51:08 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "struct.h"

void	__my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	__draw_a_line(t_point *a, t_point *b, t_img *img);
void	__swap_ab(t_point *a, t_point *b);
int		__abs(int x);
void	__down_y(t_point *a, t_point *b, t_img *img);
void	__up_y(t_point *a, t_point *b, t_img *img);
void	__up_x(t_point *a, t_point *b, t_img *img);
void	__down_x(t_point *a, t_point *b, t_img *img);
void	__init_seg(int xa, int xb, int ya, int yb);
int		*__chartoint(char **split, t_tab *tab);
int		**__tabjoin(char **split, t_tab *tab);
int		__init_window(t_mlx *info, t_img *img);
int		__draw(t_tab *tab);
void	__write_img(t_tab *tab, t_img *img, t_mlx *info);
void	__calculate_xy(t_point *point, int x, int y, t_mlx *info);

#endif