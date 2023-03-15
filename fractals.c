/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:10:05 by nabboune          #+#    #+#             */
/*   Updated: 2023/03/15 06:26:16 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractal(int key, t_global *mlx)
{
	ft_init(mlx);
	if (key == 46)
	{
		ft_mandelbrot(mlx);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->image->img, 0, 0);
	}
	else if (key == 38)
	{
		ft_julia(mlx);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->image->img, 0, 0);
	}
	else if (key == 53)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		ft_free_mlx(mlx);
		exit(0);
	}
	// printf("%d\n", key);
	return (key);
}

void	ft_mandelbrot(t_global *mlx)
{
	while (mlx->screen->x < WIDTH)
	{
		mlx->complex->real = mlx->screen->x * (mlx->range->real_end - mlx->range->real_start) / WIDTH - mlx->range->real_end - 0.5;
		while (mlx->screen->y < HEIGHT)
		{
			mlx->complex->imaginary = mlx->range->imaginary_end - mlx->screen->y * (mlx->range->imaginary_end - mlx->range->imaginary_start) / HEIGHT;
			mlx->zn->n = 0;
			mlx->zn->real = 0;
			mlx->zn->imaginary = 0;
			while ((mlx->zn->real * mlx->zn->real + mlx->zn->imaginary * mlx->zn->imaginary <= 4) && mlx->zn->n < 100)
			{
				mlx->zn->tmp = mlx->zn->real * mlx->zn->real + mlx->complex->real - mlx->zn->imaginary * mlx->zn->imaginary;
				mlx->zn->imaginary = 2 * mlx->zn->real * mlx->zn->imaginary + mlx->complex->imaginary;
				mlx->zn->real = mlx->zn->tmp;
				mlx->zn->n = mlx->zn->n + 1;
			}
			if (mlx->zn->n == 100)
				my_mlx_pixel_put(mlx->image, mlx->screen->x, mlx->screen->y, 0x00FFFFFF);
			else
				my_mlx_pixel_put(mlx->image, mlx->screen->x, mlx->screen->y, 0x000F000A * mlx->zn->n);
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
			mlx->zn->real = mlx->screen->x * (mlx->range->real_end - mlx->range->real_start) / WIDTH - mlx->range->real_end;
			mlx->zn->imaginary = mlx->range->imaginary_end - mlx->screen->y * (mlx->range->imaginary_end - mlx->range->imaginary_start) / HEIGHT;
			while ((mlx->zn->real * mlx->zn->real + mlx->zn->imaginary * mlx->zn->imaginary <= 4) && mlx->zn->n < 100)
			{
				mlx->zn->tmp = mlx->zn->real * mlx->zn->real + mlx->complex->real - mlx->zn->imaginary * mlx->zn->imaginary;
				mlx->zn->imaginary = 2 * mlx->zn->real * mlx->zn->imaginary + mlx->complex->imaginary;
				mlx->zn->real = mlx->zn->tmp;
				mlx->zn->n = mlx->zn->n + 1;
			}
			if (mlx->zn->n == 100)
				my_mlx_pixel_put(mlx->image, mlx->screen->x, mlx->screen->y, 0x00FFFFFF);
			else
				my_mlx_pixel_put(mlx->image, mlx->screen->x, mlx->screen->y, 0x000F000A * mlx->zn->n);
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
		mlx->complex->real = mlx->screen->x * (mlx->range->real_end - mlx->range->real_start) / WIDTH - mlx->range->real_end - 0.5;
		while (mlx->screen->y < HEIGHT)
		{
			mlx->complex->imaginary = -(mlx->range->imaginary_end - mlx->screen->y * (mlx->range->imaginary_end - mlx->range->imaginary_start) / HEIGHT);
			mlx->zn->n = 0;
			mlx->zn->real = 0;
			mlx->zn->imaginary = 0;
			while ((mlx->zn->real * mlx->zn->real + mlx->zn->imaginary * mlx->zn->imaginary <= 4) && mlx->zn->n < 100)
			{
				mlx->zn->tmp = mlx->zn->real * mlx->zn->real + mlx->complex->real - mlx->zn->imaginary * mlx->zn->imaginary;
				mlx->zn->imaginary = fabs(2 * mlx->zn->real * mlx->zn->imaginary )+ mlx->complex->imaginary;
				mlx->zn->real = mlx->zn->tmp;
				mlx->zn->n = mlx->zn->n + 1;
			}
			if (mlx->zn->n == 100)
				my_mlx_pixel_put(mlx->image, mlx->screen->x, mlx->screen->y, 0x00FFFFFF);
			else
				my_mlx_pixel_put(mlx->image, mlx->screen->x, mlx->screen->y, 0x000F000A * mlx->zn->n);
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
		mlx->complex->real = mlx->screen->x * (mlx->range->real_end - mlx->range->real_start) / WIDTH - mlx->range->real_end - 0.5;
		while (mlx->screen->y < HEIGHT)
		{
			mlx->complex->imaginary = mlx->range->imaginary_end - mlx->screen->y * (mlx->range->imaginary_end - mlx->range->imaginary_start) / HEIGHT;
			mlx->zn->n = 0;
			mlx->zn->real = 0;
			mlx->zn->imaginary = 0;
			while ((mlx->zn->real * mlx->zn->real + mlx->zn->imaginary * mlx->zn->imaginary <= 4) && mlx->zn->n < 100)
			{
				mlx->zn->tmp = mlx->zn->real * mlx->zn->real + mlx->complex->real - mlx->zn->imaginary * mlx->zn->imaginary;
				mlx->zn->imaginary = -2 * mlx->zn->real * mlx->zn->imaginary + mlx->complex->imaginary;
				mlx->zn->real = mlx->zn->tmp;
				mlx->zn->n = mlx->zn->n + 1;
			}
			if (mlx->zn->n == 100)
				my_mlx_pixel_put(mlx->image, mlx->screen->x, mlx->screen->y, 0x00FFFFFF);
			else
				my_mlx_pixel_put(mlx->image, mlx->screen->x, mlx->screen->y, 0x000F000A * mlx->zn->n);
			mlx->screen->y = mlx->screen->y + 1;
		}
		mlx->screen->y = 0;
		mlx->screen->x = mlx->screen->x + 1;
	}
}
