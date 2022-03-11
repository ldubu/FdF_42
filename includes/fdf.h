/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:07:22 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/11 12:31:46 by ldubuche         ###   ########.fr       */
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
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdint.h>

void	__my_mlx_pixel_put(t_mlx *info, int x, int y, int color);
void	__draw_a_line(t_point *a, t_point *b, t_mlx *img);
void	__swap_ab(t_point *a, t_point *b);
int		__abs(int x);
void	__down_y(t_point *a, t_point *b, t_mlx *img);
void	__up_y(t_point *a, t_point *b, t_mlx *img);
void	__up_x(t_point *a, t_point *b, t_mlx *img);
void	__down_x(t_point *a, t_point *b, t_mlx *img);
void	__init_seg(int xa, int xb, int ya, int yb);
int		*__chartoint(char **split, t_tab *tab);
int		**__tabjoin(char **split, t_tab *tab);
int		__init_window(t_mlx *info, t_img *img, t_tab *tab);
int		__draw(t_tab *tab);
int		__write_img(t_mlx *info);
void	__calculate_xy(t_point *point, int x, int y, t_mlx *info);
int		__key_press(int keycode, t_mlx *info);
int 	__free_tab(t_tab *tab);
int		__mouse_event(int button,int x,int y,t_mlx *info);
int		__close(t_mlx *info);
int		__expose(t_mlx *info);
void	__init_image(t_mlx *info);
int		__zoom(int button, int x, int y, t_mlx *info);
int		__color(int z, t_tab *tab);

#endif