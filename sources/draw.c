/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 10:45:51 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/27 10:45:53 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	swap_params(t_info *info)
{
	int x;
	int y;

	x = info->crd->x0;
	info->crd->x0 = info->crd->x1;
	info->crd->x1 = x;
	y = info->crd->y0;
	info->crd->y0 = info->crd->y1;
	info->crd->y1 = y;
}

static void	draw_line_low(t_info *info)
{
	info->dx = info->crd->x1 - info->crd->x0;
	info->dy = info->crd->y1 - info->crd->y0;
	info->yi = 1;
	if (info->dy < 0)
	{
		info->yi = -1;
		info->dy = -info->dy;
	}
	info->derr = 2 * info->dy - info->dx;
	info->y = info->crd->y0;
	info->x = info->crd->x0;
	while (info->x <= info->crd->x1)
	{
		mlx_pixel_put(info->mlx_ptr, info->win_ptr, info->x + info->meta->go_x,
						info->y + info->meta->go_y, info->meta->color);
		if (info->derr > 0)
		{
			info->y += info->yi;
			info->derr = info->derr - 2 * info->dx;
		}
		info->derr = info->derr + 2 * info->dy;
		info->x++;
	}
}

static void	draw_line_high(t_info *info)
{
	info->dx = info->crd->x1 - info->crd->x0;
	info->dy = info->crd->y1 - info->crd->y0;
	info->xi = 1;
	if (info->dx < 0)
	{
		info->xi = -1;
		info->dx = -info->dx;
	}
	info->derr = 2 * info->dx - info->dy;
	info->x = info->crd->x0;
	info->y = info->crd->y0;
	while (info->y <= info->crd->y1)
	{
		mlx_pixel_put(info->mlx_ptr, info->win_ptr, info->x + info->meta->go_x,
						info->y + info->meta->go_y, info->meta->color);
		if (info->derr > 0)
		{
			info->x += info->xi;
			info->derr = info->derr - 2 * info->dy;
		}
		info->derr = info->derr + 2 * info->dx;
		info->y++;
	}
}

static void	draw_line(t_info *info)
{
	int		dir;

	dir = abs(info->crd->y1 - info->crd->y0)
	< abs(info->crd->x1 - info->crd->x0);
	if (dir && info->crd->x0 > info->crd->x1)
		swap_params(info);
	if (!dir && info->crd->y0 > info->crd->y1)
		swap_params(info);
	(dir) ? draw_line_low(info) : draw_line_high(info);
}

void		drawing(t_info *info)
{
	info->i = -1;
	while (++info->i < info->meta->amount - 1)
	{
		if ((info->dot[info->i].x > info->dot[info->i + 1].x))
			info->i++;
		info->crd->x0 = info->dot[info->i].x;
		info->crd->y0 = info->dot[info->i].y;
		info->crd->x1 = info->dot[info->i + 1].x;
		info->crd->y1 = info->dot[info->i + 1].y;
		draw_line(info);
	}
	info->i = 0;
	while (info->meta->amount - info->meta->row - 1 > info->i)
	{
		info->l = -1;
		while (++info->l <= info->meta->row)
		{
			info->i++;
			info->crd->x0 = info->dot[info->meta->row + info->i].x;
			info->crd->y0 = info->dot[info->meta->row + info->i].y;
			info->crd->x1 = info->dot[info->i - 1].x;
			info->crd->y1 = info->dot[info->i - 1].y;
			draw_line(info);
		}
	}
}
