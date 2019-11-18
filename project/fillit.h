/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:27:54 by vvaltone          #+#    #+#             */
/*   Updated: 2019/11/11 14:06:48 by vvaltone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

typedef struct	s_map
{
	char		**array;
}				t_map;

typedef struct	s_block
{
	char			pieceletter;
	int				piececoords[8];
	int				offset_x;
	int				offset_y;
	struct s_block	*next;
}				t_block;

int				adjacency_counter(char *buf);
int				charcount(char *buf);
int				check_boundaries(t_block *piece, int map_size, char axis);
int				overlap(t_map *map, t_block *piece);
int				square_root(int num);
int				solve_fillit(t_map *map, t_block *piecelist, int map_size);
int				valid(char *buf, int size);
size_t			count_pieces(t_block *piecelist);
t_block			*move_to_topleft(t_block *piece);
t_block			*createpiece(char *buf, char pieceletter);
t_block			*createlist(char *buf, int size);
t_block			*parser(char *filename);
t_map			*new_map(int size);
void			free_map(t_map *map, int map_size);
void			free_piecelist(t_block *list);
void			move_x(t_block *piece, int n);
void			move_y(t_block *piece, int y);
void			print_map(t_map *map, int size);
void			place(t_block *piece, t_map *map, char letter);
void			solve(t_block *piecelist);

#endif
