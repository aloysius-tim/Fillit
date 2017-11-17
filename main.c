/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:17:32 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/17 11:17:35 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

static void	usage(void)
{
	write(2, "usage: ./fillit input_file\n", 27);
	exit(1);
}

int			main(int argc, char **argv)
{
	int		size;
	t_piece	pieces[27];

	if (argc != 2)
		usage();
	if ((size = parse(argv[1], pieces)) == 0)
		fillit_error();
	fill_it(pieces, size);
	return (0);
}
