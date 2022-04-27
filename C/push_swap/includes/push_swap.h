/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 08:12:03 by izouf             #+#    #+#             */
/*   Updated: 2021/12/30 18:20:11 by izouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_element
{
	int					n;
	ssize_t				i;
	int					keep;
	struct s_element	*next;
	struct s_element	*prev;
}						t_element;

typedef struct s_stack
{
	t_element		*head;
	size_t			size;
	size_t			pairs;
	t_element		*markup_head;
}					t_stack;

typedef struct s_command
{
	char				*name;
	struct s_command	*next;
}						t_command;

typedef struct s_list
{
	size_t			size;
	t_command		*head;
}					t_list;

typedef struct s_shift
{
	t_element	*ela;
	t_element	*elb;
	int			dira;
	int			dirb;
	size_t		size;
	int			is_set;
}				t_shift;

t_stack		*ft_create_stack(void);
t_list		*ft_create_list(void);
t_element	*ft_create_element(int n);
t_command	*ft_create_command(char *name);
t_shift		*ft_create_shift(void);

void		ft_add_command(t_list *list, t_command *command);
void		ft_exec_command(t_stack *stack_a, t_stack *stack_b, char *command);
void		ft_print(t_list *list);

void		ft_add_elem(t_stack *stack, t_element *element);
void		ft_push(t_element *element, t_stack *stack);
t_element	*ft_pop(t_stack *stack);

void		ft_direction(t_stack *stack_a, t_stack *stack_b, t_shift *shift);

void		ft_free_list(t_list *list);
void		ft_free_stack(t_stack *stack);

void		ft_markup(t_stack *stack);
size_t		ft_u_markup(t_stack *stack, t_element *markup_head);
void		ft_index_stack(t_stack *stack);

void		px(t_stack *from, t_stack *to, char *name, t_list *list);
void		sx(t_stack *stack, char *name, t_list *list);
void		ss(t_stack *a, t_stack *b, char *name, t_list *list);

void		rx(t_stack *stack, char *name, t_list *list);
void		rr(t_stack *a, t_stack *b, char *name, t_list *list);
void		rrx(t_stack *a, char *name, t_list *list);
void		rrr(t_stack *a, t_stack *b, char *name, t_list *list);

t_list		*ft_solve(t_stack *stack_a);
void		ft_solve_a(t_stack *stack_a, t_stack *stack_b, t_list *list);
void		ft_solve_b(t_stack *stack_a, t_stack *stack_b, t_list *list);

t_stack		*ft_cf_a(int argc, char **argv);
void		ft_check_double(t_stack *stack);
#endif
