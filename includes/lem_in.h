/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 12:45:01 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/18 12:45:03 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/ft_printf/libftprintf.h"

# define N_CONNECTIONS 100
# define MAX_PATHS 1023

typedef struct		s_room
{
	unsigned int	index;
	char			*name;
	struct s_room	**edges;
	struct s_room	*next;
	int				combo_eval;
	int				level;
	int				path_row;
	int				path_col;
	int				ant_num;
	bool			visited;
}					t_room;

typedef struct		s_map
{
	unsigned int	start_room_ind;
	unsigned int	end_room_ind;
	t_room			*room_list;
	unsigned int	arr_size;
	unsigned int	num_rooms;
	t_room			**room_arr;
}					t_map;

typedef struct		s_lem
{
	int				fd_read;
	int				num_ants;
	t_map			*map;
	t_room			***paths;
}					t_lem;

void				ft_read_ants(t_lem *lem, char *line);

void				ft_read_rooms(t_lem *lem, char *line, bool start_room,
									bool end_room);
void				ft_rooms_into_array(t_lem *lem);

void				ft_read_connections(char *line, t_lem *lem);

int					ft_hash(char *s, unsigned int *greatest_ind);

void				ft_delete_dead_ends(t_map *map, int arr_size, int i,
										int deleted);
void				ft_bfs_level(t_lem *lem, int next, int curr_level, int i);

void				ft_push_to_q(t_room **q, t_room *room, t_lem *lem);

int					ft_is_in_q(t_room **q, t_room *room, int num_rooms);

void				ft_set_level_for_visited(t_room **room);

int					ft_assign_room_level_n_q(t_room **curr_room,
									t_room **q_unvisited, t_room **q_visited);
void				ft_initialize_q(t_room ***q_visited, t_room ***q_unvisited,
									t_lem *lem);
int					ft_visited_n_is_in_q(t_room *connection, t_room **q_visited,
										t_room **q_unvisited, int num_rooms);
void				ft_start_n_free_q(t_room ***q_visited,
										t_room ***q_unvisited, t_lem *lem);
void				ft_sort_connections(t_room ***room_arr,
										unsigned int room_i);
void				ft_start_connections_paths(t_lem *lem, t_room *room,
												int max_len);
void				ft_shortest_path(t_room **path, t_room *room, int max_len);

int					ft_valid_connection(t_room **path, t_room *room, int *i,
										int max_len);
void				ft_malloc_paths(t_room ****paths, int num_paths,
									int path_len);
void				ft_malloc_arr_of_rooms(t_room ***arr, int num_rooms,
											bool check_needed);
void				ft_malloc_pointer_to_arr_of_rooms(t_room ****p, int	size);

void				ft_malloc_room(t_room **room);

void				ft_free_arr_of_rooms(t_room ***arr);

void				ft_free_pointer_to_arr_of_rooms(t_room ****p);

void				ft_free_room(t_room **room);

void				ft_free_lem(t_lem *lem);

int					ft_is_in_path(t_room **path, t_room *room);

void				ft_delete_current_room_from_path(t_room ***path, int row,
														int last_col);
int					ft_count_connections(t_room **room_arr, int room_ind);

void				ft_delete_path(t_room ***path);

int					ft_count_steps_per_path(int steps_sum, int combo_n_paths);

int					ft_paths_better_eval(t_room ***paths, int num_ants);

void				ft_assign_ant_nums(t_room ***paths);

void				ft_move_ants(int num_ants, t_room ***paths);

void				ft_make_moves(t_room ***paths, int n_ants,
									int finished_ants, int last_ant_name);

#endif
