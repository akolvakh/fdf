/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 10:46:42 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/27 10:46:43 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	front(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0);
	*y = -z + (previous_x + previous_y) * sin(0);
}

static void	parallel(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.46373398);
	*y = -z + (previous_x + previous_y) * sin(0.46373398);
}

static void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

static void	conic(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.785398);
	*y = -z + (previous_x + previous_y) * sin(0.785398);
}

void		projection_checker(t_info *info)
{
	int		cnt;

	cnt = info->meta->amount;
	while (cnt >= 0)
	{
		info->dot[cnt].x = info->def[cnt].x * info->meta->scale;
		info->dot[cnt].y = info->def[cnt].y * info->meta->scale;
		info->dot[cnt].z = info->def[cnt].z * info->meta->scale;
		cnt--;
	}
	cnt = info->meta->amount;
	if (info->meta->projection == FRONT)
		while (--cnt > 0)
			front(&info->dot[cnt].x, &info->dot[cnt].y, info->dot[cnt].z);
	if (info->meta->projection == PARALLEL)
		while (--cnt > 0)
			parallel(&info->dot[cnt].x, &info->dot[cnt].y, info->dot[cnt].z);
	if (info->meta->projection == ISO)
		while (--cnt > 0)
			iso(&info->dot[cnt].x, &info->dot[cnt].y, info->dot[cnt].z);
	if (info->meta->projection == CONIC)
		while (--cnt > 0)
			conic(&info->dot[cnt].x, &info->dot[cnt].y, info->dot[cnt].z);
}
