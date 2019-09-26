/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_visited_n_is_in_q.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:08:08 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:08:10 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_visited_n_is_in_q() function if a given room (connection) is not in
**	a path (room->visited == false) is not in q_visited and is not in q_unvisted
**	and room is not NULL.
**
**	Param 1: t_room *connection is a room to check.
**
**	Param 2: t_room **q_visited is an array of visited rooms during breadth
**	first search leveling.
**
**	Param 3: t_room **q_unvisited is an array of unvisited rooms during breadth
**	first search leveling.
**
**	Param 4: int num_rooms is a size of q, the max index to check within.
**
**	Returns: 0 if given room (connection) is not in any of qs and path
**	and not NULL. Returns 1 otherwise.
*/

int		ft_visited_n_is_in_q(t_room *connection, t_room **q_visited, \
							t_room **q_unvisited, int num_rooms)
{
	if (connection != NULL \
		&& !ft_is_in_q(q_visited, connection, num_rooms) \
		&& !ft_is_in_q(q_unvisited, connection, num_rooms) \
		&& connection->visited == false)
	{
		return (0);
	}
	return (1);
}
