/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:08:59 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/25 13:46:12 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	__read_map(char **line, int fd, t_tab *tab)
{
	free(*line);
	*line = __get_next_line(fd);
	tab->y_max = tab->y_max + 1;
	if (*line != NULL)
		tab->coordonnees = __tabjoin(__split(*line, ' '), tab);
	if (*line != NULL && tab->coordonnees == NULL)
	{
		free(*line);
		while (*line != NULL)
		{
			*line = __get_next_line(fd);
			free(*line);
		}
		return (0);
	}
	else
		return (1);
}

int	*__chartoint(char **split, t_tab *tab)
{
	int	i;
	int	*line;

	i = 0;
	while (split[i] != NULL)
		i++;
	line = (int *) malloc (sizeof(int) * i);
	i = 0;
	while (split[i] != NULL)
	{
		if ((split[i][0] < '0' || split[i][0] > '9') && split[i][0] != '-' \
		&& split[i][0] != '\n')
		{
			__free_split(split, &i);
			free(line);
			return (NULL);
		}
		line[i] = __conversion(&i, split, tab);
	}
	free(split[i]);
	free(split);
	if (tab->x_max > i)
		tab->x_max = i;
	return (line);
}

int	__conversion(int *i, char **split, t_tab *tab)
{
	int	number;

	number = __atoi(split[*i]);
	free(split[*i]);
	if (number < tab->z_min)
		tab->z_min = number;
	if (number > tab->z_max)
		tab->z_max = number;
	*i = *i + 1;
	return (number);
}

int	**__tabjoin(char **split, t_tab *tab)
{
	int	i;
	int	**new;

	if (split == NULL)
		return (tab->coordonnees);
	i = 0;
	new = (int **) malloc(sizeof(int *) * (tab->y_max + 2));
	while (i < tab->y_max)
	{
		new[i] = tab->coordonnees[i];
		i++;
	}
	free(tab->coordonnees);
	new[i] = __chartoint(split, tab);
	if (new[i] == NULL)
	{
		__free_tab(tab);
		return (NULL);
	}
	new[i + 1] = NULL;
	return (new);
}
