/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:07:22 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/25 14:25:47 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
// Affichage des codes d'actions (KeyPress...)
# include <X11/X.h>
// Affichage des code des touches du clavier
# include <X11/keysym.h>
// Pour des entiers de 8 bit
# include <stdint.h>
# include "mlx.h"
# include "libft.h"
# include "struct.h"

# ifndef BONUS
#  define BONUS 0
# endif

/* Read map */
int		__conversion(int *i, char **split, t_tab *tab);
int		__read_map(char **line, int fd, t_tab *tab);
int		*__chartoint(char **split, t_tab *tab);
int		**__tabjoin(char **split, t_tab *tab);

/* Graphical */
int		__key_press(int keycode, t_mlx *info);
int		__close(t_mlx *info);
int		__draw(t_tab *tab);

/* Draw line */
void	__draw_a_line(t_point *a, t_point *b, t_mlx *img);
void	__down_y(t_point *a, t_point *b, t_mlx *img);
void	__down_x(t_point *a, t_point *b, t_mlx *img);
void	__up_y(t_point *a, t_point *b, t_mlx *img);
void	__up_x(t_point *a, t_point *b, t_mlx *img);

/* Draw line utils */
void	__my_mlx_pixel_put(t_mlx *info, int x, int y, int color);
void	__swap_ab(t_point *a, t_point *b);

/* Color */
int		__color(int z, t_tab *tab);
void	__color_down_x(t_point *a, t_point *b, int i, t_mlx *img);
void	__color_down_y(t_point *a, t_point *b, int i, t_mlx *img);
void	__color_up_x(t_point *a, t_point *b, int i, t_mlx *img);
void	__color_up_y(t_point *a, t_point *b, int i, t_mlx *img);

/* Init */
int		__init_window(t_mlx *info, t_img *img, t_tab *tab);
void	__init_data(t_mlx *info, t_tab *tab);
void	__init_image(t_mlx *info);

/* Scale */
void	__too_small(t_point *t, float test, t_mlx *info);
void	__isometric(t_point *t, t_mlx *info, t_tab *tab);
void	__auto_scale(t_mlx *info, t_tab *tab);

/* Write img */
void	__write_img2(t_mlx *info, t_point *a, t_point *b, t_pair *coor);
void	__calculate_xy(t_point *point, int x, int y, t_mlx *info);
void	__write_img(t_mlx *info, t_point *a, t_point *b);
int		__update_img(t_mlx *info);

/* Free */
int		__free_gnl(int fd, char **line, t_tab *tab);
void	__free_split(char **split, int *i);
int		__free_tab(t_tab *tab);

/* Bonus */
int		__zoom(int button, int x, int y, t_mlx *info);
int		__key_bonus2(int keycode, t_mlx *info);
void	__rotate(t_point *point, t_mlx *info);
int		__key_bonus(int keycode, t_mlx *info);

#endif