/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:15:48 by hanebaro          #+#    #+#             */
/*   Updated: 2024/06/26 17:36:42 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
#define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <stdio.h>//a supprimer apres
#include<unistd.h>
#include<stdlib.h>
typedef struct noeud
{
	int			content;
	struct noeud	*next;
	int index;
}	box;

size_t	ft_strlen(char *s);
int	ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int	ft_strcmp(const char *s1, const char *s2);
char	*get_next_line(int fd);
void sa(box **stack_a);
void sb(box **stack_b);
void ss(box **stack_a, box **stack_b);
void pa(box **stack_a, box **stack_b);
void pb(box **stack_a, box **stack_b);
void ra(box **stack_a);
void rb(box **stack_b);
void rr(box **stack_a, box **stack_b);
void rra(box **stack_a);
void rrb(box **stack_b);
void rrr(box **stack_a, box **stack_b);


#endif