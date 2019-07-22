/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hendler_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 10:46:01 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/27 10:46:03 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color_changer(t_info *info)
{
	ft_putstr("COLOR: yellow\n");
	info->meta->color += 9;
}

void	set_red(t_info *info)
{
	ft_putstr("COLOR: yellow\n");
	info->meta->color = YELLOW;
}

void	set_green(t_info *info)
{
	ft_putstr("COLOR: cyan\n");
	info->meta->color = CYAN;
}

void	set_blue(t_info *info)
{
	ft_putstr("COLOR: pink\n");
	info->meta->color = PINK;
}

void	set_white(t_info *info)
{
	ft_putstr("COLOR: white\n");
	info->meta->color = WHITE;
}
