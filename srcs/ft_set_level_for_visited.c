/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_set_level_for_visited.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:04:07 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:04:10 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_set_level_for_visited() function assignes a level = 100 to those
**	connections of the given room that are visited during the path searching.
**
**	Param 1: t_room **room is a pointer to a pointer to a room which connections
**	needs to be checked.
**
**	Returns: none.
*/

void	ft_set_level_for_visited(t_room **room)
{
	int	i;

	i = 0;
	while (i < N_CONNECTIONS)
	{
		if ((*room)->edges[i] != NULL \
			&& (*room)->edges[i]->visited == true)
		{
			(*room)->edges[i]->level = 100;
		}
		i++;
	}
}
