/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 15:06:38 by bfrochot          #+#    #+#             */
/*   Updated: 2017/08/02 19:15:14 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "./libft/libft.h"

typedef struct	s_fil
{
	char	*map;
	char	*piece;
	int		fd;
	int		ply;
	int		lig;
	int		col;
	int		start;
	int		pl;
	int		pc;
	int		ps;
}				t_fil;

#endif
