/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:14:43 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/08 14:47:37 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_tab	tab;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	line = __get_next_line(fd);
	tab.coordonnees = (int **) malloc(sizeof(int *) * 1);
	tab.coordonnees[0] = __chartoint(__split(line, ' '), &tab);
	tab.x_max = 0;
	tab.y_max = 0;
	tab.z_max = 0;
	tab.z_min = 0;
	while (line != NULL)
	{
		free(line);
		line = __get_next_line(fd);
		tab.y_max = tab.y_max + 1;
		if (line != NULL)
			tab.coordonnees = __tabjoin(__split(line, ' '), &tab);
	}	
	close(fd);
	__draw(&tab);
	return (0);
}

/*int x = 0;
	int y;
	while (tab.coordonnees[x] != NULL)
	{
		y = 0;
		while (y < tab.x_max)
		{
			printf("%2d ", tab.coordonnees[x][y]);
			y++;
		}
		printf("\n");
		free(tab.coordonnees[x]);
		x++;
	}
	free(tab.coordonnees);*/
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
		line[i] = __atoi(split[i]);
		if (line[i] < tab->z_min)
			tab->z_min = line[i];
		if (line[i] < tab->z_max)
			tab->z_max = line[i];
		i++;
	}
	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i ++;
	}
	free(split[i]);
	free(split);
	if (tab->x_max < i)
		tab->x_max = i;
	return (line);
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
	new[i + 1] = NULL;
	return (new);
}
