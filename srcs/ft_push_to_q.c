/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push_to_q.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 14:59:13 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 14:59:16 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_push_to_q() function adds given room to given q (array of rooms).
**	The function will ignore the starting room of the given graph.
**
**	Param 1: t_room **q is an array of rooms.
**
**	Param 2: t_room *room is a room to add to given q.
**
**	Param 3: t_lem *lem is a struct that holds all the necessary data
**	about the given map with ants, rooms, connections and later generated
**	possible paths for the execution.
**
**	Returns: none.
*/

void	ft_push_to_q(t_room **q, t_room *room, t_lem *lem)
{
	int	i;

	i = 0;
	if (room != lem->map->room_arr[lem->map->start_room_ind])
	{
		while (q[i] != NULL)
		{
			i++;
		}
		q[i] = room;
	}
}
