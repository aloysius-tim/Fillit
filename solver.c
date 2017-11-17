/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:08 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/17 11:18:11 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

void				fillit_error(void)
{
	write(1, "error\n", 6);
	exit(1);
}

static int			try_place(int index, t_piece piece, int point,
														t_board *board)
{
	if (((point + piece[0]) & (BOARD_SIDE_SIZE - 1)) >= board->side_size
			|| ((point + piece[1]) & (BOARD_SIDE_SIZE - 1)) >= board->side_size
			|| ((point + piece[2]) & (BOARD_SIDE_SIZE - 1)) >= board->side_size
			|| ((point + piece[3]) & (BOARD_SIDE_SIZE - 1)) >= board->side_size
			|| (point + piece[3]) / BOARD_SIDE_SIZE >= board->side_size
			|| board->self[piece[0] + point] != '.'
			|| board->self[piece[1] + point] != '.'
			|| board->self[piece[2] + point] != '.'
			|| board->self[piece[3] + point] != '.')
		return (0);
	board->self[piece[0] + point] = 'A' + index;
	board->self[piece[1] + point] = 'A' + index;
	board->self[piece[2] + point] = 'A' + index;
	board->self[piece[3] + point] = 'A' + index;
	return (1);
}

static void			remove(t_piece piece, int point, char *board)
{
	board[piece[0] + point] = '.';
	board[piece[1] + point] = '.';
	board[piece[2] + point] = '.';
	board[piece[3] + point] = '.';
}

static int			solve(int index, t_piece *pieces, int nb_pieces,
		t_board *board)
{
	int		point;
	int		i;
	int		board_size;

	if (index == nb_pieces)
		return (1);
	i = 0;
	board_size = board->side_size * board->side_size;
	while (i <= board_size)
	{
		point = (i % board->side_size)
			+ ((i / board->side_size) * BOARD_SIDE_SIZE);
		if (try_place(index, pieces[index], point, board))
		{
			if (solve(index + 1, pieces, nb_pieces, board))
				return (1);
			remove(pieces[index], point, board->self);
		}
		++i;
	}
	return (0);
}

int					fill_it(t_piece *pieces, int nb_pieces)
{
	t_board	board;
	char	actual_board[BOARD_SIZE];

	board.self = actual_board;
	if (!init_board(&board, nb_pieces))
		fillit_error();
	while (1)
	{
		if (solve(0, pieces, nb_pieces, &board))
			break ;
		++(board.side_size);
	}
	print_board(&board);
	return (0);
}
