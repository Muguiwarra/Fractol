/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:05:54 by nabboune          #+#    #+#             */
/*   Updated: 2022/12/26 13:47:25 by nabboune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_m(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_substr_m(char *str, int start, int end)
{
	char	*ptr;
	int		i;

	if (!str)
		return (0);
	ptr = malloc((end - start + 2) * sizeof(char));
	if (ptr)
	{
		i = start;
		while (i < end)
		{
			ptr[i] = str[i];
			i++;
		}
		ptr[i++] = '\n';
		ptr[i] = '\0';
	}
	return (ptr);
}

char	*ft_newline(char *str, int index)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc((ft_strlen_m(str + index) + 1) * sizeof(char));
	index++;
	while (str[index])
		ptr[i++] = str[index++];
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strchr_m(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == '\0')
		return (-1);
	return (i);
}

void	ft_free(char *str)
{
	char	*tmp;

	tmp = str;
	if (str)
		free(str);
	tmp = 0;
}
