/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:47:53 by bsen              #+#    #+#             */
/*   Updated: 2024/05/19 13:50:43 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include "../minilibx/mlx.h"

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
	init_mlx(data);
	render(data);
	mlx_hook(data->mlx_win, 2, 0, keyboard, data);
	mlx_hook(data->mlx_win, 17, 0, close_window, data);
	mlx_loop_hook(data->mlx, put_xml, data);
	mlx_loop(data->mlx);


}
int	close_window(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_exit(data);
	return (0);
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
