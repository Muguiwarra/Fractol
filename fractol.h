/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 01:04:35 by nabboune          #+#    #+#             */
/*   Updated: 2023/03/16 08:57:08 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1000
# define HEIGHT 1000

# include "Libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_image_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_image_data;

typedef struct s_complex_n
{
	int				n;
	double			tmp;
	double			real;
	double			imaginary;
}					t_complex_n;

typedef struct s_pixel
{
	double			x;
	double			y;
}					t_pixel;

typedef struct s_fractal_range
{
	double			real_start;
	double			real_end;
	double			imaginary_start;
	double			imaginary_end;
}					t_fractal_range;

typedef struct s_mouse_pos
{
	double			x;
	double			y;
	double			zoom;
	double			tmp;
}					t_mouse_pos;

typedef struct s_global
{
	void			*ptr;
	void			*win;
	int				fractal_id;
	void			(*fractal)(struct s_global *);
	int				color_in;
	int				color_out;
	t_image_data	*image;
	t_complex_n		*zn;
	t_complex_n		*complex;
	t_fractal_range	*range;
	t_pixel			*screen;
	t_mouse_pos		*pos;
}					t_global;

void				ft_start(char **av, t_global *mlx);
void				ft_parse(char **av, t_global *mlx);
void				my_mlx_pixel_put(t_image_data *data, int x, int y,
						int color);
int					ft_init_alloc(t_global *mlx);
void				ft_init(t_global *mlx);
void				ft_free_mlx(t_global *mlx);
int					keybord(int key, t_global *mlx);
void				move_screen(int key, t_global *mlx);
void				fractals(int key, t_global *mlx);
void				ft_mandelbrot(t_global *mlx);
void				ft_julia(t_global *mlx);
void				ft_burning_ship(t_global *mlx);
void				ft_tricorn(t_global *mlx);
int					mouse(int key, int x, int y, t_global *mlx);
void				ft_zoom_in(t_global *mlx);
void				ft_zoom_out(t_global *mlx);
int					julia_mouse(int x, int y, t_global *mlx);
int					infinity(t_global *mlx);
int					ft_close(t_global *mlx);
void				ft_error(void);
void				ft_verification(char **av);
void				ft_where_the_magie_happen_for_mandelbrot(t_global *mlx);
void				ft_where_the_magie_happen_for_julia(t_global *mlx);
void				ft_where_the_magie_happen_for_burning_ship(t_global *mlx);
void				ft_where_the_magie_happen_for_tricorn(t_global *mlx);

#endif