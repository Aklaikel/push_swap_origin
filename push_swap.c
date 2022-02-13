/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:54:39 by aklaikel          #+#    #+#             */
/*   Updated: 2022/02/13 02:10:18 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


int	len_stack(t_list *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	ft_check_repeat(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_strncmp(str[i], str[j]) == 0)
				return (0);
			j++;
		}
	i++;
	}
	return (1);
}

void	ft_creat(t_list **a, char **str)
{
	int	x;
	int	y;
	int	status;

	x = 1;
	status = 1;
	while (str[x])
	{
		y = 0;
		while (str[x][y])
		{
			if (str[x][y] == '-' && str[x][y + 1] >= '0'
				&& str[x][y + 1] <= '9')
				y++;
			if (!(str[x][y] >= '0' && str[x][y] <= '9'))
			{
				//free str
				write(2, "error\n", 6);
				exit(0);
			}
			status++;
			y++;
		}
		if (status == 1)
			*a = ft_lstnew(atoi(str[x]));
		else
			ft_lstadd_back(a, ft_lstnew(ft_atoi(str[x])));
		x++;
	}
}

int	get_min(t_list *a)
{
	int	min;
	int	min_i;
	int	i;

	min_i = 0;
	min = a->content;
	a = a->next;
	i = 1;
	while (a)
	{
		if (a->content < min)
		{
			min = a->content;
			min_i = i;
		}
		i++;
		a = a->next;
	}
	return (min_i);
}

int	get_max(t_list *a)
{
	int	max;
	int	max_i;
	int	i;
	
	max_i = 0;
	max = a->content;
	a = a->next;
	i = 1;
	while (a)
	{
		if (a->content > max)
		{
			max = a->content;
			max_i = i;
		}
		i++;
		a = a->next;
	}
	return (max_i);
}

void    ft_sort_array(char **str)
{
    int        x;
    int        y;
    char    *b;

    x = 1;
    if (!str)
        return ;
    while (str[x])
    {
        y = x + 1;
        while (str[y])
        {
            if (ft_atoi(str[x]) > ft_atoi(str[y]))
            {
                b = str[x];
                str[x] = str[y];
                str[y] = b;
            }
            y++;
        }
        x++;
	}
}
void 	get_index(t_list	**a, char	**str)
{
	int x;

	t_list	*tmp;

	tmp = (*a);
	while(tmp)
	{
		x = 1;
		while(str[x])
		{
			if (tmp->content == ft_atoi(str[x]))
			{
				tmp->index = x;					
				break ;
			}
			x++;
		}
		tmp = tmp->next;
	}
}
t_list	*markup_head(t_list	**a, int len)
{
	t_list	*head;
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*ret;
	t_list 	*ret1;

	int x;
	int y;
	x = 1;
	y = 0;
	int len2;
	head = (*a);
	
	while(head)
	{
		x = 1;
		tmp = head;
		tmp2 = tmp;
		ret1 = tmp;
		len2 = len;
		while(tmp)
		{
			if (tmp2->content < tmp->content)
			{
					x++;
					tmp2 = tmp;
			}
			len2--;
			tmp = tmp->next;
		}
		// printf("%d\n",len2);
		if(len2 > 0)
		{
			tmp = (*a);
			while(len2)
			{
				if (tmp2->content < tmp->content)
				{
						x++;
						tmp2 = tmp;
				}
				tmp = tmp->next;
				len2--;
			}
		}
		if (x > y)
		{
			y = x;
			ret = ret1;
		}
		head = head->next;
	}
	return (ret);
}

void	ft_bool(t_list	**a, t_list *mar, int len)
{
	t_list *head;
	head = (*a);

	while (head->content != mar->content)
		head = head->next;
	while (head)
	{
		if (head->content >= mar->content)
		{
			head->bool = 1;
			mar = head;
		}
		else 
			head->bool = 0;
		head = head->next;
		len--;
	}
	if (len > 0)
	{
		head = (*a);
		while (len)
		{
			if (head->content >= mar->content)
			{
				head->bool = 1;
				mar = head;
			}
			else 
				head->bool = 0;
			head = head->next;
			len--;
		}
	}
}
void ft_push_node_to_b(t_list **a, t_list **b, int len , int x, t_list *node)
{
	t_list *head;
	
	if ((len / 2) >= x)
	{
		head = (*a);
		while(node->content != head->content)
			{
				rotate(a, "ra\n");
				head = (*a);
			}
		push(a,b, "pb\n");
	}
	else 
		{
			head = (*a);
			while(node->content != head->content)
			{
				reverse_rotate(a, "rra\n");
				head = (*a);
			}
			push(a,b, "pb\n");
		}
		
}
void ft_push_to_b(t_list **a, t_list **b, int len)
{
	t_list *head;
	head = (*a);
	
	int x;
	x = 0;
	while (head)
	{
		if(head->bool == 0)
		{
			ft_push_node_to_b(a, b, len ,x, head);
			head = *a;
			x = 0;
		}
		else
		{
			x++;
			head = head->next;
		}
	}
}





// TODO
// TODO
// TODO
// TODO
// TODO
// TODO
// TODO
// TODO
// TODO
// TODO
// TODO
// TODO
// TODO

int	get_index_elem(t_list *top, t_list *elem)
{
	int	index;

	index = 0;
	while (top && top != elem)
	{
		top = top->next;
		index++;
	}
	return (index);
}

int	is_the_max(t_list *a, t_list *markup, int content_b)
{
	while (a->next != markup && a->next != NULL)
		a = a->next;
	return (content_b > a->content);
}

t_list *get_index_after(t_list *a, t_list *markup, int content_b)
{
	t_list	*after;
	
	if (content_b < markup->content || is_the_max(a, markup, content_b))
		after = markup;
	else if (content_b < a->content && content_b > ft_lstlast(a)->content)
		after = a;
	else
	{
		while (a->next)
		{
			if (content_b > a->content && content_b < a->next->content)
				break ;
			a = a->next;
		}
		after = a->next;
	}
	// printf(" after = %d\n", after->content);
	return (after);
}

int get_needed_moves(t_list *a, t_list *b, t_list *markup, t_list *elem_b)
{
	int		up_b;
	int		index;
	int		index_after;
	int		len_b;
	t_list	*after;

	len_b = len_stack(b);
	index = get_index_elem(b, elem_b);
	// puts("hna");
	// printf("index_b = %d	elem = %d	len_b = %d\n", index, elem_b->content, len_b);
	up_b = index;
	if (index > len_b / 2)
		up_b = len_b - index;
	after = get_index_after(a, markup, elem_b->content);
	index_after = get_index_elem(a, after);
	//printf("up_b = %d	index_after = %d\n", up_b, index_after);
	return (up_b + ft_min(index_after, len_stack(a) - index_after));
}

t_list	*get_optimal(t_list *a, t_list *b, t_list *markup)
{
	if(!b || !a)
		return (NULL);
	int		min_moves;
	int		tmp;
	t_list	*elem;
	t_list	*tmp_b;
	
	tmp_b = b;
	min_moves = get_needed_moves(a, tmp_b, markup, b);
	elem = b;
	// printf("%d needs %d moves\n", elem->content, min_moves);
	b = b->next;
	while (b)
	{
		tmp = get_needed_moves(a, tmp_b, markup, b);
		// printf("%d needs %d moves\n", b->content, tmp);
		if (tmp < min_moves)
		{
			min_moves = tmp;
			elem = b;
		}
		b = b->next;
	}
	return (elem);
}

// TODO
// TODO
// TODO
// TODO
// TODO
// TODO
// TODO
// TODO
// TODO
// TODO
// TODO
// TODO
// TODO

// void	last_push(t_list **a, t_list **b, t_list *optimal)
// {
	
// }

void	ft_push_to_a(t_list **a, t_list **b, t_list *optimal, t_list *mar)
{
	int		i;
	int index;
	int list_size;
	list_size = len_stack(*b);
	index = get_index_elem((*b), optimal);
	
	if(index > (list_size / 2))
	{
		while(list_size - index++)
			reverse_rotate(b, "rrb\n");
	}
	else 
	{
		while(index--)
			rotate(b,"rb\n");
	}
	// last_push(&optimal,*a,*b);
	list_size = len_stack(*a);
	t_list	*after = get_index_after(*a, mar, (*b)->content);
	i = get_index_elem(*a, after);
	// printf("After = %d		Index after = %d\n", after->content, i);
	// printf("index  %d\ntmp: %p\n ", i, tmp);
	// disp(*a, "a =  ");
	// disp(*b, "b =  ");
	if (i < list_size - i)
		while(i--)
			rotate(a, "ra\n");
	else
	{
		// rra; while i-th not in top
		while (list_size - i++)
			reverse_rotate(a, "rra\n");
	}
	push(b, a, "pa\n");
}

void	sort_more_than_five(t_list	**a, t_list	**b, int len, char	**str)
{
	t_list	*mar;
	t_list	*optimal;

	ft_sort_array(str);
	get_index(a, str);
	mar = markup_head(a, len);
	ft_bool(a, mar, len);
	ft_push_to_b(a, b, len);
	mar = markup_head(a, len_stack(*a));
	// printf("Markup: %d\n", mar->content);
	// disp(*a, "a = ");
	// disp(*b, "b = ");
	// exit(1);
	optimal = get_optimal(*a, *b, mar);
	while (optimal)
	{
		ft_push_to_a(a,b,optimal, mar);
		// if ((*a)->content < mar->content)
		// 	mar = *a;
		mar = markup_head(a, len_stack(*a));
		// printf("Markup: %d\n", mar->content);
		// disp(*a, "a = ");
		// disp(*b, "b = ");
		optimal = get_optimal(*a, *b, mar);
	}
	mar = markup_head(a, len);
	int index = get_index_elem(*a, mar);
	if(index > (len / 2))
	{
		while(len - index++)
			reverse_rotate(a, "rra\n");
	}
	else 
	{
		while(index--)
			rotate(a,"ra\n");
	}
	// disp(*a, "a = ");
	// disp(*b, "b = ");

	exit(0);	
	// calcule_nb_moves(a, b, len);
	// t_list *h = *a;
	// while (h) {
	// 	printf("Nbr = %d	B = %d\n", h->content, h->bool);
	// 	h = h->next;
	// }
	// exit(0);
}
void	sort_three(t_list **a)
{
	int	i;

	i = get_max(*a);
	if (i == 0)
		rotate(a, "ra\n");
	else if (i == 1)
		reverse_rotate(a, "rra\n");
	if ((*a)->content > (*a)->next->content)
		swap(*a, "sa\n");
}

void	sort_five(t_list **a, t_list **b, int len)
{
	int	i;
	while (len > 3)
	{
		i = get_min(*a);
		if (i <= len / 2)
		{
			while (i--)
				rotate(a, "ra\n");
		}
		else
		{
			while (len - i++)
				reverse_rotate(a, "rra\n");
		}
		push(a, b, "pb\n");
		len--;
	}
	sort_three(a);
	while (*b)
		push(b, a, "pa\n");
}
// void check_sorted(t_list *a)
// {
// 	while(a)
// 	{
// 		if (a->content > a->next->content)
// 		{
// 			//free all 
// 			return (1);
// 		}
// 		a = a->next;
// 	}
// 	return (0);
// }
int	check_suivi(t_list	*a)
{
	int	i;
	int j;
	int	tmp;
	t_list *head;

	head = a;
	j = 0;
	i = get_min(a);
	a = a + i;
	
	while(1)
	{
		if ((a)->next == NULL)
		{
			tmp = (a)->content;
			break;
		}
		if((a)->content > (a)->next->content)
			return -1;
		a = (a)->next;
	}
	a = head;
	if (tmp > a->content && i != 0)
		return -1;
	while (j < i - 1)
	{
		if((a)->content > (a)->next->content)
			return 0;
		a = (a)->next;
		j++;
	}
	return (i);
}
void	sort_suivi_array(t_list **a, int len)
{
	int	i;
	(void)len;
	i = check_suivi(*a);
	if (i <= len / 2)
		while (i--)
			rotate(a, "ra\n");
	else
		while (len - i++)
			reverse_rotate(a, "rra\n");
}

void func(void)
{
	int pid = getpid();
	char buff[1024];
	sprintf(buff, "leaks %d", pid);
	system(buff);
}

int	main(int ac, char **av)
{
	// atexit(func);
	char	**str;
	char	*sep;
	t_list	*a;
	t_list	*b;
	int		i;
	b = NULL;
	a = NULL; // malloc(sizeof(t_list));
	sep = " ";
	str = ft_split(ft_strjoin(ac, av, sep), ' ');
	ft_creat(&a, str);
	if (ft_check_repeat(str) == 0)
	{
		//free(str);
		write(2, "error\nyou have a repeated int", 29);
		exit (0);
	}
	i = len_stack(a);
	// check_sorted(a);
	// if(check_suivi(a) != -1)
	// 	sort_suivi_array(&a, i);	
	if (i == 0 || i == 1)
		return (0);
	// if (i == 3)
	// 	sort_three(&a);
	// if(i == 5)
	// 	sort_five(&a, &b, i);
	// else
	sort_more_than_five(&a, &b, i, str);
		
	// while (a)
	// {
	// 	printf("%d\n", a->content);
	// 	a = a->next;
	// }
	//ft_lstclear(a);
	//ft_lstclear(b);
}
