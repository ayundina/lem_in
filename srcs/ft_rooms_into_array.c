/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rooms_into_array.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/15 13:31:52 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/15 13:31:56 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_rooms_into_array() function creates an array of all given rooms:
**	As we have already a linked list of rooms and each room has
**	a unique hashed index number, the function allocates the size of the array
**	according to the greatest hashed index to fit all the rooms.
**	A room is assigned to the array corresponding
**	to its unique hashed index number.
**	When all the rooms are in the array next function reads rooms connections.
**
**	Param 1: t_lem *lem is a struct that holds all the necessary data
**	about the given map with ants, rooms, connections and later generated
**	possible paths for the execution.
**
**	Returns: none.
*/

void	ft_rooms_into_array(t_lem *lem)
{
	t_room	*tmp_room;

	tmp_room = lem->map->room_list;
	ft_malloc_arr_of_rooms(&lem->map->room_arr, lem->map->arr_size, 0);
	if (!lem->map->room_arr)
		exit(ft_printf("lem-in ERROR: malloc failed\n"));
	while (tmp_room != NULL)
	{
		if (lem->map->room_arr[tmp_room->index] == NULL)
		{
			lem->map->room_arr[tmp_room->index] = tmp_room;
		}
		tmp_room = tmp_room->next;
	}
}
