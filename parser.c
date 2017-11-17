/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:17:48 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/17 11:17:52 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"

static void	move_piece(char *from, char *to)
{
	if (*to != '.')
		fillit_error();
	*to = *from;
	*from = '.';
}

static void	inplace_move(char *tetri)
{
	int i;
	int	j;
	int	x;

	i = 0;
	while (tetri[i] == '.' || tetri[i] == '\n')
		++i;
	j = i;
	while (j > 4)
		j -= 5;
	j = i - j;
	x = i % 5;
	i = -1;
	while (++i < 20)
	{
		if (tetri[i] == '#')
			x = ((i % 5 < x) ? i % 5 : x);
	}
	j += x;
	i = -1;
	while (++i < 20 && j)
	{
		if (tetri[i] == '#')
			move_piece(tetri + i, tetri + i - j);
	}
}

static void	table_to_index(char *table, t_piece piece)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 20)
	{
		if (table[i] == '#')
			piece[j++] = (i % 5) + (i / 5) * BOARD_SIDE_SIZE;
		++i;
	}
}

static int	file_to_buffer(int fd, char buffer[1024])
{
	int	size;

	size = read(fd, buffer, 1024);
	if (size < 0 || size > 545 || (size + 1) % 21 != 0)
	{
		close(fd);
		fillit_error();
	}
	return ((size + 1) / 21);
}

int			parse(char *path, t_piece tab_pieces[27])
{
	char	buffer[1024];
	int		fd;
	int		i;
	int		size;

	if ((fd = open(path, O_RDONLY)) == -1)
		fillit_error();
	size = file_to_buffer(fd, buffer);
	if (close(fd) == -1)
		fillit_error();
	i = 0;
	fd = 0;
	while (i < size)
	{
		inplace_move(buffer + fd);
		if (!is_in_list(buffer + fd))
			fillit_error();
		table_to_index(buffer + fd, tab_pieces[i]);
		fd += 21;
		++i;
	}
	return (i);
}
