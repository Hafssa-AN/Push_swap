/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:09:39 by hanebaro          #+#    #+#             */
/*   Updated: 2024/06/26 12:04:49 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/push_swap.h"

void sa(box **stack_a)
{
    //swap values
    if(!stack_a || !*stack_a || !(*stack_a)->next)
        return;//quoi faire!!
    box *elm1;
    box *elm2;

    elm1= *stack_a;
    elm2 = elm1->next;
    elm1->next = elm2->next;
    elm2->next = elm1;
    *stack_a = elm2;
    write(1,"sa\n",3);
}
void sb(box **stack_b)
{
    if(!stack_b || !*stack_b || !(*stack_b)->next)
        return ;//quoi faire!!
    box *elm1;
    box *elm2;

    elm1= *stack_b;
    elm2 = elm1->next;
    elm1->next = elm2->next;
    elm2->next = elm1;
    *stack_b = elm2;
    write(1,"sb\n",3);
}
void ss(box **stack_a, box **stack_b)
{
    sa(stack_a);
    sb(stack_b);
    write(1,"ss\n",3);
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
    write(1,"pa\n",3);
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
    write(1,"pb\n",3);
    
}
void ra(box **stack_a)
{
    box *f_elm;
    box *l_elm;

    if(!stack_a || !*stack_a || !(*stack_a)->next)
        return;//quoi faire!!
    f_elm = *stack_a;
    l_elm = *stack_a;
    while(l_elm->next != NULL)
        l_elm = l_elm->next;
    l_elm->next = f_elm;
    *stack_a = f_elm->next;
    f_elm->next = NULL;
    write(1,"ra\n",3);
}
void rb(box **stack_b)
{
    box *f_elm;
    box *l_elm;
    if(!stack_b || !*stack_b || !(*stack_b)->next)
        return;//quoi faire!!
    f_elm = *stack_b;
    l_elm = *stack_b;
    while(l_elm->next != NULL)
        l_elm = l_elm->next;
    l_elm->next = f_elm;
    *stack_b = f_elm->next;
    f_elm->next = NULL;
    write(1,"rb\n",3);
}
void rr(box **stack_a, box **stack_b)
{
    ra(stack_a);
    rb(stack_b);
    write(1,"rr\n",3);
}

void rra(box **stack_a)
{
    box *l_elm;
    box *b_last;

    if(!stack_a || !*stack_a || !(*stack_a)->next)
        return;//quoi faire!!
    l_elm = *stack_a;
    b_last = NULL;
    while(l_elm->next != NULL)
    {
        b_last = l_elm;
        l_elm = l_elm->next;
    }
    l_elm->next = *stack_a;
    *stack_a = l_elm;
    // if(blast)
    b_last->next = NULL;
    write(1,"rra\n",4);
}
void rrb(box **stack_b)
{
    box *l_elm;
    box *b_last;

    if(!stack_b || !*stack_b || !(*stack_b)->next)
        return;//quoi faire!!
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
    write(1,"rrb\n",4);
}
void rrr(box **stack_a, box **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    write(1,"rrr\n",4);
}