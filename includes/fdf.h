/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:07:22 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/03 10:32:37 by ldubuche         ###   ########.fr       */
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
void	__draw_a_line(t_segment *seg, t_img *img);
void	__swap_ab(t_segment *seg);
int		__abs(int x);
void	__down_x(t_segment *seg, t_img *img);
void	__down_y(t_segment *seg, t_img *img);
void	__up_x(t_segment *seg, t_img *img);
void	__up_y(t_segment *seg, t_img *img);
void	__init_seg(int xa, int xb, int ya, int yb);
int		*__chartoint(char **split, t_tab *tab);
int		**__tabjoin(int **lines, char **split, int size, t_tab *tab);

#endif