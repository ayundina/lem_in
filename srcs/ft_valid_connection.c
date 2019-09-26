/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_valid_connection.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:27:45 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:27:48 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_valid_connection() function determines if a connection of the given room
**	can lead to the end room of the given graph.
**
**	Param 1: t_room **path is an array of rooms that forms a path from start
**	room to the finish (end) room.
**
**	Param 2: t_room *room is a room connections of which are being checked.
**
**	Param 3: int *i is a pointer to an index of the given room connection.
**
**	Param 4: int max_len is a max lengths allowed for the path. It is the max
**	level * 3.
**
**	Returns: 1 if connection can lead to the end of the graph, 0 otherwise.
*/

int	ft_valid_connection(t_room **path, t_room *room, int *i, int max_len)
{
	while (room->edges[*i] != NULL)
	{
		if (room->level != 0 \
			&& room->edges[*i] != NULL \
			&& room->edges[*i]->visited == false \
			&& room->edges[*i]->level - 1 <= room->level \
			&& room->path_col + 1 < max_len && room->path_col != 0 \
			&& !ft_is_in_path(path, room->edges[*i]))
			return (1);
		else
			(*i)++;
	}
	return (0);
}
