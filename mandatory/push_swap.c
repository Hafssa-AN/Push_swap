/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:01:04 by hanebaro          #+#    #+#             */
/*   Updated: 2024/06/26 17:55:54 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void free_stack(box **stack_a)
{
    box *tmp;

    while(*stack_a != NULL)
    {
        tmp = *stack_a;
        *stack_a = (*stack_a)->next;
        free(tmp);
    }
}
void print_error(box **stack_a)
{
    free_stack(stack_a);
    write(2,"Error\n",6);
    exit(1);
}

int is_dupl(box *stack,int x)
{
    box *tmp;
    if(stack != NULL)
    {
        tmp = stack;
        while(tmp != NULL)
        {
            if(tmp->content == x)
                return (1);
            tmp = tmp->next;
        }
    }
    return (0);
}

void add_content(box **stack,int nb)
{
    box *new;
    box *tmp;
    
    new = (box *)malloc(sizeof(box));
    if(!new)
        return;// apres cette null faut free
    new->content = nb;
    new->next = NULL;
    if(*stack == NULL)
    {
        *stack = new;  
        return;
    }
    tmp = *stack;
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
}
long calc_nbr(char *argv, int *j,long *nb)
{
    int len_num;

    *nb = 0;
    len_num = 0;

    while(argv[*j] >= '0' && argv[*j] <= '9')
    {

        (*nb) = (*nb) * 10 + (argv[*j] - 48);
        (*j)++;
        if((*nb) != 0)
            len_num++;
    }
    return (len_num);
}
void pre_tr(char *argv, int *j, int *sg,box **stack_a)
{
    *sg = 1;
    // len_num = 0;
    while(argv[*j] == 32)
        (*j)++;
    if(argv[*j] == '+' || argv[*j] == '-')
    {
        if(*j != 0 && argv[(*j) - 1] != ' ')
            print_error(stack_a);
        if(argv[*j] == '-')
            *sg = -1;
        (*j)++;
    }
    if((argv[*j] < '0' || argv[*j] > '9'))
        print_error(stack_a);
}
void    val_num(char *argv,box **stack_a,long nb,int *j)
{
    if(nb > 2147483647 || nb < -2147483648)
        print_error(stack_a);
    if(is_dupl(*stack_a,nb))
        print_error(stack_a);
    add_content(stack_a,nb);
    while(argv[*j] == 32)
        (*j)++;
}
void fnct(int argc, char *argv[],box **stack_a)
{
    int i;
    int j;
    int sg;
    long nb;

    i = 1;   
    while(i < argc)
    {
        if(!argv[i][0])
            print_error(stack_a);
        j = 0;
        while(argv[i][j])
        {
            pre_tr(argv[i], &j, &sg,stack_a);
            if(calc_nbr(argv[i],&j,&nb) > 10)
                print_error(stack_a);
            nb = nb * sg;
            val_num(argv[i],stack_a,nb,&j);
        }
        i++;
    }
}

int	ft_lstsize(box *stack)
{
	int		size;
	box	*p;

	size = 0;
	p = stack;
	while (p)
	{
		size++;
		p = p -> next;
	}
	return (size);
}
int main(int argc, char *argv[])
{
    box *stack_a;
    box *stack_b;
    
    stack_a = NULL;
    stack_b = NULL;
    fnct(argc, argv, &stack_a);
    if(argc == 3 || argc == 4)
        sort_3(&stack_a);
    else
    {
        if (argc == 5)
            sort4(&stack_a, &stack_b);
        else if (argc == 6)
            sort5(&stack_a, &stack_b);
        else if (argc > 5)
            others(&stack_a, &stack_b);
    }
    return(0);
}
