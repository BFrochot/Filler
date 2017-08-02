/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 18:42:40 by bfrochot          #+#    #+#             */
/*   Updated: 2017/08/02 20:25:32 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// char	can_go_there(t_fil *fil, int x, int y)
// {
// 	int beg;
// 	int i;
// 	int crash;

// 	crash = 0;
// 	beg = fil->start + 4 + x * (fil->col + 5) + y;
// 	i = fil->ps;
// 	while (fil->str[i])
// 	{
// 		if (fil->str[beg] != '\n')
// 		{
// 			if (fil->str[i] == '*' && fil->str[beg] == fil->ply)
// 				crash++;
// 			fil->str[beg++] = fil->str[i++];
// 		}
// 		else
// 			return (0);
// 		if (fil->str[i] == '\n')
// 		{
// 			while (fil->str[beg] != '\n')
// 				++beg;
// 			++i;
// 			beg += 5 + y;
// 		}
// 		if (crash == 2)
// 			return (0);
// 	}
// 	return (crash == 1 ? 1 : 0);
// }

void	piece(t_fil	*fil, char *line)
{
	int i;

	fil->pl = atoi(line + 6);
	i = 0;
	while (line[i + 6] != ' ')
		++i;
	fil->pc = atoi(line + i + 6);
	free(line);
	fil->piece = ft_strdup("");
	i = 0;
	while (i < fil->pl)
	{
		get_next_line(0, &line);
		fil->piece = ft_strjoinfree(fil->piece, line, 3);
		fil->piece = ft_strjoinfree(fil->piece, "\n", 1);
		++i;
	}
}

void	init(t_fil	*fil)
{
	int		i;

	get_next_line(0, &(fil->map));
	fil->ply = fil->map[10] == '2' ? 'X' : 'O';
	free(fil->map);
	get_next_line(0, &(fil->map));
	fil->lig = atoi(fil->map + 8);
	i = 0;
	while(fil->map[i + 9] != ' ')
		++i;
	fil->col = atoi(fil->map + i + 9);
	free(fil->map);
}

int		main(void)
{
	t_fil	*fil;
	char	*line;
	int		i;

	fil = palloc(sizeof(t_fil));
	init(fil);
	while (1)
	{
		fil->map = ft_strdup("");
		if (get_next_line(0, &line) && *line == 'P')
		{
			free(line);
			get_next_line(0, &line);
		}
		free(line);
		while ((i = get_next_line(0, &line)) > 0 && *line != 'P')
		{
			fil->map = ft_strjoinfree(fil->map, line, 3);
			fil->map = ft_strjoinfree(fil->map, "\n", 1);
		}
		if (i == 0)
			break ;
			// fil->fd = open("../asdfdgh", O_TRUNC | O_WRONLY);
			// ft_putstr_fd("\nmap = ", fil->fd);
			// ft_putstr_fd(fil->map, fil->fd);
			// ft_putstr_fd("STOP\n", fil->fd);
			// close(fil->fd);
		if (i == -1)
			ft_putstr_fd("Error\n", 2);
		piece(fil, line);
		// can_go_there(fil, 8, 2);
		ft_putstr("12 14\n");
		free(fil->map);
	}
}
