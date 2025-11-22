/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:37:51 by hqannouc          #+#    #+#             */
/*   Updated: 2025/11/18 16:54:46 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../includes/libft/libft.h"
# include "../includes/gnl/get_next_line.h"
# include <stdio.h>

# define ARGS_ERR "Invalid arguments"
# define EMPTY_ERR "Empty map / Empty lines"
# define WALL_ERR "Not surrounded by walls"
# define MAP_ERR "Incorrect map elements"
# define CUB_ERR "Not a \".cub\" file"
# define XPM_ERR "Not a \".xpm\" file"
# define FILE_ERR "File does not exist"
# define IMG_ERR "Incorrect image path/file"
# define CONFIG_ERR "Invalid config elements"

typedef struct s_pars
{
	char	*unsplit;
	int		f_is_set;
	int		c_is_set;
}	t_pars;

typedef struct s_scene
{
	char	*n_path;
	char	*s_path;
	char	*e_path;
	char	*w_path;
	int		f_color;
	int		c_color;
	char	**map;
	int		map_height;
	int		map_width;
	char	**map_pad;
	t_pars	*pars;
}	t_scene;

void			print_error(char *err);
void			error_exit(t_scene *scene, char *err);

int				is_space(char c);
void			skip_whitespace(char *line, int *i);
int				is_player(char c);
int				is_valid_element(char c);
int				ft_strstr_index(const char *big, const char *small);

void			cub_check(t_scene *scene, char *filename);
int				check_path(t_scene *scene, char *info);
char			*read_file_to_string(int fd);

char			**return_scene(t_scene *game, char *filename);
int				check_id_info(t_scene *scene, char *line);
int				get_scene_info(t_scene *scene, char *filename);
void			height_width(t_scene *scene);

int				validate_map(t_scene *scene, char **map);
char			**add_padding(t_scene scene);

#endif