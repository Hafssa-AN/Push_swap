/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 01:40:38 by hanebaro          #+#    #+#             */
/*   Updated: 2024/06/26 12:11:39 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/push_swap.h"
int is_sort(box **stack)
{
    box *tmp;

    if(!stack || !*stack)
        return(0);
    tmp = *stack;
    while(tmp != NULL)
    {
        if(tmp->next && (tmp->content > tmp->next->content))
            return(0);
        tmp = tmp->next;
    }
    return(1);
}

void val_sort(box **tmp, int val, int *i)
{
    if((*tmp)->next && (val >  (*tmp)->next->content))
            (*i)++;
    (*tmp) = (*tmp)->next;   
}
int *etiqueter(box **stack)
{
    int *tab;
    box *tmp;
    int i;
    int val;
    
    tab = (int *)malloc(2 * sizeof(int));
    if (!tab)
        return NULL;
    tmp = *stack;
    i = 0;
    val = (*stack)->content;
    while(tmp != NULL)
        val_sort(&tmp, val, &i);
    tab[0] = i;
    val = (*stack)->next->content;
    tmp = (*stack)->next;
    i = 0;
    while(tmp != NULL)
        val_sort(&tmp, val, &i);
    tab[1] = i;
    return(tab);
}
void sort_3(box **stack)
{
    int *tab;
    
    if(!stack || !*stack)
        return;
    if(is_sort(stack))
        return;// a verifier
    tab = etiqueter(stack);
    if(tab[0] == 0 && tab[1] == 1)
    {
        rra(stack);
        sa(stack);
    }
    else if (tab[0] == 2 && tab[1] == 1)
    {
        ra(stack);
        sa(stack);
    }
    else if (tab[0] == 2 && tab[1] == 0)
        ra(stack);
    else if (tab[0] == 1 && tab[1] == 0)
        sa(stack);
    else if (tab[0] == 1 && tab[1] == 1)
        rra(stack);
    free(tab);
}
int find_min(box *tmp)
{
    int i;
    int exist;
    int min;
    
    min = tmp->content;
    i = 0;
    while(tmp)
    {
        if(tmp->next && (min >  tmp->next->content))
        {
            min = tmp->next->content;
            exist = i + 1;
        }
        tmp = tmp->next;
        i++;
    }
    return(exist);
}
void sort4(box **stack_a,box **stack_b)
{
    int pos_min;

    pos_min = find_min(*stack_a);
    if(pos_min == 1)
        sa(stack_a);
    else if(pos_min == 2)
    {
        rra(stack_a);
        rra(stack_a);
    }
    else if(pos_min == 3)
        rra(stack_a);
    pb(stack_a, stack_b);
    sort_3(stack_a);
    pa(stack_a, stack_b);
}

void sort5(box **stack_a,box **stack_b)
{
    int pos_min;

    pos_min = find_min(*stack_a);
    if(pos_min == 1)
        sa(stack_a);
    else if(pos_min == 2)
    {
        ra(stack_a);
        ra(stack_a);
    }
    else if(pos_min == 3)
    {
        rra(stack_a);
        rra(stack_a);
    }
        
    else if(pos_min == 4)
        rra(stack_a);
    pb(stack_a, stack_b);
    sort4(stack_a, stack_b);
    pa(stack_a, stack_b);
}

void indexer(box **stack_a)
{
    box *tmp;
    box *fix;

    fix = *stack_a;
    while(fix)
    {
        fix->index = 0;
        tmp = *stack_a;
        while(tmp)
        {
            if(tmp->content < fix->content)
                fix->index++;
            tmp = tmp->next;
        }
        fix = fix->next;
    }
}
int interval(int total)
{
    if (total <= 50)
		return (8);
	else if (total <= 100)
		return (15);
	else
		return (35);
}
int find_max(box **stack)
{
    
    int max;
    box *tmp;

    tmp = *stack;
    max = ft_lstsize(tmp) - 1;
    while(tmp)
    {
        if((tmp)->index == max)
            return((tmp)->index);
        (tmp) = (tmp)->next;
    }
    return (0);
}

char in_half(box *stack)
{
    int size;
    int i;

    i = 0;
    size = ft_lstsize(stack);
    while(i <= (size / 2))
    {
        if(stack->index == size - 1)
            return('t');
        i++;
        stack = stack->next;
    }
    return('b'); 
}

void final_sort(box **stack_a, box **stack_b)
{
    char half;

    half = 'n';
    while(*stack_b)
    {
        if(find_max(stack_b) == (*stack_b)->index)
        {
            half = 'n';
            pa(stack_a, stack_b);
        }    
        else 
        {
            if(half == 'n')
                half = in_half(*stack_b);
            if (half == 't')
                rb(stack_b);
            else if(half == 'b')
                rrb(stack_b);
        }
    }
}

void    others(box **stack_a, box **stack_b)
{
    int intervale[2];
    
    indexer(stack_a);
    intervale[0] = 0;
    intervale[1] = interval(ft_lstsize(*stack_a));
    while(*stack_a)
    {
        if ((*stack_a)->index <= intervale[1] && (*stack_a)->index >= intervale[0])
        {
            pb(stack_a,stack_b);
            intervale[0]++;
            intervale[1]++;
        }
        else if ((*stack_a)->index < intervale[0])
        {
            pb(stack_a,stack_b);
            rb(stack_b);
            intervale[0]++;
            intervale[1]++;
        }    
        else
            ra(stack_a);
    }
    final_sort(stack_a, stack_b);
}
