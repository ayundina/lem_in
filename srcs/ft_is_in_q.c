/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_is_in_q.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 14:59:48 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 14:59:51 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_is_in_q() function checks if withing the maximum number of rooms
**	(num_rooms) in q (array of rooms) the given room is found.
**
**	Param 1: t_room **q is an array of rooms.
**
**	Param 2: t_room *room is a room to search for in the given q.
**
**	Param 3: int num_rooms is a max numbers of rooms in the given q.
**
**	Returns: 1 if given room is in given q, returns 0 otherwise.
*/

int		ft_is_in_q(t_room **q, t_room *room, int num_rooms)
{
	int	i;

	i = 0;
	while (q[i] == NULL)
	{
		if (i == num_rooms + 1)
			return (0);
		i++;
	}
	while (q[i] != NULL)
	{
		if (q[i] == room)
			return (1);
		i++;
	}
	return (0);
}
