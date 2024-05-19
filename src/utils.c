/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:06:28 by bsen              #+#    #+#             */
/*   Updated: 2024/05/19 14:35:10 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"
#include "../minilibx/mlx.h"

void	exit_err(char *str, t_data *data)
{
	if (data->map)
		ft_free(data->map);
	if (data->read_map)
		free(data->read_map);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
void	init_mlx(t_data *data)
{
	int	x;
	int	y;

	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->map_x * 64,
			data->map_y * 64, "so_long");
	data->player = mlx_xpm_file_to_image(data->mlx,
			"./textures/player.xpm", &x, &y);
	data->exit = mlx_xpm_file_to_image(data->mlx,
			"./textures/exit.xpm", &x, &y);
	data->collect = mlx_xpm_file_to_image(data->mlx,
			"./textures/collect.xpm", &x, &y);
	data->wall = mlx_xpm_file_to_image(data->mlx,
			"./textures/wall.xpm", &x, &y);
	data->background = mlx_xpm_file_to_image(data->mlx,
			"./textures/floor.xpm", &x, &y);
	if (!data->player || !data->exit || !data->collect
		|| !data->wall || !data->background)
		mlx_exit(data);
}
void mlx_exit(t_data *data)
{
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->collect)
		mlx_destroy_image(data->mlx, data->collect);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->background)
		mlx_destroy_image(data->mlx, data->background);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	exit_err("Error\nMlx Error", data);

}
void render(t_data *data)
{
	int x;
	int y;

	mlx_clear_window(data->mlx, data->mlx_win);
	y = -1;
	while (++y < data->map_y)
	{
		x = -1;
		while (++x < data->map_x)
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
						data->wall, x * 64, y * 64);
			else if (data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
						data->background, x * 64, y * 64);
			else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
						data->collect, x * 64, y * 64);
			else if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
						data->exit, x * 64, y * 64);
			else if (data->map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
						data->player, x * 64, y * 64);
	}
}
