/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_malloc_paths.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:28:42 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:28:47 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_malloc_paths() function allocates memory space for an array of paths,
**	where one path is an array of rooms and where room is a pointer to the
**	t_room struct.
**
**	Param 1: t_room ****paths is a pointer to an array of paths.
**
**	Param 2: int num_paths is the number of paths for which a memory space needs
**	to be allocated.
**
**	Param 3: int path_len is a length for each path that needs to be allocated.
**
**	Returns: none.
*/

void	ft_malloc_paths(t_room ****paths, int num_paths, int path_len)
{
	int	i;

	i = 0;
	ft_malloc_pointer_to_arr_of_rooms(paths, num_paths);
	while (i < num_paths)
	{
		ft_malloc_arr_of_rooms(&(*paths)[i], path_len, 0);
		ft_malloc_room(&(*paths)[i][0]);
		i++;
	}
}
