/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:00:32 by mbui              #+#    #+#             */
/*   Updated: 2020/11/23 10:15:10 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include "libft/libft.h"

//delete
#include <stdio.h>

typedef struct s_point
{
	int x;
	int y;
} t_point;

typedef struct s_object
{
	int width;
	int height;
	char **tab;
	t_point pt;
} t_object;

typedef struct s_filler
{
	char me;
	char opp;
	t_object piece;
	t_object map;
	int score;
	t_point res;
} t_filler;

int main(void);
#endif
