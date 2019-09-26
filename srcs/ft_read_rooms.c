/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_rooms.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/15 12:50:20 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/15 12:50:28 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_is_numeric() function checks if a string has only numeric values
**	ended by a space or end of line character.
**
**	Param 1: char *str is a string to check for numeric characters.
**
**	Returns: 1 if a string is numeric, 0 if other characters are encountered.
*/

static int	ft_is_numeric(char *str)
{
	if (str == NULL)
		return (0);
	while (*str != '\0' && *str != ' ')
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/*
**	ft_copy_room() function creates a new struct with the room data,
**	copies the name of the room and creates a unique hashed index
**	based on the rooms name. The unique hashed index is used to place room into
**	an array of rooms without collisions.
**	It keeps account of the highest array index to allocate enough space to fit
**	all the rooms.
**	ft_copy_room() checks for correct input of given room format:
**	"room coordinate_X coordinate_Y".
**
**	Param 1: t_map **map is a struct which holds data about the given map.
**
**	Param 2: char *line is a line from the given file.
**
**	Returns: none or error message and exits if an error occurred.
*/

static void	ft_copy_room(t_map **map, char *line)
{
	char	*x_coord;
	char	*y_coord;
	char	*cut;
	t_room	*tmp;

	if (line[0] == '\0')
		exit(ft_printf("lem-in ERROR: invalid room - room is a new line\n"));
	tmp = (*map)->room_list;
	ft_malloc_room(&(*map)->room_list);
	(*map)->room_list->name = ft_strdup(line);
	cut = ft_strchr((*map)->room_list->name, ' ');
	x_coord = cut + 1;
	y_coord = ft_strrchr(cut, ' ') + 1;
	if (x_coord == y_coord || !ft_is_numeric(x_coord) \
		|| !ft_is_numeric(y_coord))
	{
		exit(ft_printf("lem-in ERROR: invalid room coordinate - %s\n", line));
	}
	ft_memset((void *)cut, '\0', ft_strlen(cut));
	(*map)->room_list->index = ft_hash((*map)->room_list->name, \
										&(*map)->arr_size);
	(*map)->room_list->next = tmp;
}

/*
**	ft_start_or_end() function checks if "##start" or "##end" room comment
**	is present in the line.
**
**	Param 1: int fd is a file descriptor to read a line from for get_next_lene()
**
**	Param 2: char **line is a line from given file
**
**	Param 3: bool *start_room becomes true if a "##start" room comment
**	was encountered. Which means the next room mentioned after the comment
**	is a start room.
**
**	Param 4: bool *end_room becomes true if a "##end" room comment
**	was encountered. Which means the next room mentioned after the comment
**	is an end room.
**
**	Returns: none or error message and exits if an error occurred
*/

static void	ft_start_or_end(int fd, char **line, bool *start_room, \
							bool *end_room)
{
	if ((*line)[0] == '#' && (*line)[1] == '#' \
		&& (*line)[2] == 's' && !ft_strcmp(*line, "##start"))
	{
		*start_room = true;
		ft_printf("%s\n", *line);
		ft_strdel(line);
		if (get_next_line(fd, line) != 1)
			exit(ft_printf("lem-in ERROR: get_next_line failed\n"));
	}
	else if ((*line)[0] == '#' && (*line)[1] == '#' \
				&& (*line)[2] == 'e' && !ft_strcmp(*line, "##end"))
	{
		*end_room = true;
		ft_printf("%s\n", *line);
		ft_strdel(line);
		if (get_next_line(fd, line) != 1)
			exit(ft_printf("lem-in ERROR: get_next_line failed\n"));
	}
	else if ((*line)[0] == '#')
	{
		ft_printf("%s\n", *line);
		ft_strdel(line);
	}
}

/*
**	ft_copy_start_or_end() copies start and end room array indexes into a map
**	struct to have easy access to those rooms later
**
**	Param 1: t_map *map is a struct which holds an info about the map.
**
**	Param 2: bool *start_room is true if a "##start" room comment
**	was encountered. Which means the next room mentioned after the comment
**	is a start room.
**
**	Param 3: bool *end_room is true if a "##end" room comment
**	was encountered. Which means the next room mentioned after the comment
**	is an end room.
**
**	Returns: none or error message and exits if an error occurred
*/

static void	ft_copy_start_or_end(t_map *map, bool *start_room, bool *end_room)
{
	if (*start_room == true)
	{
		map->start_room_ind = map->room_list->index;
		*start_room = false;
	}
	else if (*end_room == true)
	{
		map->end_room_ind = map->room_list->index;
		*end_room = false;
	}
}

/*
**	ft_read_rooms() function reads from a given file the rooms
**	of the map - vertices of the graph, and saves the data in a "map" struct.
**	In ft_copy_room () it creates a linked list of all the rooms and each room
**	receives a unique hashed index number to be placed in an array
**	without collisions.
**	When the function reads a new line of an input it prints it to stdout.
**	ft_read_rooms() counts the number of rooms to allocate enough memory
**	for queue in bfs leveling function.
**	The function checks if it reads the "start" or the "end" room
**	to save their array indexes in the "map" struct to have quick
**	access to these rooms.
**	When all rooms (vertices) are copied in a linked list and
**	a line with a connection (edge) encountered (room_1-room_2), all rooms are
**	placed into array and ft_read_connections() is called
**
**	Param 1: t_lem *lem is a struct that holds all the necessary data
**	about the given map with ants, rooms, connections and later generated
**	possible paths for the execution.
**
**	Param 2: char *line is a pointer to a string to save a line from
**	the given file.
**
**	Param 3: bool start_room to keep in mind if "##start" room comment was
**	encountered and the room after the comment is the start (source) room.
**
**	Param 4: bool end_room to keep in mind if "##end" room comment was
**	encountered and the room after the comment is the finish (sink) room.
**
**	Returns: none or error message and exits if an error occurred
*/

void		ft_read_rooms(t_lem *lem, char *line, bool start_room, \
							bool end_room)
{
	while (get_next_line(lem->fd_read, &line) == 1)
	{
		if (!line)
			exit(ft_printf("lem-in ERROR: get_next_line failed\n"));
		if (line[0] == 'L')
			exit(ft_printf("lem-in ERROR: invalid map - L-room: %s\n", line));
		if (ft_strchr(line, '-'))
		{
			ft_rooms_into_array(lem);
			ft_read_connections(line, lem);
			return ;
		}
		ft_start_or_end(lem->fd_read, &line, &start_room, &end_room);
		if (line && line[0] == '#' && (start_room == true || end_room == true))
			exit(ft_printf("lem-in ERROR: invalid map - ##start or ##end \
							followed by no room\n"));
		if (line)
		{
			ft_printf("%s\n", line);
			ft_copy_room(&lem->map, line);
			lem->map->num_rooms++;
			ft_strdel(&line);
		}
		ft_copy_start_or_end(lem->map, &start_room, &end_room);
	}
}
