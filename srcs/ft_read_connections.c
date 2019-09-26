/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_connections.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/15 13:38:12 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/15 13:38:16 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_insert_new_edge() function adds a room (connection) to an array of edges
**	(connections). It first checks if the given room (connection) is already
**	present in the array.
**
**	Param 1: t_room ***edges is a pointer to array of edges (connections) where
**	a new room (connection) have to be added.
**
**	Param 2: t_room *room_to_connect is a new room (connection) that have to be
**	added to the array of edges.
**
**	Returns: none.
*/

static void	ft_insert_new_edge(t_room ***edges, t_room *room_to_connect)
{
	int	i;

	i = 0;
	while (i < N_CONNECTIONS)
	{
		if ((*edges)[i] == room_to_connect)
			return ;
		if ((*edges)[i] == NULL)
		{
			(*edges)[i] = room_to_connect;
			return ;
		}
		i++;
	}
}

/*
**	ft_malloc_n_copy_connection() function allocates an array of edges
**	(connections) for each room if it wasn't allocated before (the check if
**	an array needs to be allocated happens in ft_malloc_arr_of_rooms() function)
**	Then each room gets a copy of a room it connected to.
**
**	Param 1: t_lem *lem is a struct that holds all the necessary data
**	about the given map with ants, rooms, connections and later generated
**	possible paths for the execution.
**
**	Param 2: unsigned int room_one is an index of the first room in given edge
**	in the array of all given rooms.
**
**	Param 3: unsigned int room_two is an index of the first room in given edge
**	in the array of all given rooms.
**
**	Returns: none.
*/

static void	ft_malloc_n_copy_connection(t_lem *lem, unsigned room_one, \
										unsigned room_two)
{
	ft_malloc_arr_of_rooms(&lem->map->room_arr[room_one]->edges, \
							N_CONNECTIONS, 1);
	ft_malloc_arr_of_rooms(&lem->map->room_arr[room_two]->edges, \
							N_CONNECTIONS, 1);
	ft_insert_new_edge(&lem->map->room_arr[room_one]->edges, \
						lem->map->room_arr[room_two]);
	ft_insert_new_edge(&lem->map->room_arr[room_two]->edges, \
						lem->map->room_arr[room_one]);
}

/*
**	ft_copy_connections() function receives a line as "room_1-room_2" that
**	means that "room_1" is connected to "room_2". Both names of rooms are sent
**	to get their hashed index, that is index in the array of rooms.
** In ft_malloc_n_copy_connection() function for each room, array of
**	connections is allocated if it doesn't exist yet. And "room_1" is copied
**	into "room_2" array of edges and "room_2" is copied into "room_1" array
**	of edges.
**
**	Param 1: char *line is a pointer to a string to save a line from
**	the given file.
**
**	Param 2: t_lem *lem is a struct that holds all the necessary data
**	about the given map with ants, rooms, connections and later generated
**	possible paths for the execution.
**
**	Returns: none or error message and exits if an error occurred.
*/

static void	ft_copy_connections(char *line, t_lem *lem)
{
	char		**edge;
	unsigned	room_one;
	unsigned	room_two;

	edge = ft_strsplit(line, '-');
	if (edge[1] == NULL)
		exit(ft_printf("lem-in ERROR: invalid connection: %s\n", line));
	room_one = ft_hash(edge[0], NULL);
	room_two = ft_hash(edge[1], NULL);
	if (lem->map->room_arr[room_one] == NULL \
		|| lem->map->room_arr[room_two] == NULL)
		exit(ft_printf("lem-in ERROR: invalid connection: %s\n", line));
	ft_malloc_n_copy_connection(lem, room_one, room_two);
	ft_strdel(&edge[0]);
	ft_strdel(&edge[1]);
	free(edge);
	edge = NULL;
}

/*
**	ft_read_connections() function checks if previosly parsed rooms has start
**	and end rooms. The first encountered connection passed to
**	ft_read_connections() with "*line" variable.
**	Each room node has "**edges", which is array of rooms, array that holds
**	pointers to rooms. All the rooms saved only once in a linked list.
**	Other references to rooms are containing adresses of the rooms.
**	In ft_copy_connections() function line with connection is parsed and
** both rooms get a new edge in their array of edges
**	(edge is same as connection).
**	Check at the end of ft_read_connections() is if start and end room
**	are having connections.
**
**	Param 1: char *line is a pointer to a string to save a line from
**	the given file.
**
**	Param 2: t_lem *lem is a struct that holds all the necessary data
**	about the given map with ants, rooms, connections and later generated
**	possible paths for the execution.
**
**	Returns: none or error message and exits if an error occurred.
*/

void		ft_read_connections(char *line, t_lem *lem)
{
	ft_printf("%s\n", line);
	if ((lem->map->start_room_ind == 0 \
			&& lem->map->room_arr[lem->map->start_room_ind] == NULL) \
		|| (lem->map->end_room_ind == 0 \
			&& lem->map->room_arr[lem->map->end_room_ind] == NULL))
		exit(ft_printf("lem-in ERROR: invalid map - no start or end room\n"));
	ft_copy_connections(line, lem);
	ft_strdel(&line);
	while (get_next_line(lem->fd_read, &line) == 1)
	{
		if (!line)
			exit(ft_printf("lem-in ERROR: get_next_line failed\n"));
		ft_printf("%s\n", line);
		if (ft_strchr(line, '-'))
			ft_copy_connections(line, lem);
		ft_strdel(&line);
	}
	if (lem->map->room_arr[lem->map->start_room_ind]->edges == NULL \
		|| lem->map->room_arr[lem->map->end_room_ind]->edges == NULL)
		exit(ft_printf("lem-in ERROR: invalid map - start or end \
						is not connected\n"));
	ft_delete_dead_ends(lem->map, lem->map->arr_size, 0, 0);
}
