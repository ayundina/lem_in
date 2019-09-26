/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_move_ants.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:53:47 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:53:50 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_move_ants() function assignes a number of ants to each path that has been
**	discoverd and moves the ants along the paths.
**
**	Param 1: int num_ants is a number of ants given to lead through the given
**	graph.
**
**	Param 2: t_room ***paths is an array of paths found.
**
**	Returns: none.
*/

void	ft_move_ants(int num_ants, t_room ***paths)
{
	ft_assign_ant_nums(paths);
	ft_make_moves(paths, num_ants, 0, 0);
}
