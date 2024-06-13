/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:28:54 by bsen              #+#    #+#             */
/*   Updated: 2024/05/30 13:39:44 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	map_name_control(char *map_name)
{
	int	i;

	i = ft_strlen(map_name);
	if (map_name[i - 1] != 'r' && map_name[i - 2] != 'e'
		&& map_name[i - 3] != 'b' && map_name[i - 4] != '.')
		return (1);
	return (0);
}

char	**read_map_length(t_data *data, char *str)
{
	char	vrmap;
	int		ret;
	int		length;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		exit_err("Error\nfd Error", data);
	length = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, &vrmap, 1);
		if (ret == -1)
		{
			close(fd);
			exit_err("Error\nRead Error", data);
		}
		length += ret;
	}
	close(fd);
	return (read_map(data, length, str));
}

char	**read_map(t_data *data, int length, char *str)
{
	char	**vmap;
	char	*map;
	int		i;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		exit_err("Error\nRead Error", data);
	map = malloc(length + 1 * (sizeof(char)));
	if (!map)
	{
		close(fd);
		exit_err("Error\nMalloc Error", data);
	}
	i = 1;
	i = read(fd, map, length + 1);
	close(fd);
	if (i == -1)
		exit_err("Error\nRead Error", data);
	map[i] = '\0';
	vmap = ft_split(map, '\n');
	if (!vmap)
		exit_err("Error/nMalloc Error", data);
	data->read_map = ft_strdup(map);
	return (free(map), vmap);
}

void	map_controls(char *map, t_data *data)
{
	char	**vmap;

	if (nl_control(map) == 1)
		exit_err("Error\nMap is wrong", data);
	if (map_wall_control(data->map, data) == 1)
		exit_err("Error\nMap is wrong", data);
	if (length_control(data->map_x, data->map) == 1)
		exit_err("Error\nMap is wrong", data);
	if (collect_control(data->map) == 1)
		exit_err("Error\nMap is wrong", data);
	if (chr_count(map, 'P') != 1)
		exit_err("Error\nMap is wrong", data);
	if (chr_count(map, 'E') != 1)
		exit_err("Error\nMap is wrong", data);
	vmap = ft_split(map, '\n');
	if (!vmap)
		exit_err("Error\nMalloc Error", data);
	p_finding(data, data->map);
	path_finding(vmap, data->player_y, data->player_x, data);
	ft_free(vmap);
	if (data->collectebles != 0)
		exit_err("Error\nMap is wrong", data);
}
