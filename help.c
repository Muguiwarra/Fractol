/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:53:55 by nabboune          #+#    #+#             */
/*   Updated: 2023/03/16 08:58:49 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_verification(char **av)
{
	if ((ft_strncmp(av[1], "Mandelbrot", 11) != 0) && (ft_strncmp(av[1],
				"Julia", 6) != 0) && (ft_strncmp(av[1], "Tricorn", 8) != 0)
		&& (ft_strncmp(av[1], "Burning Ship", 13) != 0))
	{
		ft_error();
		exit(0);
	}
}

void	ft_parse(char **av, t_global *mlx)
{
	if (ft_strncmp(av[1], "Mandelbrot", 11) == 0)
		mlx->fractal = &ft_mandelbrot;
	else if (ft_strncmp(av[1], "Julia", 6) == 0)
		mlx->fractal = &ft_julia;
	else if (ft_strncmp(av[1], "Tricorn", 8) == 0)
		mlx->fractal = &ft_tricorn;
	else if (ft_strncmp(av[1], "Burning Ship", 13) == 0)
		mlx->fractal = &ft_burning_ship;
}

void	ft_error(void)
{
	ft_printf("\e[1;1H\e[2J");
	ft_printf("\033[0;33m");
	ft_printf("\t\t==> FRACTOL <==\n");
	ft_printf("\033[0m");
	ft_printf("\033[0;31m");
	ft_printf("PLEASE ENTER A VALID ARGUMENT !\n");
	ft_printf("\033[0m");
	ft_printf("\033[0;36m");
	ft_printf("You'll find bellow a list of valid fractals \
		that can be passed as an argument :\n");
	ft_printf("\033[0m");
	ft_printf("\033[0;32m");
	ft_printf("\t==> Mandelbrot\n");
	ft_printf("\t==> Julia\n");
	ft_printf("\t==> Tricorn\n");
	ft_printf("\t==> Burning Ship\n");
	ft_printf("\033[0m");
}

int	keybord(int key, t_global *mlx)
{
	if (key == 46 || key == 38 || key == 11 || key == 17)
		fractals(key, mlx);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		move_screen(key, mlx);
	else if (key == 49)
		ft_init(mlx);
	else if (key == 53)
		ft_close(mlx);
	else if (key == 8)
	{
		mlx->color_out = rand();
		mlx->color_in = rand();
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->image->img, 0, 0);
	return (1);
}

void	move_screen(int key, t_global *mlx)
{
	double	mv;

	mv = (mlx->range->real_end - mlx->range->real_start) / 10;
	if (key == 123)
	{
		mlx->range->real_start += mv;
		mlx->range->real_end += mv;
	}
	else if (key == 124)
	{
		mlx->range->real_start -= mv;
		mlx->range->real_end -= mv;
	}
	else if (key == 125)
	{
		mlx->range->imaginary_start -= mv;
		mlx->range->imaginary_end -= mv;
	}
	else if (key == 126)
	{
		mlx->range->imaginary_start += mv;
		mlx->range->imaginary_end += mv;
	}
	mlx->fractal(mlx);
}
