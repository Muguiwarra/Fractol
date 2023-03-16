/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:12:12 by nabboune          #+#    #+#             */
/*   Updated: 2023/03/16 08:56:00 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_image_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_init_alloc(t_global *mlx)
{
	mlx->image = (t_image_data *)malloc(sizeof(t_image_data));
	if (!mlx->image)
		return (free(mlx), 0);
	mlx->zn = (t_complex_n *)malloc(sizeof(t_complex_n));
	if (!mlx->zn)
		return (free(mlx->image), free(mlx), 0);
	mlx->complex = (t_complex_n *)malloc(sizeof(t_complex_n));
	if (!mlx->complex)
		return (free(mlx->image), free(mlx->zn), free(mlx), 0);
	mlx->range = (t_fractal_range *)malloc(sizeof(t_fractal_range));
	if (!mlx->range)
		return (free(mlx->image), free(mlx->zn), free(mlx->complex), free(mlx),
			0);
	mlx->screen = (t_pixel *)malloc(sizeof(t_pixel));
	if (!mlx->screen)
		return (free(mlx->image), free(mlx->zn), free(mlx->complex),
			free(mlx->range), free(mlx), 0);
	mlx->pos = (t_mouse_pos *)malloc(sizeof(t_mouse_pos));
	if (!mlx->pos)
		return (free(mlx->image), free(mlx->zn), free(mlx->complex),
			free(mlx->range), free(mlx->screen), free(mlx), 0);
	return (1);
}

void	ft_free_mlx(t_global *mlx)
{
	free(mlx->pos);
	free(mlx->screen);
	free(mlx->range);
	free(mlx->complex);
	free(mlx->zn);
	free(mlx->image);
	free(mlx);
}

void	ft_init(t_global *mlx)
{
	mlx->screen->x = -0.25;
	mlx->screen->y = -0.3;
	mlx->pos->x = 0;
	mlx->pos->x = 0;
	mlx->range->real_start = -2;
	mlx->range->real_end = 2;
	mlx->range->imaginary_start = -2;
	mlx->range->imaginary_end = 2;
	mlx->color_out = 0x000F000A;
	mlx->color_in = 0x00FFFFFF;
}

int	ft_close(t_global *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	ft_free_mlx(mlx);
	exit(0);
	return (0);
}
