/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_delete_current_room_from_path.c                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:37:43 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:37:47 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_delete_current_room_from_path() function removes the given room
**	(path[row][col]) from the given path (array of rooms that forms a path).
**
**	Param 1: t_room ***path is a pointer to a path where last room needs to be
**	deleted.
**
**	Param 2: int row refers to the path number.
**
**	Param 3: int last_col refers to the room in the path that needs
**	to be deleted.
**
**	Returns: none.
*/

void	ft_delete_current_room_from_path(t_room ***path, int row, int last_col)
{
	if (last_col >= 0)
	{
		if ((*path)[last_col] != NULL && (*path)[last_col]->path_row == row)
		{
			(*path)[last_col]->path_row = 0;
			(*path)[last_col]->path_col = 0;
		}
		if (last_col != 0)
		{
			(*path)[0]->path_col -= 1;
			(*path)[last_col] = NULL;
		}
		if (last_col == 2)
			ft_delete_current_room_from_path(path, row, last_col - 1);
	}
}
