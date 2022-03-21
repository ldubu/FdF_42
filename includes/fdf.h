/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:07:22 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/21 16:02:16 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
//# include <string.h>
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

# ifndef BONUS
#  define BONUS 0
# endif

void	__my_mlx_pixel_put(t_mlx *info, int x, int y, int color);
void	__draw_a_line(t_point *a, t_point *b, t_mlx *img);
void	__swap_ab(t_point *a, t_point *b);
void	__down_y(t_point *a, t_point *b, t_mlx *img);
void	__up_y(t_point *a, t_point *b, t_mlx *img);
void	__up_x(t_point *a, t_point *b, t_mlx *img);
void	__down_x(t_point *a, t_point *b, t_mlx *img);
void	__init_seg(int xa, int xb, int ya, int yb);
int		*__chartoint(char **split, t_tab *tab);
int		**__tabjoin(char **split, t_tab *tab);
int		__init_window(t_mlx *info, t_img *img, t_tab *tab);
int		__draw(t_tab *tab);
int		__update_img(t_mlx *info);
void	__calculate_xy(t_point *point, int x, int y, t_mlx *info);
int		__key_press(int keycode, t_mlx *info);
int		__free_tab(t_tab *tab);
int		__mouse_event(int button, int x, int y, t_mlx *info);
int		__close(t_mlx *info);
int		__expose(t_mlx *info);
void	__init_image(t_mlx *info);
int		__zoom(int button, int x, int y, t_mlx *info);
int		__color(int z, t_tab *tab);
void	__rotate(t_point *point, t_mlx *info);
void	__color_down_x(t_point *a, t_point *b, int i, t_mlx *img);
void	__color_down_y(t_point *a, t_point *b, int i, t_mlx *img);
void	__color_up_x(t_point *a, t_point *b, int i, t_mlx *img);
void	__color_up_y(t_point *a, t_point *b, int i, t_mlx *img);
void	__init_data(t_mlx *info, t_tab *tab);
int		__key_bonus(int keycode, t_mlx *info);
int		__key_bonus2(int keycode, t_mlx *info);
void	__write_img2(t_mlx *info, t_point *a, t_point *b, t_pair *coor);
void	__write_img(t_mlx *info, t_point *a, t_point *b);

#endif