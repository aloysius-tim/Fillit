/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:17:16 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/17 11:17:18 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define MAX_PIECES 26
# define BOARD_SIDE_SIZE 16
# define BOARD_SIZE 16 * 16

typedef struct	s_board
{
	char		*self;
	int			side_size;
}				t_board;

typedef int		t_piece[4];

int				init_board(t_board *board, int nb_pieces);
void			print_board(t_board const *board);
void			fillit_error(void);
int				is_in_list(char *tetri);
int				parse(char *path, t_piece tab_pieces[27]);
int				fill_it(t_piece *piece, int nb_pieces);

#endif
