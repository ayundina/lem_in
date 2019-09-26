/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malloc_arr_of_rooms.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:29:43 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:29:45 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_malloc_arr_of_rooms() function allocates memory space for an array of
**	pointers.
**
**	Param 1: t_room ***arr is a pointer to an array where space for the array
**	needs to be allocated.
**
**	Param 2: int num rooms is the size of a space needs to be allocated.
**
**	Param 3: bool check_nedded is a check nedded for arrays a space for which
**	was already allocated, but those arrays can be sent to this function again.
**	Such case appears in ft_read_connections.c
**
**	Returns: none or error message and exits if an error occurred.
*/

void	ft_malloc_arr_of_rooms(t_room ***arr, int num_rooms, bool check_needed)
{
	if (*arr == NULL && check_needed)
		*arr = (t_room **)ft_memalloc(sizeof(t_room *) * (num_rooms + 2));
	if (!check_needed)
		*arr = (t_room **)ft_memalloc(sizeof(t_room *) * (num_rooms + 2));
	if (!*arr)
		exit(ft_printf("lem-in ERROR: malloc failed\n"));
}
