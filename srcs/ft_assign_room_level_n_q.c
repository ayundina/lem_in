/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_assign_room_level_n_q.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:05:39 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:05:42 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_assign_room_level_n_q() function pops a room from q_unvisited and
**	pushes it to q_visited, that assignes to curr_room and it's level to level.
**
**
**	Param 1: t_room **curr_room is a pointer to a pointer to a room.
**
**	Param 2: t_room **q_unvisited is a pointer to the next room in q_unvisited.
**
**	Param 2: t_room ***q_visited is a pointer to the next room in q_visited.
**
**	Returns: level of the next room in q_unvisited.
*/

int		ft_assign_room_level_n_q(t_room **curr_room, t_room **q_unvisited, \
									t_room **q_visited)
{
	int	level;

	*curr_room = *q_unvisited;
	level = (*curr_room)->level;
	*q_unvisited = NULL;
	*q_visited = *curr_room;
	return (level);
}
