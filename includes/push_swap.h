/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:45:31 by mea               #+#    #+#             */
/*   Updated: 2022/03/07 16:07:50 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}				t_stack;

typedef struct s_stack_met
{
	int				avg;
	int				max;
	int				min;
}	t_met;

typedef struct s_stacks
{
	t_stack	*b;
	t_stack	*a;
	t_met	*a_met;
	t_met 	*b_met;
}	t_stacks;

int				check_int_overflow(char *str);
int				checkargs(char *str);
int				checkdouble(t_stack *stack_a);
int 			checkifsorted(t_stack **stack_a);
void			error_print(int nb);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_strlen(char *s);
t_stack 		*node_creation(int arg, t_stack **stack);
t_stack			*ft_last(t_stack *stack);
void			ft_add_back(t_stack **stack, t_stack *new);
int				stacklen(t_stack **stack_a);
void			printmyarray(int *arr, int size);
int				*get_array_sorted(t_stack **stack_a, int *array, int size);
int 			get_max(int *arr, int size);
void 			countSort(int arr[], int n, int exp);
void 			radix_sort(int *arr, int size);
int 			*copystackinarray(int *arr, t_stack **stack_a);
int 			*copynegnbinarray(int *arr, t_stack **stack_a);
int 			*copyposnbinarray(int *arr, t_stack **stack_a);
int				sizeofmyarray(int *arr);
int				checksize(int size);
int				calculebestnb(int size, int divider, int chunck, int *arr);
int				morenbinstack(t_stack **stack_a, int nbfound);
int				*changesignofarray(int *arr, int size);
int				*mergearrays(int *arr, int *arr2, int i, int j);
void			printmystack(t_stack *stack_a);
void			bestchoice(t_stack **stack_a, t_stack **stack_b, int nbfound);
void			lastpush(t_stack **stack_a, t_stack **stack_b, int size);
int				getmin(t_stack **stack);
void			putitright(t_stack **stack_a, t_stack **stack_b, int min_b, int max_b);
void			move_to_top(t_stack **stack_b, int nbf);
int				getmax(t_stack **stack);
int				getpos(t_stack **stack, int nbf);
unsigned int	getdiff(t_stack **stack_a, t_stack **stack_b);
int				findminpos(t_stack **stack_a);
void			move_to_top(t_stack **stack_b, int nbf);
void			ft_printstr(char *str, int nb);
int				findmin(t_stack **stack_a);
void 			ft_printstr(char *str, int nb);
int				getposnbtop(t_stack **stack, int nbfound);
void			putitinthemiddle(t_stack **tmp, t_stack **stack_a, t_stack **stack_b, int minpos, int pos);
int				getposnbbot(t_stack **stack, int nbfound);
void			sorting(t_stack **stack_a, t_stack **stack_b);
void			bigsort(t_stack **stack_a, t_stack **stack_b, int size);
void			sort_three(t_stack **stack_a);
void			sort4and5(t_stack **stack_a, t_stack **stack_b);
void			sort_above5(t_stack **stack_a, t_stack **stack_b);

void			swap_a(t_stack **stack);
void			swap_b(t_stack **stack);
void			swap_all(t_stack **stack_a, t_stack **stack_b);
void			push_a(t_stack **stack_a, t_stack **stack_b);
void			push_b(t_stack **stack_a, t_stack **stack_b);
void			rotate_a(t_stack **stack);
void			rotate_b(t_stack **stack);
void			rotate_all(t_stack **stack_a, t_stack **stack_b);
void			rotate_reverse_a(t_stack **stack, char *str);
void			rotate_reverse_b(t_stack **stack, char *str);
void			rotate_reverse_all(t_stack **stack_a, t_stack **stack_b);

#endif