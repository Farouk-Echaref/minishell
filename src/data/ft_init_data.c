#include "data.h"

void	ft_init_data(t_data *data)
{
	if (! data)
		return ;
	data->tokens = NULL;
	data->tree = NULL;
}
