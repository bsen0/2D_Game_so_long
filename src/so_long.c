/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:47:53 by bsen              #+#    #+#             */
/*   Updated: 2024/05/17 14:05:26 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include "minilibx/mlx.h"

static void	start_game(char *map_name, t_data *data)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		exit_err("Error\nRead Error", data);
	close(fd);
	data->map = read_map_length(data, map_name);
	collectebles(data->map, data);
	map_controls(data->read_map,data);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		exit_err("Error\nMlx Error", data);
	data->mlx_win = mlx_new_window(data->mlx, data->map_x * 64, data->map_y * 64, "so_long");
	if (data->mlx_win == NULL)
		exit_err("Error\nMlx Error", data);


}
int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	av++;
	map_name_control(*av);
	start_game(*av, &data);
	ft_free(data.map);
	free(data.read_map);
}
