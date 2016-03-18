/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:56:58 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/18 17:41:36 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit(char *str)
{
	ft_putendl(str);
	exit(1);
}

int		my_key_func(int keycode, void *param)
{
	param = param + 0;
	if (keycode == 53)
		ft_exit("quit");
	if (keycode == 123)
		draw_left(param);
	if (keycode == 124)
		draw_right(param);
	if (keycode == 126)
		draw_up(param);
	if (keycode == 125)
		draw_down(param);
	if (keycode == 69)
		iter_plus(param);
	if (keycode == 78)
		iter_moins(param);
	return (0);
}

int		my_mouse_func(int button, int x, int y, void *param)
{
	param = param + 0;
	if (button == 4)
		zoom_in(param, x, y);
	if (button == 5)
		zoom_out(param, x, y);
	return (0);
}

void	draw_px(int x, int y, int color, t_param *param)
{
	*(int *)(unsigned long)(param->str_img + (param->size_line * y) +
			(x * param->bits / 8)) = color;
}

void	init_zoom(t_zoom *zoom)
{
	zoom->x1 = -2.2;
	zoom->x2 = 2.2;
	zoom->y1 = -1.5;
	zoom->y2 = 1.5;
	zoom->zoom = 350;
	zoom->iter_max = 50;
}

void	wich_one(char *argv, t_param *param)
{
	int		arg;
	t_zoom	zoom;

	arg = ft_atoi(argv);
	init_zoom(&zoom);
	param->zoom = zoom;
	if (arg != 1 && arg != 2)
		ft_exit("Erreur");
	if (arg == 1)
	{
		param->wich = 1;
		mandel_iter(param, &param->zoom);
	}
	else if (arg == 2)
	{
		param->wich = 2;
		julia_iter(param, &zoom);
	}
}

int		main(int argc, char **argv)
{
	t_param		param;

	argv = argv + 0;
	if (argc != 2)
		ft_exit("Erreur");
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, LARGEUR, HAUTEUR, "fractol");
	param.img = mlx_new_image(param.mlx, LARGEUR, HAUTEUR);
	mlx_mouse_hook(param.win, my_mouse_func, &param);
	mlx_key_hook(param.win, my_key_func, &param);
	wich_one(argv[1], &param);
	mlx_loop(param.mlx);
}
