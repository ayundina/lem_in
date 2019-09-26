/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_delete_path.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 15:40:05 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/17 15:40:08 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_delete_path(t_room ***path)
{
	int	i;

	i = 1;
	(*path)[0]->combo_eval = 0;
	(*path)[0]->path_row = 0;
	(*path)[0]->path_col = 0;
	while ((*path)[i] != NULL)
	{
		(*path)[i] = NULL;
		i++;
	}
}
