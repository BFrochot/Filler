/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosi <cosi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 15:06:38 by bfrochot          #+#    #+#             */
/*   Updated: 2017/09/09 13:28:12 by cosi             ###   ########.fr       */
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
void	result(int i, int k, char *end, t_fil *f);
void	des_right2(t_fil *fil);
void	des_left2(t_fil *fil);
void	asc_right2(t_fil *fil);
void	asc_left2(t_fil *fil);
void	des_left(t_fil *fil);
void	des_right(t_fil *fil);
void	asc_left(t_fil *fil);
void	asc_right(t_fil *fil);
void	put_map(t_fil *fil);

#endif
