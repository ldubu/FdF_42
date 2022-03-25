/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubuche <laura.dubuche@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:14:43 by ldubuche          #+#    #+#             */
/*   Updated: 2022/03/25 12:44:41 by ldubuche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 	
	Ouverture du fichier
	Lecture de la carte
	Affichage
*/

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;
	t_tab	tab;

	ret = 1;
	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	line = __get_next_line(fd);
	tab = (t_tab){NULL, __strlen(line), 0, 0, 0};
	tab.coordonnees = (int **) malloc(sizeof(int *) * 1);
	if (!tab.coordonnees)
		return (0);
	tab.coordonnees[0] = __chartoint(__split(line, ' '), &tab);
	if (tab.coordonnees[0] == NULL)
		return (__free_gnl(fd, &line, &tab));
	while (line != NULL && ret)
		ret = __read_map(&line, fd, &tab);
	close(fd);
	if (ret)
		__draw(&tab);
	return (__free_tab(&tab));
}
