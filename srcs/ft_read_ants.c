/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_ants.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/15 13:29:05 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/15 13:29:12 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_read_ants() function reads from a given file the number of ants
**	and checks if the input is correct - only one number and
**	a new line character.
**
**	Param 1: t_lem *lem is a struct that holds all the necessary data
**	about the given map with ants, rooms, connections and later generated
**	possible paths for the execution.
**
**	Param 2: char *line is a pointer to a string to save a line from
**	the given file.
**
**	Returns: none or error message and exits if an error occurred
*/

void	ft_read_ants(t_lem *lem, char *line)
{
	if (get_next_line(lem->fd_read, &line) == 1)
	{
		if (!line)
			exit(ft_printf("lem-in ERROR: get_next_line failed\n"));
		lem->num_ants = ft_atoi(line);
		if (lem->num_ants <= 0 \
			|| line[ft_num_len_base(lem->num_ants, 10)] != '\0')
		{
			exit(ft_printf("lem-in ERROR: invalid map - no ants\n"));
		}
		ft_printf("%s\n", line);
		ft_strdel(&line);
	}
	else
	{
		exit(ft_printf("Usage: ./lem-in < valid_map.file\n"));
	}
}
