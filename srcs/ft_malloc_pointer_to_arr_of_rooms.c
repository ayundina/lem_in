/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malloc_pointer_to_arr_of_rooms.c                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:30:29 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:30:31 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_malloc_pointer_to_arr_of_rooms() function allocates memory space for
**	a pointer to an array of rooms.
**
**	Param 1: t_room ****p is a pointer to an array of rooms.
**
**	Param 2: int size is a size needed to be allocated.
**
**	Returns: none or error an message and exits if an error occurred.
*/

void	ft_malloc_pointer_to_arr_of_rooms(t_room ****p, int size)
{
	*p = (t_room ***)ft_memalloc(sizeof(t_room **) * (size + 1));
	if (!*p)
		exit(ft_printf("lem-in ERROR: malloc failed\n"));
}
