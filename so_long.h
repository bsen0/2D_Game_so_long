/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:44:42 by bsen              #+#    #+#             */
/*   Updated: 2024/05/16 14:55:38 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>

typedef struct s_data
{
	char **map;
	char *read_map;
	int map_y;
	int map_x;
	int collect;
	int player_x;
	int player_y;
	int exit_x;
	int exit_y;
} t_data;

void map_name_control(char *map_name);
void exit_err(char *str, t_data *data);
int map_wall_control(char **map, t_data *data);
int nl_control(char *map);
void map_controls(char *map,char **map2, t_data *data);
char **read_map(t_data *data, int length, char *str);
char **read_map_length(t_data *data, char *str);
void map_name_control(char *map_name);
int length_control(int x, char **map);
int	collect_control(char **map);
int chr_count(char *map, char c);
void collectebles(char **map, t_data *data);
void path_finding(char **map, int x, int y, t_data *data);
void P_finding(t_data *data, char **map);


#endif
