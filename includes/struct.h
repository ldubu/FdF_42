/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:02:36 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/25 16:41:22 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data_image
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}			t_img;

typedef struct s_segment
{
	int	xa;
	int	xb;
	int	ya;
	int	yb;
	int color;
}		t_segment;

typedef struct s_data_tab
{
	int **tab;
	int x_max;
	int	y_max;
}		t_tab;


#endif