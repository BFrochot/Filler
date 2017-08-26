#include "filler.h"

void	asc_left2(t_fil *fil)
{
	int i;
	int j;
	char end;

	end = 0;
	j = fil->lig / 2 + fil->pl;
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
		des_right(fil);
}

void	asc_right2(t_fil *fil)
{
	int i;
	int j;
	char end;

	end = 0;
	j = fil->lig / 2 + fil->pl;
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
		des_left(fil);
}

void	des_left2(t_fil *fil)
{
	int i;
	int j;
	char end;

	end = 0;
	j = fil->lig / 2 + fil->pl;
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
		asc_right(fil);
}

void	des_right2(t_fil *fil)
{
	int i;
	int j;
	char end;

	end = 0;
	j = fil->lig / 2 + fil->pl;
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
		asc_left(fil);
}
