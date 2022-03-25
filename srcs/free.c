/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:26:07 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/24 15:40:52 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	__free_tab(t_tab *tab)
{
	int	x;

	x = 0;
	while (tab->coordonnees[x] != NULL)
	{
		free(tab->coordonnees[x]);
		x++;
	}
	free(tab->coordonnees);
	return (0);
}

int	__free_gnl(int fd, char **line, t_tab *tab)
{
	free (*line);
	while (*line != NULL)
	{
		*line = __get_next_line(fd);
		free(*line);
	}
	return (__free_tab(tab));
}

void	__free_split(char **split, int *i)
{
	while (split[*i] != NULL)
		free(split[(*i)++]);
	free(split[*i]);
	free(split);
}
