/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_moves.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:54:57 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:55:01 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_beginning() function moves an ant from the start to the room that is next
**	to start room. It checks if a room is a room (not NULL) and has an ant and
**	there still should be ants sent through the paths ("last_ant_name" is an int
**	value that was assigned to an ant that was last to leave the start room,
**	so if "last_ant_name" number is equal to the given number of ants, it means
**	that all required ants are on their way to the end room and no need to move
**	any ants from the start). If the above statement is true the "last_ant_name"
**	is increased by one and written in a room after start room in the path.
**	At the same time, the number of ants assigned to the path
**	is decreased by one.
**	"last_ant_num" is assigned to ant_num in "room + 2" because "room + 2" equal
**	to 2nd index in the path (array of rooms). 0 index is a struct with
**	a number of ants to move through the path and index 1 is a start room.
**	Start room is a room where ants should actually be, but because of the start
**	room is present in all the found paths we won't use it to store values that
**	might differ for different paths.
**
**	Param 1: t_room ***path is a pointer to an array of rooms, a path.
**
**	Param 2: int room is a room in the path to check for an ant to move.
**
**	Param 3: int *last_ant_name is a pointer to a number that is the ant name
**	and equal to the number of ants that left the start room.
**
**	Param 4: int num_ants is the number of ants given to move from the start to
**	the end rooms in a graph.
**
**	Returns: none.
*/

void	ft_beginning(t_room ***path, int room, int *last_ant_name, \
						int num_ants)
{
	if ((*path)[room]->name == NULL && (*path)[room]->ant_num > 0 \
		&& *last_ant_name < num_ants)
	{
		(*last_ant_name) += 1;
		(*path)[room]->ant_num -= 1;
		(*path)[room + 2]->ant_num = *last_ant_name;
		ft_printf("L%d-%s ", (*path)[room + 2]->ant_num, \
					(*path)[room + 2]->name);
	}
}

/*
**	ft_middle_way() function deals with those ants that are passed the start
**	room and has a name assigned.
**	If the room is a room (not NULL) and it has an ant and the next room
**	is a room (was checked before it was sent here). Ant name will be written
**	in the next room and zeroed in the current room. The move will be printed
**	in stdout. If the next room is an end room number of finished ants will be
**	increased by one. If the number of the given ants will be equal to
**	the number of the ants that reached the finish the function will return 0
**	that means the process of moving ants have to terminate.
**
**	Param 1: t_room ***path is a pointer to an array of rooms, a path.
**
**	Param 2: int room is a room in the path to check for an ant to move.
**
**	Param 3: int num_ants is the number of ants given to move from the start to
**	the end rooms in a graph.
**
**	Param 4: int *finished_ants is a pointer to the number of ants the reached
**	the end room so far.
**
**	Returns: 0 if all the given ants have reached the end room, 1 otherwise.
*/

int		ft_middle_way(t_room ***path, int room, int num_ants, \
						int *finished_ants)
{
	if ((*path)[room]->name != NULL && (*path)[room]->ant_num > 0)
	{
		(*path)[room + 1]->ant_num = (*path)[room]->ant_num;
		(*path)[room]->ant_num = 0;
		ft_printf("L%d-%s ", (*path)[room + 1]->ant_num, \
					(*path)[room + 1]->name);
		if ((*path)[room + 2] == NULL)
		{
			(*finished_ants)++;
			if (*finished_ants == num_ants)
			{
				ft_printf("\n");
				return (0);
			}
		}
	}
	return (1);
}

/*
**	ft_make_moves() function traverse through all the given paths from end
**	to start and if an ant is present in the room (struct where an ant is
**	written as an int number, which is the name of the ant) it moves the ant to
**	the next room.
**	Index zero, in a path (array of rooms), is an additional struct to hold the
**	length of the path, its evaluation if it's the first path and the number of
**	ants that assigned to this path. When an ant is taken from the zero element
**	(index zero) of the path the number of ants in the zero element will be
**	decreased by one, the ant will receive its name (an int value) and this
**	value will be written in the room that is next after the start room.
**	The move will be printed in stdout as L<ant name>-<the room it moved to>.
**	within one step all the ants in all the paths will be moved one room
**	forward and new line character will be printed. The process will be repeated
**	until the given ants will reach the end room (number of finished ants will
**	be equal to the given ants).
**
**	Param 1: t_room ***paths is an array of paths to use to move ants through,
**	where a path is an array of rooms.
**
**	Param 2: int n_ants is a number of given ants to lead from start to end.
**
**	Param 3: int finished_ants is a number of ants that have reached
**	the end room. This value given to ft_make_moves() function as 0.
**
**	Param 4: int last_ant_name is a name of an ant. This value is given to
**	ft_make_moves() function as 0.
**
**	Returns: none.
*/

void	ft_make_moves(t_room ***paths, int n_ants, int finished_ants, \
						int last_ant_name)
{
	int	i;
	int	len;

	while (1)
	{
		i = 0;
		while (paths[i] != NULL && paths[i][1] != NULL)
		{
			len = paths[i][0]->path_col;
			while (len >= 0)
			{
				if (paths[i][len]->ant_num != 0 && paths[i][len + 1] != NULL)
				{
					ft_beginning(&paths[i], len, &last_ant_name, n_ants);
					if (!ft_middle_way(&paths[i], len, n_ants, &finished_ants))
						return ;
				}
				len--;
			}
			i++;
		}
		ft_printf("\n");
	}
}
