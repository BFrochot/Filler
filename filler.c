/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 18:42:40 by bfrochot          #+#    #+#             */
/*   Updated: 2017/08/07 19:34:47 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	can_go_there(t_fil *fil, int x, int y)
{
	int i;
	int j;
	int line;
	int crash;

	crash = 0;
	line = 0;
	while (line < fil->pl)
	{
		i = y;
		j = 0;
		while (j < fil->pc)
		{
			if (i < 0 || i >= fil->col || line + x < 0 || line + x >= fil->lig)
			{
				if (fil->piece[j + line * fil->pc] != '.')
				{
					crash = 2;
					break ;
				}
			}
			else
			{
				fil->cgt = i + 4 + (line + x) * (4 + fil->col);
				if (fil->piece[j + line * fil->pc] == '*')
				{
					if (fil->map[fil->cgt] == fil->ply)
						++crash;
					else if (fil->map[fil->cgt] != '.')
					{
						crash = 2;
						break ;
					}
				}
			}
			++i;
			++j;
		}
		++line;
	}
	return (crash == 1 ? 1 : 0);
}

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
	fil->us[0] = 0;
	fil->us[1] = 0;
	fil->him[0] = 0;
	fil->him[1] = 0;
	free(fil->map);
	fil->map = NULL;
	fil->map2 = NULL;
	fil->last = 0;
	fil->start = 0;
	f->mid = 0;
}
void	last_piece(t_fil *f)
{
	int i;

	i = -1;
	if (!f->map2)
	{
		while (f->map[++i])
			if (f->map[i] == f->ply)
				fil->start = i;
		return ;
	}
	while (f->map[++i])
		if (f->map[i] != f->ply && f->map2[i]!= 'o' && f->map2[i] != 'x' && f->map2[i] != f->map[i])
		{
			f->map[i] += 32;
			f->last = i;
		}
	free(f->map2);
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
			fil->map = ft_strjoinfree(fil->map, line, 3);
		last_piece(fil);
		if (i == 0)
			break ;
		if (i == -1)
		{
			ft_putstr_fd("Error\n", 2);
			break ;
		}
				// fil->fd = open("../asdfdgh", O_APPEND | O_WRONLY);
				// ft_putstr_fd("\nmap = ", fil->fd);
				// ft_putstr_fd(fil->map, fil->fd);
				// ft_putstr_fd("STOP\n", fil->fd);
				// close(fil->fd);
		piece(fil, line);
		filler(fil);
		fil->map2 = fil->map;
	}
}
