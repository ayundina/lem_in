/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_pointer_to_arr_of_rooms.c                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:33:00 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:33:04 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_pointer_to_arr_of_rooms(t_room ****p)
{
	if (*p)
	{
		free(*p);
		*p = NULL;
	}
}
