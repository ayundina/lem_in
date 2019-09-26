/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_start_connections_paths.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:15:09 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:15:11 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_start_connections_paths() function takes first connection of the start
**	room and builds a path to the end room. "i" refers to an index
**	in an array of paths. If a path was impossible to create "i" will not be
**	incremented. Index 0 in each path is taken to store extra data about
**	the path: its length, number of ants that will be launched through that path
**	After a path is created, the discovered paths are evaluated on the number
**	of steps. The paths searching will stop when all start connections will
**	be visited or paths evaluation will give worse result than without last
**	discovered path.
**
**	Param 1: t_lem *lem is a struct that holds all the necessary data
**	about the given map with ants, rooms, connections and later generated
**	possible paths for the execution.
**
**	Param 2: t_room *room is a starting room of the given graph.
**
**	Param 3: int max_len is a max length allowed for the path. It is the max
**	level * 3.
**
**	Returns: none.
*/

void		ft_start_connections_paths(t_lem *lem, t_room *room, int max_len)
{
	int	i;

	i = 0;
	while (room->edges[0]->visited == false && lem->paths[i] != NULL)
	{
		lem->paths[0][0]->path_row = i;
		lem->paths[i][0]->path_col = 2;
		lem->paths[i][1] = room;
		lem->paths[i][2] = room->edges[0];
		room->edges[0]->visited = true;
		room->edges[0]->path_row = i;
		room->edges[0]->path_col = 2;
		ft_shortest_path(lem->paths[i], room->edges[0], max_len);
		ft_bfs_level(lem, 0, 0, 0);
		if (lem->paths[i][1] == NULL)
			lem->paths[0][0]->path_row -= 1;
		if (!ft_paths_better_eval(lem->paths, lem->num_ants))
		{
			ft_delete_path(&lem->paths[i]);
			return ;
		}
		if (lem->paths[i][1] != NULL)
			i++;
	}
}
