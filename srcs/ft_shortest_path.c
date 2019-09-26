/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_shortest_path.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:26:48 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:26:50 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_shortest_path() is a recursive function with backtracking that moves from
**	given room to its connections and so on till it reaches the end room of
**	the given graph. If the end wasn't reached and there are no way further,
**	the last room will be deleted from the path and further search
**	will be continued.
**
**	Param 1: t_room **path is a pointer to a path in the creation
**	or to be created.
**
**	Param 2: t_room *room is room to check its connections to continue
**	the search.
**
**	Param 3: int max_lem is the maximum length limitation for the path,
**	which is a max level of the graph multiplied by 3.
**
**	Returns: none.
*/

void	ft_shortest_path(t_room **path, t_room *room, int max_len)
{
	int	i;

	i = 0;
	while (ft_valid_connection(path, room, &i, max_len))
	{
		room->edges[i]->path_col = room->path_col + 1;
		room->edges[i]->path_row = room->path_row;
		path[0]->path_col = room->edges[i]->path_col;
		path[room->edges[i]->path_col] = room->edges[i];
		if (room->edges[i]->level != 0)
			room->edges[i]->visited = true;
		ft_shortest_path(path, room->edges[i], max_len);
		if (path[path[0]->path_col]->level == 0)
			return ;
		i++;
	}
	if (path[path[0]->path_col]->level != 0 \
		&& room->edges[i + 1] == NULL)
	{
		ft_delete_current_room_from_path(&path, room->path_row, room->path_col);
	}
}
