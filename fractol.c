/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 02:40:16 by nabboune          #+#    #+#             */
/*   Updated: 2023/03/15 05:06:59 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main()
{
	t_global	*mlx;

	mlx = (t_global *) malloc(sizeof(t_global));
	if (!mlx)
		return (0);
	if (!ft_init_alloc(mlx))
		return (0);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "Fractol Made By Muguiwarra");
	mlx->image->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->image->addr = mlx_get_data_addr(mlx->image->img, &mlx->image->bits_per_pixel,
										&mlx->image->line_length, &mlx->image->endian);
	mlx_hook(mlx->win, 2, 1L << 2, fractal, mlx);
	mlx_mouse_hook(mlx->win, mouse, mlx);
	mlx_loop_hook(mlx->ptr, infinity, mlx);
	mlx_loop(mlx->ptr);
}
