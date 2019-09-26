/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_initialize_q.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:06:58 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:07:03 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_initialize_q() function allocates memory q_visited and q_unvisited for
**	breadth first search leveling function. It assignes pushes end room to
**	q_unvisited to start leveling of the rooms.
**
**
**	Param 1: t_room ***q_visited is a pointer to an array of visited rooms.
**
**	Param 2: t_room ***q_unvisited is a pointer to an array of unvisited rooms.
**
**	Param 3: t_lem *lem is a struct that holds all the necessary data
**	about the given map with ants, rooms, connections and later generated
**	possible paths for the execution.
**
**	Returns: none.
*/

void	ft_initialize_q(t_room ***q_visited, t_room ***q_unvisited, t_lem *lem)
{
	*q_unvisited = NULL;
	*q_visited = NULL;
	ft_malloc_arr_of_rooms(q_unvisited, lem->map->num_rooms, 0);
	ft_malloc_arr_of_rooms(q_visited, lem->map->num_rooms, 0);
	(*q_unvisited)[0] = lem->map->room_arr[lem->map->end_room_ind];
}
