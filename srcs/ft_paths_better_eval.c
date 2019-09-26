/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_paths_better_eval.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:46:30 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:46:32 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_paths_better_eval() function counts the number of steps it will take to
**	lead the given number of ants through the given paths.
**	First it counts the number of ants per path where paths[0][0]->path_row
**	refers to the number of given paths.
**	paths[row][0]->path_col refers to the length of the path.
**	In a while loop the function counts the sum of steps through all the paths,
**	and ft_count_steps counts the final number of steps.
**	If the new number of steps is less or equal to previous and the number
**	of rooms in last added path is less or equal to the number of steps
** a new evaluation of steps replaces the previous
**
**	Param 1: t_room ***paths is an array of paths, where one path is an array
**	of rooms.
**
**	Param 2: int num_ants is the number of ants given to lead through the graph.
**
**	Returns: 1 if the new combination of paths gives smaller or same number of
**	steps comparing to the previous combination, 0 otherwise.
*/

int		ft_paths_better_eval(t_room ***paths, int num_ants)
{
	int	row;
	int	steps;
	int	ants_per_path;
	int	ants_per_path_remain;

	row = 0;
	ants_per_path = num_ants / (paths[0][0]->path_row + 1);
	ants_per_path_remain = num_ants % (paths[0][0]->path_row + 1);
	steps = paths[row][0]->path_col + ants_per_path + ants_per_path_remain - 2;
	while (paths[row + 1] != NULL && paths[row + 1][1] != NULL)
	{
		row++;
		steps += paths[row][0]->path_col + ants_per_path - 2;
	}
	steps = ft_count_steps_per_path(steps, paths[0][0]->path_row + 1);
	if ((steps <= paths[0][0]->combo_eval
			&& steps >= paths[paths[0][0]->path_row][0]->path_col)
		|| paths[0][0]->combo_eval == 0)
	{
		paths[0][0]->combo_eval = steps;
		return (1);
	}
	return (0);
}
