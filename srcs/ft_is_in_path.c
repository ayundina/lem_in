/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_is_in_path.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:35:54 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:35:56 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_is_in_path() function check if the given room is present in
**	the given path.
**
**	Param 1: t_room **paths is an array of rooms that forms a path from
**	the start to the end room of the given graph.
**
**	Param 2: t_room *room is a room to search for in the given path.
**
**	Returns: 1 if the room is found in the path, 0 otherwise.
*/

int		ft_is_in_path(t_room **path, t_room *room)
{
	int	col;

	col = 0;
	if (path != NULL)
	{
		while (path[col] != NULL)
		{
			if (path[col] == room)
				return (1);
			col++;
		}
	}
	return (0);
}
