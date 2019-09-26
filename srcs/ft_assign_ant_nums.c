/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_assign_ant_nums.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:48:20 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:48:22 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_assign_ant_nums () function finds the number of ants for each path
**	based on previously found number of steps.
**
**	Param 1: t_room ***paths is an array of paths where one path is an array
**	of rooms.
**
**	Returns: none.
*/

void	ft_assign_ant_nums(t_room ***paths)
{
	int	steps;
	int	i;

	steps = paths[0][0]->combo_eval;
	i = 0;
	while (paths[i] != NULL && paths[i][1] != NULL)
	{
		paths[i][0]->ant_num = steps - paths[i][0]->path_col + 2;
		i++;
	}
}
