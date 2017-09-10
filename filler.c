/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosi <cosi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 18:42:40 by bfrochot          #+#    #+#             */
/*   Updated: 2017/09/10 17:43:46 by cosi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "fdf.h"

char	*joinspaces(char *str, int i)
{
	char s[i + 1];

	s[i] = 0;
	while (i--)
		s[i] = ' ';
	str = ft_strjoinfree(str, s, 1);
	return (str);
}

// void	put_map(t_fil *f, char **av, char **ev)
// {
// 	int i;
// 	int j;
// 	char *map;

// 	// i = 4;
// 	// map = ft_strdup("");
// 	// while (f->map[i])
// 	// {
// 	// 	if (i % (4 + f->col) == 0)
// 	// 	{
// 	// 		map = ft_strjoinfree(map, "\n", 1);
// 	// 		i += 4;
// 	// 	}
// 	// 	if (f->map[i] == f->ply)
// 	// 	{
// 	// 		map = ft_strjoinfree(map, "\033[46m", 1);
// 	// 		j = 1;
// 	// 		while (f->map[++i] == f->ply)
// 	// 			++j;
// 	// 		map = joinspaces(map, j);
// 	// 		map = ft_strjoinfree(map, "\033[0m", 1);
// 	// 	}
// 	// 	else if (f->map[i] == '.')
// 	// 	{
// 	// 		map = ft_strjoinfree(map, "\033[44m", 1);
// 	// 		j = 1;
// 	// 		while (f->map[++i] == '.')
// 	// 			++j;
// 	// 		map = joinspaces(map, j);
// 	// 		map = ft_strjoinfree(map, "\033[0m", 1);
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		map = ft_strjoinfree(map, "\033[47m", 1);
// 	// 		j = 1;
// 	// 		while (f->map[++i] != '.' && f->map[i] != f->ply && !ft_isdigit(f->map[i]))
// 	// 			++j;
// 	// 		map = joinspaces(map, j);
// 	// 		map = ft_strjoinfree(map, "\033[0m", 1);
// 	// 	}
// 	// }
// 	// map = ft_strjoinfree(map, "\033[0m\n\n", 1);
// 	// ft_putstr_fd(map, 2);
// 	(void)map;
// 	(void)j;
// 	i = 4;
// 	while (f->map[i])
// 	{
// 		if (i % (4 + f->col) == 0)
// 		{
// 			ft_putchar_fd('\n', 2);
// 			i += 4;
// 		}
// 		if (f->map[i] == f->ply)
// 			ft_putstr_fd("\033[46m  \033[0m", 2);
// 		else if (f->map[i] == '.')
// 			ft_putstr_fd("\033[44m  \033[0m", 2);
// 		else
// 			ft_putstr_fd("\033[47m  \033[0m", 2);
// 		++i;
// 	}
// 	ft_putchar_fd('\n', 2);
// 	ft_putchar_fd('\n', 2);
// 	if (f->last)
// 		usleep(20000);
// }

void	touch(t_fil *fil, int x, int y)
{
	int line;
	int i;

	line = 0;
	while (line < fil->pl)
	{
		i = y;
		while (i - y < fil->pc)
		{
			if (fil->piece[i - y + line * fil->pc] == '*')
			{
				if (i == 0)
					fil->touch_left = 1;
				else if (fil->tl < 50 && fil->map[3 + i + (fil->col + 4) * (line + x)] == (fil->ply == 'O' ? 'X' : 'O'))
					fil->tl += 1;
				else if (i == fil->col - 1)
					fil->touch_right = 1;
				else if (fil->tr < 50 && fil->map[5 + i + (fil->col + 4) * (line + x)] == (fil->ply == 'O' ? 'X' : 'O'))
					fil->tr += 1;
				else if (line + x == fil->lig - 1)
					fil->touch_bot = 1;
				else if (fil->tb < 50 && fil->map[4 + i + (fil->col + 4) * (line + x + 1)] == (fil->ply == 'O' ? 'X' : 'O'))
					fil->tb += 1;
				else if (line + x == 0)
					fil->touch_top = 1;
				else if (fil->tt < 50 && fil->map[3 + i + (fil->col + 4) * (line + x - 1)] == (fil->ply == 'O' ? 'X' : 'O'))
					fil->tt += 1;
			}
			++i;
		}
		++line;
	}
}

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
				if (fil->piece[j + line * fil->pc] == '*')
				{
					fil->cgt = i + 4 + (line + x) * (4 + fil->col);
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
	if (crash == 1)
		touch(fil, x, y);
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

char	init(t_fil	*fil)
{
	int		i;

	get_next_line(0, &(fil->map));
	fil->ply = fil->map[10] == '2' ? 'X' : 'O';
	free(fil->map);
	get_next_line(0, &(fil->map));
	if (fil->map[0] != 'P' || fil->map[1] != 'l')
	{
		free(fil->map);
		return (1);
	}
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
	fil->mid = 0;
	fil->touch_top = 0;
	fil->tt = 0;
	fil->touch_bot = 0;
	fil->tb = 0;
	fil->touch_right = 0;
	fil->tr = 0;
	fil->touch_left = 0;
	fil->tl = 0;
	return (0);
}

void	last_piece(t_fil *f, t_env *ev)
{
	int i;

	i = -1;
	if (!f->map2)
	{
		while (f->map[++i])
		{
			if (f->map[i] == f->ply)
			{
				mlx_put_image_to_window(ev->mlx, ev->win, ev->img2, 51 + (i % (f->col + 4) - 4) * 5, 51 + (i / (f->col + 4)) * 5);
				// remp(i % (f->col + 4) - 4, i / (f->col + 4), 2, ev);
				f->start = i;
			}
			else if (f->map[i] == 'O' || f->map[i] == 'X')
				mlx_put_image_to_window(ev->mlx, ev->win, ev->img3, 51 + (i % (f->col + 4) - 4) * 5, 51 + (i / (f->col + 4)) * 5);
				// remp(i % (f->col + 4) - 4, i / (f->col + 4), 3, ev);
		}
		return ;
	}
	f->last = 0;
	while (f->map[++i])
		if (f->map2[i] != f->map[i])
		{
			if (f->map[i] != f->ply && f->map2[i]!= 'o' && f->map2[i] != 'x')
			{
				// remp(i % (f->col + 4) - 4, i / (f->col + 4), 1, ev);
				mlx_put_image_to_window(ev->mlx, ev->win, ev->img2, 51 + (i % (f->col + 4) - 4) * 5, 51 + (i / (f->col + 4)) * 5);
				f->map[i] += 32;
				f->last = i;
			}
			if (f->map[i] == f->ply)
				// remp(i % (f->col + 4) - 4, i / (f->col + 4), 0, ev);
				mlx_put_image_to_window(ev->mlx, ev->win, ev->img3, 51 + (i % (f->col + 4) - 4) * 5, 51 + (i / (f->col + 4)) * 5);
		}
	free(f->map2);
}

int		loop(t_env *ev)
{
	char	*line;
	int		i;

	ev->f->map = ft_strdup("");
	if (get_next_line(0, &line) && *line == 'P')
	{
		free(line);
		get_next_line(0, &line);
	}
	free(line);
	while ((i = get_next_line(0, &line)) > 0 && *line != 'P')
		ev->f->map = ft_strjoinfree(ev->f->map, line, 3);
	if (i == 0)
		return (0);
	if (i == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	last_piece(ev->f, ev);
	piece(ev->f, line);
	filler(ev->f);
	// mlx_clear_window(ev->mlx, ev->win);
	// if (ev->f->last)
		// usleep(50000);
	ev->f->map2 = ev->f->map;
	return (1);
}

int		main(void)
{
	t_fil	*fil;
	// char	*line;
	int		i;
	// char *bit;
	// int j;

	fil = palloc(sizeof(t_fil));
	if (init(fil))
	{
		ft_putstr_fd("Error on filler exec, well done !\n", 2);
		return (2);
	}

	t_env	*ev;

	ev = palloc(sizeof(t_env));
	ev->f = fil;
	initev(ev);
	ev->mlx = mlx_init();
	ev->win = mlx_new_window(ev->mlx, ev->winx, ev->winy, "test");
	ev->img = mlx_new_image(ev->mlx, ev->winx, ev->winy);
	ev->p_img = mlx_get_data_addr(ev->img, &ev->bpp, &(ev->s_line), &(ev->ed));
	fdfinit(ev);
	mlx_string_put(ev->mlx, ev->win, 0, 0, 0xFF0000,
		" Filler");
	mlx_put_image_to_window(ev->mlx, ev->win, ev->img, 50, 50);

	ev->img2 = mlx_new_image(ev->mlx, 4, 4);
	ev->p_img2 = mlx_get_data_addr(ev->img2, &ev->bpp, &(ev->s_line), &(ev->ed));
	i = -1;
	while (++i < 16)
		((int *)ev->p_img2)[i] = 0xFF0000;

	ev->img3 = mlx_new_image(ev->mlx, 4, 4);
	ev->p_img3 = mlx_get_data_addr(ev->img3, &ev->bpp, &(ev->s_line), &(ev->ed));
	i = -1;
	while (++i < 16)
		((int *)ev->p_img3)[i] = 0xFFFFF;

	// while (1)
	// {
	// // ft_putstr_fd("ICI\n", 2);
	// // 	i = fork();
	// // 	if (i != 0)
	// // 		execve("/usr/bin/clear", av, ev);
	// // 	waitpid(i, NULL, WUNTRACED);
	// // ft_putstr_fd("LA\n", 2);
	// 	fil->map = ft_strdup("");
	// 	if (get_next_line(0, &line) && *line == 'P')
	// 	{
	// 		free(line);
	// 		get_next_line(0, &line);
	// 	}
	// 	free(line);
	// 	while ((i = get_next_line(0, &line)) > 0 && *line != 'P')
	// 		fil->map = ft_strjoinfree(fil->map, line, 3);
	// 	last_piece(fil, ev);
	// 	if (i == 0)
	// 		break ;
	// 	if (i == -1)
	// 	{
	// 		ft_putstr_fd("Error\n", 2);
	// 		break ;
	// 	}
	// 			// fil->fd = open("../asdfdgh", O_TRUNC | O_WRONLY);
	// 			// bit = palloc(ft_strlen(fil->map) * 4);
	// 			// i = 4;
	// 			// j = -1;
	// 			// while (fil->map[i])
	// 			// {
	// 			// 	if (i % (4 + fil->col) == 0)
	// 			// 	{
	// 			// 		ft_putchar_fd('\n', 2);
	// 			// 		i += 4;
	// 			// 		bit[++j] = '\n';
	// 			// 	}
	// 			// 	if (fil->map[i] == fil->ply)
	// 			// 	{
	// 			// 		bit[++j] = '9';
	// 			// 		bit[++j] = ' ';
	// 			// 	}
	// 			// 	else if (fil->map[i] == '.')
	// 			// 	{
	// 			// 		bit[++j] = '0';
	// 			// 		bit[++j] = ' ';
	// 			// 	}
	// 			// 	else
	// 			// 	{
	// 			// 		bit[++j] = '-';
	// 			// 		bit[++j] = '9';
	// 			// 		bit[++j] = ' ';
	// 			// 	}
	// 			// 	++i;
	// 			// }
	// 			// bit[++j] = '\n';
	// 			// bit[++j] = 0;
	// 			// ft_putstr_fd(bit, fil->fd);
	// 			// close(fil->fd);
	// 	piece(fil, line);
	// 	filler(fil);
	// 	mlx_put_image_to_window(ev->mlx, ev->win, ev->img, 50, 50);
	// 	usleep(20000);
	// 	// put_map(fil);
	// 	fil->map2 = fil->map;
	// }

	mlx_key_hook(ev->win, keymap, ev);
	// mlx_expose_hook(ev->win, loop, ev);
	mlx_loop_hook (ev->mlx, loop, ev);
	mlx_loop(ev->mlx);
}
