/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosi <cosi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 15:06:38 by bfrochot          #+#    #+#             */
/*   Updated: 2017/08/06 18:03:55 by cosi             ###   ########.fr       */
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
}				t_fil;

char	can_go_there(t_fil *fil, int x, int y);
void	filler(t_fil *fil);

#endif
