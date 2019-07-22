/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hendler_scale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 10:46:29 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/27 10:46:31 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_altitude_down(t_info *info)
{
	ft_putstr("ALTITUDE: down\n");
	info->cnt = info->meta->amount;
	while (info->cnt > 0)
	{
		if (info->def[info->cnt].z != 0)
		{
			info->def[info->cnt].z--;
			if (info->def[info->cnt].z == 0)
				info->def[info->cnt].z--;
		}
		info->cnt--;
	}
}

void	set_altitude_up(t_info *info)
{
	ft_putstr("ALTITUDE: up\n");
	info->cnt = info->meta->amount;
	while (info->cnt > 0)
	{
		if (info->def[info->cnt].z != 0)
		{
			info->def[info->cnt].z++;
			if (info->def[info->cnt].z == 0)
				info->def[info->cnt].z++;
		}
		info->cnt--;
	}
}

void	set_scale_up(t_info *info)
{
	ft_putstr("SCALE: up\n");
	info->cnt = info->meta->amount;
	info->meta->scale *= 2;
	while (info->cnt > 0)
	{
		info->dot[info->cnt].x *= info->meta->scale;
		info->dot[info->cnt].y *= info->meta->scale;
		info->dot[info->cnt].z *= info->meta->scale;
		info->cnt--;
	}
}

void	set_scale_down(t_info *info)
{
	ft_putstr("SCALE: down\n");
	info->cnt = info->meta->amount;
	info->meta->scale /= 2;
	if (info->meta->scale <= 0)
	{
		ft_putstr("You have reached the limit\n");
		info->meta->scale = 1;
	}
	while (info->cnt > 0)
	{
		info->dot[info->cnt].x *= info->meta->scale;
		info->dot[info->cnt].y *= info->meta->scale;
		info->dot[info->cnt].z *= info->meta->scale;
		info->cnt--;
	}
}
