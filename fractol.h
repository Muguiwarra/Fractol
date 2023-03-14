/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 01:04:35 by nabboune          #+#    #+#             */
/*   Updated: 2023/03/14 05:33:20 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1000
# define HEIGHT 1000

# include "Libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
#include <stdio.h>

typedef struct s_image_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image_data;

typedef struct s_complex_n
{
	int	n;
	double	tmp;
	double	real;
	double	imaginary;
}				t_complex_n;

typedef struct	s_pixel
{
	double		x;
	double		y;
}				t_pixel;

typedef struct	s_complex
{
	double		real;
	double		imaginary;
}				t_complex;

typedef struct	s_fractal_range
{
	double	real_start;
	double	real_end;
	double	imaginary_start;
	double	imaginary_end;
}				t_fractal_range;

typedef struct	s_mouse_pos
{
	double	x;
	double	y;
	double	zoom;
	double	x_tmp;
	double	y_tmp;
}				t_mouse_pos;

typedef struct	s_global
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_image_data	*image;
	t_complex_n		zn;
	t_complex		complex;
	t_fractal_range	range;
	t_pixel			screen;
	t_mouse_pos		pos;
}				t_global;

#endif