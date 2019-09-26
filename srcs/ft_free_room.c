/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_room.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:33:51 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:33:55 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_free_room() function frees a t_room struct.
**
**	Param 1: t_room **room is a pointer to a t_room struct pointer.
**
**	Returns: none.
*/

void	ft_free_room(t_room **room)
{
	if (*room)
	{
		ft_strdel(&(*room)->name);
		ft_free_arr_of_rooms(&(*room)->edges);
		(*room)->next = NULL;
		ft_memset((void *)(*room), 0, sizeof(t_room));
		(*room)->visited = false;
		free(*room);
		*room = NULL;
	}
}
