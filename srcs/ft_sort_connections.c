/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_connections.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:13:17 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:13:20 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_sort_connections() function sorts in accending order connections
**	of the given room (index in array of rooms) based on their level.
**
**	Param 1: t_room ***room_arr is a pointer to an array of rooms.
**
**	Param 2: unsigned int room_i is an index in the array, a room,
**	connections of which needs to be sorted.
**
**	Returns: none.
*/

void	ft_sort_connections(t_room ***room_arr, unsigned int room_i)
{
	int		i;
	int		j;
	t_room	*tmp_edge;

	i = 0;
	while (i < N_CONNECTIONS)
	{
		j = i + 1;
		while (j < N_CONNECTIONS)
		{
			if ((*room_arr)[room_i]->edges[j] != NULL
				&& ((*room_arr)[room_i]->edges[i] == NULL \
					|| ((*room_arr)[room_i]->edges[i] != NULL \
						&& (*room_arr)[room_i]->edges[i]->level
						> (*room_arr)[room_i]->edges[j]->level)))
			{
				tmp_edge = (*room_arr)[room_i]->edges[i];
				(*room_arr)[room_i]->edges[i] = (*room_arr)[room_i]->edges[j];
				(*room_arr)[room_i]->edges[j] = tmp_edge;
			}
			j++;
		}
		i++;
	}
}
