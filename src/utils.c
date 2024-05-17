/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:06:28 by bsen              #+#    #+#             */
/*   Updated: 2024/05/17 14:22:36 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../so_long.h"

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
void	*init_mlx(t_data *data)
{
	int	x;
	int	y;

	data->mlx_data->mlx = mlx_init();
	if (data->mlx_data->mlx == NULL)
		mlx_exit(data);
	data->mlx_data->player = mlx_xpm_file_to_image(data->mlx_data->mlx,
			"textures/ronaldo.xpm", &x, &y);
	data->mlx_data->exit = mlx_xpm_file_to_image(data->mlx_data->mlx,
			"textures/exit.xpm", &x, &y);
	data->mlx_data->collect = mlx_xpm_file_to_image(data->mlx_data->mlx,
			"textures/collect.xpm", &x, &y);
	data->mlx_data->wall = mlx_xpm_file_to_image(data->mlx_data->mlx,
			"textures/wall.xpm", &x, &y);
	data->mlx_data->background = mlx_xpm_file_to_image(data->mlx_data->mlx,
			"textures/floor.xpm", &x, &y);
	data->mlx_data->mlx_win = mlx_new_window(data->mlx_data->mlx, data->map_x
			* 64, data->map_y * 64, "so_long");
	if (!data->mlx_data->player || !data->mlx_data->exit || !data->mlx_data->collect
		|| !data->mlx_data->wall || !data->mlx_data->background || !data->mlx_data->mlx_win)
		mlx_exit(data);

}
void mlx_exit(t_data *data)
{
	if (data->mlx_data->player)
		mlx_destroy_image(data->mlx_data->mlx, data->mlx_data->player);
	if (data->mlx_data->exit)
		mlx_destroy_image(data->mlx_data->mlx, data->mlx_data->exit);
	if (data->mlx_data->collect)
		mlx_destroy_image(data->mlx_data->mlx, data->mlx_data->collect);
	if (data->mlx_data->wall)
		mlx_destroy_image(data->mlx_data->mlx, data->mlx_data->wall);
	if (data->mlx_data->background)
		mlx_destroy_image(data->mlx_data->mlx, data->mlx_data->background);
	if (data->mlx_data->mlx_win)
		mlx_destroy_window(data->mlx_data->mlx, data->mlx_data->mlx_win);
	if (data->mlx_data->mlx)
		mlx_destroy_display(data->mlx_data->mlx);
	exit_err("Error\nMlx Error", data);

}
void render(t_data *data)
{
	int x;
	int y;

	mlx_clear_window(data->mlx_data->mlx, data->mlx_data->mlx_win);
	y = -1;
	while (++y < data->map_y)
	{
		x = -1;
		while (++x < data->map_x)
		{
			if (data->map[x][y] == '1')
				mlx_put_image_to_window(data->mlx_data->mlx, data->mlx_data->mlx_win,
						data->mlx_data->wall, x * 64, y * 64);
			else if (data->map[x][y] == '0')
				mlx_put_image_to_window(data->mlx_data->mlx, data->mlx_data->mlx_win,
						data->mlx_data->background, x * 64, y * 64);
			else if (data->map[x][y] == 'C')
				mlx_put_image_to_window(data->mlx_data->mlx, data->mlx_data->mlx_win,
						data->mlx_data->collect, x * 64, y * 64);
			else if (data->map[x][y] == 'E')
				mlx_put_image_to_window(data->mlx_data->mlx, data->mlx_data->mlx_win,
						data->mlx_data->exit, x * 64, y * 64);
			else if (data->map[x][y] == 'P')
				mlx_put_image_to_window(data->mlx_data->mlx, data->mlx_data->mlx_win,
						data->mlx_data->player, x * 64, y * 64);
		}
	}
}
