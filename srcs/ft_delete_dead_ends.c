/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_delete_dead_ends.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/15 13:47:37 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/15 13:47:39 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_clear_n_free(t_room **room)
{
	ft_strdel(&(*room)->name);
	free((*room)->edges);
	(*room)->index = 0;
	free(*room);
	*room = NULL;
}

static void	ft_delete_from_connections(t_room *room, t_room *to_delete)
{
	int	i;

	i = 0;
	while (i < N_CONNECTIONS)
	{
		if (room->edges[i] == to_delete)
		{
			room->edges[i] = NULL;
			return ;
		}
		i++;
	}
}

/*
**	ft_delete_room() function deletes a given room from the connections of
**	the rooms the given room connected to. And frees the given room.
**
**	Param 1: t_room **room is a pointer to a room pointer.
**
**	Returns: none.
*/

static int	ft_delete_room(t_room **room)
{
	int	i;

	i = 0;
	while (i < N_CONNECTIONS)
	{
		if ((*room)->edges && (*room)->edges[i] != NULL)
		{
			ft_delete_from_connections((*room)->edges[i], (*room));
			ft_clear_n_free(&(*room));
			return (1);
		}
		else if ((*room)->edges == NULL)
		{
			ft_clear_n_free(&(*room));
			return (1);
		}
		i++;
	}
	return (0);
}

/*
**	ft_delete_dead_ends() function deletes those rooms that has only one
**	connection and not start or end room.
**	Ideally a room should have two connections: one connection that led to
**	the room, second, that leads to the next room. If there is only one
**	connection - we came to a dead end.
**	Deletion has to be done in iterations until the number of deleted rooms in
**	one iteration won't equal zero, that will mean there are no more rooms with
**	one connection.
**
**	Param 1: t_map *map is a struct that holds data about the given graph.
**
**	Param 2: int arr_size is maximum index value in an array of given rooms.
**
**	Param 3: int deleted is a number of rooms deleted within one iteration.
**
**	Returns: none.
*/

void		ft_delete_dead_ends(t_map *map, int arr_size, int i, \
								int deleted)
{
	int	j;
	int	connection;

	while (i <= arr_size)
	{
		connection = 0;
		if (map->room_arr[i] != NULL)
		{
			j = 0;
			while (j < N_CONNECTIONS)
			{
				if (map->room_arr[i]->edges != NULL \
					&& map->room_arr[i]->edges[j] != NULL)
					connection++;
				j++;
			}
			if (connection <= 1 \
				&& map->room_arr[i]->index != map->start_room_ind \
				&& map->room_arr[i]->index != map->end_room_ind)
				deleted += ft_delete_room(&map->room_arr[i]);
		}
		i++;
	}
	if (deleted > 0)
		ft_delete_dead_ends(map, arr_size, 0, 0);
}
