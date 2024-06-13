/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:47:53 by bsen              #+#    #+#             */
/*   Updated: 2024/05/30 13:57:50 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include "../so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void	start_game(char *map_name, t_data *data)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		exit_err("Error\nRead Error", data);
	close(fd);
	data->map = read_map_length(data, map_name);
	collectebles(data->map, data);
	map_controls(data->read_map, data);
	init_mlx(data);
	render(data);
	mlx_hook(data->mlx_win, 2, 0, keyboard, data);
	mlx_hook(data->mlx_win, 17, 0, close_window, data);
	mlx_loop_hook(data->mlx, put_xml, data);
	mlx_loop(data->mlx);
}

void	init_data(t_data *data)
{
	data->map = NULL;
	data->read_map = NULL;
	data->map_y = 0;
	data->map_x = 0;
	data->collectebles = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->exit_x = 0;
	data->exit_y = 0;
	data->mc = 0;
	data->cc = 0;
	data->mlx = NULL;
	data->player = NULL;
	data->exit = NULL;
	data->collect = NULL;
	data->wall = NULL;
	data->background = NULL;
	data->mlx_win = NULL;
}

int	close_window(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_exit(data, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_putstr_fd("Error\nMap name is missing\n", 2), 1);
	av++;
	init_data(&data);
	if (map_name_control(*av) == 1)
		exit_err("Error\nMap name is wrong\n", &data);
	start_game(*av, &data);
	ft_free(data.map);
	free(data.read_map);
}
