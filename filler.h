/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 15:06:38 by bfrochot          #+#    #+#             */
/*   Updated: 2017/08/22 19:19:28 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "./libft/libft.h"

typedef struct	s_fil
{
	char	*map;
	char	*map2;
	char	*piece;
	int		fd;
	int		ply;
	int		lig;
	int		col;
	int		start;
	int		pl;
	int		pc;
	int		ps;
	int		cgt;
	int		us[2];
	int		him[2];
	int		last;
	int		lastus;
	int		cases;
	char	touch_top;
	char	tt;
	char	touch_bot;
	char	tb;
	char	touch_right;
	char	tr;
	char	touch_left;
	char	tl;
	char	mid;
}				t_fil;

char	can_go_there(t_fil *fil, int x, int y);
void	filler(t_fil *fil);

#endif
