#ifndef TREE_H
# define TREE_H
# include <stdlib.h>

typedef struct s_tree t_tree;

struct s_tree
{
	void	*content;
	t_tree	*left;
	t_tree	*right;
};

t_tree	*ft_new_tree_node(void *content);
void	ft_tree_clear(t_tree **tree_ptr);


#endif
