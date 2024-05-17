/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:53:11 by bsen              #+#    #+#             */
/*   Updated: 2024/05/17 12:56:56 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"

int	chr_count(char *map, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (map[i] == c)
			count++;
		i++;
	}
	return (count);
}
void	P_finding(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
			}
			j++;
		}
		i++;
	}
}
void	path_finding(char **map, int x, int y, t_data *data)
{
	if (data->map[x][y] == 'E' || data->map[x][y] == 'C')
		data->collect--;
	if (data->map[x][y - 1] != '1' && map[x][y - 1] != '1')
	{
		map[x][y - 1] = '1';
		path_finding(map, x, y - 1, data);
	}
	if (data->map[x][y + 1] != '1' && map[x][y + 1] != '1')
	{
		map[x][y + 1] = '1';
		path_finding(map, x, y + 1, data);
	}
	if (data->map[x - 1][y] != '1' && map[x - 1][y] != '1')
	{
		map[x - 1][y] = '1';
		path_finding(map, x - 1, y, data);
	}
	if (data->map[x + 1][y] != '1' && map[x + 1][y] != '1')
	{
		map[x + 1][y] = '1';
		path_finding(map, x + 1, y, data);
	}
}
