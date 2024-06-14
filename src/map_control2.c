/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:52:11 by bsen              #+#    #+#             */
/*   Updated: 2024/05/30 13:50:46 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	nl_control(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (1);
		i++;
	}
	if (map[0] == '\n')
		return (1);
	return (0);
}

int	map_wall_control(char **map, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map[0][++j])
		if (map[0][j] != '1')
			return (1);
	while (map[++i])
		if (map[i][0] != '1' || map[i][j - 1] != '1')
			return (1);
	j = -1;
	while (map[i - 1][++j])
		if (map[i - 1][j] != '1')
			return (1);
	data->map_x = j;
	data->map_y = i;
	return (0);
}

int	length_control(int x, char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != x)
			return (1);
		i++;
	}
	return (0);
}

int	collect_control(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'C' && map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	collectebles(char **map, t_data *data)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		exit_err("Error\nThere is no collectebles", data);
	data->collectebles = count + 1;
	data->cc = count;
}
