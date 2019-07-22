/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hendler_meta.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 10:46:11 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/27 10:46:13 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_default(t_info *info)
{
	ft_putstr("DRAW: done\n");
	info->meta->color = WHITE;
	info->meta->scale = 1;
	info->meta->go_x = info->meta->width * 0.4;
	info->meta->go_y = info->meta->heigth * 0.4;
	info->meta->projection = FRONT;
}

void	set_position(t_info *info, int x, int y)
{
	ft_putstr("POSITION: set\n");
	info->meta->go_x = x;
	info->meta->go_y = y;
}

void	set_description(t_info *info)
{
	mlx_string_put(info->mlx_ptr, info->win_ptr, 7, 15, 0x9EC651, "GO: p | \
		POS: click | EXIT: esc, x | CLR: q, w, e, r  | ZOOM: scroll | \
		PRJ: 1, 2, 3 | ALT: click l/r");
}

void	set_error(int error)
{
	char *msg;

	if ((error == MAP && (msg = "ERROR: invalid map\n"))
	|| (error == MLX && (msg = "ERROR: can't initialize mlx\n"))
	|| (error == WIN && (msg = "ERROR: can't create window\n"))
	|| (error == VALUE && (msg = "ERROR: invalid value\n"))
	|| (error == FILE && (msg = "ERROR: can't open file\n"))
	|| (error == MALLOC && (msg = "ERROR: can't malloc memory\n"))
	|| (error == USAGE && (msg = "USAGE: ./fdf map.fdf\n")))
		ft_putstr(msg);
	exit(-1);
}
