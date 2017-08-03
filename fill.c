#include "filler.h"

void	asc_left(t_fil *fil)
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
				ft_putnbr(j);
				ft_putchar(' ');
				ft_putnbr(i);
				ft_putchar('\n');
				end = 1;
			}
			++i;
		}
		--j;
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
		i = fil->col + fil->pc;
		while (i > -1 * fil->pc + 1 && !end)
		{
			if (can_go_there(fil, j, i))
			{
				ft_putnbr(j);
				ft_putchar(' ');
				ft_putnbr(i);
				ft_putchar('\n');
				end = 1;
			}
			--i;
		}
		--j;
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
		i = fil->col + fil->pc;
		while (i > -1 * fil->pc + 1 && !end)
		{
			if (can_go_there(fil, j, i))
			{
				ft_putnbr(j);
				ft_putchar(' ');
				ft_putnbr(i);
				ft_putchar('\n');
				end = 1;
			}
			--i;
		}
		++j;
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
		i = -1 * fil->pc + 1;
		while (i < fil->col + fil->pc && !end)
		{
			if (can_go_there(fil, j, i))
			{
				ft_putnbr(j);
				ft_putchar(' ');
				ft_putnbr(i);
				ft_putchar('\n');
				end = 1;
			}
			++i;
		}
		++j;
	}
	if (!end)
		ft_putchar('\n');
}

void	filler(t_fil *f)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < f->lig)
	{
		j = 0;
		while (j < f->col)
		{
			k = j + 4 + i * (4 + f->col);
			if (f->map[k] != '.')
			{
				if (f->map[k] == f->ply)
				{
					f->us[0] += i;
					f->us[1] += j;
				}
				else
				{
					f->him[0] += i;
					f->him[1] += j;
				}
			}
			++j;
		}
		++i;
	}
	if (f->us[0] > f->him[0])
	{
		if (f->us[1] > f->him[1])
			des_left(f);
		else
			des_right(f);
	}
	else
	{
		if (f->us[1] > f->him[1])
			asc_left(f);
		else
			asc_right(f);
	}
}
