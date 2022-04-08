/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:06:51 by mmanouze          #+#    #+#             */
/*   Updated: 2022/04/08 15:11:51 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_var *var, char *str)
{
	int		fd;
	char	*map;
	char	*take;

	take = NULL;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_error();
	map = get_next_line(fd);
	if (!map)
		ft_error();
	var->length = ft_strlen(map) - 1;
	while (map)
	{
		var->height++;
		if (ft_strcmp(map, "\n") == 0)
			ft_error();
		take = ft_strjoin(take, map);
		free(map);
		map = get_next_line(fd);
	}
	var->two = ft_split(take, '\n');
	free(take);
}

void	up_down_walls(t_var *var)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (var->two[0][i] == '1')
		i++;
	while (var->two[var->height - 1][a] == '1')
		a++;
	if (i != var->length || a != var->length)
		ft_error();
}

void	side_walls(t_var *var)
{
	int	i;
	int	k;

	k = 0;
	i = var->height - 1;
	while (i)
	{
		if (var->two[i][0] == '1' && var->two[i][var->length - 1] == '1')
			k++;
		i--;
	}
	if (k != var->height - 1)
		ft_error();
}

void	extra_2(t_var *var, int i, int j)
{
	if (var->two[i][j] == 'P')
			var->p++;
	else if (var->two[i][j] == 'C')
		var->c++;
	else if (var->two[i][j] == 'E')
		var->e++;
	else if (var->two[i][j] == '1' || var->two[i][j] == '0')
		var->o_i++;
}

void	map_elements(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (var->two[i][j])
	{
		if (var->two[i][j] == 'P' || var->two[i][j] == 'E'
			|| var->two[i][j] == 'C' || var->two[i][j] == '0'
			|| var->two[i][j] == '1')
			extra_2(var, i, j);
		else
			ft_error();
		j++;
		if (j == var->length && var->two[i + 1])
		{
			i++;
			j = 0;
		}
	}
	if (var->p != 1 || var->c == 0 || var->e == 0)
		ft_error();
}
