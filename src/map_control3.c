/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:53:11 by bsen              #+#    #+#             */
/*   Updated: 2024/05/16 15:46:15 by bsen             ###   ########.fr       */
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
				data->player_x = i;
				data->player_y = j;
			}
			j++;
		}
		i++;
	}
}
void	path_finding(char **map, int px, int py, t_data *data)
{
	int	x;
	int	y;

	x = py;
	y = px;
	if (map[x][y] == 'E' || map[x][y] == 'C')
		data->collect--;
	if (map[x][y - 1] != '1')
		path_finding(map, y, x - 1, data);
	if (map[x][y + 1] != '1')
		path_finding(map, y, x + 1, data);
	if (map[x - 1][y] != '1')
		path_finding(map, y - 1, x, data);
	if (map[x + 1][y] != '1')
		path_finding(map, y + 1, x, data);
}
