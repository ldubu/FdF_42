/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:14:43 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/03 12:15:45 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		**lines;
	int		size;
	t_tab	tab;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	line = __get_next_line(fd);
	//printf("malloc gnl line %p\n", line);
	lines = (int **) malloc(sizeof(int *));
	//printf("malloc lines %p\n", lines);
	lines[0] = __chartoint(__split(line, ' '), &tab);
	size = 1;
	while (line != NULL)
	{
		printf("the first one\n");
		free(line);
		line = __get_next_line(fd);
		//printf("malloc gnl line %p\n", line);
		lines = __tabjoin(lines, __split(line, ' '), size, &tab);
		size ++;
	}
/*	int x = 0;
	int y;
	while (lines[x] != NULL)
	{
		y = 0;
		while (y < tab.x_max)
		{
			//printf("%d ", lines[x][y]);
			y++;
		}
		//printf("\n");
		x++;
	}
	close(fd);
	return (0);*/
}

int	*__chartoint(char **split, t_tab *tab)
{
	int	i;
	int	*line;

	i = 0;
	while (split[i] != NULL)
		i++;
	line = (int *) malloc (sizeof(int) * i);
	//printf("malloc line %p\n", line);
	i = 0;
	while (split[i] != NULL)
	{
		line[i] = __atoi(split[i]);
		i++;
	}
	i = 0;
	while (split[i] != NULL)
	{
		printf("and these one %s %d?\n", split[i], line[i]);
		printf("%d\n", i);
		free(split[i]);
		i ++;
	}
	printf("no these one\n");
	free(split);
	tab->x_max = i;
	tab->y_max = tab->y_max + 1;
	return (line);
}

int	**__tabjoin(int **lines, char **split, int size, t_tab *tab)
{
	int	i;
	int	**new;

	if (split == NULL)
		return (lines);
	i = 0;
	new = (int **) malloc(sizeof(int *) * size + 2);
	while (i < size)
	{
		new[i] = lines[i];
		i++;
	}
	printf("these one\n");
	free(lines);
	new[i] = __chartoint(split, tab);
	new[i + 1] = NULL;
	return (new);
}
