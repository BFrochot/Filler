/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosi <cosi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:37:45 by bfrochot          #+#    #+#             */
/*   Updated: 2017/09/10 17:24:58 by cosi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "./libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>
# include "filler.h"

# define LEN_LINE 20

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		fd;
	char	***array;
	int		tx;
	int		ty;
	int		rx;
	int		ry;
	float	p;
	int		len;
	double	zoom;
	int		winx;
	int		winy;
	int		max;
	int		min;
	void	*img;
	void	*img2;
	void	*img3;
	char	*p_img;
	char	*p_img2;
	char	*p_img3;
	int		bpp;
	int		s_line;
	int		ed;
	double	px;
	double	py;
	double	mx;
	double	my;
	char	c;
	t_fil	*f;
}				t_env;

void			error(int i);
int				get_next_line(const int fd, char **line);
int				keymap(int keycode, t_env *ev);
char			**ft_strsplitquote(char const *s, char c, char tab);
int				fdfinit(t_env *ev);
int				printcontrol(t_env *ev);
void			draw_line(double *pts1, double *pts2, int color, t_env *ev);
void			initev(t_env *ev);
int				printcontrol(t_env *ev);
void			remp(int x, int y, char c, t_env *ev);
#endif
