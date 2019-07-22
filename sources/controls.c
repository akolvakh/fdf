/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 10:45:40 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/27 10:45:43 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_cross(void)
{
	exit(0);
	return (0);
}

int	deal_key(int keycode, t_info *info)
{
	if (keycode == ESC)
		deal_cross();
	if (keycode == P)
		set_default(info);
	if (keycode == Q)
		set_red(info);
	if (keycode == W)
		set_green(info);
	if (keycode == E)
		set_blue(info);
	if (keycode == R)
		set_color_changer(info);
	if (keycode == ONE)
		set_front(info);
	if (keycode == TWO)
		set_parallel(info);
	if (keycode == THREE)
		set_iso(info);
	if (keycode == FOUR)
		set_conic(info);
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	projection_checker(info);
	drawing(info);
	set_description(info);
	return (0);
}

int	deal_mouse(int button, int x, int y, t_info *info)
{
	if (button == CLICK)
		set_position(info, x, y);
	if (button == SCROLL_UP)
		set_scale_up(info);
	if (button == SCROLL_DOWN)
		set_scale_down(info);
	if (button == TAB)
		set_altitude_up(info);
	if (button == SHIFT)
		set_altitude_down(info);
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	projection_checker(info);
	drawing(info);
	set_description(info);
	return (0);
}
