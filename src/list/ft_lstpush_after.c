#include "list.h"

void	ft_lstpush_after(t_list *target, t_list *new_el)
{
	t_list	*next;

	if (! target || ! new_el)
		return ;
	next = target->next;
	target->next = new_el;
	new_el->prev = target;
	new_el->next = next;
	if (next)
		next->prev = new_el;
}
