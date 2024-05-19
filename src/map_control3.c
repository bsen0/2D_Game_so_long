/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:53:11 by bsen              #+#    #+#             */
/*   Updated: 2024/05/19 14:31:07 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"
#include "../minilibx/mlx.h"

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
		data->collectebles--;
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

int keyboard(int key, t_data *data)
{
	if (key == 53)
		exit(0);
	else if (key == 13 && data->map[data->player_y - 1][data->player_x] != '1')
		data->player_y--;
	else if (key == 1 && data->map[data->player_y + 1][data->player_x] != '1')
		data->player_y++;
	else if (key == 0 && data->map[data->player_y][data->player_x - 1] != '1')
		data->player_x--;
	else if (key == 2 && data->map[data->player_y][data->player_x + 1] != '1')
		data->player_x++;
	else
		return (0);
	ft_putstr_fd("Player moves:", 1);
	ft_putnbr_fd(++data->mc, 1);
	ft_putchar_fd('\n', 1);
	if (data->map[data->player_y][data->player_x] == 'C')
	{
		data->map[data->player_y][data->player_x] = '0';
		--data->cc;
	}
	if (data->map[data->player_y][data->player_x] == 'E' && data->cc == 0)
	{
		ft_putstr_fd("You win\n", 1);
		exit(0);
	}
	return (0);
}	
int	put_xml(t_data *data)
{
	render(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->player,
		data->player_x * 64, data->player_y * 64);
	return (0);
}
