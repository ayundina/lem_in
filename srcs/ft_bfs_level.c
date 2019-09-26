/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bfs_level.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/15 14:08:02 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/15 14:08:07 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_bfs_level() function uses bredth first search to set levels to rooms in
**	the given graph, starting from the end room. That way looking at the level
**	of rooms that directly connected to the start we'll see the connection that
**	is closest to the end.
**	A room can have a number of connections. To speed up the shortest path
**	searching, connections of each room are sorted in accending order based
**	on its level. Then to discover a new shortest path we'll know that picking
**	the first connection from the array of connections will compose the shortest
**	path to the end.
**
**	New leveling is done after each new discovered path. Rooms of the path are
**	set to visited and won't be taken for any other path, their level
**	in ft_bfs_level() function will be set to 100 and in sorting function they
**	will be moved to the last indexes of the array of connections.
**
**	take start room
**	add the room to q_unvisited
**	while q_unvisited
**		current_room = first in q_unvisited
**		current_level = current_room->level
**		pop current_room from q_unvisited
**		push current_room in q_visited
**		(don't push end_room to visited, I want end_room to have the max level)
**		while current_room connections
**			if connection is not in q_visited \
**				&& connection is not in q_unvisited \
**				&& connection->visited == false (it's not in one of the paths)
**				connection->level = current_connection + 1;
**				add connection to q_unvisited;
**			if connection->visited = true \
**				(it's in one of the paths and I want to ignore that room \
**				in future paths discovery)
**				connection->level = 100;
**		ft_sort_connections_in_accending(room_arr, current_room->index)
**	sort connections of start room (because it was't added to any q, so it\
**	wasn't sorted);
**	free both q;
**
**
**	Param 1: t_lem *lem is a struct that holds all the necessary data
**	about the given map with ants, rooms, connections and later generated
**	possible paths for the execution.
**
**	Param 2: int next is an index to traverse q. Given as 0.
**
**	Param 3: int curr_level is a level to assign. Given as 0.
**
**	Param 4: int i is an index to traverse connections of rooms. Given as 0.
**
**	Returns: none.
*/

void		ft_bfs_level(t_lem *lem, int next, int curr_level, int i)
{
	t_room	**q_unvisited;
	t_room	**q_visited;
	t_room	*curr_room;

	ft_initialize_q(&q_visited, &q_unvisited, lem);
	while (q_unvisited[next] != NULL)
	{
		curr_level = ft_assign_room_level_n_q(&curr_room, &q_unvisited[next], \
												&q_visited[next]);
		i = 0;
		while (i < N_CONNECTIONS)
		{
			if (!ft_visited_n_is_in_q(curr_room->edges[i], q_visited, \
									q_unvisited, lem->map->num_rooms))
			{
				curr_room->edges[i]->level = curr_level + 1;
				ft_push_to_q(&q_unvisited[next + 1], curr_room->edges[i], lem);
			}
			ft_set_level_for_visited(&curr_room);
			i++;
		}
		ft_sort_connections(&lem->map->room_arr, curr_room->index);
		next++;
	}
	ft_start_n_free_q(&q_visited, &q_unvisited, lem);
}
