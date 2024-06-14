/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:44:42 by bsen              #+#    #+#             */
/*   Updated: 2024/05/29 18:20:52 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_data
{
	char	**map;
	char	*read_map;
	int		map_y;
	int		map_x;
	int		collectebles;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		mc;
	int		cc;
	void	*mlx;
	void	*player;
	void	*exit;
	void	*collect;
	void	*wall;
	void	*background;
	void	*mlx_win;

}			t_data;

void		exit_err(char *str, t_data *data);
int			map_wall_control(char **map, t_data *data);
int			nl_control(char *map);
void		map_controls(char *map, t_data *data);
char		**read_map(t_data *data, int length, char *str);
char		**read_map_length(t_data *data, char *str);
int			map_name_control(char *map_name);
int			length_control(int x, char **map);
int			collect_control(char **map);
int			chr_count(char *map, char c);
void		collectebles(char **map, t_data *data);
void		path_finding(char **map, int x, int y, t_data *data);
void		p_finding(t_data *data, char **map);
void		ft_free(char **str);
void		init_mlx(t_data *data);
void		mlx_exit(t_data *data, int i);
int			keyboard(int key, t_data *data);
int			put_xml(t_data *data);
void		render(t_data *data);
int			close_window(t_data *data);

#endif
