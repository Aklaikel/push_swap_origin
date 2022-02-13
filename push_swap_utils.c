/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 02:32:56 by aklaikel          #+#    #+#             */
/*   Updated: 2022/02/12 23:15:37 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap(t_list *lst, char *str)
{
	int	tmp;

	tmp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = tmp;
	if (!str)
		return ;
	ft_putstr(str);
}

void	delete_top(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	free(tmp);
}

void	delete_bottom(t_list **lst)
{
	t_list	*tmp;

	free(ft_lstlast(*lst));
	tmp = *lst;
	while ((tmp)->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
}

void	push(t_list **src, t_list **dst, char *str)
{
	int	tmp;

	tmp = (*src)->content;
	delete_top(src);
	ft_lstadd_front(dst, ft_lstnew(tmp));
	if (str)
		ft_putstr(str);
}

void	rotate(t_list **lst, char *str)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	ft_lstadd_back(lst, tmp);	
	if (str)
		ft_putstr(str);
}

void	reverse_rotate(t_list **lst, char *str)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *lst;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(lst, last);
	if (str)
		ft_putstr(str);
}

// int main()
// {
// 	t_list *a = NULL;
// 	t_list *b = NULL;
// 	t_list	*tmp = NULL;

// 	ft_lstadd_front(&a, ft_lstnew(20));
// 	ft_lstadd_front(&a, ft_lstnew(10));
// 	ft_lstadd_front(&a, ft_lstnew(16));
// 	ft_lstadd_front(&a, ft_lstnew(1));
// 	ft_lstadd_front(&a, ft_lstnew(13));
// 	ft_lstadd_front(&a, ft_lstnew(15));
// 	ft_lstadd_front(&a, ft_lstnew(14));
// 	ft_lstadd_front(&a, ft_lstnew(19));
// 	printf ("stack a ::\n");
// 	tmp = a;
// 	while(tmp)
// 	{
// 		printf("%d\n", tmp->content);
// 		tmp = tmp->next;
// 	}
// 	// push(&a,&b,"pb\n");
// 	// push(&a,&b,"pb\n");
// 	// push(&a,&b,"pb\n");
// 	// swap(a,"sa\n");
// 	// rotate(&a, "ra\n");
// 	// printf ("stack a ::\n");
// 	// tmp = a;
// 	// while(tmp)
// 	// {
// 	// 	printf("%d\n", tmp->content);
// 	// 	tmp = tmp->next;
// 	// }
// 	// printf ("stack b ::\n");
// 	delete_bottom(&a);
// 	reverse_rotate(&a,"rra\n");
// 	printf ("stack a ::\n");
// 	tmp = a;
// 	while(tmp)
// 	{
// 		printf("%d\n", tmp->content);
// 		tmp = tmp->next;
// 	}
// }