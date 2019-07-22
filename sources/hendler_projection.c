/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hendler_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 10:46:20 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/27 10:46:22 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_front(t_info *info)
{
	ft_putstr("PROJECTION: front\n");
	info->meta->projection = FRONT;
}

void	set_parallel(t_info *info)
{
	ft_putstr("PROJECTION: parallel\n");
	info->meta->projection = PARALLEL;
}

void	set_iso(t_info *info)
{
	ft_putstr("PROJECTION: iso\n");
	info->meta->projection = ISO;
}

void	set_conic(t_info *info)
{
	ft_putstr("PROJECTION: conic\n");
	info->meta->projection = CONIC;
}
