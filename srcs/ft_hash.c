/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hash.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ayundina <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/15 13:41:47 by ayundina      #+#    #+#                 */
/*   Updated: 2019/09/15 13:41:51 by ayundina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	ft_hash() function creates a unique hashed index based on the rooms name
**	and keeps accountant of the highest index, so rooms can be saved
**	in an array.
**	It lowers the assci value in order to lower the number of taken bits
**	(5 bits instead of 8 for four characters name)
**	in order to lower the final index value.
**	The idea is to combine each first 5 bits of each character into one binary
**	set to generate an unsigned int.
**	It is done by shifting bits to the left, to give space to then copy new set
**	of bits from a character.
**
**
**	Example:
**	Room name: "Wjh0"
**
**	->	1st char: 'W'
**	char before lowering ascii value:	'W' = ascii: 87 = binary 1010111
**	char with lowered ascii value:		' ' = ascii: 32 = binary: 100000
**
**	index before shift = decimal:		0		= binary: 0
**	index after shift = decimal:		0		= binary: 0
**
**	index after copied bits of a char = 32		= binary: 100000
**
**
**	->	2nd char: 'j'
**	char before lowering ascii value:	'j' = ascii: 106	= binary 1101010
**	char with lowered ascii value:		'-' = ascii: 45		= binary: 101101
**
**	index before shift = decimal:		32		= binary: 100000
**	index after shift = decimal:		1024	= binary: 10000000000
**
**	index after copied bits of a char = 1069	= binary: 10000101101
**
**	->	3rd char: 'h'
**	char before lowering ascii value:	'h' = ascii: 104	= binary 1101000
**	char with lowered ascii value:		'+' = ascii: 43		= binary: 101011
**
**	index before shift = decimal:		1069	= binary: 10000101101
**	index after shift = decimal:		34208	= binary: 1000010110100000
**
**	index after copied bits of a char = 34187	= binary: 1000010110001011
**
**	->	4th char: '0'
**	char before lowering ascii value:	'0' = ascii: 48		= binary 110000
**	char with lowered ascii value:		''	= ascii: 0		= binary: 0
**
**	index before shift = decimal:		34187	= binary: 1000010110001011
**	index after shift = decimal:		1093984	= binary: 100001011000101100000
**
**	index after copied bits of a char = 1093984	= binary: 100001011000101100000
**
**
**	Param 1: char *s is a string with a name of a room.
**
**	Param 2: unsigned int *greatest_ind is a pointer to int that holds the
**	highest index so far.
**
**	Returns: hashed index.
*/

int	ft_hash(char *s, unsigned int *greatest_ind)
{
	unsigned	index;
	char		c;
	int			i;

	i = 0;
	index = 0;
	while (s[i] && i < 4)
	{
		c = s[i];
		if (ft_isdigit(c))
			c -= 48;
		else if (c >= 'A' && c <= 'Z')
			c -= 55;
		else if (c >= 'a' && c <= 'z')
			c -= 61;
		else
			c = 62;
		index <<= 5;
		index ^= c;
		i++;
	}
	if (greatest_ind != NULL && index > *greatest_ind)
		*greatest_ind = index;
	return (index);
}
