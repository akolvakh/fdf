/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 15:42:05 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/27 11:47:51 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

enum				e_keys
{
	Q = 12, W = 13,
	E = 14, R = 15,
	UP = 126, DOWN = 125,
	ONE = 18, TWO = 19,
	THREE = 20, FOUR = 21,
	TAB = 1, SHIFT = 2,
	P = 35, ESC = 53,
	CLICK = 1, SCROLL_UP = 4,
	SCROLL_DOWN = 5, FRONT = 1,
	PARALLEL = 2, ISO = 3,
	CONIC = 4
};

enum				e_colors
{
	YELLOW = 0xF5B201, CYAN = 0x3FB1B7,
	PINK = 0xFF0FFF, WHITE = 0xFFFFFF,
	RED = 0xCC0000, GREEN = 0x98FB98,
	BLUE = 0x0000FF, DEF_COLOR = 0xF5B201
};

enum				e_display
{
	START_X = 100, START_Y = 100,
	WTH = 1024, HTH = 1024
};

enum				e_errors
{
	MAP = 1, MLX = 2,
	WIN = 3, VALUE = 4,
	FILE = 5, MALLOC = 6,
	USAGE = 7
};

typedef struct		s_dot
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_dot;

typedef struct		s_crd
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
}					t_crd;

typedef struct		s_meta
{
	int				color;
	int				scale;
	int				amount;
	int				row;
	int				projection;
	int				width;
	int				heigth;
	int				go_x;
	int				go_y;
}					t_meta;

typedef struct		s_info
{
	int				i;
	int				l;
	int				ret;
	int				line;
	int				cnt;
	int				fd;
	int				dx;
	int				dy;
	int				yi;
	int				xi;
	int				d;
	int				y;
	int				x;
	int				derr;
	char			*buff;
	char			**tmp;
	void			*mlx_ptr;
	void			*win_ptr;
	t_dot			*def;
	t_dot			*dot;
	t_crd			*crd;
	t_meta			*meta;
}					t_info;

int					deal_key(int keycode, t_info *info);
int					deal_mouse(int button, int x, int y, t_info *info);
int					deal_cross(void);
void				set_error(int error);
void				set_front(t_info *info);
void				set_parallel(t_info *info);
void				set_iso(t_info *info);
void				set_conic(t_info *info);
void				set_white(t_info *info);
void				set_blue(t_info *info);
void				set_green(t_info *info);
void				set_red(t_info *info);
void				set_color_changer(t_info *info);
void				set_default(t_info *info);
void				set_position(t_info *info, int x, int y);
void				set_scale_down(t_info *info);
void				set_scale_up(t_info *info);
void				set_altitude_up(t_info *info);
void				set_altitude_down(t_info *info);
void				set_description(t_info *info);
void				projection_checker(t_info *info);
void				drawing(t_info *info);

#endif
