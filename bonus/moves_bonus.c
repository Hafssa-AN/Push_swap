/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:16:54 by hanebaro          #+#    #+#             */
/*   Updated: 2024/06/26 16:19:34 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/push_swap_bonus.h"

void sa(box **stack_a)
{
    box *elm1;
    box *elm2;
    
    if(!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    elm1= *stack_a;
    elm2 = elm1->next;
    elm1->next = elm2->next;
    elm2->next = elm1;
    *stack_a = elm2;
}
void sb(box **stack_b)
{
    box *elm1;
    box *elm2;
    
    if(!stack_b || !*stack_b || !(*stack_b)->next)
        return ;
    elm1= *stack_b;
    elm2 = elm1->next;
    elm1->next = elm2->next;
    elm2->next = elm1;
    *stack_b = elm2;
}
void ss(box **stack_a, box **stack_b)
{
    sa(stack_a);
    sb(stack_b);
}
void pa(box **stack_a, box **stack_b)
{
    box *tmp;
    
    if (!stack_b || !*stack_b)
        return;
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
}
void pb(box **stack_a, box **stack_b)
{
    box *tmp;
    
    if (!stack_a || !*stack_a)
        return;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp->next = *stack_b;
    *stack_b = tmp;
    
}
void ra(box **stack_a)
{
    box *f_elm;
    box *l_elm;

    if(!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    f_elm = *stack_a;
    l_elm = *stack_a;
    while(l_elm->next != NULL)
        l_elm = l_elm->next;
    l_elm->next = f_elm;
    *stack_a = f_elm->next;
    f_elm->next = NULL;
}
void rb(box **stack_b)
{
    box *f_elm;
    box *l_elm;
    
    if(!stack_b || !*stack_b || !(*stack_b)->next)
        return;
    f_elm = *stack_b;
    l_elm = *stack_b;
    while(l_elm->next != NULL)
        l_elm = l_elm->next;
    l_elm->next = f_elm;
    *stack_b = f_elm->next;
    f_elm->next = NULL;
}
void rr(box **stack_a, box **stack_b)
{
    ra(stack_a);
    rb(stack_b);
}

void rra(box **stack_a)
{
    box *l_elm;
    box *b_last;

    if(!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    l_elm = *stack_a;
    b_last = NULL;
    while(l_elm->next != NULL)
    {
        b_last = l_elm;
        l_elm = l_elm->next;
    }
    l_elm->next = *stack_a;
    *stack_a = l_elm;
    b_last->next = NULL;
}
void rrb(box **stack_b)
{
    box *l_elm;
    box *b_last;

    if(!stack_b || !*stack_b || !(*stack_b)->next)
        return;
    l_elm = *stack_b;
    b_last = NULL;
    while(l_elm->next != NULL)
    {
        b_last = l_elm;
        l_elm = l_elm->next;
    }
    l_elm->next = *stack_b;
    *stack_b = l_elm;
    b_last->next = NULL;
}
void rrr(box **stack_a, box **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}