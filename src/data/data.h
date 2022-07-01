#ifndef DATA_H
# define DATA_H

# include "list/list.h"
# include "tree/tree.h"
# include <stdlib.h>

// single source of truth
typedef struct s_data t_data;

struct s_data
{
	t_list			*tokens;
	struct s_tree	*tree;
};

void	ft_destroy_data(t_data *data);
void	ft_init_data(t_data *data);

#endif
