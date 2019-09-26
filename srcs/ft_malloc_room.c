/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malloc_room.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:31:33 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:31:35 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_malloc_room() function allocates memory space for a t_room struct.
**
**	Param 1: t_room **room is a pointer to a pointer to t_room struct.
**
**	Returns: none or error an message and exits if an error occurred.
*/

void	ft_malloc_room(t_room **room)
{
	*room = (t_room *)ft_memalloc(sizeof(t_room));
	if (!*room)
		exit(ft_printf("lem-in ERROR: malloc failed\n"));
}
