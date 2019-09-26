/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_arr_of_rooms.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:32:17 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:32:18 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_arr_of_rooms(t_room ***arr)
{
	if (*arr)
	{
		free(*arr);
		*arr = NULL;
	}
}
