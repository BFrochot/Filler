/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 17:51:01 by bfrochot          #+#    #+#             */
/*   Updated: 2017/08/02 19:19:10 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	error(void)
{
	ft_putstr_fd("Filler exec error, good job guys !\n", 2);
	exit(666);
}

char	can_go_there(t_fil *fil, int x, int y)
{
	int beg;
	int i;
	int crash;

	crash = 0;
	beg = fil->start + 4 + x * (fil->col + 5) + y;
	i = fil->ps;
	while (fil->str[i])
	{
		if (fil->str[beg] != '\n')
		{
			if (fil->str[i] == '*' && fil->str[beg] == fil->ply)
				crash++;
			fil->str[beg++] = fil->str[i++];
		}
		else
			return (0);
		if (fil->str[i] == '\n')
		{
			while (fil->str[beg] != '\n')
				++beg;
			++i;
			beg += 5 + y;
		}
		if (crash == 2)
			return (0);
	}
	// ft_putstr_fd("\ncrash = ", fil->fd);
	// ft_putnbr_fd(crash, fil->fd);
	// ft_putstr_fd(" et \n", fil->fd);
	// ft_putstr_fd(fil->str, fil->fd);
	return (crash == 1 ? 1 : 0);
}

	// ft_putstr_fd("\ni = ", fd);
	// ft_putnbr_fd(i, fd);
	// ft_putstr_fd(" et len = ", fd);
	// ft_putnbr_fd(len, fd);
	// ft_putstr_fd("\n", fd);

void	init(t_fil *fil)
{
	int i;
	int len;

	len = ft_strlen(fil->str);
	i = 0;
	i += 9;
	fil->lig = atoi(fil->str + i);
	while (fil->str[i] && fil->str[i++] != ' ')
		;
	fil->col = atoi(fil->str + i);
	while (fil->str[i] && fil->str[i++] != '\n')
		;
	while (fil->str[i] && fil->str[i++] != '\n')
		;
	fil->start = i;
	i += fil->lig * (fil->col + 5) + 6;
	fil->pl = atoi(fil->str + i);
	while (fil->str[i] && fil->str[i++] != ' ')
		;
	fil->pc = atoi(fil->str + i);
	while (fil->str[i] && fil->str[i++] != '\n')
		;
	fil->ps = i;
}

int		main(void)
{
	t_fil	*fil;
	char	buf[BUFF_SIZE + 1];
	int i;

	i = read(0, buf, 40);
	buf[39] = 0;
	buf[BUFF_SIZE] = 0;
	fil = palloc(sizeof(t_fil));
	fil->ply = buf[10] == '2' ? 'X' : 'O';
	fil->str = NULL;
	while (1)
	{
		fil->fd = open("../asdfdgh", O_TRUNC | O_WRONLY);
		free(fil->str);
		fil->str = ft_strdup("");
		while ((i = read(0, buf, BUFF_SIZE)) == BUFF_SIZE)
			fil->str = ft_strjoinfree(fil->str, buf, 1);
		if (i == -1)
			exit(0);
		buf[i] = 0;
		fil->str = ft_strjoinfree(fil->str, buf, 1);
		ft_putstr_fd(fil->str, fil->fd);
		init(fil);
		can_go_there(fil, 8, 2);
		close(fil->fd);
		ft_putstr("12 14\n");
	}
	ft_putstr_fd("Sors\n", 2);
	return (0);
}
