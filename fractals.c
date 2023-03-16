/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:10:05 by nabboune          #+#    #+#             */
/*   Updated: 2023/03/16 08:59:45 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractals(int key, t_global *mlx)
{
	if (key == 46)
	{
		ft_init(mlx);
		mlx->fractal = &ft_mandelbrot;
	}
	else if (key == 38)
	{
		ft_init(mlx);
		mlx->fractal = &ft_julia;
	}
	else if (key == 11)
	{
		ft_init(mlx);
		mlx->fractal = &ft_burning_ship;
	}
	else if (key == 17)
	{
		ft_init(mlx);
		mlx->fractal = &ft_tricorn;
	}
}

void	ft_mandelbrot(t_global *mlx)
{
	while (mlx->screen->x < WIDTH)
	{
		mlx->complex->real = mlx->screen->x * (mlx->range->real_end
				- mlx->range->real_start) / WIDTH - mlx->range->real_end - 0.5;
		while (mlx->screen->y < HEIGHT)
		{
			mlx->complex->imaginary = mlx->range->imaginary_end - mlx->screen->y
				* (mlx->range->imaginary_end - mlx->range->imaginary_start)
				/ HEIGHT;
			mlx->zn->n = 0;
			mlx->zn->real = 0;
			mlx->zn->imaginary = 0;
			ft_where_the_magie_happen_for_mandelbrot(mlx);
			if (mlx->zn->n == 100)
				my_mlx_pixel_put(mlx->image, mlx->screen->x, mlx->screen->y,
					mlx->color_in);
			else
				my_mlx_pixel_put(mlx->image, mlx->screen->x, mlx->screen->y,
					mlx->color_out * mlx->zn->n);
			mlx->screen->y = mlx->screen->y + 1;
		}
		mlx->screen->y = 0;
		mlx->screen->x = mlx->screen->x + 1;
	}
}

void	ft_julia(t_global *mlx)
{
	while (mlx->screen->x < WIDTH)
	{
		mlx->complex->real = mlx->pos->x;
		while (mlx->screen->y < HEIGHT)
		{
			mlx->complex->imaginary = mlx->pos->y;
			mlx->zn->n = 0;
			mlx->zn->real = mlx->screen->x * (mlx->range->real_end
					- mlx->range->real_start) / WIDTH - mlx->range->real_end;
			mlx->zn->imaginary = mlx->range->imaginary_end - mlx->screen->y
				* (mlx->range->imaginary_end - mlx->range->imaginary_start)
				/ HEIGHT;
			ft_where_the_magie_happen_for_julia(mlx);
			if (mlx->zn->n == 100)
				my_mlx_pixel_put(mlx->image, mlx->screen->x, mlx->screen->y,
					mlx->color_in);
			else
				my_mlx_pixel_put(mlx->image, mlx->screen->x, mlx->screen->y,
					mlx->color_out * mlx->zn->n);
			mlx->screen->y = mlx->screen->y + 1;
		}
		mlx->screen->y = 0;
		mlx->screen->x = mlx->screen->x + 1;
	}
}

void	ft_burning_ship(t_global *mlx)
{
	while (mlx->screen->x < WIDTH)
	{
		mlx->complex->real = mlx->screen->x * (mlx->range->real_end
				- mlx->range->real_start) / WIDTH - mlx->range->real_end - 0.5;
		while (mlx->screen->y < HEIGHT)
		{
			mlx->complex->imaginary = -(mlx->range->imaginary_end
					- mlx->screen->y * (mlx->range->imaginary_end
						- mlx->range->imaginary_start) / HEIGHT);
			mlx->zn->n = 0;
			mlx->zn->real = 0;
			mlx->zn->imaginary = 0;
			ft_where_the_magie_happen_for_burning_ship(mlx);
			if (mlx->zn->n == 100)
				my_mlx_pixel_put(mlx->image, mlx->screen->x, mlx->screen->y,
					mlx->color_in);
			else
				my_mlx_pixel_put(mlx->image, mlx->screen->x, mlx->screen->y,
					mlx->color_out * mlx->zn->n);
			mlx->screen->y = mlx->screen->y + 1;
		}
		mlx->screen->y = 0;
		mlx->screen->x = mlx->screen->x + 1;
	}
}

void	ft_tricorn(t_global *mlx)
{
	while (mlx->screen->x < WIDTH)
	{
		mlx->complex->real = mlx->screen->x * (mlx->range->real_end
				- mlx->range->real_start) / WIDTH - mlx->range->real_end - 0.5;
		while (mlx->screen->y < HEIGHT)
		{
			mlx->complex->imaginary = mlx->range->imaginary_end - mlx->screen->y
				* (mlx->range->imaginary_end - mlx->range->imaginary_start)
				/ HEIGHT;
			mlx->zn->n = 0;
			mlx->zn->real = 0;
			mlx->zn->imaginary = 0;
			ft_where_the_magie_happen_for_tricorn(mlx);
			if (mlx->zn->n == 100)
				my_mlx_pixel_put(mlx->image, mlx->screen->x, mlx->screen->y,
					mlx->color_in);
			else
				my_mlx_pixel_put(mlx->image, mlx->screen->x, mlx->screen->y,
					mlx->color_out * mlx->zn->n);
			mlx->screen->y = mlx->screen->y + 1;
		}
		mlx->screen->y = 0;
		mlx->screen->x = mlx->screen->x + 1;
	}
}
