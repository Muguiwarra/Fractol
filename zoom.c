/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:13:07 by nabboune          #+#    #+#             */
/*   Updated: 2023/03/15 06:27:35 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse(int key, int x, int y, t_global *mlx)
{
	mlx->pos->x = -((((double) x / WIDTH) * (mlx->range->real_end - mlx->range->real_start)) - mlx->range->real_end);
	mlx->pos->y = ((- (double) y / HEIGHT) * (mlx->range->imaginary_end - mlx->range->imaginary_start)) + mlx->range->imaginary_end ;
	if (key == 4)
		ft_zoom_in(mlx);
	else if (key == 5)
		ft_zoom_out(mlx);
	return (0);
}

void	ft_zoom_in(t_global *mlx)
{
	mlx->pos->zoom = 0.5;
	mlx->pos->tmp = (mlx->range->real_end - mlx->range->real_start) * mlx->pos->zoom;
	mlx->range->real_end = mlx->pos->x + \
							(mlx->range->real_end - mlx->pos->x) * mlx->pos->zoom;
	mlx->range->real_start = mlx->range->real_end - mlx->pos->tmp;
	mlx->pos->tmp = (mlx->range->imaginary_end - mlx->range->imaginary_start) * mlx->pos->zoom;
	mlx->range->imaginary_end = mlx->pos->y + \
							(mlx->range->imaginary_end - mlx->pos->y) * mlx->pos->zoom;
	mlx->range->imaginary_start = mlx->range->imaginary_end - mlx->pos->tmp;
}

void	ft_zoom_out(t_global *mlx)
{
	mlx->pos->zoom = 2;
	mlx->pos->tmp = (mlx->range->real_end - mlx->range->real_start) * mlx->pos->zoom;
	mlx->range->real_end = mlx->pos->x + (mlx->range->real_end - mlx->pos->x) * mlx->pos->zoom;
	mlx->range->real_start = mlx->range->real_end - mlx->pos->tmp;
	mlx->pos->tmp = (mlx->range->imaginary_end - mlx->range->imaginary_start) * mlx->pos->zoom;
	mlx->range->imaginary_end = mlx->pos->y + (mlx->range->imaginary_end - mlx->pos->y) * mlx->pos->zoom;
	mlx->range->imaginary_start = mlx->range->imaginary_end - mlx->pos->tmp;
}

int	infinity(t_global *mlx)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx->screen->x = 0;
	while (mlx->screen->x < WIDTH)
	{
		mlx->screen->y = 0;
		while (mlx->screen->y < HEIGHT)
		{
			ft_julia(mlx);
			mlx->screen->y++;
		}
		mlx->screen->x++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->image->img, 0, 0);
	return (0);
}