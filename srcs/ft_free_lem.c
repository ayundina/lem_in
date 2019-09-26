/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_lem.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:34:45 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:34:47 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_rooms(t_map **map)
{
	while ((*map)->arr_size != 0)
	{
		if ((*map)->room_arr[(*map)->arr_size] != NULL)
			ft_free_room(&(*map)->room_arr[(*map)->arr_size]);
		(*map)->arr_size--;
	}
	if ((*map)->room_arr[(*map)->arr_size] != NULL)
		ft_free_room(&(*map)->room_arr[(*map)->arr_size]);
}

void	ft_free_paths(t_room ****paths)
{
	int	row;
	int	col;

	row = 0;
	while ((*paths)[row] != NULL)
	{
		col = 0;
		while ((*paths)[row][col] != NULL)
		{
			if (col == 0)
				ft_free_room(&(*paths)[row][col]);
			(*paths)[row][col] = NULL;
			col++;
		}
		ft_free_arr_of_rooms(&(*paths)[row]);
		row++;
	}
	ft_free_pointer_to_arr_of_rooms(paths);
}

void	ft_free_lem(t_lem *lem)
{
	lem->num_ants = 0;
	ft_free_rooms(&lem->map);
	ft_free_arr_of_rooms(&lem->map->room_arr);
	ft_memset((void *)lem->map, 0, sizeof(t_map));
	free(lem->map);
	lem->map = NULL;
	ft_free_paths(&lem->paths);
}
