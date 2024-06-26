/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:57:30 by hanebaro          #+#    #+#             */
/*   Updated: 2024/06/26 16:50:02 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>//a supprimer apres
#include<unistd.h>
#include<stdlib.h>
typedef struct noeud
{
	int			content;
	struct noeud	*next;
	int index;
}	box;

void	sort_3(box **stack);
void sort4(box **stack_a,box **stack_b);
void sort5(box **stack_a,box **stack_b);
void    others(box **stack_a, box **stack_b);
int	ft_lstsize(box *stack);
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
