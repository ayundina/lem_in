/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_count_connections.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:38:46 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:38:48 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_count_connections() function counts the number of connections of
**	the given room.
**
**	Param 1: t_room **room_arr is an array of rooms.
**
**	Param 2: int room_ind is an index in the array, a room,
**	connections of which needs to be counted.
**
**	Returns: number of connections.
*/

int		ft_count_connections(t_room **room_arr, int room_ind)
{
	int	i;
	int	num_connections;

	i = 0;
	num_connections = 0;
	while (room_arr[room_ind] != NULL && room_arr[room_ind]->edges != NULL \
			&& room_arr[room_ind]->edges[i] != NULL)
	{
		num_connections++;
		i++;
	}
	return (num_connections);
}
