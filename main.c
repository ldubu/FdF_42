/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:14:43 by ldubuche          #+#    #+#             */
/*   Updated: 2022/02/25 16:54:09 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int 	*tab[];
	char 	**spli;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	line = __get_next_line(fd);
	tab = (int **) malloc(sizeof(int *));
	spli = __split(line, ' ');
	//initier t_tab
	tab = __chartoint(spli);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = __get_next_line(fd);
		tab = __tabjoin(tab, __split(line, ' '));
	}
	close(fd);
}

int	*__chartoint(char ** split, t_tab *tab)
{
	int i;
	int *line;

	i = 0;
	while (split[i] != NULL)
		i++;
	line = (int *) malloc (sizeof(int) * i);
	i = 0;
	while (split[i] != NULL)
	{
		line[i] = __atoi(split[i]);
		i++;
	}
	tab->x_max = i;
	tab->y_max += 1;
	return (line);
}