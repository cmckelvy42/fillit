/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:02:50 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/02/26 14:29:47 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
#include "./libft/libft.h"

typedef struct		s_etris
{
	char			letter;
	int				x[4];
	int				y[4];
	struct s_etris	*next;
}					t_etris;

void				tetread(char *filename);
size_t				tetsize(int fd);
#endif
