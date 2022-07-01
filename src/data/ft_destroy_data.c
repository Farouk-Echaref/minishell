#include "data.h"

void	ft_destroy_data(t_data *data)
{
	if (! data)
		return ;
	ft_lstclear(&data->tokens, &free);
	ft_tree_clear(&data->tree, &free);
}
