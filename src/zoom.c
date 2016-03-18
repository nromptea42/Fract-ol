/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:36:08 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/18 18:51:59 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

# define H 5

void	zoom_in(t_param *param, int x, int y)
{
/*	param->zoom.x1 = x - H;	
	param->zoom.x2 = x + H;
	param->zoom.y1 = y - H;
	param->zoom.y2 = y + H;*/
	x = x + 0;
	y = y + 0;
	param->zoom.zoom = param->zoom.zoom + 50;
	if (param->wich == 1)
		mandel_iter(param, &param->zoom);
	if (param->wich == 2)
		julia_iter(param, &param->zoom);
}

void	zoom_out(t_param *param, int x, int y)
{
/*	param->zoom.x1 = x + H;
	param->zoom.x2 = x - H;
	param->zoom.y1 = y + H;
	param->zoom.y2 = y - H;*/
	x = x + 0;
	y = y + 0;
	param->zoom.zoom = param->zoom.zoom - 50;
	if (param->wich == 1)
		mandel_iter(param, &param->zoom);
	if (param->wich == 2)
		julia_iter(param, &param->zoom);
}
