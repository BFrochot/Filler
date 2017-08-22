#include "filler.h"

void	result(int i, int j, char *end, t_fil *f)
{
	ft_putnbr(i);
	ft_putchar(' ');
	ft_putnbr(j);
	ft_putchar('\n');
	*end = 1;
	free(f->piece);
}

void	left_des(t_fil *fil)
{
	int i;
	int j;
	char end;

	end = 0;
	i = fil->col + fil->pc;
	while (i > -1 * fil->pc + 1 && !end)
	{
		j = -1 * fil->pl + 1;
		while (j < fil->lig + fil->pl && !end)
		{
			if (can_go_there(fil, j, i))
			{
				result(j, i, &end, fil);
				fil->lastus = j * (fil->col + 4) + i + 4;
			}
			++j;
		}
		--i;
	}
	if (!end)
		ft_putchar('\n');
}

void	left_asc(t_fil *fil)
{
	int i;
	int j;
	char end;

	end = 0;
	i = fil->col + fil->pc;
	while (i > -1 * fil->pc + 1 && !end)
	{
		j = fil->lig + fil->pl;
		while (j > -1 * fil->pl + 1 && !end)
		{
			if (can_go_there(fil, j, i))
			{
				result(j, i, &end, fil);
				fil->lastus = j * (fil->col + 4) + i + 4;
			}
			--j;
		}
		--i;
	}
	if (!end)
		ft_putchar('\n');
}

void	right_des(t_fil *fil)
{
	int i;
	int j;
	char end;

	end = 0;
	i = -1 * fil->pc + 1;
	while (i < fil->col + fil->pc && !end)
	{
		j = -1 * fil->pl + 1;
		while (j < fil->lig + fil->pl && !end)
		{
			if (can_go_there(fil, j, i))
			{
				result(j, i, &end, fil);
				fil->lastus = j * (fil->col + 4) + i + 4;
			}
			++j;
		}
		++i;
	}
	if (!end)
		ft_putchar('\n');
}

void	right_asc(t_fil *fil)
{
	int i;
	int j;
	char end;

	end = 0;
	i = -1 * fil->pc + 1;
	while (i < fil->col + fil->pc && !end)
	{
		j = fil->lig + fil->pl;
		while (j > -1 * fil->pl + 1 && !end)
		{
			if (can_go_there(fil, j, i))
			{
				result(j, i, &end, fil);
				fil->lastus = j * (fil->col + 4) + i + 4;
			}
			--j;
		}
		++i;
	}
	if (!end)
		ft_putchar('\n');
}

void	asc_right(t_fil *fil)
{
	int i;
	int j;
	char end;

	end = 0;
	j = fil->lig + fil->pl;
	while (j > -1 * fil->pl + 1 && !end)
	{
		i = -1 * fil->pc + 1;
		while (i < fil->col + fil->pc && !end)
		{
			if (can_go_there(fil, j, i))
			{
				result(j, i, &end, fil);
				fil->lastus = j * (fil->col + 4) + i + 4;
			}
			++i;
		}
		--j;
	}
	if (!end)
		ft_putchar('\n');
}

void	asc_left(t_fil *fil)
{
	int i;
	int j;
	char end;

	end = 0;
	j = fil->lig + fil->pl;
	while (j > -1 * fil->pl + 1 && !end)
	{
		i = fil->col + fil->pc;
		while (i > -1 * fil->pc + 1 && !end)
		{
			if (can_go_there(fil, j, i))
			{
				result(j, i, &end, fil);
				fil->lastus = j * (fil->col + 4) + i + 4;
			}
			--i;
		}
		--j;
	}
	if (!end)
		ft_putchar('\n');
}

void	des_left(t_fil *fil)
{
	int i;
	int j;
	char end;

	end = 0;
	j = -1 * fil->pl + 1;
	while (j < fil->lig + fil->pl && !end)
	{
		i = fil->col + fil->pc;
		while (i > -1 * fil->pc + 1 && !end)
		{
			if (can_go_there(fil, j, i))
			{
				result(j, i, &end, fil);
				fil->lastus = j * (fil->col + 4) + i + 4;
			}
			--i;
		}
		++j;
	}
	if (!end)
		ft_putchar('\n');
}

void	des_right(t_fil *fil)
{
	int i;
	int j;
	char end;

	end = 0;
	j = -1 * fil->pl + 1;
	while (j < fil->lig + fil->pl && !end)
	{
		i = -1 * fil->pc + 1;
		while (i < fil->col + fil->pc && !end)
		{
			if (can_go_there(fil, j, i))
			{
				result(j, i, &end, fil);
				fil->lastus = j * (fil->col + 4) + i + 4;
			}
			++i;
		}
		++j;
	}
	if (!end)
		ft_putchar('\n');
}

void	test(t_fil *f)
{
	int i;
	int j;
	int k;
	int l;
	char end;

	end = 0;
	i = f->last / (4 + f->col);
	j = f->last / (4 + f->col);
	while ((j > -1 * f->pl + 1 || i < f->lig + f->pl) && !end)
	{
		k = f->last % (4 + f->col) - 4;
		l = f->last % (4 + f->col) - 4;
		while ((l > -1 * f->pc + 1 || k < f->col + f->pc) && !end)
		{
			if (can_go_there(f, i, k))
				result(i, k, &end, f);
			if (!end && can_go_there(f, i, l))
				result(i, l, &end, f);
			if (!end && can_go_there(f, j, k))
				result(j, k, &end, f);
			if (!end && can_go_there(f, j, l))
				result(j, l, &end, f);
			++k;
			--l;
		}
		++i;
		--j;
	}
	if (!end)
		ft_putchar('\n');
}

void	filler(t_fil *f)
{
	if (!f->map2)
	{
		if (f->start % (4 + f->col) - 4 < f->col / 2)
		{
			if (f->start / (4 + f->col) < f->lig / 2)
			{
				// ft_putstr_fd("\nCase1\n", 2);
				asc_left(f);
				f->cases = 1;
			}
			else
			{
				// ft_putstr_fd("\nCase2\n", 2);
				des_left(f);
				f->cases = 2;
			}
		}
		else
		{
			if (f->start / (4 + f->col) < f->lig / 2)
			{
				// ft_putstr_fd("\nCase3\n", 2);
				asc_right(f);
				f->cases = 3;
			}
			else
			{
				// ft_putstr_fd("\nCase4\n", 2);
				des_right(f);
				f->cases = 4;
			}
		}
	}
	else if (!f->mid)
	{
		if (f->cases == 1 && f->lastus % (4 + f->col) - 4 < f->col / 2 && f->lastus / (4 + f->col) < f->lig / 2)
		{
				asc_left(f);
		}
		else if (f->cases == 2 && f->lastus % (4 + f->col) - 4 < f->col / 2 && f->lastus / (4 + f->col) > f->lig / 2)
		{
				des_left(f);
		}
		else if (f->cases == 3 && f->lastus % (4 + f->col) - 4 >= f->col / 2 && f->lastus / (4 + f->col) < f->lig / 2)
		{
				asc_right(f);
		}
		else if (f->cases == 4 && f->lastus % (4 + f->col) - 4 >= f->col / 2 && f->lastus / (4 + f->col) > f->lig / 2)
		{
				des_right(f);
		}
		else
		{
			f->mid = 1;
			filler(f);
		}
	}
	else
	{
		if (f->cases == 1)
		{
			if (!f->touch_right && f->tr < 5)
				left_asc(f);
			else if (!f->touch_left && f->tl < 10)
				right_asc(f);
			else if (!f->touch_bot && f->tr < 5)
				asc_right(f);
			else
				test(f);
		}
		if (f->cases == 2)
		{
			if (!f->touch_right && f->tr < 5)
				left_des(f);
			else if (!f->touch_left && f->tl < 10)
				right_des(f);
			else if (!f->touch_top && f->tt < 5)
				des_right(f);
			else 
				test(f);
		}
		if (f->cases == 3)
		{
			if (!f->touch_left && f->tl < 5)
				right_asc(f);
			else if (!f->touch_right && f->tr < 10)
				left_asc(f);
			else if (!f->touch_bot && f->tb < 5)
				asc_left(f);
			else 
				test(f);
		}
		if (f->cases == 4)
		{
			if (!f->touch_left && f->tl < 5)
				right_des(f);
			else if (!f->touch_right && f->tr < 10)
				left_des(f);
			else if (!f->touch_top && f->tt < 5)
				des_left(f);
			else 
				test(f);
		}
	}
}

// void	filler(t_fil *f)
// {
// 	int i;
// 	int j;
// 	int k;
// 	int l;
// 	char end;

// 	end = 0;
// 	i = f->last / (4 + f->col);
// 	j = f->last / (4 + f->col);
// 	while ((j > -1 * f->pl + 1 || i < f->lig + f->pl) && !end)
// 	{
// 		k = f->last % (4 + f->col) - 4;
// 		l = f->last % (4 + f->col) - 4;
// 		while ((l > -1 * f->pc + 1 || k < f->col + f->pc) && !end)
// 		{
// 			if (can_go_there(f, i, k))
// 				result(i, k, &end);
// 			if (!end && can_go_there(f, i, l))
// 				result(i, l, &end);
// 			if (!end && can_go_there(f, j, k))
// 				result(j, k, &end);
// 			if (!end && can_go_there(f, j, l))
// 				result(j, l, &end);
// 			++k;
// 			--l;
// 		}
// 		++i;
// 		--j;
// 	}
// 	if (!end)
// 		ft_putchar('\n');

// }

// void	filler(t_fil *f)
// {
// 	int i;
// 	int j;
// 	int k;

// 	i = 0;
// 	while (i < f->lig)
// 	{
// 		j = 0;
// 		while (j < f->col)
// 		{
// 			k = j + 4 + i * (4 + f->col);
// 			if (f->map[k] != '.')
// 			{
// 				if (f->map[k] == f->ply)
// 				{
// 					f->us[0] += i;
// 					f->us[1] += j;
// 				}
// 				else
// 				{
// 					f->him[0] += i;
// 					f->him[1] += j;
// 				}
// 			}
// 			++j;
// 		}
// 		++i;
// 	}
// 	if (f->us[0] > f->him[0])
// 	{
// 		if (f->us[1] > f->him[1])
// 			des_left(f);
// 		else
// 			des_right(f);
// 	}
// 	else
// 	{
// 		if (f->us[1] > f->him[1])
// 			asc_left(f);
// 		else
// 			asc_right(f);
// 	}
// }
