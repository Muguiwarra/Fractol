/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 02:40:16 by nabboune          #+#    #+#             */
/*   Updated: 2023/03/14 05:31:33 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_image_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_zoom_in(t_global *mlx)
{
	mlx->pos.zoom = 0.5;
	mlx->pos.x_tmp = (mlx->range.real_end - mlx->range.real_start) * mlx->pos.zoom;
	mlx->range.real_end = mlx->pos.x + (mlx->range.real_end - mlx->pos.x) * mlx->pos.zoom;
	mlx->range.real_start = mlx->range.real_end - mlx->pos.x_tmp;
	mlx->pos.y_tmp = (mlx->range.imaginary_end - mlx->range.imaginary_start) * mlx->pos.zoom;
	mlx->range.imaginary_end = mlx->pos.y + (mlx->range.imaginary_end - mlx->pos.y) * mlx->pos.zoom;
	mlx->range.imaginary_start = mlx->range.imaginary_end - mlx->pos.y_tmp;
}

void	ft_zoom_out(t_global *mlx)
{
	mlx->pos.zoom = 2;
	mlx->pos.x_tmp = (mlx->range.real_end - mlx->range.real_start) * mlx->pos.zoom;
	mlx->range.real_end = mlx->pos.x + (mlx->range.real_end - mlx->pos.x) * mlx->pos.zoom;
	mlx->range.real_start = mlx->range.real_end - mlx->pos.x_tmp;
	mlx->pos.y_tmp = (mlx->range.imaginary_end - mlx->range.imaginary_start) * mlx->pos.zoom;
	mlx->range.imaginary_end = mlx->pos.y + (mlx->range.imaginary_end - mlx->pos.y) * mlx->pos.zoom;
	mlx->range.imaginary_start = mlx->range.imaginary_end - mlx->pos.y_tmp;
}

void	ft_init(t_global *mlx)
{
	mlx->range.real_start = -2;
	mlx->range.real_end = 2;
	mlx->range.imaginary_start = -2;
	mlx->range.imaginary_end = 2;
}

void	ft_mandelbrot(t_global *mlx)
{
	while (mlx->screen.x < WIDTH)
	{
		mlx->complex.real = mlx->screen.x * (mlx->range.real_end - mlx->range.real_start) / WIDTH - mlx->range.real_end;
		mlx->screen.y = 0;
		while (mlx->screen.y < HEIGHT)
		{
			mlx->complex.imaginary = mlx->range.imaginary_end - mlx->screen.y * (mlx->range.imaginary_end - mlx->range.imaginary_start) / HEIGHT;
			mlx->zn.n = 0;
			mlx->zn.real = 0;
			mlx->zn.imaginary = 0;
			while ((mlx->zn.real * mlx->zn.real + mlx->zn.imaginary * mlx->zn.imaginary <= 4) && mlx->zn.n < 100)
			{
				mlx->zn.tmp = mlx->zn.real * mlx->zn.real + mlx->complex.real - mlx->zn.imaginary * mlx->zn.imaginary;
				mlx->zn.imaginary = 2 * mlx->zn.real * mlx->zn.imaginary + mlx->complex.imaginary;
				mlx->zn.real = mlx->zn.tmp;
				mlx->zn.n = mlx->zn.n + 1;
			}
			if (mlx->zn.n == 100)
				my_mlx_pixel_put(mlx->image, mlx->screen.x, mlx->screen.y, 0x00000000);
			else
				my_mlx_pixel_put(mlx->image, mlx->screen.x, mlx->screen.y, 0x000F000A * mlx->zn.n);
			mlx->screen.y = mlx->screen.y + 1;
		}
		mlx->screen.x = mlx->screen.x + 1;
	}
}

int		mouse(int key, int x, int y, t_global *mlx)
{
	x = (double) x;
	y = (double) y;
	mlx->pos.x = x * (mlx->range.real_end - mlx->range.real_start) / WIDTH - mlx->range.real_end;
	mlx->pos.y = mlx->range.imaginary_end - y * (mlx->range.imaginary_end - mlx->range.imaginary_start) / HEIGHT;
	if (key == 4)
		ft_zoom_in(mlx);
	else if (key == 5)
		ft_zoom_out(mlx);
	// ft_mandelbrot(mlx);
	return (0);
}

int	fractal(int key, t_global *mlx)
{
	mlx->screen.x = 0;
	ft_init(mlx);
	if (key == 46)
		ft_mandelbrot(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->image->img, 0, 0);
	return (key);
}

int	infinity(t_global *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	mlx->screen.x = 0;
	while (mlx->screen.x < WIDTH)
	{
		mlx->screen.y = 0;
		while (mlx->screen.y < HEIGHT)
		{
			ft_mandelbrot(mlx);
			mlx->screen.y++;
		}
		mlx->screen.x++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->image->img, 0, 0);
	return (0);
}

int	main()
{
	t_global	*mlx;

	mlx = (t_global *) malloc(sizeof(t_global));
	mlx->image = (t_image_data *) malloc(sizeof(t_image_data));
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "Fractol Made By Muguiwarra");
	mlx->image->img = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->image->addr = mlx_get_data_addr(mlx->image->img, &mlx->image->bits_per_pixel,
										&mlx->image->line_length, &mlx->image->endian);
	mlx_mouse_hook(mlx->mlx_win, mouse, mlx);
	mlx_hook(mlx->mlx_win, 2, 1L << 2, fractal, mlx);
	mlx_loop_hook(mlx->mlx_ptr, infinity, mlx);
	mlx_loop(mlx->mlx_ptr);
}