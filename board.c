/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:17:02 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/17 11:17:05 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <limits.h>
#include <unistd.h>

int		init_board(t_board *board, int nb_pieces)
{
	int i;

	i = 0;
	while (i < BOARD_SIZE)
		board->self[i++] = '.';
	board->side_size = 2;
	while (board->side_size * board->side_size < nb_pieces * 2)
		board->side_size++;
	return (1);
}

void	print_board(t_board const *board)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (counter < board->side_size)
	{
		write(1, board->self + i, board->side_size);
		write(1, "\n", 1);
		i += BOARD_SIDE_SIZE;
		++counter;
	}
}
