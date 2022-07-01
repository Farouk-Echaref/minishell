/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarhou <mzarhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:08:18 by mzarhou           #+#    #+#             */
/*   Updated: 2022/07/01 01:08:20 by mzarhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list	t_list;

struct s_list
{
	void	*content;
	t_list	*prev;
	t_list	*next;
};

void	ft_lstadd_back(t_list **lst, t_list *new_element);
void	ft_lstadd_front(t_list **lst, t_list *new_element);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

void	ft_lstpush_after(t_list *target, t_list *new_el);
t_list	*ft_lstdetach(t_list *el);

#endif
