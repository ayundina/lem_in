/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_start_n_free_q.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:09:37 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:09:40 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_start_n_free_q() function set levels of visited connections
**	of start room to 100. Sorts connections of start room and frees qs.
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

void	ft_start_n_free_q(t_room ***q_visited, t_room ***q_unvisited, \
							t_lem *lem)
{
	ft_set_level_for_visited(&lem->map->room_arr[lem->map->start_room_ind]);
	ft_sort_connections(&lem->map->room_arr, lem->map->start_room_ind);
	ft_free_arr_of_rooms(q_visited);
	ft_free_arr_of_rooms(q_unvisited);
}
