#include "filler.h"
#include "fdf.h"

void	put_pixel(int x, int y, int color, t_env *ev)
{
	if (x < 0 || y < 0)
		return ;
	if (x > ev->winx || y > ev->winy)
		return ;
	// ev->p_img = mlx_get_data_addr(ev->img, &(ev->bpp), &(ev->s_line),
	// &(ev->ed));
	((int *)ev->p_img)[x + y * ev->s_line / 4] = color;
}

void	draw_line(double *pts1, double *pts2, int color, t_env *ev)
{
	double i;
	double m;

	pts1[2] = fabs(pts1[2]) > fabs(pts2[2]) ? pts2[2] : pts1[2];
	if (pts1[0] == pts2[0] && pts1[1] == pts2[1])
		put_pixel(pts1[0], pts1[1], color, ev);
	else if (fabs(pts1[0] - pts2[0]) >= fabs(pts1[1] - pts2[1]))
	{
		i = pts1[0] <= pts2[0] ? pts1[0] - 1 : pts2[0] - 1;
		while (++i <= (pts1[0] <= pts2[0] ? pts2[0] : pts1[0]) && (m = i *
			(pts1[1] - pts2[1]) / (pts1[0] - pts2[0]) + (pts2[1] * pts1[0] -
			pts2[0] * pts1[1]) / (pts1[0] - pts2[0])) <= ev->winy)
			put_pixel(i, m, color, ev);
	}
	else
	{
		i = pts1[1] <= pts2[1] ? pts1[1] - 1 : pts2[1] - 1;
		while (++i <= (pts1[1] <= pts2[1] ? pts2[1] : pts1[1]) && (m = i *
			(pts1[0] - pts2[0]) / (pts1[1] - pts2[1]) - (pts2[1] * pts1[0] -
			pts2[0] * pts1[1]) / (pts1[1] - pts2[1])) <= ev->winx)
			put_pixel(m, i, color, ev);
	}
}

int		fdfinit(t_env *ev)
{
	double	pts1[2];
	double	pts2[2];
	int		i;

	pts1[0] = 0;
	pts2[0] = 5 * ev->f->col;
	i = -1;
	while (++i <= ev->f->lig)
	{
		pts1[1] = 5 * i;
		pts2[1] = 5 * i;
		draw_line(pts1, pts2, 0xFFF, ev);
	}
	pts2[1] = 5 * ev->f->lig;
	pts1[1] = 0;
	i = -1;
	while (++i <= ev->f->col)
	{
		pts1[0] = 5 * i;
		pts2[0] = 5 * i;
		draw_line(pts1, pts2, 0xFFF, ev);
	}
	return (1);
}
void	initev(t_env *ev)
{
	ev->mlx = NULL;
	ev->win = NULL;
	ev->array = NULL;
	ev->rx = -60;
	ev->ry = 60;
	ev->winx = ev->f->col * 5 + 102;
	ev->winy = ev->f->lig * 5 + 102;
	ev->winx = ev->winx > 500 ? ev->winx : 500;
	ev->winy = ev->winy > 500 ? ev->winy : 500;
	ev->zoom = ev->winx / (2.5 * ev->len);
	ev->p = ev->zoom / 10;
	ev->tx = 0;
	ev->ty = ev->len / 2;
	ev->px = 0;
	ev->py = 0;
	ev->mx = 0;
	ev->my = 0;
	ev->c = 1;
}

void	remp(int x, int y, char c, t_env *ev)
{
	int 	i;
	double	pts1[2];
	double	pts2[2];

	x = 1 + 5 * x;
	y = 1 + 5 * y;
	pts1[0] = x;
	pts2[0] = x + 3;
	i = -1;
	while (++i < 4)
	{
		pts1[1] = y + i;
		pts2[1] = y + i;
		if (c == 3)
			draw_line(pts1, pts2, 0xFF00FF, ev);
		else if (c == 2)
			draw_line(pts1, pts2, 0xFFFFFF, ev);
		else
			draw_line(pts1, pts2, !c ? 0xFFFFF : 0xFF0000, ev);
	}
}

void	put_map(t_fil *fil)
{
	t_env	*ev;

	ev = palloc(sizeof(t_env));
	initev(ev);
	ev->f = fil;
	ev->mlx = mlx_init();
	ev->win = mlx_new_window(ev->mlx, ev->winx, ev->winy, "test");
	ev->img = mlx_new_image(ev->mlx, ev->winx, ev->winy);
	ev->p_img = mlx_get_data_addr(ev->img, &ev->bpp, &(ev->s_line), &(ev->ed));
	fdfinit(ev);
	// mlx_key_hook(ev->win, keymap, ev);
	// mlx_expose_hook(ev->win, fdfinit, ev);
	// mlx_loop(ev->mlx);
}
