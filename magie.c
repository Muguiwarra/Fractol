/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magie.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:56:55 by nabboune          #+#    #+#             */
/*   Updated: 2023/03/16 09:09:01 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_where_the_magie_happen_for_mandelbrot(t_global *mlx)
{
	while ((mlx->zn->real * mlx->zn->real + mlx->zn->imaginary
			* mlx->zn->imaginary <= 4) && mlx->zn->n < 100)
	{
		mlx->zn->tmp = mlx->zn->real * mlx->zn->real
			+ mlx->complex->real - mlx->zn->imaginary
			* mlx->zn->imaginary;
		mlx->zn->imaginary = 2 * mlx->zn->real * mlx->zn->imaginary
			+ mlx->complex->imaginary;
		mlx->zn->real = mlx->zn->tmp;
		mlx->zn->n = mlx->zn->n + 1;
	}
}

void	ft_where_the_magie_happen_for_julia(t_global *mlx)
{
	while ((mlx->zn->real * mlx->zn->real + mlx->zn->imaginary
			* mlx->zn->imaginary <= 4) && mlx->zn->n < 100)
	{
		mlx->zn->tmp = mlx->zn->real * mlx->zn->real
			+ mlx->complex->real - mlx->zn->imaginary
			* mlx->zn->imaginary;
		mlx->zn->imaginary = 2 * mlx->zn->real * mlx->zn->imaginary
			+ mlx->complex->imaginary;
		mlx->zn->real = mlx->zn->tmp;
		mlx->zn->n = mlx->zn->n + 1;
	}
}

void	ft_where_the_magie_happen_for_tricorn(t_global *mlx)
{
	while ((mlx->zn->real * mlx->zn->real + mlx->zn->imaginary
			* mlx->zn->imaginary <= 4) && mlx->zn->n < 100)
	{
		mlx->zn->tmp = mlx->zn->real * mlx->zn->real
			+ mlx->complex->real - mlx->zn->imaginary
			* mlx->zn->imaginary;
		mlx->zn->imaginary = -2 * mlx->zn->real * mlx->zn->imaginary
			+ mlx->complex->imaginary;
		mlx->zn->real = mlx->zn->tmp;
		mlx->zn->n = mlx->zn->n + 1;
	}
}

void	ft_where_the_magie_happen_for_burning_ship(t_global *mlx)
{
	while ((mlx->zn->real * mlx->zn->real + mlx->zn->imaginary
			* mlx->zn->imaginary <= 4) && mlx->zn->n < 100)
	{
		mlx->zn->tmp = mlx->zn->real * mlx->zn->real
			+ mlx->complex->real - mlx->zn->imaginary
			* mlx->zn->imaginary;
		mlx->zn->imaginary = fabs(2 * mlx->zn->real
				* mlx->zn->imaginary) + mlx->complex->imaginary;
		mlx->zn->real = mlx->zn->tmp;
		mlx->zn->n = mlx->zn->n + 1;
	}
}
