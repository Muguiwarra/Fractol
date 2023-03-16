/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 02:40:16 by nabboune          #+#    #+#             */
/*   Updated: 2023/03/16 09:08:24 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_start(char **av, t_global *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT,
			"Fractol Made By Muguiwarra");
	mlx->image->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->image->addr = mlx_get_data_addr(mlx->image->img,
			&mlx->image->bits_per_pixel, &mlx->image->line_length,
			&mlx->image->endian);
	ft_parse(av, mlx);
	ft_init(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->image->img, 0, 0);
	mlx_mouse_hook(mlx->win, mouse, mlx);
	mlx_hook(mlx->win, 2, 1L << 2, keybord, mlx);
	mlx_hook(mlx->win, 6, 0L, julia_mouse, mlx);
	mlx_hook(mlx->win, 17, 0L, ft_close, mlx);
	mlx_loop_hook(mlx->ptr, infinity, mlx);
	mlx_loop(mlx->ptr);
}

int	main(int ac, char **av)
{
	t_global	*mlx;

	if (ac == 2)
	{
		mlx = (t_global *)malloc(sizeof(t_global));
		if (!mlx)
			return (0);
		if (!ft_init_alloc(mlx))
			return (0);
		ft_verification(av);
		ft_start(av, mlx);
	}
	ft_error();
	return (0);
}
