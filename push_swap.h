/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:42:12 by aklaikel          #+#    #+#             */
/*   Updated: 2022/02/12 23:13:49 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
	int				bool;
}				t_list;

char	*ft_strjoin(int size, char **strs, char *sep);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_atoi(const char	*str);
void	ft_putstr(char *s);
void	delete_top(t_list	**lst);
void	rotate(t_list	**lst, char	*str);
void	reverse_rotate(t_list	**lst, char *str);
void	push(t_list	**src, t_list	**dst, char *str);
void	swap(t_list	*lst, char	*str);
void	sort_three(t_list **a);
void	check_sorted(t_list *a);
int	check_suivi(t_list	*a);
int ft_min(int a, int b);
void    disp(t_list *a, char *str);
int	ft_lstsize(t_list *lst);

// typedef struct s_stack
// {
// 	int		len;
// 	t_list	*head;
// 	t_list	*bottom;
// }				t_stack;

#endif