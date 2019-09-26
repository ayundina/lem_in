/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:58:16 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:58:19 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Working perfect with "big" map. Solves correctly 5 out of 10 on
**	"big-superposition"
**	Splited into more files. Single function per file.
**	Has unused functions and variables.
**	Norms are fixed for working functions
**	Test is almost OK
**	No leaks
**	Deleted unused variables from structs in header file
**	Deleted unused files
**
**	Fixed it with Lauris's map... and commented...
*/

#include "lem_in.h"

/*
**	main () function reads from a file given in stdin.
**	It reads ants, mallocs lem.map - is a struct, part of "lem" struct,
**	to save data about the given map saves rooms into an array.
**	Levels map from end to start
**	Builds paths from start room to end room.
**	Moves ants along those paths
**
**	Param 1: none
**
**	Returns: 0 if success, error message and exits if an error occurred
*/

int		main(void)
{
	int				start_edges;
	unsigned int	i;
	t_lem			lem;

	i = 0;
	lem.fd_read = 0;
	ft_read_ants(&lem, NULL);
	lem.map = (t_map *)ft_memalloc(sizeof(t_map));
	if (!lem.map)
		exit(ft_printf("lem-in ERROR: map malloc failed\n"));
	ft_read_rooms(&lem, NULL, false, false);
	if (!lem.map->room_arr)
		exit(ft_printf("lem-in ERROR: invalid map - no connections\n"));
	ft_bfs_level(&lem, 0, 0, 0);
	start_edges = ft_count_connections(lem.map->room_arr, \
										lem.map->start_room_ind);
	ft_malloc_paths(&lem.paths, start_edges, \
					lem.map->room_arr[lem.map->start_room_ind]->level * 3);
	ft_start_connections_paths(&lem, \
						lem.map->room_arr[lem.map->start_room_ind], \
						lem.map->room_arr[lem.map->start_room_ind]->level * 3);
	ft_printf("\n");
	ft_move_ants(lem.num_ants, lem.paths);
	ft_free_lem(&lem);
	return (0);
}
