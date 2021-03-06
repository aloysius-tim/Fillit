/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:35 by tkeynes           #+#    #+#             */
/*   Updated: 2017/11/17 11:18:38 by tkeynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H
# define NB_BASICS 19

static char const g_basics[NB_BASICS][21] =
{
	"#...\n#...\n#...\n#...\n",
	"####\n....\n....\n....\n",
	"##..\n##..\n....\n....\n",
	"#...\n#...\n##..\n....\n",
	"..#.\n###.\n....\n....\n",
	"##..\n.#..\n.#..\n....\n",
	"###.\n#...\n....\n....\n",
	".#..\n.#..\n##..\n....\n",
	"###.\n..#.\n....\n....\n",
	"##..\n#...\n#...\n....\n",
	"#...\n###.\n....\n....\n",
	"##..\n.##.\n....\n....\n",
	".#..\n##..\n#...\n....\n",
	".##.\n##..\n....\n....\n",
	"#...\n##..\n.#..\n....\n",
	".#..\n###.\n....\n....\n",
	"###.\n.#..\n....\n....\n",
	"#...\n##..\n#...\n....\n",
	".#..\n##..\n.#..\n....\n"
};

#endif
