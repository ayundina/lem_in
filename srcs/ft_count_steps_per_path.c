/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_count_steps_per_path.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:45:45 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:45:48 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_count_steps_per_path() function takes the sum of steps for
**	the combination of paths and divides it to the number of paths.
**	if the division has a decimal number, one more step is added.
**
**	Param 1: int steps_sum is a sum of steps for all paths.
**
**	Param 2: int combo_n_paths is a number of paths found.
**
**	Returns: the number of steps that it takes to lead given number of ants
**	through the given graph.
*/

int		ft_count_steps_per_path(int steps_sum, int combo_n_paths)
{
	int	steps;
	int	steps_remainder;

	steps = steps_sum / combo_n_paths;
	steps_remainder = steps_sum % combo_n_paths;
	if (steps_remainder != 0)
		steps += 1;
	return (steps);
}
